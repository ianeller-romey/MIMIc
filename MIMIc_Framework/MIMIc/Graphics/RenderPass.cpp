
// Framework
#include "ErrorLogManager.h"

// Graphics
#include "RenderPass.h"

// external
#include "SDL.h"
#include "glew.h"
#include "SDL_opengl.h"


namespace MIMIc { namespace Graphics {

    RenderPass::RenderPass() :
        m_window(0),
        m_glContext(0),
        m_initialized(false),
        m_referenceCounter(new int(0))
    {
    }


    RenderPass::RenderPass(Framework::Window* window) :
        m_window(window),
        m_glContext(0),
        m_initialized(false),
        m_referenceCounter(new int(0))
    {
    }


    RenderPass::RenderPass(const RenderPass& rhs) :
        HasId<RenderPass>(rhs),
        m_window(rhs.m_window),
        m_glContext(rhs.m_glContext),
        m_initialized(rhs.m_initialized),
        m_referenceCounter(rhs.m_referenceCounter)
    {
        if(m_initialized && m_referenceCounter)
            ++(*m_referenceCounter);
    }


    RenderPass::~RenderPass()
    {
        if(m_initialized && m_referenceCounter && --(*m_referenceCounter) == 0)
        {
            SDL_GL_DeleteContext((SDL_GLContext*)m_glContext);

            delete m_referenceCounter;
            m_referenceCounter = NULL;
        }
    }


    RenderPass& RenderPass::operator=(const RenderPass& rhs)
    {
        m_window = rhs.m_window;
        m_glContext = rhs.m_glContext;
        m_initialized = rhs.m_initialized;
        m_referenceCounter = rhs.m_referenceCounter;

        if(m_initialized && m_referenceCounter)
            ++(*m_referenceCounter);

        return *this;
    }


    bool RenderPass::Initialize()
    {
        return Initialize(NULL);
    }


    bool RenderPass::Initialize(Framework::Window* window)
    {
        if(window)
            SetWindow(window);
        
        if(!m_window)
            return false;

        if(!m_initialized && !(*m_referenceCounter))
        {
            *m_referenceCounter = 1;

            auto sdlWindow = (SDL_Window*)m_window->GetSDLWindow();
            m_glContext = SDL_GL_CreateContext(sdlWindow);
            if(!m_glContext)
            {
                // SDL_GetError(); to ErrorLog
                return false;
            }

            auto glewError = glewInit();
            if(glewError != GLEW_OK)
            {
                // ErrorLog
                return false;
            }

            if(!InitializeOpenGL())
            {
                // ErrorLog
                return false;
            }

            m_initialized = true;
        }

        return m_glContext != NULL;
    }


    void RenderPass::SetWindow(Framework::Window* window)
    {
        m_window = window;
    }


    void RenderPass::LogShaderError(const GLuint shader) const
    {
        GLint maxLength = 0;
	    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

	    //  The maxLength includes the NULL character
	    std::vector<GLchar> errorLog(maxLength);
	    glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);

        ERRORLOGMANAGERINSTANCE.CreateErrorLog(&errorLog[0]);
    }


    void RenderPass::LogFailedToFindLocationError(const char* const shader, const char* const location) const
    {
        std::string error("Failed to find");
        error += " ";
        error += location;
        error += " ";
        error += "in";
        error += " ";
        error += shader;
        error += ".";
        ERRORLOGMANAGERINSTANCE.CreateErrorLog(error.c_str());
    }

} }
