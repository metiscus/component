#ifndef src_core_vector2_h_
#define src_core_vector2_h_

class Vector2
{
private:
    float x_;
    float y_;

public:
    Vector2(float x = 0, float y = 0);

    inline float& GetX() { return x_; }
    inline float& GetY() { return y_; }
    inline float GetX() const { return x_; }
    inline float GetY() const { return y_; }

    inline void SetX(const float& x) { x_ = x; }
    inline void SetY(const float& y) { y_ = y; }
    void Set(const float& x, const float& y);

    float Length() const;
    float Length2() const;

    Vector2 AsUnit() const;
    void ToUnit();

    bool IsUnit() const;

    Vector2 operator+(const Vector2& rhs) const;
    Vector2 operator-(const Vector2& rhs) const;
    Vector2 operator*(const float& rhs) const;
    Vector2 operator/(const float& rhs) const;

    Vector2& operator+=(const Vector2& rhs);
    Vector2& operator-=(const Vector2& rhs);
    Vector2& operator*=(const float& rhs);
    Vector2& operator/=(const float& rhs);

    friend Vector2 operator*(const float& lhs, const Vector2& rhs);

    float Dot(const Vector2& rhs) const;
    float ScalarProjection(const Vector2& rhs) const;
    Vector2 Projection(const Vector2& rhs) const;
};

Vector2 operator*(const float& lhs, const Vector2& rhs);


#endif
