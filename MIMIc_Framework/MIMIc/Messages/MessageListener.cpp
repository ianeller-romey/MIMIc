
// Messages
#include "MessageListener.h"


namespace MIMIc { namespace Messages {

    MessageListener::MessageListener()
    {
        s_listeners.push_back(*this);
    }


    MessageListener::~MessageListener()
    {
        s_listeners.remove(*this);
    }

    
    std::list<MessageListener&>& MessageListener::GetListeners()
    {
        return s_listeners;
    }


    void MessageListener::Process(Types::CreateTextEntity* message)
    {
    }

} }
