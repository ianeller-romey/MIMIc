
#ifndef DATAMODEL_TEXTSTYLETYPE_H
#define DATAMODEL_TEXTSTYLETYPE_H

// DataModel
#include "TextStyleTypeCharacter.h"

// std
#include <vector>
#include <string>


namespace MIMIc { namespace DataModel {

    class TextStyleDeserializer;

} }


namespace MIMIc { namespace DataModel {

    class TextStyleType
    {
        friend class TextStyleDeserializer;

        public:
            TextStyleType();
            TextStyleType(const TextStyleType& rhs);
            ~TextStyleType();

            TextStyleType& operator=(const TextStyleType& rhs);

            const char* const GetType() const;
            
            void AddTextStyleTypeCharacter(const TextStyleTypeCharacter& character);
            TextStyleTypeCharacter GetTextStyleTypeCharacter(const unsigned x, const unsigned y) const;

        private:
            std::string m_type;
            std::vector<TextStyleTypeCharacter> m_characters;
    };

} }

#endif
