
#ifndef GRAPHICS_RENDERPASS_H
#define GRAPHICS_RENDERPASS_H

// Framework
#include "Window.h"

// Components
#include "Component.h"

// Utilities
#include "HasId.h"


namespace MIMIc { namespace Graphics {

    class RenderPass : public Utilities::HasId<RenderPass>
    {
        public:
            RenderPass();
            RenderPass(Framework::Window* window);
            RenderPass(const RenderPass& rhs);
            virtual ~RenderPass();

            RenderPass& operator=(const RenderPass& rhs);
            
            bool Initialize();
            bool Initialize(Framework::Window* window);
            virtual void Update() = 0;

            void SetWindow(Framework::Window* window);

            virtual bool RemoveGraphicsComponent(Components::Component* const graphicsComponent) = 0;

        protected:
            Framework::Window* m_window;
            void* m_glContext;
            bool m_initialized;
            int* m_referenceCounter;

            virtual bool InitializeOpenGL() = 0;

            void LogShaderError(const unsigned shader) const;
            void LogFailedToFindLocationError(const char* const shader, const char* const location) const;
    };

} }

#endif
