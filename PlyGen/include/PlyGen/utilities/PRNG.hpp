#ifndef _PLYGEN_UTILITIES_PRNG_HPP
#define _PLYGEN_UTILITIES_PRNG_HPP

namespace plygen::utilities
{

    class PRNG
    {
    public:
        static unsigned long long sfGenerateRandomUInt64();
        static unsigned long long sfGenerateSeededUInt64(unsigned long long Seed, unsigned long long Seed2);
    };

}

#endif // !_PLYGEN_UTILITIES_PRNG_HPP
