
#ifndef MESSAGES_MESSAGELISTENER_H
#define MESSAGES_MESSAGELISTENER_H

// std
#include <list>


namespace MIMIc { namespace Messages {

    namespace Types {

        struct CreateTextEntity;

    }

    class MessageListener
    {
        public:
            MessageListener();
            virtual ~MessageListener();
            static std::list<MessageListener*>& GetListeners();

            virtual void Process(Types::CreateTextEntity* message);

        private:
            static std::list<MessageListener*> s_listeners;
    };

} }

#endif
