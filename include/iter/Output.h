#ifndef ITERATOR_OUTPUT_H_
#define ITERATOR_OUTPUT_H_

#include <iterator>
#include <functional>

#include "../Iterator.h"

namespace simple
{
namespace iter
{

template<typename K, typename T, typename D = std::ptrdiff_t, typename P = T*,
    typename R = T&, typename C = std::output_iterator_tag,
    typename IT = std::iterator<C, T, D, P, R>>
class Output : public virtual Iterator<K, C, T, D, P, R, IT>
{
public:
    typedef std::function<R(P)> LValueHandleType;
private:
    static R LValueDefaultHandle(P ptr);
private:
    LValueHandleType m_lvalue_handle;
public:
    Output(P ptr);
    Output(const Output<K, T, D, P, R, C, IT>& cpy);
    Output(Output<K, T, D, P, R, C, IT>&& mov);
public:
    void SetLValueHandle(LValueHandleType lvalue_handle);
    void SetLValueHandle(const Output<K, T, D, P, R, C, IT>& cpy);
public:
    Output<K, T, D, P, R, C, IT>& 
        operator=(const Output<K, T, D, P, R, C, IT>& cpy);
    Output<K, T, D, P, R, C, IT>& operator=(P ptr);
    R operator*();
    R operator->();
};

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R Output<K, T, D, P, R, C, IT>::LValueDefaultHandle(P ptr)
{
    return *ptr;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Output<K, T, D, P, R, C, IT>::Output(P ptr) :
    Iterator<K, C, T, D, P, R, IT>(ptr),
    m_lvalue_handle(LValueDefaultHandle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Output<K, T, D, P, R, C, IT>::Output(const Output<K, T, D, P, R, C, IT>& cpy) :
    Iterator<K, C, T, D, P, R, IT>(cpy),
    m_lvalue_handle(cpy.m_lvalue_handle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Output<K, T, D, P, R, C, IT>::Output(Output<K, T, D, P, R, C, IT>&& mov) :
    Iterator<K, C, T, D, P, R, IT>(mov),
    m_lvalue_handle(mov.m_lvalue_handle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Output<K, T, D, P, R, C, IT>::
    SetLValueHandle(LValueHandleType lvalue_handle)
{
    m_lvalue_handle = lvalue_handle;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Output<K, T, D, P, R, C, IT>::
    SetLValueHandle(const Output<K, T, D, P, R, C, IT>& cpy)
{
    SetLValueHandle(cpy.m_lvalue_handle);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Output<K, T, D, P, R, C, IT>& Output<K, T, D, P, R, C, IT>::
    operator=(const Output<K, T, D, P, R, C, IT>& cpy)
{
    Iterator<K, C, T, D, P, R, IT>::operator=(cpy);
    SetLValueHandle(cpy);
    return *this;
}

template<typename K, typename T, typename D, typename P,
typename R, typename C, typename IT>
Output<K, T, D, P, R, C, IT>& Output<K, T, D, P, R, C, IT>::operator=(P ptr)
{
    Iterator<K, C, T, D, P, R, IT>::operator=(ptr);
    return *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R Output<K, T, D, P, R, C, IT>::operator*()
{
    if (m_lvalue_handle != nullptr)
        return m_lvalue_handle(m_ptr);
    return LValueDefaultHandle(m_ptr);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R Output<K, T, D, P, R, C, IT>::operator->()
{
    return *(*this);
}

}

}

#endif //!ITERATOR_OUTPUT_H_
