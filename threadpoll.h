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
#include <type_traits>
class ThreadPoll:public Singleton<ThreadPoll>
{
    friend class Singleton<ThreadPoll>;
    using Task=std::packaged_task<void()>;
public:
    ~ThreadPoll();
    template<typename F, typename ...Args>
    auto post(F&& f, Args&&... args) -> std::future<std::invoke_result_t<F, Args...>>
    {
        using RetType = std::invoke_result_t<F, Args...>;

        if (stop_.load())
            return std::future<RetType>{};

        // 用 lambda 替代 bind，内部用 std::invoke 统一调用
        auto task = std::make_shared<std::packaged_task<RetType()>>(
            [f = std::forward<F>(f), ...args = std::forward<Args>(args)]() mutable {
                return std::invoke(std::move(f), std::move(args)...);
            }
            );

        std::future<RetType> ret = task->get_future();
        {
            std::lock_guard<std::mutex> lock(mtx_);
            queue_.emplace([task] { (*task)(); });
        }
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
