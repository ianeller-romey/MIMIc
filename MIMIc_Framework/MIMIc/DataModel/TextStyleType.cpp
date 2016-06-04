
// DataModel
#include "TextStyleType.h"


namespace MIMIc { namespace DataModel {

    TextStyleType::TextStyleType()
    {
    }


    TextStyleType::TextStyleType(const TextStyleType& rhs) :
        m_type(rhs.m_type),
        m_characters(rhs.m_characters)
    {
    }


    TextStyleType::~TextStyleType()
    {
    }


    TextStyleType& TextStyleType::operator=(const TextStyleType& rhs)
    {
        m_type = rhs.m_type;
        m_characters = rhs.m_characters;

        return *this;
    }

    const char* const TextStyleType::GetType() const
    {
        return m_type.c_str();
    }

            
    void TextStyleType::AddTextStyleTypeCharacter(const TextStyleTypeCharacter& character)
    {
        m_characters.push_back(character);
    }


    TextStyleTypeCharacter TextStyleType::GetTextStyleTypeCharacter(const unsigned x, const unsigned y) const
    {
        // TODO: Better searching, maybe use a hash table?
        for(auto begin = m_characters.begin(), end = m_characters.end(); begin != end; ++begin)
        {
            auto character = *begin;
            if(character.X() == x && character.Y() == y)
                return character;
        }

        throw; // TODO
    }

} }
