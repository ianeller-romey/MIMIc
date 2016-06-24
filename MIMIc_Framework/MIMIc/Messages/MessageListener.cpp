
// Messages
#include "MessageListener.h"
#include "MessageTypes.h"
#include "RequestResponseTypes.h"


namespace MIMIc { namespace Messages {

    std::list<MessageListener*> MessageListener::s_listeners;


    MessageListener::MessageListener()
    {
        s_listeners.push_back(this);
    }


    MessageListener::~MessageListener()
    {
        s_listeners.remove(this);
    }

    
    std::list<MessageListener*>& MessageListener::GetListeners()
    {
        return s_listeners;
    }


    void MessageListener::Process(Types::CreateTextEntity* message)
    {
    }


    void MessageListener::Process(Types::SetTextString* message)
    {
    }

} }
