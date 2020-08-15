/*
 * Copyright © 2020 Ki-Tae Kim
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ELIP_STATS_RANDOM_ENGINE_H
#define ELIP_STATS_RANDOM_ENGINE_H

#include <random>

namespace elip {
/**
 * @brief A wrapper class of std pseudo-random number engines.
 */
class RandomEngine {
   public:
    RandomEngine() {}
    virtual ~RandomEngine() {}

    /**
     * @brief Generate and initialize std::mt19937 random engine
     *
     * @param entire_seed a boolean to determine whether to use entire seed.
     *
     * @return initialized std::mt19937 generator.
     */
    std::mt19937 GetMT19937(bool entire_seed = true);

   private:
    std::random_device rd_;
};

}  // namespace elip

#endif /* ifndef ELIP_STATS_RANDOM_ENGINE_H */
