
#include "WindowManager.h"

#include "SDL.h"


namespace MIMIc { namespace Framework { namespace Managers {

    WindowManager* WindowManager::s_instance = 0;


    WindowManager& WindowManager::INSTANCE()
    {
        if(!s_instance)
            s_instance = new WindowManager();

        return *s_instance;
    }


    WindowManager::WindowManager()
    {
    }


    bool WindowManager::Initialize()
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) 
        {
            // SDL_GetError(); to ErrorLog
            return false;
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        return true;
    }


    void WindowManager::Update()
    {
        for(int i = 0, j = m_windows.size(); i < j; ++i)
        {
            SDL_PumpEvents();

            m_windows[i].Update();
        }
    }


    bool WindowManager::Shutdown()
    {
        SDL_Quit();
        return true;
    }


    Window* const WindowManager::CreateWindow(const char* title, const int x, const int y, const int width, const int height)
    {
        m_windows.push_back(Window(title, x, y, width, height));
        m_windows.back().Initialize();
        return &m_windows.back();
    }


    const Window& WindowManager::GetWindowAt(int index) const
    {
        return m_windows[index];
    }

} } }
