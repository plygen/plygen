#ifndef _PLYGENGUI_RENDERER_VULKAN_HPP
#define _PLYGENGUI_RENDERER_VULKAN_HPP

#include "Base.hpp"
#include <iostream>
#include <vector>

#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_vulkan.h>
#include <imgui.h>

namespace plygen::gui::renderer
{

    class RendererVulkan : public RendererBase
    {
    public:
        RendererVulkan(unsigned Width, unsigned Height, std::string Title);
        ~RendererVulkan();

        inline unsigned GetWidth()
        {
            return m_Width;
        }

        inline unsigned GetHeight()
        {
            return m_Height;
        }

        bool Initialize();
        bool Shutdown();
        bool BeginFrame();
        bool EndFrame();
        bool ShallRender();

        inline bool IsRunning()
        {
            return m_Running;
        }

    protected:
        VkPhysicalDevice SetupVulkan_SelectPhysicalDevice();
        void SetupVulkan(std::vector<const char*> instance_extensions);
        void SetupVulkanWindow(ImGui_ImplVulkanH_Window* wd, VkSurfaceKHR surface, int width, int height);
        void CleanupVulkan();
        void CleanupVulkanWindow();
        void FrameRender(ImGui_ImplVulkanH_Window* wd, ImDrawData* draw_data);
        void FramePresent(ImGui_ImplVulkanH_Window* wd);

    protected:
        unsigned m_Width;
        unsigned m_Height;
        std::string m_Title;
        bool m_Running;
        GLFWwindow* m_GlfwWindow;
        bool m_SwapChainRebuild;

        VkAllocationCallbacks* m_VkAllocator;
        VkInstance m_VkInstance;
        VkPhysicalDevice m_VkPhysicalDevice;
        VkDevice m_VkDevice;
        uint32_t m_VkQueueFamily;
        VkQueue m_VkQueue;
        VkDebugReportCallbackEXT m_VkDebugReport;
        VkPipelineCache m_VkPipelineCache;
        VkDescriptorPool m_VkDescriptorPool;

        ImGui_ImplVulkanH_Window m_WindowData;

        GLFWdropfun m_OriginalDropFunction;
        GLFWkeyfun m_OriginalKeyFunction;
    };

} // namespace plygen::gui::renderer

#endif // !_PLYGENGUI_RENDERER_VULKAN_HPP
