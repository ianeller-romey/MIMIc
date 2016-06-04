
#include "TextTextureDeserializer.h"

#include <string>   // std::string
#include <fstream>  // std::ifstream


namespace MIMIc { namespace Graphics {

    TextTextureDeserializer* TextTextureDeserializer::s_instance = NULL;

    unsigned TextTextureDeserializer::s_defaultTextureSize = 19 * 32;


    TextTextureDeserializer& TextTextureDeserializer::INSTANCE()
    {
        if(!s_instance)
            s_instance = new TextTextureDeserializer();

        return *s_instance;
    }


    TextTextureDeserializer::~TextTextureDeserializer()
    {
        for(auto begin = m_cache.begin(), end = m_cache.end(); begin != end; ++begin)
        {
            auto textureBytes = begin->second.GetTextureForEditing();
            delete textureBytes;
        }
    }
    
    
    TextTextureDeserializer::TextTextureDeserializer()
    {
    }

    
    TextTexture TextTextureDeserializer::Deserialize(const char* fileName) const
    {
        std::string textureBytes;
        textureBytes.reserve(s_defaultTextureSize);

        std::ifstream file(fileName);
        int textureWidth = 0,
            textureHeight = 0;
        if(file.is_open())
        {
            std::string line;
            while(std::getline(file, line))
            {
                textureBytes.append(line);

                if(textureWidth != 0 && textureWidth != line.length())
                    // Width needs to be uniform
                    throw; // TODO
                else
                    textureWidth = line.length();

                ++textureHeight;
            }
        }
        file.close();

        TEXTTEXTURECHAR* textureBytesFinal = new TEXTTEXTURECHAR[textureBytes.size()];
        for(int i = 0, j = textureBytes.size(); i < j; ++i)
            textureBytesFinal[i] = (textureBytes[i] - 48); // lazy ATOI
        return TextTexture(textureBytesFinal, textureWidth, textureHeight);
    }

} }
