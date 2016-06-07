
#ifndef UTILITIES_JSONDESERIALIZER_H
#define UTILITIES_JSONDESERIALIZER_H

// Utilities
#include "Deserializer.h"

// std
#include <map>
#include <string>
#include <fstream>


namespace MIMIc { namespace Utilities {

    template <typename KEYTYPE, typename VALUETYPE>
    class JsonDeserializer : public Deserializer<KEYTYPE, VALUETYPE>
    {
        public:
            JsonDeserializer();
            JsonDeserializer(const JsonDeserializer& rhs);
            virtual ~JsonDeserializer();

            virtual JsonDeserializer& operator=(const JsonDeserializer& rhs)
            {
                m_cache = rhs.m_cache;
                m_fstream = rhs.m_fstream;
            }

            void Start(const char* const fileName);
            void End();
            

        protected:
            static const char* s_openObject,
                               s_closeObject,
                               s_openArray,
                               s_closeArray,
                               s_objectDelimiter,
                               s_stringDelimiter;

            void ReadObjectStart(char** name);
            void ReadObjectEnd();

            void ReadArrayStart(char** name);
            void ReadArrayEnd();

            void ReadNamedStringValue(char** name, char** value);
            void ReadNamedBinaryValue(char** name, char** value);
            void ReadBinaryValue(const unsigned length, char** value);


        private:
            std::ifstream m_fstream;

            void ReadString(char** value);
            void ReadToDelimiter(char** value, const char delimiter, bool isString);
    };

} }

#include "JsonDeserializer.inl"

#endif
