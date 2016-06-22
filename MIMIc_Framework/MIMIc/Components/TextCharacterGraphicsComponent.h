
#ifndef COMPONENTS_TEXTCHARACTERGRAPHICSCOMPONENT_H
#define COMPONENTS_TEXTCHARACTERGRAPHICSCOMPONENT_H

// Components
#include "Component.h"

// DataModel
#include "TextStyleTypeCharacter.h"

// Graphics
#include "VERTICES.h"

// Math
#include "Vector2D.h"


namespace MIMIc { namespace Components {

    class TextCharacterGraphicsComponent : public Component
    {
        public:
            TextCharacterGraphicsComponent(const long entityId, Component* transformationComponent, const char* const style, const char character);
            TextCharacterGraphicsComponent(const TextCharacterGraphicsComponent& rhs);
            virtual ~TextCharacterGraphicsComponent() override;


            virtual void Update() override;

            Component* GetTransformationComponent();
            DataModel::TextStyleTypeCharacter* GetTextStyleTypeCharacter();
            Math::Vector2D* GetVertices();

        private:
            TextCharacterGraphicsComponent& operator=(const TextCharacterGraphicsComponent& rhs);

            Component* m_transformationComponent;
            DataModel::TextStyleTypeCharacter m_textStyleTypeCharacter;
            Math::Vector2D m_vertices[NUM_VERTICES];
    };

} }

#endif
