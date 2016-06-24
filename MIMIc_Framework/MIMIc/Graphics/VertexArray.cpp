
#include "VertexArray.h"


namespace MIMIc { namespace Graphics {

    VertexArray::VertexArray()
    {
    }


    VertexArray::VertexArray(const VertexArray& rhs)
    {
        for(unsigned i = 0; i < NUM_VERTICES; ++i)
            m_array[i] = rhs.m_array[i];
    }


    VertexArray& VertexArray::operator=(const VertexArray& rhs)
    {
        for(unsigned i = 0; i < NUM_VERTICES; ++i)
            m_array[i] = rhs.m_array[i];

        return *this;
    }


    Math::Vector2D& VertexArray::operator[](unsigned i)
    {
        return m_array[i];
    }


    const Math::Vector2D& VertexArray::operator[](unsigned i) const
    {
        return m_array[i];
    }

} }
