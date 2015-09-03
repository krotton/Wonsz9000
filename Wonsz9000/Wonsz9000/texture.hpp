// Wonsz9000 - texture loading

#pragma once

class Texture
{

public:
    // Load the texture from a PNG file.
    Texture(std::string const& filename);
    
    // Make the texture active.
    inline void bind() const
    {
        glBindTexture(GL_TEXTURE_2D, texture_id);
    }
    
    // Make the texture inactive.
    inline void unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

public: // exceptions
    struct Error : public std::exception
    {
        Error(std::string const& filename, std::string const& msg):
            filename(filename), msg(msg)
        {}
        
        char const* what() const noexcept
        {
            return ("Could not load texture: " + filename + ". " + msg).c_str();
        }
        
    private:
        std::string const filename, msg;
    };
    
    struct LoadError : Error
    {
        LoadError(std::string const& filename): Error(filename, "No such file!") {}
    };
    
    struct SizeError : Error
    {
        SizeError(std::string const& filename, unsigned width, unsigned height):
            Error(filename,
                  "File has inappropriate dimensions: " +
                    std::to_string(width) + "x" + std::to_string(height) + "!") {}
    };
    
private:
    GLuint texture_id;
    
    std::vector<unsigned char> image_data;
    unsigned img_w, img_h;
};
