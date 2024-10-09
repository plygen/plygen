#include "PlyGenGui/Renderer/Base.hpp"

namespace plygen::gui::renderer
{

    RendererBase::RendererBase() : m_DropFileHandler([](...) {}), m_KeyHandler([](...) {})
    {
    }

} // namespace plygen::gui::renderer
