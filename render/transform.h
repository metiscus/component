#ifndef src_core_transform_cc_
#define src_core_transform_cc_

#include "matrix3.h"
#include "vector2.h"

class Transform
{
private:
    Matrix3 matrix_;

public:
    Transform();
    
    void SetPosition(const Vector2& pos);
    Vector2 GetPosition() const;

    void SetOrientation(const float& degrees);
    float GetOrientation() const;


    inline Matrix3& GetMatrix() { return matrix_; }
    const Matrix3& GetMatrix() const { return matrix_; }
    void SetMatrix(const Matrix3& rhs);

    Transform Apply(const Transform& rhs) const;
};

#endif
