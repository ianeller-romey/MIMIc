
// DataModel
#include "TextStyle.h"


namespace MIMIc { namespace DataModel {

    TextStyle::TextStyle()
    {
    }


    TextStyle::TextStyle(const TextStyle& rhs) :
        m_style(rhs.m_style),
        m_types(rhs.m_types)
    {
    }


    TextStyle::~TextStyle()
    {
    }


    TextStyle& TextStyle::operator=(const TextStyle& rhs)
    {
        m_style = rhs.m_style;
        m_types = rhs.m_types;

        return *this;
    }

    const char* const TextStyle::GetStyle() const
    {
        return m_style.c_str();
    }

            
    void TextStyle::AddTextStyleType(const TextStyleType& type)
    {
        m_types.push_back(type);
    }


    TextStyleType TextStyle::GetTextStyleType(const char* const type) const
    {
        // TODO: Better searching
        for(auto begin = m_types.begin(), end = m_types.end(); begin != end; ++begin)
        {
            auto character = *begin;
            if(strcmp(character.GetType(), type) == 0)
                return character;
        }

        throw; // TODO
    }

} }
