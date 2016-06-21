
#ifndef MESSAGES_REQUESTRESPONSETYPES_H
#define MESSAGES_REQUESTRESPONSETYPES_H

// Messages
#include "MessageTypeHelpers.h"
#include "MessageListener.h"

// Math
#include "Vector2D.h"

// std
#include <string>


namespace MIMIc { namespace Messages { namespace Types {

    struct Request
    {
        virtual ~Request() {};
    };


    struct Response
    {
        virtual ~Response() {};
    };

} } }

#endif
