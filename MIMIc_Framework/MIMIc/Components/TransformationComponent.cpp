
// Components
#include "TransformationComponent.h"


namespace MIMIc { namespace Components {

    TransformationComponent::TransformationComponent() :
        m_position(0.0, 0.0, Math::Vector2D::NormalizationState::Ignored),
        m_lastPosition(0.0, 0.0, Math::Vector2D::NormalizationState::Ignored),
        m_rotation(0.0),
        m_lastRotation(0.0),
        m_scale(1.0, 1.0, Math::Vector2D::NormalizationState::Ignored),
        m_lastScale(1.0, 1.0, Math::Vector2D::NormalizationState::Ignored),
        m_velocity(0.0, 0.0, Math::Vector2D::NormalizationState::Ignored),
        m_lastVelocity(0.0, 0.0, Math::Vector2D::NormalizationState::Ignored)
    {
    }


    TransformationComponent::TransformationComponent(const Math::Vector2D& position, const float rotation, const Math::Vector2D& scale, const Math::Vector2D& velocity) :
        m_position(position),
        m_lastPosition(position),
        m_rotation(rotation),
        m_lastRotation(rotation),
        m_scale(scale),
        m_lastScale(scale),
        m_velocity(velocity),
        m_lastVelocity(velocity)
    {
    }


    TransformationComponent::TransformationComponent(const TransformationComponent& rhs) :
        m_position(rhs.m_position),
        m_lastPosition(rhs.m_lastPosition),
        m_rotation(rhs.m_rotation),
        m_lastRotation(rhs.m_lastRotation),
        m_scale(rhs.m_scale),
        m_lastScale(rhs.m_lastScale),
        m_velocity(rhs.m_velocity),
        m_lastVelocity(rhs.m_lastVelocity)
    {
    }


    TransformationComponent::~TransformationComponent()
    {
    }


    TransformationComponent& TransformationComponent::operator=(const TransformationComponent& rhs)
    {
        m_position = rhs.m_position;
        m_lastPosition = rhs.m_lastPosition;
        m_rotation = rhs.m_rotation;
        m_lastRotation = rhs.m_lastRotation;
        m_scale = rhs.m_scale;
        m_lastScale = rhs.m_lastScale;
        m_velocity = rhs.m_velocity;
        m_lastVelocity = rhs.m_lastVelocity;

        return *this;
    }


    void TransformationComponent::Update()
    {
        m_lastPosition = m_position;
        m_lastRotation = m_rotation;
        m_lastScale = m_scale;
        m_lastVelocity = m_velocity;
    }


    void TransformationComponent::Translate(const Math::Vector2D& translator)
    {
        SetPosition(m_position.X() + translator.X(), m_position.X() + translator.Y());
    }


    void TransformationComponent::SetPosition(const float x, const float y)
    {
        m_position.X(x);
        m_position.Y(y);
    }


    bool TransformationComponent::PositionChanged() const
    {
        return m_lastPosition != m_position;
    }


    Math::Vector2D TransformationComponent::GetPositionChange() const
    {
        return m_position - m_lastPosition;
    }


    Math::Vector2D TransformationComponent::GetPosition() const
    {
        return m_position;
    }


    void TransformationComponent::SetRotation(const float rotation)
    {
        m_rotation = rotation;
    }


    bool TransformationComponent::RotationChanged() const
    {
        return m_lastRotation != m_rotation;
    }


    float TransformationComponent::GetRotationChange() const
    {
        return m_rotation - m_lastRotation;
    }


    float TransformationComponent::GetRotation() const
    {
        return m_rotation;
    }


    void TransformationComponent::SetScale(const float x, const float y)
    {
        m_scale.X(x);
        m_scale.Y(y);
    }


    bool TransformationComponent::ScaleChanged() const
    {
        return m_lastScale != m_scale;
    }


    Math::Vector2D TransformationComponent::GetScaleChange() const
    {
        return m_scale - m_lastScale;
    }


    Math::Vector2D TransformationComponent::GetScale() const
    {
        return m_scale;
    }


    void TransformationComponent::SetVelocity(const float x, const float y)
    {
        m_velocity.X(x);
        m_velocity.Y(y);
    }


    bool TransformationComponent::VelocityChanged() const
    {
        return m_lastVelocity != m_velocity;
    }


    Math::Vector2D TransformationComponent::GetVelocityChange() const
    {
        return m_velocity - m_lastVelocity;
    }


    Math::Vector2D TransformationComponent::GetVelocity() const
    {
        return m_velocity;
    }


} }
