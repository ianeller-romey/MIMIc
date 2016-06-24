
#ifndef GRAPHICS_VERTEXARRAY_H
#define GRAPHICS_VERTEXARRAY_H

// Graphics
#include "VERTICES.h"

// Math
#include "Vector2D.h"


namespace MIMIc { namespace Graphics {

    class VertexArray
    {
        public:
            VertexArray();
            VertexArray(const VertexArray& rhs);

            VertexArray& operator=(const VertexArray& rhs);

            Math::Vector2D& operator[](unsigned i);

            const Math::Vector2D& operator[](unsigned i) const;

        private:
            Math::Vector2D m_array[NUM_VERTICES];
    };

} }

#endif
