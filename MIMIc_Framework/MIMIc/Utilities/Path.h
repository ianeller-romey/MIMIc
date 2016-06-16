
#ifndef UTILITIES_PATH_H
#define UTILITIES_PATH_H

// std
#include <string>


namespace MIMIc { namespace Utilities {

    class Path
    {
        public:
            static std::string GetFileName(const char* const path);
            static std::string GetFileNameWithoutExtension(const char* const path);

        private:
            Path();
            Path(const Path& rhs);
            ~Path();

            Path& operator=(const Path& rhs);
    };

} }

#endif
