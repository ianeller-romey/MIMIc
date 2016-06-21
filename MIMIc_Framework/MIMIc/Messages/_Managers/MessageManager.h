
#ifndef MESSAGES_MESSAGEMANAGER_H
#define MESSAGES_MESSAGEMANAGER_H

// Messages
#include "MessageTypes.h"

// std
#include <list>


#define MAILMAN MIMIc::Messages::Managers::MessageManager::INSTANCE()


using namespace MIMIc::Messages::Types;


namespace MIMIc { namespace Messages { namespace Managers {

    class MessageManager
    {
        public:
            static MessageManager& INSTANCE();

            bool Initialize();
            void Update();
            bool Shutdown();

            void PostMessage(Message* message);
            void PostHighPriorityMessage(Message* message);
            void ReturnServiceRequested(Message* message);

        private:
            MessageManager();
            MessageManager(const MessageManager& rhs); // undefined; singleton
            MessageManager& operator=(const MessageManager& rhs); // undefined; singleton

            static MessageManager* s_instance;

            std::list<Message*> m_messages;

            void MessageDispatch(Message* message) const;
    };

} } }

#endif
