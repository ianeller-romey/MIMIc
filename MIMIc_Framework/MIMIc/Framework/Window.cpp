
#include "Window.h"

#include "SDL.h"
#include "glew.h"
#include "SDL_opengl.h"


namespace MIMIc { namespace Framework {

    Window::Window(const char* title, const int x, const int y, const int width, const int height) :
        m_sdlWindow(0),
        m_initialized(false),
        m_referenceCounter(new int(0)),
        m_title(title),
        m_x(x),
        m_y(y),
        m_width(width),
        m_height(height)
    {
    }


    Window::Window(const Window& rhs) :
        HasId<Window>(rhs),
        m_sdlWindow(rhs.m_sdlWindow),
        m_initialized(rhs.m_initialized),
        m_referenceCounter(rhs.m_referenceCounter),
        m_title(rhs.m_title),
        m_x(rhs.m_x),
        m_y(rhs.m_y),
        m_width(rhs.m_width),
        m_height(rhs.m_height)
    {
        if(m_initialized && m_referenceCounter)
            ++(*m_referenceCounter);
    }


    Window::~Window()
    {
        if(m_initialized && m_referenceCounter && --(*m_referenceCounter) == 0)
        {
            SDL_DestroyWindow((SDL_Window*)m_sdlWindow);
            m_sdlWindow = NULL;

            delete m_referenceCounter;
            m_referenceCounter = NULL;
        }
    }


    Window& Window::operator=(const Window& rhs)
    {
        m_sdlWindow = rhs.m_sdlWindow;
        m_initialized = rhs.m_initialized;
        m_referenceCounter = rhs.m_referenceCounter;
        m_title = rhs.m_title;
        m_x = rhs.m_x;
        m_y = rhs.m_y;
        m_width = rhs.m_width;
        m_height = rhs.m_height;

        if(m_initialized && m_referenceCounter)
            ++(*m_referenceCounter);

        return *this;
    }


    bool Window::Initialize()
    {
        if(!m_initialized && !(*m_referenceCounter))
        {
            *m_referenceCounter = 1;

            m_sdlWindow = SDL_CreateWindow(m_title.c_str(), m_x, m_y, m_width, m_height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
            if(!m_sdlWindow)
            {
                // SDL_GetError(); to ErrorLog
                return false;
            }

            m_initialized = true;
        }

        return m_sdlWindow != NULL;
    }


    void Window::Update()
    {
    }


    void* const Window::GetSDLWindow() const
    {
        return m_sdlWindow;
    }

} }
