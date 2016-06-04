
#ifndef FRAMEWORK_WINDOW_H
#define FRAMEWORK_WINDOW_H

#include "HasId.h"

#include <string>


namespace MIMIc { namespace Framework {

    class Window : public Utilities::HasId<Window>
    {
        public:
            Window(const char* title, const int x, const int y, const int width, const int height);
            Window(const Window& rhs);
            ~Window();

            Window& operator=(const Window& rhs);

            bool Initialize();
            void Update();

            void* const GetSDLWindow() const;

        private:
            void* m_sdlWindow;
            bool m_initialized;
            int* m_referenceCounter;
            std::string m_title;
            int m_x, 
                m_y, 
                m_width, 
                m_height;
    };

} }

#endif
