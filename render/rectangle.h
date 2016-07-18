#pragma once

#include "vector2.h"

class Rectangle
{
public:
    Rectangle();
    Rectangle(const Vector2& center, const Vector2& extents);
    Rectangle(float x, float y, float w, float h);
    void SetCenter(const Vector2& center);
    void SetExtents(const Vector2& extents);
    void ExpandBy(const Rectangle& other);
    inline const Vector2& GetCenter() const { return center_; }
    inline const Vector2& GetExtents() const { return extents_; }
    inline const Vector2& GetMin() const { return min_; }
    inline const Vector2& GetMax() const { return max_; }

    bool ContainsPoint(const Vector2& point) const;
    bool Intersects(const Rectangle& other) const;

    void Reset();
private:
    Vector2 center_;
    Vector2 extents_;
    Vector2 min_;
    Vector2 max_;

    void UpdateMinMax();
};
