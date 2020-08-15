#ifndef ELIP_STATS_RANDOME_SAMPLE_H
#define ELIP_STATS_RANDOME_SAMPLE_H

#include "elip/stats/random_engine.h"

namespace elip {

namespace {

std::mt19937& DefaultGenerator() {
    static std::mt19937 default_generator = RandomEngine{}.GetMT19937();
    return default_generator;
}

}  // namespace

/**
 * @brief Sample a random number uniformly distributed in [a, b).
 *
 * @tparam T number type, e.g., integer or double
 * @param a
 * @param b
 * @param engine Random engine to generate the sample.
 *
 * @return
 */
template <typename T,
          typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
T SampleUniform(T a, T b, std::mt19937& gen = DefaultGenerator()) {
    std::uniform_int_distribution<T> distrib{a, b};
    return distrib(gen);
}

template <typename T = double,
          typename std::enable_if<!std::is_integral<T>::value>::type* = nullptr>
T SampleUniform(T a = T{0.0}, T b = T{1.0},
                std::mt19937& gen = DefaultGenerator()) {
    std::uniform_real_distribution<T> distrib{a, b};
    return distrib(gen);
}

/**
 * @brief Sample a random number from a nomal distribution N(mean, stddev).
 *
 * @tparam T number type
 * @param mean
 * @param stddev
 *
 * @return
 */
template <typename T = double,
          typename std::enable_if<!std::is_integral<T>::value>::type* = nullptr>
T SampleNormal(T mean = T{0.0}, T stddev = T{1.0},
               std::mt19937& gen = DefaultGenerator()) {
    std::normal_distribution<T> distrib{mean, stddev};
    return distrib(gen);
}

}  // namespace elip

#endif /* ifndef ELIP_STATS_RANDOME_SAMPLE_H */
