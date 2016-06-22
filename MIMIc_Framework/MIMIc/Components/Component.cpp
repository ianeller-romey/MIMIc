
// Components
#include "Component.h"


namespace MIMIc { namespace Components {

    Component::Component(const long entityId) :
        m_entityId(entityId)
    {
    }
    

    Component::Component(const Component& rhs) :
        m_entityId(rhs.m_entityId)
    {
    }


    Component::~Component()
    {
    }


    const long Component::GetEntityId() const
    {
        return m_entityId;
    }

} }
