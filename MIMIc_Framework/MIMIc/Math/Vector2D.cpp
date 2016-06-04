
// Math
#include "Vector2D.h"
#include "Trig.h"

// std
#include <cmath>


namespace MIMIc { namespace Math {

    Vector2D::Vector2D() :
        m_x(0),
        m_y(0),
        m_normalized(NormalizationState::Unknown)
    {
    }


    Vector2D::Vector2D(const float x, const float y) :
        m_x(x),
        m_y(y),
        m_normalized(NormalizationState::Unknown)
    {
        CheckNormalized();
    }


    Vector2D::Vector2D(const float x, const float y, const NormalizationState normalized) :
        m_x(x),
        m_y(y)
    {
        CheckNormalized();
    }


    Vector2D::Vector2D(const Vector2D& rhs) :
        m_x(rhs.m_x),
        m_y(rhs.m_y),
        m_normalized(rhs.m_normalized)
    {
    }


    Vector2D& Vector2D::operator=(const Vector2D& rhs)
    {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
        m_normalized = rhs.m_normalized;

        return *this;
    }


    bool Vector2D::operator==(const Vector2D& other) const
    {
        return m_x == other.m_x && m_y == other.m_y;
    }


    bool Vector2D::operator!=(const Vector2D& other) const
    {
        return m_x != other.m_x || m_y != other.m_y;
    }


    float Vector2D::operator*(const Vector2D& other) const
    {
        return (m_x * other.m_x) + (m_y * other.m_y);
    }


    Vector2D Vector2D::operator*(const float scalar) const
    {
        return Scale(scalar);
    }


    Vector2D& Vector2D::operator*=(const float scalar)
    {
        return ScaleAndAssign(scalar);
    }


    Vector2D Vector2D::operator+(const Vector2D& translator) const
    {
        return Translate(translator.m_x, translator.m_y);
    }


    Vector2D& Vector2D::operator+=(const Vector2D& translator)
    {
        return TranslateAndAssign(translator.m_x, translator.m_y);
    }


    Vector2D Vector2D::operator-(const Vector2D& translator) const
    {
        return Translate(-translator.m_x, -translator.m_y);
    }


    Vector2D& Vector2D::operator-=(const Vector2D& translator)
    {
        return TranslateAndAssign(-translator.m_x, -translator.m_y);
    }


    Vector2D Vector2D::Translate(const float translatorX, const float translatorY) const
    {
        return Vector2D(m_x + translatorX, m_y + translatorY, ShouldCheckNormalized());
    }


    Vector2D& Vector2D::TranslateAndAssign(const float translatorX, const float translatorY)
    {
        m_x += translatorX;
        m_y += translatorY;
        CheckNormalized();
        return *this;
    }


    Vector2D Vector2D::Rotate(const float originX, const float originY, const float theta) const
    {
        auto translated = Translate(-originX, -originY);
        Vector2D rotated(translated.m_x * Cosine(theta) - translated.m_y * Sine(theta), translated.m_x * Sine(theta) + translated.m_y * Cosine(theta), ShouldCheckNormalized());
        return rotated.Translate(originX, originY);
    }


    Vector2D& Vector2D::RotateAndAssign(const float originX, const float originY, const float theta)
    {
        auto translated = Translate(-originX, -originY);
        Vector2D rotated(translated.m_x * Cosine(theta) - translated.m_y * Sine(theta), translated.m_x * Sine(theta) + translated.m_y * Cosine(theta), ShouldCheckNormalized());
        *this = rotated.Translate(originX, originY);
        return *this;
    }


    Vector2D Vector2D::Scale(const float scalar) const
    {
        return Vector2D(m_x * scalar, m_y * scalar, ShouldCheckNormalized());
    }


    Vector2D& Vector2D::ScaleAndAssign(const float scalar)
    {
        m_x *= scalar;
        m_y *= scalar;
        CheckNormalized();
        return *this;
    }


    bool Vector2D::IsNormalized() const
    {
        if(m_normalized >= NormalizationState::Unknown)
            m_normalized = (MagnitudeSq() == 1) ? NormalizationState::YesNormalized : NormalizationState::NotNormalized;
        return m_normalized;
    }


    Vector2D Vector2D::ToPerpendicular() const
    {
        return Vector2D(-m_y, m_x, m_normalized);
    }


    float Vector2D::DistanceSq(const Vector2D& other) const
    {
        auto xDist = m_x - other.m_x;
        auto yDist = m_y - other.m_y;
        return (xDist * xDist) + (yDist * yDist);
    }


    float Vector2D::Distance(const Vector2D& other) const
    {
        return sqrt(DistanceSq(other));
    }


    float Vector2D::MagnitudeSq() const
    {
        return (*this) * (*this);
    }


    float Vector2D::Magnitude() const
    {
        return sqrt(MagnitudeSq());
    }


    Vector2D& Vector2D::Normalize()
    {
        if (m_normalized != NormalizationState::YesNormalized) { 
            auto mag = Magnitude();
            if (mag != 0) {
                m_x = m_x / mag;
                m_y = m_y / mag;
                m_normalized = NormalizationState::YesNormalized;
            }
        }

        return *this;
    }


    void Vector2D::CheckNormalized()
    {
        if(m_normalized == NormalizationState::Unknown)
            m_normalized = (IsNormalized()) ? NormalizationState::YesNormalized : NormalizationState::NotNormalized;
    }


    Vector2D::NormalizationState Vector2D::ShouldCheckNormalized() const
    {
        return (m_normalized == NormalizationState::Ignored) ? NormalizationState::Ignored : NormalizationState::Unknown;
    }


    float Vector2D::X() const
    {
        return m_x;
    }


    void Vector2D::X(const float x)
    {
        m_x = x;
    }


    float Vector2D::Y() const
    {
        return m_y;
    }


    void Vector2D::Y(const float y)
    {
        m_y = y;
    }

} }
