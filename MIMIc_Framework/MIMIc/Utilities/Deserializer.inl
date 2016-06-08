
namespace MIMIc { namespace Utilities {    

    template <typename KEYTYPE, typename VALUETYPE>
    Deserializer<KEYTYPE, VALUETYPE>::Deserializer()
    {
    }

    
    template <typename KEYTYPE, typename VALUETYPE>
    Deserializer<KEYTYPE, VALUETYPE>::Deserializer(const Deserializer<KEYTYPE, VALUETYPE>& rhs) :
        m_cache(rhs.m_cache)
    {
    }


    template <typename KEYTYPE, typename VALUETYPE>
    Deserializer<KEYTYPE, VALUETYPE>::~Deserializer()
    {
    }

    
    template <typename KEYTYPE, typename VALUETYPE>
    VALUETYPE Deserializer<KEYTYPE, VALUETYPE>::Get(const KEYTYPE& key)
    {
        if(m_cache.count(key))
            return m_cache[key];
        else
        {
            VALUETYPE deserialized = Deserialize(key);
            m_cache[key] = deserialized;
            return deserialized;
        }
    }

} }
