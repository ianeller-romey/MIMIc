
#include "TextTexture.h"

#include <cstring> // memcpy


namespace MIMIc { namespace Graphics {

    TextTexture::TextTexture() :
        m_texture(0),
        m_textureWidth(0),
        m_textureHeight(0),
        m_edited(false)
    {
    }


    TextTexture::TextTexture(TEXTTEXTURECHAR* const texture, const unsigned textureWidth, const unsigned textureHeight) :
        m_texture(0),
        m_textureWidth(0),
        m_textureHeight(0),
        m_edited(false)
    {
        SetTexture(texture, textureWidth, textureHeight, false);
    }


    TextTexture::TextTexture(const TextTexture& rhs) :
        m_texture(0),
        m_textureWidth(0),
        m_textureHeight(0),
        m_edited(false)
    {
        SetTexture(rhs.m_texture, rhs.m_textureWidth, rhs.m_textureHeight, rhs.m_edited);
    }


    TextTexture::~TextTexture()
    {
        DeleteTexture();
    }


    TextTexture& TextTexture::operator=(const TextTexture& rhs)
    {
        SetTexture(rhs.m_texture, rhs.m_textureWidth, rhs.m_textureHeight, rhs.m_edited);

        return *this;
    }


    const unsigned TextTexture::GetTextureWidth() const
    {
        return m_textureWidth;
    }


    const unsigned TextTexture::GetTextureHeight() const
    {
        return m_textureHeight;
    }


    const unsigned TextTexture::GetTextureLength() const
    {
        return m_textureWidth * m_textureHeight;
    }


    const TEXTTEXTURECHAR* const TextTexture::GetTexture() const
    {
        return m_texture;
    }


    TEXTTEXTURECHAR* TextTexture::GetTextureForEditing()
    {
        m_edited = true;
        return m_texture;
    }


    void TextTexture::SetTexture(TEXTTEXTURECHAR* const texture, const unsigned textureWidth, const unsigned textureHeight, const bool edited)
    {
        DeleteTexture();

        if(edited)
        {
            m_textureWidth = textureWidth;
            m_textureHeight = textureHeight;

            auto textureLength = GetTextureLength();
            m_texture = new TEXTTEXTURECHAR[textureLength];
            memcpy(m_texture, texture, sizeof(TEXTTEXTURECHAR) * textureLength);
        }
        else
        {
            m_textureWidth = textureWidth;
            m_textureHeight = textureHeight;
            m_texture = texture;
        }

        m_edited = edited;
    }


    void TextTexture::DeleteTexture()
    {
        if(m_edited && m_texture)
        {
            delete [] m_texture;
            m_texture = 0;
            m_textureWidth = 0;
            m_textureHeight = 0;
            m_edited = false;
        }
    }

} }
