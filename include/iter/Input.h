#ifndef ITERATOR_INPUT_H_
#define ITERATOR_INPUT_H_

#include <iterator>
#include <functional>

#include "../Iterator.h"

namespace simple
{
namespace iter
{

template<typename K, typename T, typename D = std::ptrdiff_t, typename P = T*,
    typename R = T&, typename C = std::input_iterator_tag,
    typename IT = std::iterator<C, T, D, P, R>>
class Input : public virtual Iterator<K, C, T, D, P, R, IT>
{
public:
    typedef std::function<const R(const P)> RValueHandleType;
private:
    static const R RValueDefaultHandle(const P ptr);
private:
    RValueHandleType m_rvalue_handle;
public:
    Input(P ptr);
    Input(const Input<K, T, D, P, R, C, IT>& cpy);
    Input(Input<K, T, D, P, R, C, IT>&& mov);
public:
    void SetRValueHandle(RValueHandleType rvalue_handle);
    void SetRValueHandle(const Input<K, T, D, P, R, C, IT>& cpy);
public:
    Input<K, T, D, P, R, C, IT>& 
        operator=(const Input<K, T, D, P, R, C, IT>& cpy);
    Input<K, T, D, P, R, C, IT>& operator=(P ptr);
    bool operator==(const Input<K, T, D, P, R, C, IT>& it) const;
    bool operator!=(const Input<K, T, D, P, R, C, IT>& it) const;
    const T& operator*() const;
    const T& operator->() const;
};

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R Input<K, T, D, P, R, C, IT>::RValueDefaultHandle(const P ptr)
{
    return *ptr;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Input<K, T, D, P, R, C, IT>::Input(P ptr) :
    Iterator<K, C, T, D, P, R, IT>(ptr),
    m_rvalue_handle(RValueDefaultHandle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Input<K, T, D, P, R, C, IT>::Input(const Input<K, T, D, 
    P, R, C, IT>& cpy) :
        Iterator<K, C, T, D, P, R, IT>(cpy.m_ptr),
        m_rvalue_handle(cpy.m_rvalue_handle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Input<K, T, D, P, R, C, IT>::Input(Input<K, T, D, P,
    R, C, IT>&& mov) :
        Iterator<K, C, T, D, P, R, IT>(mov.m_ptr),
        m_rvalue_handle(mov.m_rvalue_handle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Input<K, T, D, P, R, C, IT>::
    SetRValueHandle(RValueHandleType rvalue_handle)
{
    m_rvalue_handle = rvalue_handle;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Input<K, T, D, P, R, C, IT>::
    SetRValueHandle(const Input<K, T, D, P, R, C, IT>& cpy)
{
    SetRValueHandle(cpy.m_rvalue_handle);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Input<K, T, D, P, R, C, IT>& Input<K, T, D, P, R, C, IT>::
    operator=(const Input<K, T, D, P, R, C, IT>& cpy)
{
    Iterator<K, C, T, D, P, R, IT>::operator=(cpy);
    SetRValueHandle(cpy);
    return *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Input<K, T, D, P, R, C, IT>& 
Input<K, T, D, P, R, C, IT>::operator=(P ptr)
{
    Iterator<K, C, T, D, P, R, IT>::operator=(ptr);
    return *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool Input<K, T, D, P, R, C, IT>::
    operator==(const Input<K, T, D, P, R, C, IT>& it) const
{
    return m_ptr == it.m_ptr;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool Input<K, T, D, P, R, C, IT>::
    operator!=(const Input<K, T, D, P, R, C, IT>& it) const
{
    return !(*this == it);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
const T& Input<K, T, D, P, R, C, IT>::operator*() const
{
    if (m_rvalue_handle != nullptr)
        return m_rvalue_handle(m_ptr);
    return RValueDefaultHandle(m_ptr);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
const T& Input<K, T, D, P, R, C, IT>::operator->() const
{
    return *(*this);
}

}

}

#endif //!ITERATOR_INPUT_H_
