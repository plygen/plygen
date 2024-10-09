#ifndef _PLYGENGUI_UTILS_HPP
#define _PLYGENGUI_UTILS_HPP

#include <filesystem>

namespace plygen::gui
{

    class Utils
    {
    public:
        static std::filesystem::path sfGetOwnExecutablePath();
    };

} // namespace plygen::gui

#endif // !_PLYGENGUI_UTILS_HPP
