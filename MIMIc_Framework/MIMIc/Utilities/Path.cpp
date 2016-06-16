
#include "Path.h"


namespace MIMIc { namespace Utilities {

    std::string Path::GetFileName(const char* const path)
    {
        std::string temp(path);
        auto pos = temp.rfind('\\');

        if(pos == std::string::npos || pos == 0)
            return temp;
        else
            return temp.substr(pos + 1);
    }


    std::string Path::GetFileNameWithoutExtension(const char* const path)
    {
        std::string temp(GetFileName(path));
        auto pos = temp.rfind('.');

        if(pos == std::string::npos || pos == 0)
            return temp;
        else
            return temp.substr(0, pos);
    }


    Path::Path()
    {
    }


    Path::~Path()
    {
    }

} }
