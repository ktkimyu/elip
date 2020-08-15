#include "elip/stats/random_engine.h"

#include <algorithm>
#include <array>
#include <random>

namespace elip {

/**
 * The random engine is initialized depending on the argument entire_seed.
 *
 * If entire_seed == false, it is initialized using a single seed, which leads
 * to a poor quality of random sequence. If it is true we use the strategy
 * described in https://stackoverflow.com/questions/47562404/deciding-between-random-
 * device-and-seed-seq-to-generate-seeds-for-multiple-rando
 *
 */
std::mt19937 RandomEngine::GetMT19937(bool entire_seed) {
    if (entire_seed) {
        std::array<std::seed_seq::result_type, std::mt19937::state_size>
            seed_data{};
        std::generate(seed_data.begin(), seed_data.end(), std::ref(rd_));
        std::seed_seq seeds(seed_data.begin(), seed_data.end());
        std::mt19937 engine(seeds);
        return engine;
    } else {
        std::mt19937 engine(rd_());
        return engine;
    }
}
}  // namespace elip

