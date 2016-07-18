#pragma once

#include <cstdint>
#include <memory>
#include <vector>

class Image;

class Texture
{
public:
    Texture();
    Texture(const Image&);
    ~Texture();

    enum FilterType
    {
        Minification,
        Magnification
    };

    enum FilterMode
    {
        Nearest,
        Linear,
        Mipmap_Nearest,
        Linear_Mipmap_Nearest,
        Nearest_Mipmap_Linear,
        Linear_Mipmap_Linear
    };

    enum WrapType
    {
        WrapS,
        WrapT
    };
    
    enum WrapMode
    {
        Clamp_To_Edge,
        Clamp_To_Border,
        Mirrored_Repeat,
        Repeat,
        Mirror_Clamp_To_Edge
    };

    Texture(const Texture&) = delete;
    Texture& operator=(Texture& rhs) = delete;
    
    void Upload(const std::vector<uint8_t>& data, uint32_t width, uint32_t height, uint32_t channels);
    void Bind(uint32_t unit);
    void SetFilterMode(FilterType type, FilterMode mode);
    
    void SetWrapMode(WrapType type, WrapMode mode);

private:
    uint32_t texture_;
    
    void SetTextureParameter(uint32_t param, uint32_t value);
};

typedef std::shared_ptr<Texture> TexturePtr;
