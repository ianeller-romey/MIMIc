
#ifndef GRAPHICS_GRAPHICSMANAGER_H
#define GRAPHICS_GRAPHICSMANAGER_H

// Components
#include "Component.h"

// Messages
#include "MessageListener.h"

// Graphics
#include "RenderPass.h"

// std
#include <vector>
#include <list>


#define GRAPHICSMANAGERINSTANCE MIMIc::Graphics::Managers::GraphicsManager::INSTANCE()


namespace MIMIc { namespace Graphics { namespace Managers {

    class GraphicsManager : public Messages::MessageListener
    {
        public:
            static GraphicsManager& INSTANCE();

            bool Initialize();
            void Update();
            bool Shutdown();

            template <typename T>
            RenderPass* const CreateRenderPass(Framework::Window* window);
            RenderPass* const GetRenderPass(const int renderPassId) const;

            Components::Component* const CreateTextCharacterGraphicsComponent(const long entityId,
                                                                              Components::Component* transformationComponent, 
                                                                              const char* const style, 
                                                                              const char text, 
                                                                              const int renderPassId);

            void RemoveGraphicsComponent(Components::Component* const graphicsComponent);
            
        private:
            GraphicsManager();
            GraphicsManager(const GraphicsManager& rhs); // undefined; singleton
            GraphicsManager& operator=(const GraphicsManager& rhs); // undefined; singleton

            static GraphicsManager* s_instance;
            std::vector<RenderPass*> m_renderPasses;
            std::list<Components::Component*> m_graphicsComponents;
    };
    
} } }

#include "GraphicsManager.inl"

#endif
