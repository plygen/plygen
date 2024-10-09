#ifndef _PLYGEN_LORE_HPP
#define _PLYGEN_LORE_HPP

namespace plygen
{

    enum class LoreResponsibilityType
    {
        RESIDENTIAL = 0,
        // COMMERCIAL,
        // INDUSTIRAL
    };

    struct LoreBase
    {
        unsigned long long m_Seed;
        LoreResponsibilityType m_Responsibility;

        static LoreBase sfGenerate();
    };

} // namespace plygen

#endif // !_PLYGEN_LORE_HPP
