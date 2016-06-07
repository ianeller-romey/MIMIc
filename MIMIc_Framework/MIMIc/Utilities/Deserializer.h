
#ifndef UTILITIES_DESERIALIZER_H
#define UTILITIES_DESERIALIZER_H

#include <map>
#include <string>


namespace MIMIc { namespace Utilities {

    template <typename KEYTYPE, typename VALUETYPE>
    class Deserializer
    {
        public:
            Deserializer();
            Deserializer(const Deserializer& rhs);
            virtual ~Deserializer();

            virtual Deserializer& operator=(const Deserializer& rhs)
            {
                m_cache = rhs.m_cache;
            }

            VALUETYPE Get(const KEYTYPE& key);

        protected:
            std::map<KEYTYPE, VALUETYPE> m_cache;

            virtual VALUETYPE Deserialize(const KEYTYPE& key) const = 0;
    };

} }

#include "Deserializer.inl"

#endif
