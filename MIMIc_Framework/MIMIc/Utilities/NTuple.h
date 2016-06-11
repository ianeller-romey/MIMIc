
#ifndef UTILITIES_NTUPLE_H
#define UTILITIES_NTUPLE_H


namespace MIMIc { namespace Utilities {

    template <typename T, unsigned NUM>
    struct NTuple
    {
        NTuple()
        {
        }


        NTuple(T* values) :
            m_value(values[0]),
            m_next(values + 1)
        {
        }


        NTuple(const NTuple<T, NUM>& rhs) :
            m_value(rhs.m_value),
            m_next(rhs.m_next)
        {
        }


        NTuple<T, NUM>& operator=(const NTuple<T, NUM>& rhs)
        {
            m_value = rhs.m_value;
            m_next = rhs.m_next;
            return *this;
        }


        T m_value;
        NTuple<T, NUM - 1> m_next;
    };


    template <typename T>
    struct NTuple <T, 1>
    {
        NTuple()
        {
        }


        NTuple(T* values) :
            m_value(values[0])
        {
        }


        NTuple(const NTuple<T, 1>& rhs) :
            m_value(rhs.m_value)
        {
        }


        NTuple<T, 1>& operator=(const NTuple<T, 1>& rhs)
        {
            m_value = rhs.m_value;
            return *this;
        }


        T m_value;
    };

} }

#include "NTuple.inl"

#endif
