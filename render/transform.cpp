#include "transform.h"
#include <cmath>

Transform::Transform()
{

}
    
void Transform::SetPosition(const Vector2& pos)
{
    matrix_(2,0) = pos.GetX();
    matrix_(2,1) = pos.GetY();
}

Vector2 Transform::GetPosition() const
{
    return Vector2(matrix_(2,0), matrix_(2,1));
}

void Transform::SetOrientation(const float& degrees)
{
    constexpr float deg_to_rad = M_PI_2 / 90.0;
    const float angle = degrees * deg_to_rad;
    matrix_[0] = cosf(angle);
    matrix_[1] = -sinf(angle);
    matrix_[3] = sinf(angle);
    matrix_[4] = cosf(angle);
}

float Transform::GetOrientation() const
{
    constexpr float rad_to_deg = 90.0f / M_PI_2;
    return rad_to_deg * atan2(matrix_[3], matrix_[0]);
}

void Transform::SetMatrix(const Matrix3& rhs)
{
    matrix_ = rhs;
}

Transform Transform::Apply(const Transform& rhs) const
{
    Transform t;
    t.matrix_ = matrix_ * rhs.matrix_;
    return t;
}
