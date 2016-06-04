
namespace MIMIc { namespace Utilities {    

    template <typename T>
    Deserializer<T>::Deserializer()
    {
    }

    
    template <typename T>
    Deserializer<T>::Deserializer(const Deserializer<T>& rhs) :
        m_cache(rhs.m_cache)
    {
    }


    template <typename T>
    Deserializer<T>::~Deserializer()
    {
    }

    
    template <typename T>
    T Deserializer<T>::Get(const char* fileName)
    {
        if(m_cache.count(fileName))
            return m_cache[fileName];
        else
        {
            T deserialized = Deserialize(fileName);
            m_cache[fileName] = deserialized;
            return deserialized;
        }
    }

} }
