
#ifndef GRAPHICS_TEXTTEXTUREDESERIALIZER_H
#define GRAPHICS_TEXTTEXTUREDESERIALIZER_H

#include "Deserializer.h"

#include "TextTexture.h"


#define TEXTTEXTUREDESERIALIZERINSTANCE MIMIc::Graphics::TextTextureDeserializer::INSTANCE()


namespace MIMIc { namespace Graphics {

    class TextTextureDeserializer : public Utilities::Deserializer<TextTexture>
    {
        public:
            static TextTextureDeserializer& INSTANCE();

            ~TextTextureDeserializer();

        private:
            TextTextureDeserializer();
            TextTextureDeserializer(const TextTextureDeserializer& rhs); // undefined; singleton
            TextTextureDeserializer& operator=(const TextTextureDeserializer& rhs); // undefined; singleton
            
            static TextTextureDeserializer* s_instance;
            static unsigned s_defaultTextureWidth;
            static unsigned s_defaultTextureHeight;
            static unsigned s_defaultTextureSize;

            virtual TextTexture Deserialize(const char* file) const;
    };

} }

#endif
