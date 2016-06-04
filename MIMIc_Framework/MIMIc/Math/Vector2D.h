
#ifndef MATH_VECTOR2D_H
#define MATH_VECTOR2D_H

namespace MIMIc { namespace Math {

    class Vector2D
    {
        public:
            enum NormalizationState
            {
                YesNormalized,
                NotNormalized,
                Unknown,
                Ignored,

                INVALID
            };

            Vector2D();
            Vector2D(const float x, const float y);
            Vector2D(const float x, const float y, const NormalizationState normalized);
            Vector2D(const Vector2D& rhs);

            Vector2D& operator=(const Vector2D& rhs);

            bool operator==(const Vector2D& other) const;
            bool operator!=(const Vector2D& other) const;

            float operator*(const Vector2D& other) const;

            Vector2D operator*(const float scalar) const;
            Vector2D& operator*=(const float scalar);

            Vector2D operator+(const Vector2D& translator) const;
            Vector2D& operator+=(const Vector2D& translator);

            Vector2D operator-(const Vector2D& translator) const;
            Vector2D& operator-=(const Vector2D& translator);

            Vector2D Translate(const float translatorX, const float translatorY) const;
            Vector2D& TranslateAndAssign(const float translatorX, const float translatorY);

            Vector2D Rotate(const float originX, const float originY, const float theta) const;
            Vector2D& RotateAndAssign(const float originX, const float originY, const float theta);

            Vector2D Scale(const float scalar) const;
            Vector2D& ScaleAndAssign(const float scalar);

            bool IsNormalized() const;

            Vector2D ToPerpendicular() const;

            float DistanceSq(const Vector2D& other) const;
            float Distance(const Vector2D& other) const;
            float MagnitudeSq() const;
            float Magnitude() const;
            Vector2D& Normalize();

            float X() const;
            void X(const float x);

            float Y() const;
            void Y(const float y);

        private:
            float m_x,
                  m_y;
            mutable NormalizationState m_normalized;

            void CheckNormalized();
            NormalizationState ShouldCheckNormalized() const;
    };

} }

#endif
