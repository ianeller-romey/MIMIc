
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

    TextStyle TextStyleDeserializer::Deserialize(const std::string& key) const
    {
        char characterWidth, characterHeight;
        TextStyle ts;

        Start(key.c_str());
        ReadObjectStart(0, 0);
        
        ReadNamedBinaryValue<char>(0, 0, &characterWidth);
        ReadNamedBinaryValue<char>(0, 0, &characterHeight);

        ReadArrayStart(0, 0);

        bool continueOn = true;
        do
        {
            TextStyleType tst;
            char* tstType;

            ReadObjectStart(0, 0);

            ReadNamedStringValue(0, 0, &tstType, 0);
            tst.m_type = tstType;

            ReadArrayStart(0, 0);

            bool continueOn2 = true;
            do
            {
                TextStyleTypeCharacter tstc;

                ReadObjectStart(0, 0);

                ReadNamedBinaryValue<char>(0, 0, &tstc.m_x);
                ReadNamedBinaryValue<char>(0, 0, &tstc.m_y);

                ReadArrayStart(0, 0);

                CHARACTERDATA* tstcData = new CHARACTERDATA[characterWidth * characterHeight];
                for(char i = 0; i < characterHeight; ++i)
                {
                    ReadBinaryValueWithLength(characterWidth, tstcData + (characterWidth * i));
                    AdvanceLine();
                }
                tstc.m_data = tstcData;

                ReadArrayEnd();

                ReadObjectEnd();

                tst.m_characters.push_back(tstc);

                if(!ReadNextArray(continueOn2))
                    throw; // TODO
            } while(continueOn2);

            ReadArrayEnd();

            ReadObjectEnd();

            ts.m_types.push_back(tst);

            if(!ReadNextArray(continueOn))
                throw; // TODO
        } while(continueOn);
    }

} }
