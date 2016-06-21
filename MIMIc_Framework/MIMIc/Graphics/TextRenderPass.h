
#ifndef GRAPHICS_TEXTRENDERPASS_H
#define GRAPHICS_TEXTRENDERPASS_H

// Components
#include "TextCharacterGraphicsComponent.h"

// Graphics
#include "RenderPass.h"
#include "Shader.h"

// std
#include <list>


#define SHADERDATA_CHARACTERDATA unsigned
#define SHADERDATA_SIZEOF_CHARACTERDATA sizeof(SHADERDATA_CHARACTERDATA)
#define SHADERDATA_SIZEOF_VEC4 (SHADERDATA_SIZEOF_CHARACTERDATA * 4)
#define SHADERDATA_TEXTBLOCK_TEXTARRAY_SIZE 1000


namespace MIMIc { namespace Graphics {

    class TextRenderPass : public RenderPass
    {
        public:
            TextRenderPass();
            TextRenderPass(Framework::Window* window);
            TextRenderPass(const TextRenderPass& rhs);
            virtual ~TextRenderPass() override;

            TextRenderPass& operator=(const TextRenderPass& rhs);

            virtual void Update() override;

            void SetEmulatedConsoleWidth(const unsigned width);
            void SetEmulatedConsoleHeight(const unsigned height);

            void AddTextCharacterGraphicsComponent(Components::TextCharacterGraphicsComponent* const graphicsComponent);
            virtual bool RemoveGraphicsComponent(Components::Component* const graphicsComponent) override;

        private:
            static const char* const s_vertexShaderFileName;
            static const char* const s_fragmentShaderFileName;
            static const unsigned s_emulatedConsoleCharacterWidth,
                                  s_emulatedConsoleCharacterHeight;
            static const unsigned s_defaultEmulatedConsoleWidth,
                                  s_defaultEmulatedConsoleHeight;

            Shader m_vertexShader,
                   m_fragmentShader;
            unsigned m_glProgramId;
            unsigned m_glVAO,
                     m_glVBO;
            int m_glVertexAttribute_Position;
            int m_glVertexAttribute_TexCoord;
            unsigned m_glVertexUniform_Resolution;
            unsigned m_glFragmentUBO;
            unsigned m_glFragmentUBO_TextBlock;
            unsigned m_glFragmentUniform_TextColor;
            struct ShaderData_TextBlock
            {
                char m_textDimensions[SHADERDATA_SIZEOF_VEC4];
                char m_textArray[SHADERDATA_SIZEOF_VEC4 * SHADERDATA_TEXTBLOCK_TEXTARRAY_SIZE];
            } m_shaderData;
            unsigned m_emulatedConsoleWidth,
                     m_emulatedConsoleHeight;

            std::list<Components::TextCharacterGraphicsComponent*> m_TextCharacterGraphicsComponents;

            virtual bool InitializeOpenGL() override;

            void UpdateTextCharacterGraphicsComponent(Components::TextCharacterGraphicsComponent* graphicsComponent) const;
            void GenerateTextTextureData(Components::TextCharacterGraphicsComponent* component, ShaderData_TextBlock* shaderData, float** vertexData) const;
    };

} }

#endif
