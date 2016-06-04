
#ifndef FRAMEWORK_ERRORLOGMANAGER_H
#define FRAMEWORK_ERRORLOGMANAGER_H

// std
#include <vector>
#include <string>


#define ERRORLOGMANAGERINSTANCE MIMIc::Framework::Managers::ErrorLogManager::INSTANCE()


namespace MIMIc { namespace Framework { namespace Managers {

    class ErrorLogManager
    {
        public:
            static ErrorLogManager& INSTANCE();

            bool Initialize();
            void Update();
            bool Shutdown();

            void CreateErrorLog(const char* const error);
            const std::vector<const std::string> GetErrorLogs() const;

        private:
            ErrorLogManager();
            ErrorLogManager(const ErrorLogManager& rhs); // undefined; singleton
            ErrorLogManager& operator=(const ErrorLogManager& rhs); // undefined; singleton

            static ErrorLogManager* s_instance;
            std::vector<const std::string> m_errors;
    };
    
} } }

#endif
