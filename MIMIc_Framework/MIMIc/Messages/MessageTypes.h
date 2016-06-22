
#ifndef MESSAGES_MESSAGETYPES_H
#define MESSAGES_MESSAGETYPES_H

// Messages
#include "MessageTypeHelpers.h"
#include "MessageListener.h"
#include "MessageMemoryManager.h"

// std
#include <string>


#define DECLARE_MESSAGE_TYPE(name) struct name : public Message {


namespace MIMIc { namespace Messages { namespace Types {

    struct Message
    {
        virtual ~Message() {};
        virtual void Dispatch(MessageListener* listener) = 0;

        void* operator new(size_t size)
        {
            return MESSAGEMEMORYMANAGERINSTANCE.Allocate(size);
        }

        void operator delete (void * mem)
        {
            // We should never individually delete these;
            // the MessageManager bulk frees all messages when it's done processing
            throw;
        }
    };


    DECLARE_MESSAGE_TYPE(CreateTextEntity)
        const std::string m_style,
                          m_text;
        const TransformationDataForMessage m_transformation;
        const int m_renderPassId;

        CreateTextEntity(const char* const style, const char* const text, const TransformationDataForMessage transformation, const int renderPassId) :
            m_style(style),
            m_text(text),
            m_transformation(transformation),
            m_renderPassId(renderPassId)
        {
        };

        CreateTextEntity(const char* const style, const char* const text, const int renderPassId) :
            m_style(style),
            m_text(text),
            m_transformation(),
            m_renderPassId(renderPassId)
        {
        };
    END_MESSAGELISTENER_DISPATCH_DECLARATION(CreateTextEntity)

} } }

#endif
