
namespace MIMIc { namespace Utilities {

    template <typename KEYTYPE, typename VALUETYPE>
    const char* JsonDeserializer<KEYTYPE, VALUETYPE>::s_openObject = "{";

    template <typename KEYTYPE, typename VALUETYPE>
    const char* JsonDeserializer<KEYTYPE, VALUETYPE>::s_closeObject = "}";

    template <typename KEYTYPE, typename VALUETYPE>
    const char* JsonDeserializer<KEYTYPE, VALUETYPE>::s_openArray = "[";

    template <typename KEYTYPE, typename VALUETYPE>
    const char* JsonDeserializer<KEYTYPE, VALUETYPE>::s_closeArray = "]";

    template <typename KEYTYPE, typename VALUETYPE>
    const char* JsonDeserializer<KEYTYPE, VALUETYPE>::s_valueDelimiter = ":";

    template <typename KEYTYPE, typename VALUETYPE>
    const char* JsonDeserializer<KEYTYPE, VALUETYPE>::s_collectionDelimiter = ",";

    template <typename KEYTYPE, typename VALUETYPE>
    const char* JsonDeserializer<KEYTYPE, VALUETYPE>::s_stringDelimiter = "\"";

    template <typename KEYTYPE, typename VALUETYPE>
    const char* JsonDeserializer<KEYTYPE, VALUETYPE>::s_newlineDelimiter = "\n";


    template <typename KEYTYPE, typename VALUETYPE>
    JsonDeserializer<KEYTYPE, VALUETYPE>::JsonDeserializer()
    {
    }

    
    template <typename KEYTYPE, typename VALUETYPE>
    JsonDeserializer<KEYTYPE, VALUETYPE>::JsonDeserializer(const JsonDeserializer<KEYTYPE, VALUETYPE>& rhs) :
        m_cache(rhs.m_cache),
        m_fstream(rhs.m_fstream)
    {
    }


