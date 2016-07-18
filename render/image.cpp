#include "image.h"
#include "core/log.h"
#include <cstdio>
#include <iterator>

#define STB_IMAGE_IMPLEMENTATION
#include "image.inl"

Image::Image()
    : width_(0)
    , height_(0)
    , channels_(0)
{
}

Image::Image(const std::string& filename)
    : width_(0)
    , height_(0)
    , channels_(0)
{
    LoadFile(filename);
}

Image::~Image()
{
    
}

bool Image::LoadFile(const std::string& filename)
{
    uint8_t *pixels = (uint8_t*)stbi_load(filename.c_str(), (int*)&width_, (int*)&height_, (int*)&channels_, 4);
    if(!pixels)
    {
        log_error("Image::LoadFile(%s) failed to load\n", filename.c_str());
        return false;
    }
    else
    {
        data_.clear();
        std::copy(pixels, pixels+width_*height_*channels_*sizeof(uint8_t), std::back_inserter(data_));
        stbi_image_free(pixels);
    }

    return true;
}

uint32_t Image::GetWidth() const
{
    return width_;
}

uint32_t Image::GetHeight() const
{
    return height_;
}

uint32_t Image::GetChannels() const
{
    return channels_;
}

const std::vector<uint8_t>& Image::GetData() const
{
    return data_;
}

void Image::CopyData(std::vector<uint8_t>& data) const
{
    data = data_;
}

const uint32_t Image::GetSize() const
{
    return data_.size() + sizeof(Image);
}
