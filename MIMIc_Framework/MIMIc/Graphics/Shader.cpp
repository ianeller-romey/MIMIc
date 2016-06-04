
#include "Shader.h"

#include <cstring> // memcpy


namespace MIMIc { namespace Graphics {

    Shader::Shader() :
        m_content(0),
        m_contentLength(0)
    {
    }


    Shader::Shader(const char* content) :
        m_content(0),
        m_contentLength(0)
    {
        SetContent(content, strlen(content) + 1);
    }


    Shader::Shader(const Shader& rhs) :
        m_content(0),
        m_contentLength(0)
    {
        SetContent(rhs.m_content, rhs.m_contentLength);
    }


    Shader::~Shader()
    {
    }


    Shader& Shader::operator=(const Shader& rhs)
    {
        SetContent(rhs.m_content, rhs.m_contentLength);

        return *this;
    }


    const char* const Shader::GetContent() const
    {
        return m_content;
    }


    void Shader::SetContent(const char* const content, const unsigned contentLength)
    {
        DeleteContent();
        
        m_contentLength = contentLength;
        m_content = new char[m_contentLength];
        memcpy(m_content, content, sizeof(char) * m_contentLength);
    }


    void Shader::DeleteContent()
    {
        if(m_content)
        {
            delete [] m_content;
            m_content = 0;
            m_contentLength = 0;
        }
    }

} }
