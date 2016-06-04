
#ifndef FRAMEWORK_WINDOWMANAGER_H
#define FRAMEWORK_WINDOWMANAGER_H

#include "Window.h"

#include <vector>


#define WINDOWMANAGERINSTANCE MIMIc::Framework::Managers::WindowManager::INSTANCE()


namespace MIMIc { namespace Framework { namespace Managers {

    class WindowManager
    {
        public:
            static WindowManager& INSTANCE();

            bool Initialize();
            void Update();
            bool Shutdown();

            Window* const CreateWindow(const char* title, const int x, const int y, const int width, const int height);
            const Window& GetWindowAt(int index) const;

        private:
            WindowManager();
            WindowManager(const WindowManager& rhs); // undefined; singleton
            WindowManager& operator=(const WindowManager& rhs); // undefined; singleton

            static WindowManager* s_instance;
            std::vector<Window> m_windows;
    };
    
} } }

#endif
