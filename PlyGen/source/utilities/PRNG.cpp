#include "PlyGen/utilities/PRNG.hpp"
#include "pcg_random.hpp"
#include <random>

namespace plygen::utilities
{

    unsigned long long PRNG::sfGenerateRandomUInt64()
    {
        pcg64 rng = pcg64(pcg_extras::seed_seq_from<std::random_device>{});
        return rng();
    }

    unsigned long long PRNG::sfGenerateSeededUInt64(unsigned long long Seed, unsigned long long Seed2)
    {
        pcg64 rng = pcg64(Seed);
        rng.advance(Seed2);

        return rng();
    }

}
