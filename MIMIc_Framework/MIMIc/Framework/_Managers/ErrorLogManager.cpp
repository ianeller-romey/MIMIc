
#include "ErrorLogManager.h"


namespace MIMIc { namespace Framework { namespace Managers {

    ErrorLogManager* ErrorLogManager::s_instance = NULL;


    ErrorLogManager& ErrorLogManager::INSTANCE()
    {
        if(!s_instance)
            s_instance = new ErrorLogManager();

        return *s_instance;
    }


    ErrorLogManager::ErrorLogManager()
    {
    }


    bool ErrorLogManager::Initialize()
    {
        return true;
    }


    void ErrorLogManager::Update()
    {
    }


    bool ErrorLogManager::Shutdown()
    {
        return true;
    }


    void ErrorLogManager::CreateErrorLog(const char* const error)
    {
        m_errors.push_back(std::string(error));
    }


    const std::vector<const std::string> ErrorLogManager::GetErrorLogs() const
    {
        return m_errors;
    }

} } }
