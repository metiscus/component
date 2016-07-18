#ifndef src_core_matrix3_h_
#define src_core_matrix3_h_

#include <cstdint>
#include "vector2.h"


class Matrix3
{
private:
    float m_[9];

public:
    Matrix3();
    Matrix3(const float* ptr);

    Matrix3 operator*(const Matrix3& rhs) const;
    Vector2 operator*(const Vector2& rhs) const;

    Matrix3 Transpose() const;
    void ToTranspose();

    float Determinate() const;
    float Trace() const;

    float& operator[](const uint32_t& idx);
    const float& operator[](const uint32_t& idx) const;
    float& operator()(const uint32_t& x, const uint32_t& y);
    const float& operator()(const uint32_t& x, const uint32_t& y) const;

    static Matrix3 Translate(const Vector2& pos);
    static Matrix3 Scale(const Vector2& scale);
    static Matrix3 Rotate(const float& degrees);
    static Matrix3 Identity();
};


#endif
