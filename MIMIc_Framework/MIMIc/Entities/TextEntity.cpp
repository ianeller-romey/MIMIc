
// Entities
#include "TextEntity.h"

// Components
#include "TextCharacterGraphicsComponent.h"


namespace MIMIc { namespace Entities {

    TextEntity::TextEntity(Components::Component* transformationComponent, Components::Component* const graphicsComponent) :
        m_transformationComponent(transformationComponent),
        m_graphicsComponent(graphicsComponent)
    {
    }


    TextEntity::TextEntity(const TextEntity& rhs) :
        m_transformationComponent(rhs.m_transformationComponent),
        m_graphicsComponent(rhs.m_graphicsComponent)
    {
    }


    TextEntity::~TextEntity()
    {
    }


    TextEntity& TextEntity::operator=(const TextEntity& rhs)
    {
        m_transformationComponent = rhs.m_transformationComponent;
        m_graphicsComponent = rhs.m_graphicsComponent;

        return *this;
    }

} }
