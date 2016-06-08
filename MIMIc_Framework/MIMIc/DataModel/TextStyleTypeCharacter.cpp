
// DataModel
#include "TextStyleTypeCharacter.h"

// std
#include <cstring> // memcpy


namespace MIMIc { namespace DataModel {

    TextStyleTypeCharacter::TextStyleTypeCharacter() :
        m_data(0),
        m_x(0),
        m_y(0),
        m_characterWidth(0),
        m_characterHeight(0),
        m_edited(false)
    {
    }


    TextStyleTypeCharacter::TextStyleTypeCharacter(CHARACTERDATA* const data, const char characterWidth, const char characterHeight, const char x, const char y) :
        m_data(0),
        m_x(x),
        m_y(y),
        m_characterWidth(0),
        m_characterHeight(0),
        m_edited(false)
    {
        SetData(data, characterWidth, characterHeight, false);
    }


    TextStyleTypeCharacter::TextStyleTypeCharacter(const TextStyleTypeCharacter& rhs) :
        m_data(0),
        m_x(rhs.m_x),
        m_y(rhs.m_y),
        m_characterWidth(0),
        m_characterHeight(0),
        m_edited(false)
    {
        SetData(rhs.m_data, rhs.m_characterWidth, rhs.m_characterHeight, rhs.m_edited);
    }


    TextStyleTypeCharacter::~TextStyleTypeCharacter()
    {
        DeleteData();
    }


    TextStyleTypeCharacter& TextStyleTypeCharacter::operator=(const TextStyleTypeCharacter& rhs)
    {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
        SetData(rhs.m_data, rhs.m_characterWidth, rhs.m_characterHeight, rhs.m_edited);

        return *this;
    }


    const char TextStyleTypeCharacter::X() const
    {
        return m_x;
    }


    const char TextStyleTypeCharacter::Y() const
    {
        return m_y;
    }


    const char TextStyleTypeCharacter::GetCharacterWidth() const
    {
        return m_characterWidth;
    }


    const char TextStyleTypeCharacter::GetCharacterHeight() const
    {
        return m_characterHeight;
    }


    const char TextStyleTypeCharacter::GetDataLength() const
    {
        return m_characterWidth * m_characterHeight;
    }


    const CHARACTERDATA* const TextStyleTypeCharacter::GetData() const
    {
        return m_data;
    }


    CHARACTERDATA* TextStyleTypeCharacter::GetDataForEditing()
    {
        m_edited = true;
        return m_data;
    }


    void TextStyleTypeCharacter::SetData(CHARACTERDATA* const texture, const char textureWidth, const char textureHeight, const bool edited)
    {
        DeleteData();

        if(edited)
        {
            m_characterWidth = textureWidth;
            m_characterHeight = textureHeight;

            auto textureLength = GetDataLength();
            m_data = new CHARACTERDATA[textureLength];
            memcpy(m_data, texture, sizeof(CHARACTERDATA) * textureLength);
        }
        else
        {
            m_characterWidth = textureWidth;
            m_characterHeight = textureHeight;
            m_data = texture;
        }

        m_edited = edited;
    }


    void TextStyleTypeCharacter::DeleteData()
    {
        if(m_edited && m_data)
        {
            delete [] m_data;
            m_data = 0;
            m_characterWidth = 0;
            m_characterHeight = 0;
            m_edited = false;
        }
    }

} }
