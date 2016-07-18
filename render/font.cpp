#include "font.h"

#define STB_TRUETYPE_IMPLEMENTATION
#include "font_imp.h"

#include "core/log.h"
#include <cstdint>
#include <vector>

Font::Font()
{

}

bool Font::Load(const char* filename, float height)
{
    std::vector<char> ttf;
    ttf.resize(1<<20);
    FILE*fp = fopen(filename, "rb");
    if(!fp)
    {
        log_error("Font::FontLoad(%s) unable to open file.", filename);
        return false;
    }
    
    //load the font file
    fread(&ttf[0], 1, 1<<20, fp);
    fclose(fp);
    
    std::vector<uint8_t> temp_bitmap;
    temp_bitmap.resize(512*512);
    stbtt_BakeFontBitmap((const unsigned char*)&ttf[0], 0, height, &temp_bitmap[0], 512, 512, 32, 96, &glyphs_[0]);
    ttf.resize(0);

    texture_ = std::make_shared<Texture>();
    texture_->Upload(temp_bitmap, 512, 512, 1);
    temp_bitmap.resize(0);
    return true;
}

bool Font::Load(const std::string& filename, float height)
{
    return Load(filename.c_str(), height);
}
