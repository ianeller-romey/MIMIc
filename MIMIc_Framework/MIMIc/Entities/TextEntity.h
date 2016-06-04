
#ifndef ENTITIES_TEXTENTITY_H
#define ENTITIES_TEXTENTITY_H

// Components
#include "Component.h"

// Utilities
#include "HasId.h"


namespace MIMIc { namespace Entities {

    class TextEntity : public Utilities::HasId<TextEntity>
    {
        public:
            TextEntity(Components::Component* transformationComponent, Components::Component* const graphicsComponent);
            TextEntity(const TextEntity& rhs);
            ~TextEntity();

            TextEntity& operator=(const TextEntity& rhs);

        private:
            Components::Component* m_transformationComponent;
            Components::Component* m_graphicsComponent;
    };

} }

#endif
