
// Components
#include "TextStringOverTimeBehaviorComponent.h"
#include "TransformationComponent.h"


namespace MIMIc { namespace Components {

    TextStringOverTimeBehaviorComponent::TextStringOverTimeBehaviorComponent(const long entityId, Component* transformationComponent) :
        Component(entityId),
        m_transformationComponent(transformationComponent)
    {
    }


    TextStringOverTimeBehaviorComponent::TextStringOverTimeBehaviorComponent(const TextStringOverTimeBehaviorComponent& rhs) :
        Component(rhs),
        m_transformationComponent(rhs.m_transformationComponent)
    {
    }


    TextStringOverTimeBehaviorComponent::~TextStringOverTimeBehaviorComponent()
    {
    }


    void TextStringOverTimeBehaviorComponent::Update()
    {
    }


    Component* TextStringOverTimeBehaviorComponent::GetTransformationComponent()
    {
        return m_transformationComponent;
    }

} }
