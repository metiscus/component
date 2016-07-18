#include "sprite.h"

Sprite::Sprite()
    : current_frame_id_(0)
    , size_(0, 0)
    , is_enabled_(true)
{

}

Sprite::~Sprite()
{
    ;
}

void Sprite::SetSize(const Vector2& size)
{
    size_ = size;
}

void Sprite::SetTexture(TexturePtr tex)
{
    texture_ = tex;
}

void Sprite::AddFrame(const Rectangle& rect)
{
    frames_.push_back(rect);
}

const std::vector<Rectangle>& Sprite::GetFrames() const
{
    return frames_;
}

void Sprite::SetCurrentFrameId(uint32_t id)
{
    if(id > frames_.size())
    {
        id = frames_.size();
    }

    current_frame_id_ = id;
}

void Sprite::SetEnabled(bool enabled)
{
    is_enabled_ = enabled;
}

