
#ifndef COMPONENTS_TEXTTEXTUREGRAPHICSCOMPONENT_H
#define COMPONENTS_TEXTTEXTUREGRAPHICSCOMPONENT_H

// Components
#include "Component.h"

// Graphics
#include "TextTexture.h"


namespace MIMIc { namespace Components {

    class TextTextureGraphicsComponent : public Component
    {
        public:
            TextTextureGraphicsComponent(Component* transformationComponent, const char* const textTexture);
            TextTextureGraphicsComponent(const TextTextureGraphicsComponent& rhs);
            virtual ~TextTextureGraphicsComponent();

            TextTextureGraphicsComponent& operator=(const TextTextureGraphicsComponent& rhs);

            Component* GetTransformationComponent() const;
            Graphics::TextTexture* GetTextTexture();

        private:
            Component* m_transformationComponent;
            Graphics::TextTexture m_textTexture;
    };

} }

#endif
