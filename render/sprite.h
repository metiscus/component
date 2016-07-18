#ifndef src_core_sprite_h_
#define src_core_sprite_h_

#include <cstdint>
#include "node.h"
#include "texture.h"
#include "rectangle.h"
#include "vector2.h"
#include <vector>

class Sprite : public Node
{
private:
    TexturePtr texture_;
    std::vector<Rectangle> frames_;
    uint32_t current_frame_id_;
    Vector2 size_;
    bool is_enabled_;

public:
    Sprite();
    virtual ~Sprite();

    void SetSize(const Vector2& size);
    inline const Vector2& GetSize() const { return size_; }

    void SetTexture(TexturePtr tex);
    inline TexturePtr GetTexture() { return texture_; }

    void AddFrame(const Rectangle& rect);
    const std::vector<Rectangle>& GetFrames() const;
    void SetCurrentFrameId(uint32_t id);
    inline uint32_t GetCurrentFrameId() const { return current_frame_id_; }

    void SetEnabled(bool enabled);
    inline bool GetEnabled() const { return is_enabled_; }
};


#endif
