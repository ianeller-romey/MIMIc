
// Components
#include "TextCharacterGraphicsComponent.h"
#include "TransformationComponent.h"

// DataModel
#include "CharacterXYDictionary.h"
#include "TextStyleDeserializer.h"

// Graphics
#include "VERTICES.h"


namespace MIMIc { namespace Components {

    TextCharacterGraphicsComponent::TextCharacterGraphicsComponent(Component* transformationComponent, const char* const style, const char character) :
        m_transformationComponent(transformationComponent)
    {
        auto charDesc = CHARACTERXYDICTIONARYINSTANCE.GetXYFromCharacter(character);
        auto textStyle = TEXTSTYLEDESERIALIZERINSTANCE.Get(style);
        auto textType = textStyle.GetTextStyleType(charDesc.m_type.c_str());
        auto textCharacter = textType.GetTextStyleTypeCharacter(charDesc.m_xy.m_value, charDesc.m_xy.m_next.m_value);

        m_textStyleTypeCharacter = textCharacter;

        Components::TransformationComponent* transformation = (Components::TransformationComponent*)m_transformationComponent;
        auto position = transformation->GetPosition();
        auto xMax = position.X() + m_textStyleTypeCharacter.GetCharacterWidth(),
             yMax = position.Y() + m_textStyleTypeCharacter.GetCharacterHeight();
        for(int i = 0, j = NUM_VERTICES; i < j; ++i)
        {
            m_vertices[i].X(Graphics::VERTICES[i].X() * xMax);
            m_vertices[i].Y(Graphics::VERTICES[i].Y() * yMax);
        }
    }


    TextCharacterGraphicsComponent::TextCharacterGraphicsComponent(const TextCharacterGraphicsComponent& rhs) :
        m_transformationComponent(rhs.m_transformationComponent),
        m_textStyleTypeCharacter(rhs.m_textStyleTypeCharacter)
    {
        memcpy(m_vertices, rhs.m_vertices, sizeof(m_vertices));
    }


    TextCharacterGraphicsComponent::~TextCharacterGraphicsComponent()
    {
    }


    TextCharacterGraphicsComponent& TextCharacterGraphicsComponent::operator=(const TextCharacterGraphicsComponent& rhs)
    {
        m_transformationComponent = rhs.m_transformationComponent;
        m_textStyleTypeCharacter = rhs.m_textStyleTypeCharacter;
        memcpy(m_vertices, rhs.m_vertices, sizeof(m_vertices));

        return *this;
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
