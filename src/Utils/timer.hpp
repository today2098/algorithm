#ifndef ALGORITHM_TIMER_HPP
#define ALGORITHM_TIMER_HPP 1

#include <chrono>

namespace algorithm {

class Timer {
    std::chrono::system_clock::time_point m_start;

public:
    Timer() : m_start(std::chrono::system_clock::now()) {}

    // 計測開始時間を保存する．
    void restart() { m_start = std::chrono::system_clock::now(); }
    // 経過時間を返す．[msec].
    auto elapsed() const {
        auto now = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(now - m_start).count();
    }
};

}  // namespace algorithm

#endif
