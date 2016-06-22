
#ifndef MESSAGES_NOTICETYPES_H
#define MESSAGES_NOTICETYPES_H

// Messages
#include "MessageTypeHelpers.h"
#include "MessageListener.h"

// std
#include <string>


#define DECLARE_NOTICE_TYPE(name) struct name : public Notice {


namespace MIMIc { namespace Messages { namespace Types {

    struct Notice
    {
        virtual ~Notice() {};
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

} } }

#endif
