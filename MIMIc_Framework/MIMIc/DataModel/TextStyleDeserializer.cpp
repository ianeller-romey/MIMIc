
// DataModel
#include "TextStyleDeserializer.h"


namespace MIMIc { namespace DataModel {

    TextStyleDeserializer* TextStyleDeserializer::s_instance = NULL;


    TextStyleDeserializer& TextStyleDeserializer::INSTANCE()
    {
        if(!s_instance)
            s_instance = new TextStyleDeserializer();

        return *s_instance;
    }


    TextStyleDeserializer::~TextStyleDeserializer()
    {
        for(auto begin = m_cache.begin(), end = m_cache.end(); begin != end; ++begin)
        {
            // TODO: 
            // Delete dynamically allocated EVERYTHING 
        }
    }
    
    
    TextStyleDeserializer::TextStyleDeserializer()
    {
    }

    
    TextStyle TextStyleDeserializer::Deserialize(const std::string& fileName) const
    {
        
    }

} }
