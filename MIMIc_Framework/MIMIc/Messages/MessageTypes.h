
#ifndef MESSAGES_MESSAGETYPES_H
#define MESSAGES_MESSAGETYPES_H

// Messages
#include "MessageTypeHelpers.h"
#include "MessageListener.h"

// Math
#include "Vector2D.h"

// std
#include <string>


#define DECLARE_MESSAGE_TYPE(name) struct name : public Message {
#define END_MESSAGE_TYPE(name) virtual ~name() override {}; \
                               virtual void Dispatch(MessageListener* listener) override { listener->Process(this); }; };


namespace MIMIc { namespace Messages { namespace Types {

    struct Message
    {
        virtual ~Message() {};
        virtual void Dispatch(MessageListener* listener) = 0;
    };


    DECLARE_MESSAGE_TYPE(CreateTextEntity)
        std::string m_text;
        TransformationDataForMessage m_transformation;

        CreateTextEntity(const char* const text, TransformationDataForMessage transformation) :
            m_text(text),
            m_transformation(transformation)
        {
        };
    END_MESSAGE_TYPE(CreateTextEntity)

} } }

#endif
