#include "PlyGen/Lore.hpp"
#include "PlyGen/utilities/PRNG.hpp"
#include "pcg_random.hpp"
#include <random>
#include <utility>

namespace plygen
{

    LoreBase LoreBase::sfGenerate()
    {
        LoreBase lore = {};

        lore.m_Seed = utilities::PRNG::sfGenerateRandomUInt64();
        lore.m_Responsibility = LoreResponsibilityType::RESIDENTIAL;

        return std::move(lore);
    }

} // namespace plygen
