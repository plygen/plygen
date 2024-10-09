#ifndef _PLYGENGUI_APP_HPP
#define _PLYGENGUI_APP_HPP

#include "AshLogger/AshLogger.h"
#include "PlyGenGui/Renderer/Base.hpp"
#include "imgui.h"
#include <filesystem>
namespace plygen::gui
{

    class App
    {
    public:
        App();

        int Run(int ArgCount, char** ArgData);

        void ApplyStyle();
        void Render();
    private:
        std::filesystem::path m_AppDirectoryPath;
        ash::AshLogger m_Logger;
        renderer::RendererBase* m_Renderer;

        ImGuiID m_DockSpaceId;
        bool m_DockSpaceHasBeenBuilt;

        ImGuiID m_DockWindowSidebar;
        ImGuiID m_DockWindowContent;
    };

} // namespace plygen::gui

#endif // !_PLYGENGUI_APP_HPP
