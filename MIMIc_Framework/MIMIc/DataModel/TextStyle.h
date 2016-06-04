
#ifndef DATAMODEL_TEXTSTYLE_H
#define DATAMODEL_TEXTSTYLE_H

// DataModel
#include "TextStyleType.h"

// std
#include <vector>
#include <string>


namespace MIMIc { namespace DataModel {

    class TextStyle
    {
        public:
            TextStyle();
            TextStyle(const TextStyle& rhs);
            ~TextStyle();

            TextStyle& operator=(const TextStyle& rhs);

            const char* const GetStyle() const;
            
            void AddTextStyleType(const TextStyleType& type);
            TextStyleType GetTextStyleType(const char* const type) const;

        private:
            std::string m_style;
            std::vector<TextStyleType> m_types;
    };

} }

#endif
