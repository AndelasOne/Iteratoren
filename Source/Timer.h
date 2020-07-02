//
// Created by Gm7Na on 02.07.2020.
//

#ifndef ITERATOREN_TIMER_H
#define ITERATOREN_TIMER_H

#include <chrono>
class Timer
{
public:
    void start()
    {
        m_StartTime = std::chrono::system_clock::now();
        m_bRunning = true;
    }
    void stop()
    {
        m_EndTime = std::chrono::system_clock::now();
        m_bRunning = false;
    }
    double elapsedMilliseconds()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime;
        if(m_bRunning)
        {
            endTime = std::chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }
        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
    }
    double elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000.0;
    }
private:
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    bool m_bRunning = false;
};

template <typename Callable>
double time_methode(Callable && callable)
{
    Timer t;
    t.start();
    callable();
    t.stop();
    return t.elapsedMilliseconds();
}


#endif //ITERATOREN_TIMER_H
