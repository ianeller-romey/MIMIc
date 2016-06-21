
#ifndef MESSAGES_MESSAGETYPEHELPERS_H
#define MESSAGES_MESSAGETYPEHELPERS_H

// Math
#include "Vector2D.h"


namespace MIMIc { namespace Messages { namespace Types {

    struct TransformationDataForMessage
    {
        Math::Vector2D m_position;
        float m_rotation;
        Math::Vector2D m_scale;
        Math::Vector2D m_velocity;
    };

} } }

#endif
