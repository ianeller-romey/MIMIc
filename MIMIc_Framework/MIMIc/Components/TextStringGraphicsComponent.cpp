
// DataModel
#include "CharacterXYDictionary.h"
#include "TextStyleDeserializer.h"

// Components
#include "TextStringGraphicsComponent.h"
#include "TransformationComponent.h"

// Graphics
#include "VERTICES.h"


namespace MIMIc { namespace Components {

    TextStringGraphicsComponent::TextStringGraphicsComponent(const long entityId, Component* transformationComponent, const DataModel::WordDescriptor& text) :
        Component(entityId),
        m_transformationComponent(transformationComponent)
    {
        SetTextString(text);
    }


    TextStringGraphicsComponent::TextStringGraphicsComponent(const TextStringGraphicsComponent& rhs) :
        Component(rhs),
        m_transformationComponent(rhs.m_transformationComponent)
    {
        m_characters.reserve(rhs.m_characters.size());

        for(unsigned i = 0, j = rhs.m_characters.size(); i < j; ++i)
        {
            CharacterAndVertex cav;
            cav.m_value1 = rhs.m_characters[i].m_value1;

            for(unsigned k = 0, l = NUM_VERTICES; k < l; ++k)
                cav.m_value2[k] = rhs.m_characters[i].m_value2[k];

            m_characters[i] = cav;
        }
    }


    TextStringGraphicsComponent::~TextStringGraphicsComponent()
    {
    }


    void TextStringGraphicsComponent::Update()
    {
        if(m_characters.empty())
            return;

        Components::TransformationComponent* transformation = (Components::TransformationComponent*)m_transformationComponent;
        
        if (transformation->ScaleChanged() && !transformation->PositionChanged()) // new scale, no translation
        { 
            for(unsigned i = 0, j = m_characters.size(); i < j; ++i)
            {
                Update_Scale(m_characters[i], i);
            }
        } 
        else if (!transformation->ScaleChanged() && transformation->PositionChanged()) // no scale, new translation
        { 
            for(auto character : m_characters)
            {
                Update_Translation(character);
            }
        }  
        else if (transformation->ScaleChanged() && transformation->PositionChanged()) // new scale, new translation
        { 
            for(unsigned i = 0, j = m_characters.size(); i < j; ++i)
            {
                Update_ScaleAndTranslation(m_characters[i], i);
            }
        }

        if (transformation->RotationChanged()) // rotation changed
        {
            auto origin = transformation->GetPosition().Translate(m_characters.size() * m_characters[0].m_value1.GetCharacterWidth() / 2, m_characters[0].m_value1.GetCharacterHeight() / 2);
            for(auto character : m_characters)
            {
                Update_Rotation(character, origin);
            }
        }
    }


    void TextStringGraphicsComponent::SetTextString(const DataModel::WordDescriptor& word)
    {
        m_characters.clear();

        if(word.m_word.empty())
            return;

        // get these right away so that we can calculate the origin for our rotation,
        // in case we need it
        auto charDesc = CHARACTERXYDICTIONARYINSTANCE.GetXYFromCharacter(word.m_word[0]);
        auto textStyle = TEXTSTYLEDESERIALIZERINSTANCE.Get(word.m_style);
        auto textType = textStyle.GetTextStyleType(charDesc.m_type.c_str());
        auto textCharacter = textType.GetTextStyleTypeCharacter(charDesc.m_xy.m_value, charDesc.m_xy.m_next.m_value);
        
        // do the actual origin calculation
        Components::TransformationComponent* transformation = (Components::TransformationComponent*)m_transformationComponent;
        auto rotation = transformation->GetRotation();
        auto origin = transformation->GetPosition().Translate(word.m_word.size() * textCharacter.GetCharacterWidth() / 2, 
                                                              textCharacter.GetCharacterHeight() / 2);

        for(unsigned i = 0, j = word.m_word.size(); i < j; ++i)
        {
            auto character = word.m_word[i];
            CharacterAndVertex cav;

            // assign character
            charDesc = CHARACTERXYDICTIONARYINSTANCE.GetXYFromCharacter(character);
            textType = textStyle.GetTextStyleType(charDesc.m_type.c_str());
            textCharacter = textType.GetTextStyleTypeCharacter(charDesc.m_xy.m_value, charDesc.m_xy.m_next.m_value);

            cav.m_value1 = textCharacter;

            // assign vertices
            Update_ScaleAndTranslation(cav, i);
            if(rotation != 0.0)
                Update_Rotation(cav, origin);

            // done
            m_characters.push_back(cav);
        }
    }


