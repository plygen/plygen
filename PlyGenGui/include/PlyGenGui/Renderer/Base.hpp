#ifndef _PLYGENGUI_RENDERER_BASE_HPP
#define _PLYGENGUI_RENDERER_BASE_HPP

#include <functional>

namespace plygen::gui::renderer
{

    class RendererBase
    {
    public:
        using sdDropFileHandler = std::function<void(int FilePathCount, const char** FilePathArray)>;
        using sdKeyHandler = std::function<void(bool IsCtrl, bool IsShift, bool IsAlt, int KeyCode, bool IsRelease, bool IsDown)>;

        RendererBase();
        virtual ~RendererBase() = default;

        virtual bool Initialize()
        {
            return false;
        }

        virtual bool Shutdown()
        {
            return false;
        }

        virtual bool BeginFrame()
        {
            return false;
        }

        virtual bool EndFrame()
        {
            return false;
        }

        virtual bool ShallRender()
        {
            return false;
        }

        virtual sdDropFileHandler GetDropFileHandler()
        {
            return m_DropFileHandler;
        }

        virtual void SetDropFileHandler(sdDropFileHandler DropFileHandler)
        {
            m_DropFileHandler = DropFileHandler;
        }

        virtual sdKeyHandler GetKeyHandler()
        {
            return m_KeyHandler;
        }

        virtual void SetKeyHandler(sdKeyHandler KeyHandler)
        {
            m_KeyHandler = KeyHandler;
        }

    protected:
        sdDropFileHandler m_DropFileHandler;
        sdKeyHandler m_KeyHandler;
    };
} // namespace plygen::gui::renderer

#endif // !_PLYGENGUI_RENDERER_BASE_HPP
