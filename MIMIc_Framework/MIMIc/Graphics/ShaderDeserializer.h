
#ifndef GRAPHICS_SHADERDESERIALIZER_H
#define GRAPHICS_SHADERDESERIALIZER_H

#include "Deserializer.h"

#include "Shader.h"


#define TEXTTEXTUREDESERIALIZERINSTANCE MIMIc::Graphics::ShaderDeserializer::INSTANCE()


namespace MIMIc { namespace Graphics {

    class ShaderDeserializer : public Utilities::Deserializer<Shader>
    {
        public:
            static ShaderDeserializer& INSTANCE();

        private:
            ShaderDeserializer();
            ShaderDeserializer(const ShaderDeserializer& rhs); // undefined; singleton
            ShaderDeserializer& operator=(const ShaderDeserializer& rhs); // undefined; singleton
            
            static ShaderDeserializer* s_instance;

            virtual Shader Deserialize(const char* file) const;
    };

} }

#endif
