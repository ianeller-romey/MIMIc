
#ifndef GRAPHICS_SHADERDESERIALIZER_H
#define GRAPHICS_SHADERDESERIALIZER_H

// Graphics
#include "Shader.h"

// Utilities
#include "Deserializer.h"


#define TEXTTEXTUREDESERIALIZERINSTANCE MIMIc::Graphics::ShaderDeserializer::INSTANCE()


namespace MIMIc { namespace Graphics {

    class ShaderDeserializer : public Utilities::Deserializer<std::string, Shader>
    {
        public:
            static ShaderDeserializer& INSTANCE();

        private:
            ShaderDeserializer();
            ShaderDeserializer(const ShaderDeserializer& rhs); // undefined; singleton
            ShaderDeserializer& operator=(const ShaderDeserializer& rhs); // undefined; singleton
            
            static ShaderDeserializer* s_instance;

            virtual Shader Deserialize(const std::string& file) const override;
    };

} }

#endif
