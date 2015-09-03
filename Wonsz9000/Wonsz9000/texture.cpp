// Wonsz9000 - texture loading.

#include "lib/lodepng/lodepng.h"

#include "texture.hpp"

inline bool is_power_of_two(unsigned v)
{
    return v && !(v & (v - 1));
}

Texture::Texture(std::string const& filename)
{
    auto const error = lodepng::decode(image_data, img_w, img_h, filename);
    
    if (error)
    {
        throw Texture::LoadError(filename);
    }
    
    if (!is_power_of_two(img_w) || !is_power_of_two(img_h))
    {
        throw Texture::SizeError(filename, img_w, img_h);
    }
    
    glGenTextures(1, &texture_id);
    
    glBindTexture(GL_TEXTURE_2D, texture_id);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img_w, img_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image_data[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, 0);
}
