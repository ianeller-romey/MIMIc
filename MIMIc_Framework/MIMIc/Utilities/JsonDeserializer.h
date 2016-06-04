
#ifndef UTILITIES_JSONDESERIALIZER_H
#define UTILITIES_JSONDESERIALIZER_H

// Utilities
#include "Deserializer.h"

// std
#include <map>
#include <string>


namespace MIMIc { namespace Utilities {

    template <typename KEYTYPE, typename VALUETYPE>
    class JsonDeserializer : public Deserializer<KEYTYPE, VALUETYPE>
    {
        public:
            JsonDeserializer();
            JsonDeserializer(const JsonDeserializer& rhs);
            virtual ~JsonDeserializer();
            

        protected:
            const char* ReadObjectStart(const bool hasName);
            void ReadObjectEnd();

            const char* ReadArrayStart(const bool hasName);
            void ReadArrayEnd();

            const char* ReadNamedStringValue();
            const char* ReadNamedBinaryValue();
            const char* ReadBinaryValue(const unsigned length);
    };

} }

#include "JsonDeserializer.inl"

#endif
