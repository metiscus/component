#include "rectangle.h"
#include <algorithm>

Rectangle::Rectangle()
{
    
}

Rectangle::Rectangle(const Vector2& center, const Vector2& extents)
    : center_(center)
    , extents_(extents)
{
    UpdateMinMax();
}

Rectangle::Rectangle(float x, float y, float w, float h)
    : center_(x, y)
    , extents_(w, h)
{
    UpdateMinMax();
}

void Rectangle::SetCenter(const Vector2& center)
{
    center_ = center;
    UpdateMinMax();
}

void Rectangle::SetExtents(const Vector2& extents)
{
    extents_ = extents;
    UpdateMinMax();
}

void Rectangle::ExpandBy(const Rectangle& other)
{
    Vector2 other_max = other.GetMax();
    max_.SetX(std::max(max_.GetX(), other_max.GetX()));
    max_.SetY(std::max(max_.GetY(), other_max.GetY()));
    
    Vector2 other_min = other.GetMax();
    min_.SetX(std::min(min_.GetX(), other_min.GetX()));
    min_.SetY(std::min(min_.GetY(), other_min.GetY()));

    // Recompute center from min/max
    center_  = 0.5f*(max_ + min_);
    extents_ = max_ - min_;
}


bool Rectangle::ContainsPoint(const Vector2& point) const
{
    if(point.GetX() < min_.GetX()) return false;
    if(point.GetX() > max_.GetX()) return false;
    if(point.GetY() < min_.GetY()) return false;
    if(point.GetY() > max_.GetY()) return false;
    return true;
}

bool Rectangle::Intersects(const Rectangle& other) const
{
    return !( min_.GetX() > other.min_.GetX()
        || max_.GetX() < other.min_.GetX()
        || max_.GetY() > other.min_.GetY()
        || min_.GetY() < other.max_.GetY()
    );
}

void Rectangle::Reset()
{
    center_.Set(0.0f, 0.0f);
    extents_.Set(0.0f, 0.0f);
    min_.Set(0.0f, 0.0f);
    max_.Set(0.0f, 0.0f);
}

void Rectangle::UpdateMinMax()
{
    min_ = center_ - 0.5f * extents_;
    max_ = center_ + 0.5f * extents_;
}
