
// Components
#include "TextCharacterGraphicsComponent.h"

// Graphics
#include "GraphicsManager.h"
#include "TestRenderPass.h"
#include "TextRenderPass.h"

// external
#include "SDL.h"


namespace MIMIc { namespace Graphics { namespace Managers {

    GraphicsManager* GraphicsManager::s_instance = 0;


    GraphicsManager& GraphicsManager::INSTANCE()
    {
        if(!s_instance)
            s_instance = new GraphicsManager();

        return *s_instance;
    }


    GraphicsManager::GraphicsManager()
    {
    }


    bool GraphicsManager::Initialize()
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        return true;
    }


    void GraphicsManager::Update()
    {
        for(int i = 0, j = m_renderPasses.size(); i < j; ++i)
        {
            m_renderPasses[i]->Update();
        }
    }


    bool GraphicsManager::Shutdown()
    {
        for(int i = 0, j = m_renderPasses.size(); i < j; ++i)
        {
            delete m_renderPasses[i];
        }

        return true;
    }


    RenderPass* const GraphicsManager::GetRenderPass(const int renderPassId) const
    {
        for(auto begin = m_renderPasses.begin(), end = m_renderPasses.end(); begin != end; ++begin)
        {
            auto renderPass = *begin;
            if(renderPass->GetId() == renderPassId)
            {
                return renderPass;
            }
        }

        return 0;
    }


    Components::Component* const GraphicsManager::CreateTextCharacterGraphicsComponent(const long entityId, 
                                                                                       Components::Component* transformationComponent, 
                                                                                       const char* const style, 
                                                                                       const char text, 
                                                                                       const int renderPassId)
    {
        auto graphicsComponent = new Components::TextCharacterGraphicsComponent(entityId, transformationComponent, style, text);

        auto renderPass = (TextRenderPass*)GetRenderPass(renderPassId);
        renderPass->AddTextCharacterGraphicsComponent(graphicsComponent);

        m_graphicsComponents.push_back(graphicsComponent);
        return graphicsComponent;
    }


    void GraphicsManager::RemoveGraphicsComponent(Components::Component* const graphicsComponent)
    {
        for(auto begin = m_graphicsComponents.begin(), end = m_graphicsComponents.end(); begin != end; ++begin)
        {
            auto component = *begin;
            if(component == graphicsComponent)
            {
                for(auto begin2 = m_renderPasses.begin(), end2 = m_renderPasses.end(); begin2 != end2 && !(*begin2)->RemoveGraphicsComponent(component); ++begin2) ;

                m_graphicsComponents.erase(begin);

                delete component;
                break;
            }
        }
    }

} } }
