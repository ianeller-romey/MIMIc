
#ifndef MESSAGES_MESSAGEMANAGER_H
#define MESSAGES_MESSAGEMANAGER_H

// Messages
#include "MessageTypes.h"
#include "NoticeTypes.h"
#include "RequestResponseTypes.h"

// std
#include <queue>


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
            void PostNotice(Notice* notice);
            void ReturnServiceRequested(Request* request);

        private:
            MessageManager();
            MessageManager(const MessageManager& rhs); // undefined; singleton
            MessageManager& operator=(const MessageManager& rhs); // undefined; singleton

            static MessageManager* s_instance;

            std::queue<Message*> m_messages;

            void MessageDispatch(Message* message) const;
            void NoticeDispatch(Notice* notice) const;
            void RequestDispatch(Request* request) const;
            void ResponseDispatch(Response* response) const;
    };

} } }

#endif
