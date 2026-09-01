#ifndef THREADPOLL_H
#define THREADPOLL_H
#include"Singleton.h"
#include<atomic>
#include<Thread>
#include<condition_variable>
#include<mutex>
#include<queue>
#include<vector>
#include<functional>
#include <future>
class ThreadPoll:public Singleton<ThreadPoll>
{
    friend class Singleton<ThreadPoll>;
    using Task=std::packaged_task<void()>;
public:
    ~ThreadPoll();
    template<typename F,typename ...Args>
    auto post(F&&f,Args&&...args)->decltype(f(args...))
        {
        using RetType=decltype(f(args...));
            if (stop_.load())
                return std::future<RetType>{};

            // 核心：用 shared_ptr 管理 packaged_task 生命周期
            // 1. packaged_task 不可拷贝，只能移动；放入队列需要通过lambda捕获指针间接调用
            // 2. 用 bind + 完美转发，把函数+参数打包成无参可调用对象
            auto task = std::make_shared<std::packaged_task<RetType()>>(
                std::bind(std::forward<F>(f), std::forward<Args>(args)...));

            // 从 packaged_task 中获取 future，交给调用方拿结果
            std::future<RetType> ret = task->get_future();
            {
                // 加锁保护任务队列，保证入队操作线程安全
                std::lock_guard<std::mutex> cv_mt(mtx_);
                // 封装成统一的 void() 任务入队：lambda 捕获 shared_ptr，执行真正的任务
                queue_.emplace([task] { (*task)(); });
            }
            // 唤醒一个休眠中的工作线程来执行任务
            cv_.notify_one();
            return ret;

        }
private:
    ThreadPoll(int num=5);
    void start();
    void stop();
    std::atomic<int> thread_num_;
    std::atomic<bool> stop_;
    std::queue<Task> queue_;
    std::vector<std::thread> thread_poll_;
    std::mutex mtx_;
    std::condition_variable cv_;



};

#endif // THREADPOLL_H
