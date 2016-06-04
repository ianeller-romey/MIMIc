
// Components
#include "TextTextureGraphicsComponent.h"
#include "TransformationComponent.h"

// Graphics
#include "TextRenderPass.h"
#include "ShaderDeserializer.h"

// external
#include "SDL.h"
#include "glew.h"
#include "SDL_opengl.h"

// std
#include <vector> // error logging
#include <string> // error logging


namespace MIMIc { namespace Graphics {

    const char* const TextRenderPass::s_vertexShaderFileName = "..\\..\\data\\shaders\\vertex\\textrenderpass.glvs";
    const char* const TextRenderPass::s_fragmentShaderFileName = "..\\..\\data\\shaders\\fragment\\textrenderpass.glfs";
    const unsigned TextRenderPass::s_emulatedConsoleCharacterWidth = 18;
    const unsigned TextRenderPass::s_emulatedConsoleCharacterHeight = 32;
    const unsigned TextRenderPass::s_defaultEmulatedConsoleWidth = 80;
    const unsigned TextRenderPass::s_defaultEmulatedConsoleHeight = 50;


    TextRenderPass::TextRenderPass() :
        RenderPass(),
        m_glProgramId(-1),
        m_glVAO(-1),
        m_glVBO(-1),
        m_glVertexAttribute_Position(-1),
        m_glVertexAttribute_TexCoord(-1),
        m_glVertexUniform_Resolution(-1),
        m_glFragmentUBO(-1),
        m_glFragmentUBO_TextBlock(-1),
        m_glFragmentUniform_TextColor(-1),
        m_emulatedConsoleWidth(s_defaultEmulatedConsoleWidth),
        m_emulatedConsoleHeight(s_defaultEmulatedConsoleHeight)
    {
    }


    TextRenderPass::TextRenderPass(Framework::Window* window) :
        RenderPass(window),
        m_glProgramId(-1),
        m_glVAO(-1),
        m_glVBO(-1),
        m_glVertexAttribute_Position(-1),
        m_glVertexAttribute_TexCoord(-1),
        m_glVertexUniform_Resolution(-1),
        m_glFragmentUBO(-1),
        m_glFragmentUBO_TextBlock(-1),
        m_glFragmentUniform_TextColor(-1),
        m_emulatedConsoleWidth(s_defaultEmulatedConsoleWidth),
        m_emulatedConsoleHeight(s_defaultEmulatedConsoleHeight)
    {
    }


    TextRenderPass::TextRenderPass(const TextRenderPass& rhs) :
        RenderPass(rhs),
        m_glProgramId(rhs.m_glProgramId),
        m_glVAO(rhs.m_glVAO),
        m_glVBO(rhs.m_glVBO),
        m_glVertexAttribute_Position(rhs.m_glVertexAttribute_Position),
        m_glVertexAttribute_TexCoord(rhs.m_glVertexAttribute_TexCoord),
        m_glVertexUniform_Resolution(rhs.m_glVertexUniform_Resolution),
        m_glFragmentUBO(rhs.m_glFragmentUBO),
        m_glFragmentUBO_TextBlock(rhs.m_glFragmentUBO_TextBlock),
        m_glFragmentUniform_TextColor(rhs.m_glFragmentUniform_TextColor),
        m_emulatedConsoleWidth(rhs.m_emulatedConsoleWidth),
        m_emulatedConsoleHeight(rhs.m_emulatedConsoleHeight)
    {
        memcpy(m_shaderData.m_textDimensions, rhs.m_shaderData.m_textDimensions, sizeof(char) * SHADERDATA_SIZEOF_VEC4);
        memcpy(m_shaderData.m_textArray, rhs.m_shaderData.m_textArray, sizeof(char) * SHADERDATA_SIZEOF_VEC4 * SHADERDATA_TEXTBLOCK_TEXTARRAY_SIZE);
    }


    TextRenderPass::~TextRenderPass()
    {
    }


    TextRenderPass& TextRenderPass::operator=(const TextRenderPass& rhs)
    {
        m_window = rhs.m_window;
        m_glContext = rhs.m_glContext;
        m_glProgramId = rhs.m_glProgramId;
        m_glVAO = rhs.m_glVAO;
        m_glVBO = rhs.m_glVBO;
        m_glVertexAttribute_Position = rhs.m_glVertexAttribute_Position;
        m_glVertexAttribute_TexCoord = rhs.m_glVertexAttribute_TexCoord;
        m_glVertexUniform_Resolution = rhs.m_glVertexUniform_Resolution;
        m_glFragmentUBO = rhs.m_glFragmentUBO;
        m_glFragmentUBO_TextBlock = rhs.m_glFragmentUBO_TextBlock;
        m_glFragmentUniform_TextColor = rhs.m_glFragmentUniform_TextColor;
        memcpy(m_shaderData.m_textDimensions, rhs.m_shaderData.m_textDimensions, sizeof(char) * SHADERDATA_SIZEOF_VEC4);
        memcpy(m_shaderData.m_textArray, rhs.m_shaderData.m_textArray, sizeof(char) * SHADERDATA_SIZEOF_VEC4 * SHADERDATA_TEXTBLOCK_TEXTARRAY_SIZE);
        m_emulatedConsoleWidth = rhs.m_emulatedConsoleWidth;
        m_emulatedConsoleHeight = rhs.m_emulatedConsoleHeight;
        m_initialized = rhs.m_initialized;
        m_referenceCounter = rhs.m_referenceCounter;

        if(m_initialized && m_referenceCounter)
            ++(*m_referenceCounter);

        return *this;
    }


