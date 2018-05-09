#ifndef ITERATOR_BIDIRECTIONAL_H_
#define ITERATOR_BIDIRECTIONAL_H_

#include <iterator>
#include <functional>

#include "../Iterator.h"
#include "Forward.h"

namespace simple
{
namespace iter
{

template<typename K, typename T, typename D = std::ptrdiff_t, typename P = T*,
    typename R = T&, typename C = std::bidirectional_iterator_tag,
    typename IT = std::iterator<C, T, D, P, R>>
class Bidirectional : public Forward<K, T, D, P, R, C, IT>,
    public virtual Iterator<K, C, T, D, P, R, IT>
{
public:
    typedef std::function<void(P*)> DecrementHandleType;
private:
    static void DecrementDefaultHandle(P* m_dptr);
private:
    DecrementHandleType m_decrement_handle;
public:
    Bidirectional();
    Bidirectional(P ptr);
    Bidirectional(const Bidirectional<K, T, D, P, R, C, IT>& cpy);
    Bidirectional(Bidirectional<K, T, D, P, R, C, IT>&& mov);
public:
    void SetDecrementHandle(DecrementHandleType decrement_handle);
    void SetDecrementHandle(const Bidirectional<K, T, D, P, R, C, IT>& cpy);
public:
    Bidirectional<K, T, D, P, R, C, IT>& 
        operator=(const Bidirectional<K, T, D, P, R, C, IT>& cpy);
    Bidirectional<K, T, D, P, R, C, IT>& operator=(P ptr);
    Bidirectional<K, T, D, P, R, C, IT>& operator--();
    Bidirectional<K, T, D, P, R, C, IT> operator--(int);
};

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Bidirectional<K, T, D, P, R, C, IT>::DecrementDefaultHandle(P* m_dptr)
{
    if (m_dptr != nullptr)
        --(*m_dptr);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<K, T, D, P, R, C, IT>::Bidirectional() :
    Iterator<K, C, T, D, P, R, IT>(nullptr),
    m_decrement_handle(DecrementDefaultHandle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<K, T, D, P, R, C, IT>::Bidirectional(P ptr) :
    Iterator<K, C, T, D, P, R, IT>(ptr),
    m_decrement_handle(DecrementDefaultHandle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<K, T, D, P, R, C, IT>::
    Bidirectional(const Bidirectional<K, T, D, P, R, C, IT>& cpy) :
        Iterator<K, C, T, D, P, R, IT>(cpy),
        Forward<K, T, D, P, R, C, IT>(cpy),
        m_decrement_handle(cpy.m_decrement_handle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<K, T, D, P, R, C, IT>::
    Bidirectional(Bidirectional<K, T, D, P, R, C, IT>&& mov) :
        Iterator<K, C, T, D, P, R, IT>(mov),
        Forward<K, T, D, P, R, C, IT>(mov),
        m_decrement_handle(mov.m_decrement_handle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Bidirectional<K, T, D, P, R, C, IT>::
    SetDecrementHandle(DecrementHandleType decrement_handle)
{
    m_decrement_handle = decrement_handle;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Bidirectional<K, T, D, P, R, C, IT>::
    SetDecrementHandle(const Bidirectional<K, T, D, P, R, C, IT>& cpy)
{
    SetDecrementHandle(cpy.m_decrement_handle);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<K, T, D, P, R, C, IT>& Bidirectional<K, T, D, P, R, C, IT>::
    operator=(const Bidirectional<K, T, D, P, R, C, IT>& cpy)
{
    Forward<K, T, D, P, R, C, IT>::operator=(cpy);
    SetDecrementHandle(cpy);
    return *this;
}
    
template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<K, T, D, P, R, C, IT>& Bidirectional<K, T, D, P, R, C, IT>::
    operator=(P ptr)
{
    Iterator<K, C, T, D, P, R, IT>::operator=(ptr);
    return *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<K, T, D, P, R, C, IT>& 
    Bidirectional<K, T, D, P, R, C, IT>::operator--()
{
    if (m_increment_handle != nullptr)
        m_decrement_handle(&m_ptr);
    else
        DecrementDefaultHandle(&m_ptr);
    return *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<K, T, D, P, R, C, IT> 
    Bidirectional<K, T, D, P, R, C, IT>::operator--(int)
{
    return --(*this);
}

}

}

#endif //!ITERATOR_BIDIRECTIONAL_H_
