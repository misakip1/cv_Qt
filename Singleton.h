#ifndef SINGLETON_H
#define SINGLETON_H
#include<QDebug>
template<typename T>
class Singleton
{
protected:
    ~Singleton()
    {
        qDebug()<<"Http析构";
    }
    Singleton() =default;
    Singleton(const Singleton<T>&)=delete;
    Singleton&operator=(const Singleton<T>&)=delete;

public:
    static T&getInstance()
    {
        static T t;
        return t;
    }



};

#endif // SINGLETON_H
