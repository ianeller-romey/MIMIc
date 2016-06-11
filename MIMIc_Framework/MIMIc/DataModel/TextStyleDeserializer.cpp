
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
        bool success = true;
        char characterWidth, characterHeight;
        TextStyle ts;

        success = Start(key.c_str());
        success = ReadObjectStart(0, 0);
        
        success = ReadNamedBinaryValue<char>(0, 0, &characterWidth);
        success = ReadNamedBinaryValue<char>(0, 0, &characterHeight);

        success = ReadArrayStart(0, 0);

        bool continueOn = true;
        do
        {
            TextStyleType tst;
            char* tstType;

            success = ReadObjectStart(0, 0);

            success = ReadNamedStringValue(0, 0, &tstType, 0);
            tst.m_type = tstType;

            success = ReadArrayStart(0, 0);

            bool continueOn2 = true;
            do
            {
                TextStyleTypeCharacter tstc;

                success = ReadObjectStart(0, 0);

                success = ReadNamedBinaryValue<char>(0, 0, &tstc.m_x);
                success = ReadNamedBinaryValue<char>(0, 0, &tstc.m_y);

                success = ReadArrayStart(0, 0);

                CHARACTERDATA* tstcData = new CHARACTERDATA[characterWidth * characterHeight];
                for(char i = 0; i < characterHeight; ++i)
                {
                    success = ReadBinaryValueWithLength(characterWidth, tstcData + (characterWidth * i));
                    success = AdvanceLine();
                }
                tstc.m_data = tstcData;

                success = ReadArrayEnd();

                success = ReadObjectEnd();

                tst.m_characters.push_back(tstc);

                if(!ReadNextArray(continueOn2))
                    throw; // TODO
            } while(continueOn2);

            success = ReadArrayEnd();

            success = ReadObjectEnd();

            ts.m_types.push_back(tst);

            if(!ReadNextArray(continueOn))
                throw; // TODO
        } while(continueOn);
    }

} }
