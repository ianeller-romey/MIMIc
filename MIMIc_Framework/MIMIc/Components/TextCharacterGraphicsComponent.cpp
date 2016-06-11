
// Components
#include "TextCharacterGraphicsComponent.h"

// DataModel
#include "CharacterXYDictionary.h"
#include "TextStyleDeserializer.h"


namespace MIMIc { namespace Components {

    TextCharacterGraphicsComponent::TextCharacterGraphicsComponent(Component* transformationComponent, const char* const style, const char character) :
        m_transformationComponent(transformationComponent)
    {
        auto charDesc = CHARACTERXYDICTIONARYINSTANCE.GetXYFromCharacter(character);
        auto textStyle = TEXTSTYLEDESERIALIZERINSTANCE.Get(style);
        auto textType = textStyle.GetTextStyleType(charDesc.m_type.c_str());
        auto textCharacter = textType.GetTextStyleTypeCharacter(charDesc.m_xy.m_value, charDesc.m_xy.m_next.m_value);

        m_textStyleTypeCharacter = textCharacter;
    }


    TextCharacterGraphicsComponent::TextCharacterGraphicsComponent(const TextCharacterGraphicsComponent& rhs) :
        m_transformationComponent(rhs.m_transformationComponent),
        m_textStyleTypeCharacter(rhs.m_textStyleTypeCharacter)
    {
    }


    TextCharacterGraphicsComponent::~TextCharacterGraphicsComponent()
    {
    }


    TextCharacterGraphicsComponent& TextCharacterGraphicsComponent::operator=(const TextCharacterGraphicsComponent& rhs)
    {
        m_transformationComponent = rhs.m_transformationComponent;
        m_textStyleTypeCharacter = rhs.m_textStyleTypeCharacter;

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

} }
