#ifndef src_core_camera_h_
#define src_core_camera_h_

#include "rectangle.h"
#include "vector2.h"

class Camera
{
private:
    Rectangle view_;

public:
    Camera();

    void SetView(const Rectangle& view);
    inline const Rectangle& GetView() const { return view_; }

    void SetViewCenter(const Vector2& center);
    void SetViewExtents(const Vector2& extents);
    void MoveView(const Vector2& offset);

};

#endif
