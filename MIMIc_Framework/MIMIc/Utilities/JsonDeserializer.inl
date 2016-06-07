
namespace MIMIc { namespace Utilities {

    template <typename KEYTYPE, typename VALUETYPE>
    static std::string JsonDeserializer<KEYTYPE, VALUETYPE>::s_openObject = "{";

    template <typename KEYTYPE, typename VALUETYPE>
    static std::string JsonDeserializer<KEYTYPE, VALUETYPE>::s_closeObject = "}";

    template <typename KEYTYPE, typename VALUETYPE>
    static std::string JsonDeserializer<KEYTYPE, VALUETYPE>::s_openArray = "[";

    template <typename KEYTYPE, typename VALUETYPE>
    static std::string JsonDeserializer<KEYTYPE, VALUETYPE>::s_closeArray = "]";

    template <typename KEYTYPE, typename VALUETYPE>
    static std::string JsonDeserializer<KEYTYPE, VALUETYPE>::s_objectDelimiter = ",";

    template <typename KEYTYPE, typename VALUETYPE>
    static std::string JsonDeserializer<KEYTYPE, VALUETYPE>::s_stringDelimiter = "\"";


    template <typename KEYTYPE, typename VALUETYPE>
    JsonDeserializer<KEYTYPE, VALUETYPE>::JsonDeserializer()
    {
    }

    
    template <typename KEYTYPE, typename VALUETYPE>
    JsonDeserializer<KEYTYPE, VALUETYPE>::JsonDeserializer(const JsonDeserializer<T>& rhs) :
        m_cache(rhs.m_cache),
        m_fstream(rhs.m_fstream)
    {
    }


    template <typename KEYTYPE, typename VALUETYPE>
    JsonDeserializer<KEYTYPE, VALUETYPE>::~JsonDeserializer()
    {
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::Start(const char* const fileName)
    {
        m_fstream.open(fileName, std::ios_base::in);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::End()
    {
        m_fstream.close();
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::ReadObjectStart(char** name)
    {
        if(name)
            ReadName(name);
        
        char c;
        while(m_fstream.get(&c, 1) != m_fstream.eof() && c != *s_openObject) ;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::ReadObjectEnd()
    {
        char c;
        while(m_fstream.get(&c, 1) != m_fstream.eof() && c != *s_closeObject) ;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::ReadArrayStart(char** name)
    {
        if(name)
            ReadName(name);
        
        char c;
        while(m_fstream.get(&c, 1) != m_fstream.eof() && c != *s_openArray) ;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::ReadArrayEnd()
    {
        char c;
        while(m_fstream.get(&c, 1) != m_fstream.eof() && c != *s_closeArray) ;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::ReadNamedStringValue(char** name, char** value)
    {
        ReadString(name);
        ReadString(value);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::ReadNamedBinaryValue(char** name, char** value)
    {
        ReadString(name);
        ReadToDelimiter(value, *s_objectDelimiter, false);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::ReadBinaryValue(const unsigned length, char** value)
    {
        *value = new char[length];
        m_fstream.get(*value, length);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::ReadString(char** value)
    {
        // read to first string delimiter
        char c = 0;
        while(c != *s_stringDelimiter)
            m_fstream.get(&c, 1);

        ReadToDelimiter(value, *s_stringDelimiter, true);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::ReadToDelimiter(char** value, const char delimiter, bool isString)
    {
        unsigned valueLength = 0;
        char c;

        // save position
        auto position = m_fstream.tellg();

        // read length of value
        c = 0;
        while(m_fstream.get(&c, 1) != m_fstream.eof() && c != delimiter)
            ++valueLength;

        // reset position
        m_fstream.seekg(position);
        
        // read value
        if(valueLength)
        {
            // reserve space for a null termination character if we're reading a string
            *value = new char[valueLength + (isString) ? 1 : 0];

            valueLength = 0;
            c = 0;
            while(m_fstream.get(&c, 1) != m_fstream.eof() && c != delimiter)
            {
                (*value)[valueLength] = c;
                ++valueLength;
            }

            if(isString)
                (*value)[valueLength] = '\0';
        }
    }

} }
