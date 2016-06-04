
// Components
#include "TextTextureGraphicsComponent.h"

// Graphics
#include "TextTextureDeserializer.h"


namespace MIMIc { namespace Components {

    TextTextureGraphicsComponent::TextTextureGraphicsComponent(Component* transformationComponent, const char* const textTexture) :
        m_transformationComponent(transformationComponent),
        m_textTexture(TEXTTEXTUREDESERIALIZERINSTANCE.Get(textTexture))
    {
    }


    TextTextureGraphicsComponent::TextTextureGraphicsComponent(const TextTextureGraphicsComponent& rhs) :
        m_transformationComponent(rhs.m_transformationComponent),
        m_textTexture(rhs.m_textTexture)
    {
    }


    TextTextureGraphicsComponent::~TextTextureGraphicsComponent()
    {
    }


    TextTextureGraphicsComponent& TextTextureGraphicsComponent::operator=(const TextTextureGraphicsComponent& rhs)
    {
        m_transformationComponent = rhs.m_transformationComponent;
        m_textTexture = rhs.m_textTexture;

        return *this;
    }


    Component* TextTextureGraphicsComponent::GetTransformationComponent() const
    {
        return m_transformationComponent;
    }


    Graphics::TextTexture* TextTextureGraphicsComponent::GetTextTexture()
    {
        return &m_textTexture;
    }

} }
