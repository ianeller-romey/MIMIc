
#ifndef COMPONENTS_TEXTSTRINGOVERTIMEBEHAVIORCOMPONENT_H
#define COMPONENTS_TEXTSTRINGOVERTIMEBEHAVIORCOMPONENT_H

// Components
#include "Component.h"


namespace MIMIc { namespace Components {

    class TextStringOverTimeBehaviorComponent : public Component
    {
        public:
            TextStringOverTimeBehaviorComponent(const long entityId, Component* transformationComponent);
            TextStringOverTimeBehaviorComponent(const TextStringOverTimeBehaviorComponent& rhs);
            virtual ~TextStringOverTimeBehaviorComponent() override;

            virtual void Update() override;

            Component* GetTransformationComponent();

        private:
            TextStringOverTimeBehaviorComponent& operator=(const TextStringOverTimeBehaviorComponent& rhs);

            Component* m_transformationComponent;
    };

} }

#endif
