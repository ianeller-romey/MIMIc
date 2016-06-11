
#ifndef DATAMODEL_TEXTSTYLEDESERIALIZER_H
#define DATAMODEL_TEXTSTYLEDESERIALIZER_H

// DataModel
#include "TextStyle.h"

// Utilities
#include "JsonDeserializer.h"


#define TEXTSTYLEDESERIALIZERINSTANCE MIMIc::DataModel::TextStyleDeserializer::INSTANCE()


namespace MIMIc { namespace DataModel {

    class TextStyleDeserializer : public Utilities::JsonDeserializer<std::string, TextStyle>
    {
        public:
            static TextStyleDeserializer& INSTANCE();

            virtual ~TextStyleDeserializer();

        private:
            TextStyleDeserializer();
            TextStyleDeserializer(const TextStyleDeserializer& rhs); // undefined; singleton
            TextStyleDeserializer& operator=(const TextStyleDeserializer& rhs); // undefined; singleton
            
            static TextStyleDeserializer* s_instance;

            virtual TextStyle Deserialize(const std::string& key) const;
    };

} }

#endif
