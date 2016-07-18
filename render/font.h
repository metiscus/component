#ifndef src_core_font_h_
#define src_core_font_h_

#include <array>

#define STBTT_DEF extern
#include "font_imp.h"

#include "texture.h"
#include <memory>
#include <string>

class Font
{
private:
    std::array<stbtt_bakedchar, 96> glyphs_;
    TexturePtr texture_;

public:
    Font();
    bool Load(const char* filename, float height);
    bool Load(const std::string& filename, float height);

    inline TexturePtr GetTexture() { return texture_; };
};

#endif
