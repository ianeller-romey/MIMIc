
namespace MIMIc { namespace Utilities {

    template <typename T>
    long HasId<T>::s_idGenerator = 0;
    

    template <typename T>
    HasId<T>::HasId() :
        m_id(HasId<T>::s_idGenerator++)
    {
    }

    
    template <typename T>
    HasId<T>::HasId(const HasId<T>& rhs) :
        m_id(rhs.m_id)
    {
    }

    
    template <typename T>
    const long HasId<T>::GetId() const
    {
        return m_id;
    }

} }
