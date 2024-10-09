#include "PlyGenGui/App.hpp"
#include "PlyGen/Lore.hpp"
#include "PlyGenGui/Renderer/Vulkan.hpp"
#include "PlyGenGui/Utils.hpp"
#include "imgui.h"
#include "imgui_internal.h"
#include <cstdlib>
#include <filesystem>

namespace plygen::gui
{

    App::App() : m_AppDirectoryPath(), m_Logger("App", {}), m_Renderer(nullptr), m_DockSpaceId(0), m_DockSpaceHasBeenBuilt(false), m_DockWindowSidebar(0), m_DockWindowContent(0)
    {
    }

    int App::Run(int ArgCount, char** ArgData)
    {
        m_AppDirectoryPath = Utils::sfGetOwnExecutablePath().parent_path();

        // Logger

        m_Logger.AddLoggerPassage(
            new ash::AshLoggerFunctionPassage([](ash::AshLoggerDefaultPassage* This, ash::AshLoggerTag Tag, std::string Format, fmt::format_args Args, std::string FormattedString)
                                              { std::cout << This->GetParent()->GetPrefixFunction()(Tag, Format, Args) << " " << FormattedString << std::endl; }));

        // Renderer

        m_Renderer = new renderer::RendererVulkan(800, 600, "PlyGen");

        if (m_Renderer->Initialize() == false)
        {
            m_Logger.Log("Error", "Failed to initialize Renderer.");
            return -1;
        }

        m_Logger.Log("Info", "Successfully initialized.");

        // Style and Fonts

        ApplyStyle();

        if (std::filesystem::path fontsPath = m_AppDirectoryPath / "resources" / "Cantarell-Regular.ttf"; std::filesystem::exists(fontsPath) == true)
        {
            ImGui::GetIO().FontDefault = ImGui::GetIO().Fonts->AddFontFromFileTTF(fontsPath.string().c_str(), 22.f);
        }
        else
        {
            m_Logger.Log("Warning", "Resources folder or fonts are not present, please be so kind and add them into the same directory as the executable. {}", fontsPath.string());
        }

        while (m_Renderer->ShallRender())
        {
            if (m_Renderer->BeginFrame())
            {
                this->Render();
            }
            m_Renderer->EndFrame();
        }

        m_Renderer->Shutdown();

        return 0;
    }

    void App::Render()
    {
        if (ImGui::Begin("PlyGenGuiFrame", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_MenuBar))
        {
            ImGui::SetWindowSize(ImGui::GetIO().DisplaySize);
            ImGui::SetWindowPos(ImVec2(0, 0));

            if (m_DockSpaceId == 0)
            {
                m_DockSpaceId = ImGui::GetID("dockSpacePlyGen");
            }

            if (m_DockSpaceHasBeenBuilt == false)
            {
                ImGui::DockBuilderRemoveNode(m_DockSpaceId);
                ImGui::DockBuilderAddNode(m_DockSpaceId);

                ImGui::DockBuilderSplitNode(m_DockSpaceId, ImGuiDir_Left, 0.2f, &m_DockWindowSidebar, &m_DockWindowContent);

                ImGui::DockBuilderDockWindow("SideBar", m_DockWindowSidebar);
                ImGui::DockBuilderDockWindow("Content", m_DockWindowContent);

                ImGui::DockBuilderFinish(m_DockSpaceId);

                m_DockSpaceHasBeenBuilt = true;
            }

            ImGui::DockSpace(m_DockSpaceId, ImVec2(-1, -1),
                             ImGuiDockNodeFlags_NoCloseButton | ImGuiDockNodeFlags_NoWindowMenuButton | ImGuiDockNodeFlags_NoDocking | ImGuiDockNodeFlags_NoSplit | ImGuiDockNodeFlags_HiddenTabBar |
                                 ImGuiDockNodeFlags_NoUndocking);

            if (ImGui::Begin("SideBar"))
            {
                if (ImGui::Button("Generate"))
                {

                }
            }
            ImGui::End();

            if (ImGui::Begin("Content"))
            {
                ImGui::Button("Test");
            }
            ImGui::End();
        }
        ImGui::End();
    }

} // namespace plygen::gui
