
#ifndef ENTITIES_ENTITY_H
#define ENTITIES_ENTITY_H

// Components
#include "Component.h"

// Utilities
#include "HasId.h"


namespace MIMIc { namespace Entities {

    namespace Managers {

        class EntitiesManager;

    }

    class Entity : public Utilities::HasId<Entity>
    {
        friend Managers::EntitiesManager;

        public:
            Entity();
            Entity(const Entity& rhs);
            virtual ~Entity();

            Entity& operator=(const Entity& rhs);

        private:
            // only the EntityManager can set these
            Components::Component* m_transformationComponent;
            Components::Component* m_graphicsComponent;
            Components::Component* m_behaviorComponent;
            Components::Component* m_physicsComponent;
    };

} }

#endif
