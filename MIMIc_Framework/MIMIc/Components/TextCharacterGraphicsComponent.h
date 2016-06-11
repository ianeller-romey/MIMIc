
#ifndef COMPONENTS_TextCharacterGraphicsComponent_H
#define COMPONENTS_TextCharacterGraphicsComponent_H

// Components
#include "Component.h"

// DataModel
#include "TextStyleTypeCharacter.h"


namespace MIMIc { namespace Components {

    class TextCharacterGraphicsComponent : public Component
    {
        public:
            TextCharacterGraphicsComponent(Component* transformationComponent, const char* const style, const char character);
            TextCharacterGraphicsComponent(const TextCharacterGraphicsComponent& rhs);
            virtual ~TextCharacterGraphicsComponent();

            TextCharacterGraphicsComponent& operator=(const TextCharacterGraphicsComponent& rhs);

            Component* GetTransformationComponent();
            DataModel::TextStyleTypeCharacter* GetTextStyleTypeCharacter();

        private:
            Component* m_transformationComponent;
            DataModel::TextStyleTypeCharacter m_textStyleTypeCharacter;
    };

} }

#endif
