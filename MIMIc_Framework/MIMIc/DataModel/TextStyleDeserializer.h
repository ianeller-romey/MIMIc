
#ifndef GRAPHICS_TEXTSTYLEDESERIALIZER_H
#define GRAPHICS_TEXTSTYLEDESERIALIZER_H

// DataModel
#include "TextStyle.h"

// Utilities
#include "Deserializer.h"


#define TEXTSTYLEDESERIALIZERINSTANCE MIMIc::DataModel::TextStyleDeserializer::INSTANCE()


namespace MIMIc { namespace DataModel {

    class TextStyleDeserializer : public Utilities::Deserializer<TextStyle>
    {
        public:
            static TextStyleDeserializer& INSTANCE();

            ~TextStyleDeserializer();

        private:
            TextStyleDeserializer();
            TextStyleDeserializer(const TextStyleDeserializer& rhs); // undefined; singleton
            TextStyleDeserializer& operator=(const TextStyleDeserializer& rhs); // undefined; singleton
            
            static TextStyleDeserializer* s_instance;
            static unsigned s_defaultTextureWidth;
            static unsigned s_defaultTextureHeight;
            static unsigned s_defaultTextureSize;

            virtual TextStyle Deserialize(const char* file) const;
    };

} }

#endif
