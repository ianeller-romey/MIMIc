
#ifndef UTILITIES_HASID_H
#define UTILITIES_HASID_H


namespace MIMIc { namespace Utilities {

    template <typename T>
    class HasId
    {
        public:
            HasId();
            HasId(const HasId& rhs);

            HasId& operator=(const HasId& rhs)
            {
                m_id = rhs.m_id;
            }

            const long GetId() const;

        private:
            static long s_idGenerator;
            long m_id;
    };

} }

#include "HasId.inl"

#endif
