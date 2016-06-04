
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
    T Deserializer<T>::Get(const KEYTYPE& key)
    {
        if(m_cache.count(key))
            return m_cache[key];
        else
        {
            T deserialized = Deserialize(key);
            m_cache[key] = deserialized;
            return deserialized;
        }
    }

} }