    Component* TextStringGraphicsComponent::GetTransformationComponent()
    {
        return m_transformationComponent;
    }


    const unsigned TextStringGraphicsComponent::GetStringLength() const
    {
        return m_characters.size();
    }


    CharacterAndVertex& TextStringGraphicsComponent::GetCharacterAndVertex(unsigned index)
    {
        return m_characters[index];
    }


    void TextStringGraphicsComponent::Update_Scale(CharacterAndVertex& characterAndVertex, const unsigned x)
    {
        Components::TransformationComponent* transformation = (Components::TransformationComponent*)m_transformationComponent;

        auto& textStyleTypeCharacter = characterAndVertex.m_value1;
        auto& vertices = characterAndVertex.m_value2;

        float width = textStyleTypeCharacter.GetCharacterWidth(),
              height = textStyleTypeCharacter.GetCharacterHeight();

        auto scale = transformation->GetScale(),
             position(transformation->GetPosition());

        position.X(position.X() + (x * width));

        for(unsigned i = 0, j = NUM_VERTICES; i < j; ++i)
        {
            auto vert = Graphics::VERTICES[i];
            auto scaled = Math::Vector2D(vert.X() * width * scale.X(), vert.Y() * height * scale.Y());
            vertices[i].X(scaled.X() + position.X());
            vertices[i].Y(scaled.Y() + position.Y());
        }
    }


    void TextStringGraphicsComponent::Update_Translation(CharacterAndVertex& characterAndVertex)
    {
        Components::TransformationComponent* transformation = (Components::TransformationComponent*)m_transformationComponent;

        auto& textStyleTypeCharacter = characterAndVertex.m_value1;
        auto& vertices = characterAndVertex.m_value2;

        float width = textStyleTypeCharacter.GetCharacterWidth(),
              height = textStyleTypeCharacter.GetCharacterHeight();

        auto translation = transformation->GetPositionChange();

        for(unsigned i = 0, j = NUM_VERTICES; i < j; ++i)
        {
            vertices[i].TranslateAndAssign(translation.X(), translation.Y());
        }
    }


    void TextStringGraphicsComponent::Update_ScaleAndTranslation(CharacterAndVertex& characterAndVertex, const unsigned x)
    {
        Components::TransformationComponent* transformation = (Components::TransformationComponent*)m_transformationComponent;

        auto& textStyleTypeCharacter = characterAndVertex.m_value1;
        auto& vertices = characterAndVertex.m_value2;

        float width = textStyleTypeCharacter.GetCharacterWidth(),
              height = textStyleTypeCharacter.GetCharacterHeight();

        auto scale = transformation->GetScale(),
             position(transformation->GetPosition()),
             translation = transformation->GetPositionChange();

        position.X(position.X() + (x * width));

        for(unsigned i = 0, j = NUM_VERTICES; i < j; ++i)
        {
            auto vert = Graphics::VERTICES[i];
            auto scaled = Math::Vector2D(vert.X() * width * scale.X(), vert.Y() * height * scale.Y());
            vertices[i].X(scaled.X() + position.X());
            vertices[i].Y(scaled.Y() + position.Y());
            vertices[i].TranslateAndAssign(translation.X(), translation.Y());
        }
    }


    void TextStringGraphicsComponent::Update_Rotation(CharacterAndVertex& characterAndVertex, const Math::Vector2D& origin)
    {
        Components::TransformationComponent* transformation = (Components::TransformationComponent*)m_transformationComponent;

        auto& textStyleTypeCharacter = characterAndVertex.m_value1;
        auto& vertices = characterAndVertex.m_value2;

        float width = textStyleTypeCharacter.GetCharacterWidth(),
              height = textStyleTypeCharacter.GetCharacterHeight();

        auto theta = transformation->GetRotationChange();
            
        for(unsigned i = 0, j = NUM_VERTICES; i < j; ++i)
        {
            vertices[i].RotateAndAssign(origin.X(), origin.Y(), theta);
        }
    }

} }
