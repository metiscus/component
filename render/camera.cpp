#include "camera.h"

Camera::Camera()
{

}

void Camera::SetView(const Rectangle& view)
{
    view_ = view;
}

void Camera::SetViewCenter(const Vector2& center)
{
    view_.SetCenter(center);
}

void Camera::SetViewExtents(const Vector2& extents)
{
    view_.SetExtents(extents);
}

void Camera::MoveView(const Vector2& offset)
{
    Vector2 center = view_.GetCenter();
    center += offset;
    view_.SetCenter(center);
}
