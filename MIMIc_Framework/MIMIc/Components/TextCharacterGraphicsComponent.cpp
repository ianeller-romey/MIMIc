
// Components
#include "TextCharacterGraphicsComponent.h"
#include "TransformationComponent.h"

// DataModel
#include "CharacterXYDictionary.h"
#include "TextStyleDeserializer.h"

// Graphics
#include "VERTICES.h"


namespace MIMIc { namespace Components {

    TextCharacterGraphicsComponent::TextCharacterGraphicsComponent(const long entityId, Component* transformationComponent, const char* const style, const char character) :
        Component(entityId),
        m_transformationComponent(transformationComponent)
    {
        auto charDesc = CHARACTERXYDICTIONARYINSTANCE.GetXYFromCharacter(character);
        auto textStyle = TEXTSTYLEDESERIALIZERINSTANCE.Get(style);
        auto textType = textStyle.GetTextStyleType(charDesc.m_type.c_str());
        auto textCharacter = textType.GetTextStyleTypeCharacter(charDesc.m_xy.m_value, charDesc.m_xy.m_next.m_value);

        m_textStyleTypeCharacter = textCharacter;

        Components::TransformationComponent* transformation = (Components::TransformationComponent*)m_transformationComponent;
        auto position = transformation->GetPosition();
        for(int i = 0, j = NUM_VERTICES; i < j; ++i)
        {
            m_vertices[i].X((Graphics::VERTICES[i].X() * m_textStyleTypeCharacter.GetCharacterWidth()) + position.X());
            m_vertices[i].Y((Graphics::VERTICES[i].Y() * m_textStyleTypeCharacter.GetCharacterHeight()) + position.Y());
        }
    }


    TextCharacterGraphicsComponent::TextCharacterGraphicsComponent(const TextCharacterGraphicsComponent& rhs) :
        Component(rhs),
        m_transformationComponent(rhs.m_transformationComponent),
        m_textStyleTypeCharacter(rhs.m_textStyleTypeCharacter)
    {
        memcpy(m_vertices, rhs.m_vertices, sizeof(m_vertices));
    }


    TextCharacterGraphicsComponent::~TextCharacterGraphicsComponent()
    {
    }


    void TextCharacterGraphicsComponent::Update()
    {
    }


    Component* TextCharacterGraphicsComponent::GetTransformationComponent()
    {
        return m_transformationComponent;
    }


    DataModel::TextStyleTypeCharacter* TextCharacterGraphicsComponent::GetTextStyleTypeCharacter()
    {
        return &m_textStyleTypeCharacter;
    }


    Math::Vector2D* TextCharacterGraphicsComponent::GetVertices()
    {
        return m_vertices;
    }

} }
