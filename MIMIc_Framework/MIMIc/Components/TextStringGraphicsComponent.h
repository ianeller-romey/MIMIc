
#ifndef COMPONENTS_TEXTSTRINGGRAPHICSCOMPONENT_H
#define COMPONENTS_TEXTSTRINGGRAPHICSCOMPONENT_H

// DataModel
#include "TextStyleTypeCharacter.h"
#include "WordDescriptor.h"

// Components
#include "Component.h"

// Graphics
#include "VertexArray.h"
#include "VERTICES.h"

// Math
#include "Vector2D.h"

// Utilities
#include "HeteroPair.h"

// std
#include <vector>


namespace MIMIc { namespace Components {
    
    typedef Utilities::HeteroPair<DataModel::TextStyleTypeCharacter, Graphics::VertexArray> CharacterAndVertex;


    class TextStringGraphicsComponent : public Component
    {
        public:
            TextStringGraphicsComponent(const long entityId, Component* transformationComponent, const DataModel::WordDescriptor& text);
            TextStringGraphicsComponent(const TextStringGraphicsComponent& rhs);
            virtual ~TextStringGraphicsComponent() override;
            
            virtual void Update() override;

            void SetTextString(const DataModel::WordDescriptor& word);

            Component* GetTransformationComponent();
            const unsigned GetStringLength() const;
            CharacterAndVertex& GetCharacterAndVertex(unsigned index);

        private:
            TextStringGraphicsComponent& operator=(const TextStringGraphicsComponent& rhs);

            Component* m_transformationComponent;
            std::vector<CharacterAndVertex> m_characters;

            void Update_Scale(CharacterAndVertex& characterAndVertex, const unsigned x);
            void Update_Translation(CharacterAndVertex& characterAndVertex);
            void Update_ScaleAndTranslation(CharacterAndVertex& characterAndVertex, const unsigned x);
            void Update_Rotation(CharacterAndVertex& characterAndVertex, const Math::Vector2D& origin);
    };

} }

#endif
