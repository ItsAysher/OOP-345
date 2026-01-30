#pragma once

#include <string>
#include <chrono>
#include <ostream>

struct Task {
    std::string name;
    std::string units;
    std::chrono::steady_clock::duration duration;
};

class TimedTask {
    static std::size_t MAX_TASKS = 10;
    Task m_tasks[MAX_TASKS];                                // statically allocated task array
    std::size_t m_count{ 0 };                               // number of records stored
    std::chrono::steady_clock::time_point m_startTime;      // start time for current task
    std::chrono::steady_clock::time_point m_endTime;        // end time for current task
public:
    // default constructor
    TimedTask();

    // start/stop the clock for a task interval
    void startClock();
    void stopClock();

    // record a completed task using a C-style null-terminated name
    void addTask(const char* taskName);

    // formatted output of stored tasks
    friend std::ostream& operator<<(std::ostream& os, const TimedTask& tt);