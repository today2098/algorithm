#ifndef ALGORITHM_RANDOM_HPP
#define ALGORITHM_RANDOM_HPP 1

#include <concepts>
#include <limits>
#include <random>

namespace algorithm {

template <std::uniform_random_bit_generator Engine = std::default_random_engine>
class Random {
public:
    using seed_type = typename Engine::result_type;
    using engine_type = Engine;

private:
    seed_type m_seed;
    engine_type m_engine;

public:
    explicit Random() : Random(std::random_device()()) {}
    explicit Random(seed_type seed) : m_seed(seed), m_engine(seed) {}

    seed_type seed() const { return m_seed; }
    engine_type &engine() { return m_engine; }
    auto next() { return m_engine(); }

    // 離散一様分布 (Discrete Uniform Distribution) に従う乱数（整数）を生成する．
    template <std::integral Type>
    Type uniform(Type min = std::numeric_limits<Type>::min(), Type max = std::numeric_limits<Type>::max()) {
        std::uniform_int_distribution<Type> dist(min, max);
        return dist(m_engine);
    }
    // 離散一様分布 (Discrete Uniform Distribution) に従う乱数（実数）を生成する．
    template <std::floating_point Type>
    Type uniform(Type min = std::numeric_limits<Type>::min(), Type max = std::numeric_limits<Type>::max()) {
        std::uniform_real_distribution<Type> dist(min, max);
        return dist(m_engine);
    }
};

}  // namespace algorithm

#endif
