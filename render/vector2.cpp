#include "vector2.h"
#include <cfloat>
#include <cmath>

Vector2::Vector2(float x, float y)
    : x_(x)
    , y_(y)
{
    ;
}

void Vector2::Set(const float& x, const float& y)
{
    x_ = x;
    y_ = y;
}

float Vector2::Length() const
{
    return sqrtf(x_*x_+y_*y_);
}

float Vector2::Length2() const
{
    return (x_*x_+y_*y_);
}

Vector2 Vector2::AsUnit() const
{
    const float mag = 1.0f / (Length() + FLT_EPSILON);
    return Vector2(x_*mag, y_*mag);
}

void Vector2::ToUnit()
{
    const float mag = 1.0f / (Length() + FLT_EPSILON);
    x_ *= mag;
    y_ *= mag;
}

bool Vector2::IsUnit() const
{
    const float mag = 1.0f / (Length() + FLT_EPSILON);
    return (fabs(mag - 1.0) < FLT_EPSILON);
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
    return Vector2(x_+rhs.x_, y_+rhs.y_);
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
    return Vector2(x_-rhs.x_, y_-rhs.y_);
}

Vector2 Vector2::operator*(const float& rhs) const
{
    return Vector2(x_*rhs, y_*rhs);
}

Vector2 Vector2::operator/(const float& rhs) const
{
    return Vector2(x_/rhs, y_/rhs);
}


Vector2& Vector2::operator+=(const Vector2& rhs)
{
    x_ += rhs.x_;
    y_ += rhs.y_;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    return *this;
}

Vector2& Vector2::operator*=(const float& rhs)
{
    x_ *= rhs;
    y_ *= rhs;
    return *this;
}

Vector2& Vector2::operator/=(const float& rhs)
{
    x_ /= rhs;
    y_ /= rhs;
    return *this;
}

Vector2 operator*(const float& lhs, const Vector2& rhs)
{
    return rhs * lhs;
}

float Vector2::Dot(const Vector2& rhs) const
{
    return x_*rhs.x_+y_*rhs.y_;
}

float Vector2::ScalarProjection(const Vector2& rhs) const
{
    return Dot(rhs) / rhs.Length();
}

Vector2 Vector2::Projection(const Vector2& rhs) const
{
    return (Dot(rhs) / rhs.Dot(rhs)) * rhs;
}
