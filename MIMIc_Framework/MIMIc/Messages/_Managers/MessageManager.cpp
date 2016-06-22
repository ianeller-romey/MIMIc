
// Messages
#include "MessageManager.h"
#include "MessageListener.h"
#include "MessageMemoryManager.h"


namespace MIMIc { namespace Messages { namespace Managers {

    MessageManager* MessageManager::s_instance = 0;


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
        return true;
    }


    void MessageManager::Update()
    {
        while(m_messages.size())
        {
            auto message = m_messages.front();            
            MessageDispatch(message);
            m_messages.pop();
        }
        MESSAGEMEMORYMANAGERINSTANCE.FreeAll();
    }


    bool MessageManager::Shutdown()
    {
        while(m_messages.size())
        {
            m_messages.pop();
        }
        MESSAGEMEMORYMANAGERINSTANCE.FreeAll();
        return true;
    }


    void MessageManager::PostMessage(Message* message)
    {
        m_messages.push(message);
    }


    void MessageManager::PostNotice(Notice* notice)
    {
        NoticeDispatch(notice);
    }


    void MessageManager::ReturnServiceRequested(Request* request)
    {
        RequestDispatch(request);
    }


    void MessageManager::MessageDispatch(Message* message) const
    {
        for(auto listener : MessageListener::GetListeners())
        {
            message->Dispatch(listener);
        }
    }


    void MessageManager::NoticeDispatch(Notice* notice) const
    {
        for(auto listener : MessageListener::GetListeners())
        {
            notice->Dispatch(listener);
        }
    }


    void MessageManager::RequestDispatch(Request* request) const
    {
        for(auto listener : MessageListener::GetListeners())
        {
            auto response = request->Dispatch(listener);
            if(response)
                ResponseDispatch(response);
        }
    }


    void MessageManager::ResponseDispatch(Response* response) const
    {
        for(auto listener : MessageListener::GetListeners())
        {
            response->Dispatch(listener);
        }
    }

} } }
