
#ifndef COMPONENTS_TRANSFORMATIONCOMPONENT_H
#define COMPONENTS_TRANSFORMATIONCOMPONENT_H

// Components
#include "Component.h"

// Math
#include "Vector2D.h"


namespace MIMIc { namespace Components {

    class TransformationComponent : public Component
    {
        public:
            TransformationComponent(const long entityId);
            TransformationComponent(const long entityId, const Math::Vector2D& position, const float rotation, const Math::Vector2D& scale, const Math::Vector2D& velocity);
            TransformationComponent(const TransformationComponent& rhs);
            virtual ~TransformationComponent() override;

            virtual void Update() override;
            
            void Translate(const Math::Vector2D& translator);

            void SetPosition(const float x, const float y);
            bool PositionChanged() const;
            Math::Vector2D GetPositionChange() const;
            const Math::Vector2D& GetPosition() const;

            void SetRotation(const float rotation);
            bool RotationChanged() const;
            float GetRotationChange() const;
            float GetRotation() const;

            void SetScale(const float x, const float y);
            bool ScaleChanged() const;
            Math::Vector2D GetScaleChange() const;
            const Math::Vector2D& GetScale() const;

            void SetVelocity(const float x, const float y);
            bool VelocityChanged() const;
            Math::Vector2D GetVelocityChange() const;
            const Math::Vector2D& GetVelocity() const;

        private:
            TransformationComponent& operator=(const TransformationComponent& rhs);

            Math::Vector2D m_position,
                           m_lastPosition;
            float m_rotation,
                  m_lastRotation;
            Math::Vector2D m_scale,
                           m_lastScale;
            Math::Vector2D m_velocity,
                           m_lastVelocity;
    };

} }

#endif
