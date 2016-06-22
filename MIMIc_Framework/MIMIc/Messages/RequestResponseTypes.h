
#ifndef MESSAGES_REQUESTRESPONSETYPES_H
#define MESSAGES_REQUESTRESPONSETYPES_H

// Messages
#include "MessageTypeHelpers.h"
#include "MessageListener.h"

// std
#include <string>


#define DECLARE_REQUEST_TYPE(name) struct name : public Request {
#define DECLARE_RESPONSE_TYPE(name) struct name : public Response {


namespace MIMIc { namespace Messages { namespace Types {
    
    struct Response;


    struct Request
    {
        virtual ~Request() {};
        virtual Response* Dispatch(MessageListener* listener) = 0;

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

    
    struct Response
    {
        virtual ~Response() {};
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
