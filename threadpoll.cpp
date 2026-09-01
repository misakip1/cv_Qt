#include "threadpoll.h"

ThreadPoll::ThreadPoll(int num):stop_(false){
    if(num<=2||num>=8)
        thread_num_=5;
    else
        thread_num_=num;
    start();
}

void ThreadPoll::start()
{
    for(int i=0;i<thread_num_;i++)
    {
        thread_poll_.emplace_back([this](){
            while(!stop_.load())
           {
                while (!this->stop_.load()) {
                    Task task; // 存放从队列取出的任务
                    {
                        // 独占锁：配合条件变量实现等待
                        std::unique_lock<std::mutex> cv_mt(mtx_);
                        // 条件变量等待：被唤醒后自动检查谓词
                        // 唤醒条件：线程池标记停止  OR  任务队列非空
                        this->cv_.wait(cv_mt, [this] {
                            return this->stop_.load() || !this->queue_.empty();
                        });

                        // 被唤醒后队列为空 → 是stop信号触发，线程退出循环
                        if (this->queue_.empty())
                            return;

                        // 取出队首任务，用移动语义避免拷贝开销
                        task = std::move(this->queue_.front());
                        this->queue_.pop();
                    }
                    // 任务开始执行：空闲线程数-1
                    this->thread_num_--;
                    // 执行真正的任务逻辑
                    task();
                    // 任务执行完毕：空闲线程数+1
                    this->thread_num_++;
                }
            }
        });
    }
}

void ThreadPoll::stop()
{
    stop_.store(true);
    cv_.notify_all();
    for(auto&thread_:thread_poll_)
    {
        if(thread_.joinable())
            thread_.join();
    }
}
