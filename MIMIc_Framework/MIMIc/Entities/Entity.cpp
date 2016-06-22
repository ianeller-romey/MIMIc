
// Entities
#include "Entity.h"


namespace MIMIc { namespace Entities { 
    
    Entity::Entity() :
        m_transformationComponent(0),
        m_graphicsComponent(0),
        m_behaviorComponent(0),
        m_physicsComponent(0)
    {
    }
    
    
    Entity::Entity(const Entity& rhs) :
        m_transformationComponent(rhs.m_transformationComponent),
        m_graphicsComponent(rhs.m_graphicsComponent),
        m_behaviorComponent(rhs.m_behaviorComponent),
        m_physicsComponent(rhs.m_physicsComponent)
    {
    }


    Entity::~Entity()
    {
        // don't delete the components; that's handled by the EntityManager
    }
    
    
    Entity& Entity::operator=(const Entity& rhs)
    {
        m_transformationComponent = rhs.m_transformationComponent;
        m_graphicsComponent = rhs.m_graphicsComponent;
        m_behaviorComponent = rhs.m_behaviorComponent;
        m_physicsComponent = rhs.m_physicsComponent;

        return *this;
    }

} }
