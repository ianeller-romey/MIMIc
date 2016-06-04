
#ifndef GRAPHICS_TESTRENDERPASS_H
#define GRAPHICS_TESTRENDERPASS_H

#include "RenderPass.h"


namespace MIMIc { namespace Graphics {

    class TestRenderPass : public RenderPass
    {
        public:
            TestRenderPass();
            TestRenderPass(Framework::Window* window);
            TestRenderPass(const TestRenderPass& rhs);
            virtual ~TestRenderPass();

            TestRenderPass& operator=(const TestRenderPass& rhs);

            virtual void Update();

            void SetWindow(Framework::Window* window);

        protected:
            unsigned m_glProgramId;
            unsigned m_glVBO,
                     m_glIBO;
            int m_glVertexAttribute_Position;

            virtual bool InitializeOpenGL();
    };

} }

#endif
