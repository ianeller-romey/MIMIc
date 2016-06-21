
// Messages
#include "MessageManager.h"
#include "MessageListener.h"


namespace MIMIc { namespace Messages { namespace Managers {

    MessageManager* MessageManager::s_instance = NULL;


    MessageManager& MessageManager::INSTANCE()
    {
        if(!s_instance)
            s_instance = new MessageManager();

        return *s_instance;
    }


    MessageManager::MessageManager()
    {
    }


    bool MessageManager::Initialize()
    {
    }


    void MessageManager::Update()
    {
        while(m_messages.size())
        {
            auto message = m_messages.front();
            
            MessageDispatch(message);

            delete message;
            m_messages.pop_front();
        }
    }


    bool MessageManager::Shutdown()
    {
        while(m_messages.size())
        {
            auto message = m_messages.front();
            delete message;
            m_messages.pop_front();
        }
    }


    void MessageManager::PostMessage(Message* message)
    {
        m_messages.push_back(message);
    }


    void MessageManager::PostHighPriorityMessage(Message* message)
    {
        MessageDispatch(message);
    }


    void MessageManager::ReturnServiceRequested(Message* message)
    {
        // TODO
    }


    void MessageManager::MessageDispatch(Message* message) const
    {
        for(auto listener : MessageListener::GetListeners())
        {
            message->Dispatch(listener);
        }
    }

} } }
