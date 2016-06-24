
#ifndef UTILITIES_HETEROPAIR_H
#define UTILITIES_HETEROPAIR_H


namespace MIMIc { namespace Utilities {

    template <typename T1, typename T2>
    struct HeteroPair
    {
        HeteroPair()
        {
        }


        HeteroPair(const T1& value1, const T2& value2) :
            m_value1(value1),
            m_value2(value2)
        {
        }


        HeteroPair(const HeteroPair<T1, T2>& rhs) :
            m_value1(rhs.m_value1),
            m_value2(rhs.m_value2)
        {
        }


        HeteroPair<T1, T2>& operator=(const HeteroPair<T1, T2>& rhs)
        {
            m_value1 = rhs.m_value1;
            m_value2 = rhs.m_value2;

            return *this;
        }

        T1 m_value1;
        T2 m_value2;
    };

} }

#include "HeteroPair.inl"

#endif