    void TextRenderPass::Update()
    {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);

        // Clear color buffer
        glClear(GL_COLOR_BUFFER_BIT);
    
        // Bind program
        glUseProgram(m_glProgramId);

        // Bind the VAO
        glBindVertexArray(m_glVAO);

        // Bind the VBO
        /*GLfloat vertexData[] =
        {
             // x   // y  // u  // v
            -0.5f, -0.5f, 0.0f, 0.0f,
             0.5f, -0.5f, 1.0f, 0.0f,
             0.5f,  0.5f, 1.0f, 1.0f,
             0.5f,  0.5f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.0f, 0.0f,
        };    */    
        GLfloat vertexData[] =
        {
             // x   // y  // u  // v
             0.0f,  0.0f, 0.0f, 0.0f,
             19.0f,  0.0f, 1.0f, 0.0f,
             19.0f,  19.0f, 1.0f, 1.0f,
             19.0f,  19.0f, 1.0f, 1.0f,
             0.0f,  19.0f, 0.0f, 1.0f,
             0.0f,  0.0f, 0.0f, 0.0f,
        };
        glBindBuffer(GL_ARRAY_BUFFER, m_glVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_DYNAMIC_DRAW);

        // u_resolution
        glUniform2f(m_glVertexUniform_Resolution, m_emulatedConsoleWidth * s_emulatedConsoleCharacterWidth, m_emulatedConsoleHeight * s_emulatedConsoleCharacterHeight);

        // u_textColor
        glUniform3f(m_glFragmentUniform_TextColor, 1.0, 1.0, 1.0);

        // Bind the UBO
        glBindBuffer(GL_UNIFORM_BUFFER, m_glFragmentUBO);

        for(auto begin = m_textTextureGraphicsComponents.begin(), end = m_textTextureGraphicsComponents.end(); begin != end; ++begin)
        {
            GenerateTextTextureData(*begin, &m_shaderData, (float**)&vertexData);

            glBufferData(GL_UNIFORM_BUFFER, sizeof(m_shaderData), &m_shaderData, GL_DYNAMIC_DRAW);

            // Set index data and render
            glDrawArrays(GL_TRIANGLES, 0, 6);
        }

        // Unbind program
        glBindBuffer(GL_UNIFORM_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glUseProgram(0);

        glDisable( GL_BLEND );

        SDL_GL_SwapWindow((SDL_Window*)m_window->GetSDLWindow());
    }


    void TextRenderPass::SetEmulatedConsoleWidth(const unsigned width)
    {
        m_emulatedConsoleWidth = width;
    }


    void TextRenderPass::SetEmulatedConsoleHeight(const unsigned height)
    {
        m_emulatedConsoleHeight = height;
    }


    void TextRenderPass::AddTextTextureGraphicsComponent(Components::TextTextureGraphicsComponent* const graphicsComponent)
    {
        m_textTextureGraphicsComponents.push_back(graphicsComponent);
    }


    bool TextRenderPass::RemoveGraphicsComponent(Components::Component* const graphicsComponent)
    {
        auto textTextureGraphicsComponent = dynamic_cast<Components::TextTextureGraphicsComponent*>(graphicsComponent);
        if(textTextureGraphicsComponent != 0)
        {
            for(auto begin = m_textTextureGraphicsComponents.begin(), end= m_textTextureGraphicsComponents.end(); begin != end; ++begin)
            {
                auto component = *begin;
                if(component == textTextureGraphicsComponent)
                {
                    m_textTextureGraphicsComponents.erase(begin);
                    return true;
                }
            }
        }
        
        return false;
    }


    bool TextRenderPass::InitializeOpenGL()
    {
        m_vertexShader = ShaderDeserializer::INSTANCE().Get(s_vertexShaderFileName);
        m_fragmentShader = ShaderDeserializer::INSTANCE().Get(s_fragmentShaderFileName);

        m_glProgramId = glCreateProgram();

        ////////
        // Create vertex shader
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

        // Set vertex source
        auto vertexShaderSource = m_vertexShader.GetContent();
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

        // Compile vertex source
        glCompileShader(vertexShader);

        // Check vertex shader for errors
        GLint vShaderCompiled = GL_FALSE;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vShaderCompiled);
        if(vShaderCompiled != GL_TRUE)
        {
            LogShaderError(vertexShader);
            return false;
        }