    template <typename KEYTYPE, typename VALUETYPE>
    JsonDeserializer<KEYTYPE, VALUETYPE>::~JsonDeserializer()
    {
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::Start(const char* const fileName) const
    {
       m_fstream.open(fileName, std::ios_base::in);
       return m_fstream.is_open();
    }


    template <typename KEYTYPE, typename VALUETYPE>
    void JsonDeserializer<KEYTYPE, VALUETYPE>::End() const
    {
        m_fstream.close();
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadObjectStart(char** namePointer, char* nameLocation) const
    {
        if(namePointer)
            if(!ReadString(namePointer, nameLocation))
                return false;
        
        return ReadToDelimiter(s_openObject, 1, 0);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadObjectEnd() const
    {        
        return ReadToDelimiter(s_closeObject, 1, 0);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadArrayStart(char** namePointer, char* nameLocation) const
    {
        if(namePointer)
            if(!ReadString(namePointer, nameLocation))
                return false;
        
        return ReadToDelimiter(s_openArray, 1, 0);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadArrayStringValue(char** valuePointer, char* valueLocation, bool& continueOn) const
    {
        if(!ReadString(valuePointer, valueLocation))
            return false;
        
        // we'll store the actual delimiter in the third element of this array
        const unsigned num = 2;
        char delimiters[num + 1] = { *s_collectionDelimiter, *s_closeArray };

        // check if we're done with the array
        if(!ReadToDelimiter(delimiters, num, delimiters + num))
            return false;

        continueOn = (delimiters[num] == *s_collectionDelimiter);
        return true;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    template <typename T>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadArrayBinaryValue(T* valueLocation, bool& continueOn) const
    {
        if(!ReadBinaryValue<T>(valueLocation))
            return false;
        
        // we'll store the actual delimiter in the third element of this array
        const unsigned num = 2;
        char delimiters[num + 1] = { *s_collectionDelimiter, *s_closeArray };

        // check if we're done with the array
        if(!ReadToDelimiter(delimiters, num, delimiters + num))
            return false;

        continueOn = (delimiters[num] == *s_collectionDelimiter);
        return true;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadNextArray(bool& continueOn) const
    {
        // we'll store the actual delimiter in the third element of this array
        const unsigned num = 2;
        char delimiters[num + 1] = { *s_collectionDelimiter, *s_closeArray };

        // check if we're done with the array
        if(!ReadToDelimiter(delimiters, num, delimiters + num))
            return false;

        continueOn = (delimiters[num] == *s_collectionDelimiter);
        return true;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadArrayEnd() const
    {
        return ReadToDelimiter(s_closeArray, 1, 0);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadNamedStringValue(char** namePointer, char* nameLocation, char** valuePointer, char* valueLocation) const
    {
        if(!ReadString(namePointer, nameLocation))
            return false;

        if(!ReadToDelimiter(s_valueDelimiter, 1, 0))
            return false;

        if(!ReadString(valuePointer, valueLocation))
            return false;
        
        return true;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    template <typename T>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadNamedBinaryValue(char** namePointer, char* nameLocation, T* valueLocation) const
    {
        if(!ReadString(namePointer, nameLocation))
            return false;

        if(!ReadToDelimiter(s_valueDelimiter, 1, 0))
            return false;

        if(!ReadBinaryValue<T>(valueLocation))
            return false;
        
        return true;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadBinaryValueWithLength(const unsigned length, char* valueLocation) const
    {
        m_fstream.read(valueLocation, length);

        return !m_fstream.eof();
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::AdvanceLine() const
    {
        return ReadToDelimiter(s_newlineDelimiter, 1, 0);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::AdvanceComma() const
    {
        return ReadToDelimiter(s_collectionDelimiter, 1, 0);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::AdvanceBracket() const
    {
        const unsigned num = 2;
        char delimiters[num] = { s_openArray, s_closeArray };
        return ReadToDelimiter(s_collectionDelimiter, num, 0);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::AdvanceBrace() const
    {
        const unsigned num = 2;
        char delimiters[num] = { s_openObject, s_closeObject };
        return ReadToDelimiter(s_collectionDelimiter, num, 0);
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadCharacter(std::ifstream& fstream, char& character)
    {
        if(fstream.eof())
            return false;

        fstream >> std::noskipws >> character;
        return true;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::IsDelimiter(const char value, const char* const delimiters, const unsigned numDelimiters, char* actualDelimiter)
    {
        for(unsigned i = 0; i < numDelimiters; ++i)
            if(value == delimiters[i])
            {
                if(actualDelimiter)
                    *actualDelimiter = delimiters[i];
                return true;
            }

        return false;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadString(char** valuePointer, char* valueLocation) const
    {
        unsigned valueLength;
        char c;

        // read to first string delimiter
        while(ReadCharacter(m_fstream, c))
        {
            if(IsDelimiter(c, s_stringDelimiter, 1, 0))
                break;
        }

        // error check
        if(m_fstream.eof())
            return false;

        // save position
        auto position = m_fstream.tellg();

        // read length of value
        valueLength = 0;
        c = 0;
        while(ReadCharacter(m_fstream, c))
        {
            if(IsDelimiter(c, s_stringDelimiter, 1, 0))
                break;
            ++valueLength;
        }

        // error check
        if(m_fstream.eof())
            return false;

        // if we're not saving this string, exit early
        if(!valuePointer)
            return true;

        // reset position
        m_fstream.seekg(position);
        
        // read value
        if(valueLength)
        {
            // reserve space for a null termination character if we're reading a string
            auto valueLengthFinal = valueLength + 1;

            // if we're being told to create the string at a specific location, do so
            *valuePointer = (valueLocation) ? new (valueLocation) char[valueLengthFinal] : new char[valueLengthFinal];

            unsigned currentValue = 0;
            c = 0;
            while(ReadCharacter(m_fstream, c) && currentValue < valueLength)
            {
                (*valuePointer)[currentValue] = c;
                ++currentValue;
            }

            // don't forget null termination
            (*valuePointer)[currentValue] = '\0';
        }

        return true;
    }


    template <typename KEYTYPE, typename VALUETYPE>
    template <typename T>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadBinaryValue(T* valueLocation) const
    {
        m_fstream.read((char*)valueLocation, sizeof(T));

        return !m_fstream.eof();
    }


    template <typename KEYTYPE, typename VALUETYPE>
    bool JsonDeserializer<KEYTYPE, VALUETYPE>::ReadToDelimiter(const char* const delimiters, const unsigned numDelimiters, char* actualDelimiter) const
    {
        char c;

        while(ReadCharacter(m_fstream, c))
        {
            if(IsDelimiter(c, delimiters, numDelimiters, actualDelimiter))
                break;
        }

        return !m_fstream.eof();
    }

} }
