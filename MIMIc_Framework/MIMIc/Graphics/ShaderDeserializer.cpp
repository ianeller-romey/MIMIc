
#include "ShaderDeserializer.h"

#include <string>   // std::string
#include <fstream>  // std::ifstream


namespace MIMIc { namespace Graphics {

    ShaderDeserializer* ShaderDeserializer::s_instance = 0;


    ShaderDeserializer& ShaderDeserializer::INSTANCE()
    {
        if(!s_instance)
            s_instance = new ShaderDeserializer();

        return *s_instance;
    }
    
    
    ShaderDeserializer::ShaderDeserializer()
    {
    }

    
    Shader ShaderDeserializer::Deserialize(const std::string& fileName) const
    {
        std::string shaderContent;

        std::ifstream file(fileName);
        if(file.is_open())
        {
            shaderContent = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
        }
        file.close();

        return Shader(shaderContent.c_str());
    }

} }