        // Attach vertex shader to program
        glAttachShader(m_glProgramId, vertexShader);
                
        ////////
        // Create fragment shader
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            
        // Set fragment source
        auto fragmentShaderSource = m_fragmentShader.GetContent();
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

        // Compile fragment source
        glCompileShader(fragmentShader);

        // Check fragment shader for errors
        GLint fShaderCompiled = GL_FALSE;
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fShaderCompiled);
        if(fShaderCompiled != GL_TRUE)
        {
            LogShaderError(fragmentShader);
            return false;
        }

        // Attach fragment shader to program
        glAttachShader(m_glProgramId, fragmentShader);
        
        ////////
        // Link program
        glLinkProgram(m_glProgramId);

        // Check for errors
        GLint programSuccess = GL_TRUE;
        glGetProgramiv(m_glProgramId, GL_LINK_STATUS, &programSuccess);
        if(programSuccess != GL_TRUE)
        {
            LogShaderError(fragmentShader);
            return false;
        }
        
        ////////
        // Get positions
        m_glVertexAttribute_Position = glGetAttribLocation(m_glProgramId, "in_position");
        if(m_glVertexAttribute_Position == -1)
        {
            LogFailedToFindLocationError(s_vertexShaderFileName, "in_position");
            return false;
        }
        m_glVertexAttribute_TexCoord = glGetAttribLocation(m_glProgramId, "in_texCoord");
        if(m_glVertexAttribute_TexCoord == -1)
        {
            LogFailedToFindLocationError(s_vertexShaderFileName, "in_texCoord");
            return false;
        }
        m_glVertexUniform_Resolution = glGetUniformLocation(m_glProgramId, "u_resolution");
        if(m_glVertexUniform_Resolution == -1)
        {
            LogFailedToFindLocationError(s_vertexShaderFileName, "u_resolution");
            return false;
        }
        m_glFragmentUBO_TextBlock = glGetUniformBlockIndex(m_glProgramId, "u_textBlock");
        if(m_glFragmentUBO_TextBlock == -1)
        {
            LogFailedToFindLocationError(s_fragmentShaderFileName, "u_textBlock");
            return false;
        }
        m_glFragmentUniform_TextColor = glGetUniformLocation(m_glProgramId, "u_textColor");
        if(m_glFragmentUniform_TextColor == -1)
        {
            LogFailedToFindLocationError(s_fragmentShaderFileName, "u_textColor");
            return false;
        }

        ////////
        // Gen VAO
        glGenVertexArrays(1, &m_glVAO);
        glBindVertexArray(m_glVAO);

        // Gen VBO
        glGenBuffers(1, &m_glVBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_glVBO);
        glBufferData(GL_ARRAY_BUFFER, 0, 0, GL_DYNAMIC_DRAW);

        // Enable vertex position
        glEnableVertexAttribArray(m_glVertexAttribute_Position);
        glVertexAttribPointer(m_glVertexAttribute_Position, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), NULL);

        // Enable vertex texcoord
        glEnableVertexAttribArray(m_glVertexAttribute_TexCoord);
        glVertexAttribPointer(m_glVertexAttribute_TexCoord, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (const GLvoid*)(2 * sizeof(GLfloat)));
        
        // Unbind VBO
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // Gen UBO
        glGenBuffers(1, &m_glFragmentUBO);
        glBindBuffer(GL_UNIFORM_BUFFER, m_glFragmentUBO);
        glBufferData(GL_UNIFORM_BUFFER, sizeof(m_shaderData), 0, GL_DYNAMIC_DRAW);
        glBindBufferBase(GL_UNIFORM_BUFFER, m_glFragmentUBO_TextBlock, m_glFragmentUBO);
        
        // Unbind UBO
        glBindBuffer(GL_UNIFORM_BUFFER, 0);

        // Unbind VAO
        glBindVertexArray(0);

        ////////
        // Initialize clear color
        glClearColor(1.f, 0.f, 0.f, 1.f);
    
        return true;
    }

    void TextRenderPass::GenerateTextTextureData(Components::TextTextureGraphicsComponent* component, ShaderData_TextBlock* shaderData, float** vertexData) const
    {
        auto textTexture = component->GetTextTexture();
        auto textureWidth = textTexture->GetTextureWidth();
        auto textureHeight = textTexture->GetTextureHeight();

        // set texture width and texture height
        memcpy(shaderData->m_textDimensions, &textureWidth, sizeof(TEXTTEXTURECHAR));
        memcpy(shaderData->m_textDimensions + sizeof(TEXTTEXTURECHAR), &textureHeight, sizeof(TEXTTEXTURECHAR));

        // set texture
        memcpy(shaderData->m_textArray, textTexture->GetTexture(), sizeof(TEXTTEXTURECHAR) * textTexture->GetTextureLength());

        auto transformationComponent = (Components::TransformationComponent*)(component->GetTransformationComponent());
    }

} }
