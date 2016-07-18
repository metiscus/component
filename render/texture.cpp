#include "texture.h"

#include <cassert>
#include "glad/glad.h"
#include <GL/gl.h>
#include "image.h"

Texture::Texture()
    : texture_(0)
{
    glGenTextures(1, &texture_);
}

Texture::Texture(const Image& image)
    : texture_(0)
{
    glGenTextures(1, &texture_);
    Upload(image.GetData(), image.GetWidth(), image.GetHeight(), image.GetChannels());
}

Texture::~Texture()
{
    glDeleteTextures(1, &texture_);
}

void Texture::Upload(const std::vector<uint8_t>& data, uint32_t width, uint32_t height, uint32_t channels)
{
    uint32_t format = GL_RGBA;
    switch(channels)
    {
        case 1:
            format = GL_R8;
            break;
        case 2:
            format = GL_RG8;
            break;
        case 3:
            format = GL_RGB8;
            break;
        case 4:
            format = GL_RGBA8;
            break;
        default:
            assert(false);
    }
    
    assert(data.size() >= width*height*channels);

    // Get the currently bound texture
    int32_t orig_tex = 0;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &orig_tex);

    // Bind and update our texture
    glBindTexture(GL_TEXTURE_2D, texture_);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, &data[0]);

    // Restore the originally bound texture
    glBindTexture(GL_TEXTURE_2D, orig_tex);
}

void Texture::Bind(uint32_t unit)
{
    int32_t active_unit = GL_TEXTURE0;
    glGetIntegerv(GL_ACTIVE_TEXTURE, &active_unit);
    if((int32_t)(active_unit - GL_TEXTURE0) != unit)
    {
        glActiveTexture(unit);
    }
    glBindTexture(GL_TEXTURE_2D, texture_);
}

void Texture::SetFilterMode(FilterType type, FilterMode mode)
{
    int32_t orig_tex = 0;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &orig_tex);

    GLenum param;
    switch(type)
    {
        case Magnification:
            param =  GL_TEXTURE_MAG_FILTER;
            break;
        case Minification:
            param =  GL_TEXTURE_MIN_FILTER;
            break;
        default:
            assert(false);
    }

    GLenum value;
    switch(mode)
    {
        case Nearest:
            value = GL_NEAREST;
            break;
        case Linear:
            value = GL_LINEAR;
            break;
        case Mipmap_Nearest:
            value = GL_NEAREST_MIPMAP_NEAREST;
            break;
        case Linear_Mipmap_Nearest:
            value = GL_LINEAR_MIPMAP_NEAREST;
            break;
        case Nearest_Mipmap_Linear:
            value =  GL_NEAREST_MIPMAP_LINEAR;
            break;
        case Linear_Mipmap_Linear:
            value = GL_LINEAR_MIPMAP_LINEAR;
            break;
        default:
            assert(false);
    }
    SetTextureParameter(param, value);
}

void Texture::SetWrapMode(WrapType type, WrapMode mode)
{
    GLenum param;
    switch(type)
    {
        case WrapS:
            param =  GL_TEXTURE_WRAP_S;
            break;
        case WrapT:
            param =  GL_TEXTURE_WRAP_T;
            break;
        default:
            assert(false);
    }

    GLenum value;
    switch(mode)
    {
        case Clamp_To_Edge:
            value = GL_CLAMP_TO_EDGE;
            break;
        case Clamp_To_Border:
            value = GL_CLAMP_TO_BORDER;
            break;
        case Mirrored_Repeat:
            value = GL_MIRRORED_REPEAT;
            break;
        case Repeat:
            value = GL_REPEAT;
            break;
        case Mirror_Clamp_To_Edge:
            value = GL_MIRROR_CLAMP_TO_EDGE;
            break;
        default:
            assert(false);
    }
    SetTextureParameter(param, value);
}

void Texture::SetTextureParameter(uint32_t param, uint32_t value)
{
    int32_t orig_tex = 0;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &orig_tex);
    if(orig_tex != texture_)
    {
        glBindTexture(GL_TEXTURE_2D, texture_);
        glTexParameteri(GL_TEXTURE_2D, param, value);
        glBindTexture(GL_TEXTURE_2D, orig_tex);
    }
    else
    {
        glTexParameteri(GL_TEXTURE_2D, param, value);
    }
}
