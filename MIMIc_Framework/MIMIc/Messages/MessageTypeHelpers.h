
#ifndef MESSAGES_MESSAGETYPEHELPERS_H
#define MESSAGES_MESSAGETYPEHELPERS_H

// Math
#include "Vector2D.h"


#define END_MESSAGELISTENER_DISPATCH_DECLARATION(name) virtual ~name() override {}; \
                                                       virtual void Dispatch(MessageListener* listener) override { listener->Process(this); }; };


namespace MIMIc { namespace Messages { namespace Types {

    struct TransformationDataForMessage
    {
        TransformationDataForMessage() :
            m_rotation(0),
            m_scale(1.0, 1.0)
        {
        }

        Math::Vector2D m_position;
        float m_rotation;
        Math::Vector2D m_scale;
        Math::Vector2D m_velocity;
    };

} } }

#endif
