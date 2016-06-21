
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
            virtual ~JsonDeserializer() override;     

        protected:
            static const char *s_openObject,
                              *s_closeObject,
                              *s_openArray,
                              *s_closeArray,
                              *s_valueDelimiter,
                              *s_collectionDelimiter,
                              *s_stringDelimiter,
                              *s_newlineDelimiter;

            bool Start(const char* const fileName) const;
            void End() const;

            bool ReadObjectStart(char** namePointer, char* nameLocation) const;
            bool ReadObjectEnd() const;

            bool ReadArrayStart(char** name, char* nameLocation) const;
            bool ReadArrayStringValue(char** valuePointer, char* valueLocation, bool& continueOn) const;
            template <typename T>
            bool ReadArrayBinaryValue(T* valueLocation, bool& continueOn) const;
            bool ReadNextArray(bool& continueOn) const;
            bool ReadArrayEnd() const;

            bool ReadNamedStringValue(char** namePointer, char* nameLocation, char** valuePointer, char* valueLocation) const;
            template <typename T>
            bool ReadNamedBinaryValue(char** namePointer, char* nameLocation, T* valueLocation) const;
            bool ReadBinaryValueWithLength(const unsigned length, char* valueLocation) const;

            bool AdvanceLine() const;
            bool AdvanceComma() const;
            bool AdvanceBracket() const;
            bool AdvanceBrace() const;

        private:
            mutable std::ifstream m_fstream;

            static bool ReadCharacter(std::ifstream& fstream, char& character);
            static bool IsDelimiter(const char value, const char* const delimiters, const unsigned numDelimiters, char* actualDelimiter);

            bool ReadString(char** valuePointer, char* valueLocation) const;
            template <typename T>
            bool ReadBinaryValue(T* valueLocation) const;
            bool ReadToDelimiter(const char* const delimiters, const unsigned numDelimiters, char* actualDelimiter) const;
    };

} }

#include "JsonDeserializer.inl"

#endif
