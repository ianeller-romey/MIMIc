
namespace MIMIc { namespace Graphics { namespace Managers {
    
    template <typename T>
    RenderPass* const GraphicsManager::CreateRenderPass(Framework::Window* window)
    {
        m_renderPasses.push_back(new T(window));
        m_renderPasses.back()->Initialize();
        return m_renderPasses.back();
    }

} } }
