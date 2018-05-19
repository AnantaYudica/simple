#ifndef ITERATOR_INPUT_H_
#define ITERATOR_INPUT_H_

#include <iterator>
#include <functional>

#include "../id_const/Validation.h"

#include "../Handle.h"

#include "../Iterator.h"

namespace simple
{
namespace iter
{

struct InputIDConst : virtual simple::IteratorIDConst {};

struct RValueHandleIDConst : simple::iter::InputIDConst {};

template<typename Tidc, typename T, typename D = std::ptrdiff_t, 
    typename P = T*, typename R = T&, typename C = std::input_iterator_tag,
    typename IT = std::iterator<C, T, D, P, R>>
class Input : public simple::Handle<simple::iter::RValueHandleIDConst, 
    const R, const P>, public virtual simple::Iterator<Tidc, C, T, D, P, R, IT>
{
public:
    typedef typename simple::id_const::
        Validation<Tidc>::Type IDConstType;
    typedef C CategoryType;
    typedef T ValueType;
    typedef D DistanceType;
    typedef P PointerType;
    typedef R ReferenceType;
    typedef typename simple::Handle<simple::iter::RValueHandleIDConst, 
        const R, const P>::FunctionType RValueHandleType;
private:
    typedef simple::Handle<simple::iter::RValueHandleIDConst, 
        const R, const P> BaseRValueHandleType;
    typedef simple::Iterator<Tidc, C, T, D, P, R, IT> BaseIteratorType; 
private:
    static const R RValueDefaultHandle(const P ptr);
public:
    Input(P ptr);
    Input(const Input<Tidc, T, D, P, R, C, IT>& cpy);
    Input(Input<Tidc, T, D, P, R, C, IT>&& mov);
public:
    void Set(RValueHandleType) = delete;
    void SetRValueHandle(RValueHandleType rvalue_handle);
    void SetRValueHandle(const Input<Tidc, T, D, P, R, C, IT>& cpy);
public:
    Input<Tidc, T, D, P, R, C, IT>& 
        operator=(const Input<Tidc, T, D, P, R, C, IT>& cpy);
    Input<Tidc, T, D, P, R, C, IT>& operator=(P ptr);
    bool operator==(const Input<Tidc, T, D, P, R, C, IT>& it) const;
    bool operator!=(const Input<Tidc, T, D, P, R, C, IT>& it) const;
    const T& operator*() const;
    const T& operator->() const;
};

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
const R Input<Tidc, T, D, P, R, C, IT>::RValueDefaultHandle(const P ptr)
{
    return *ptr;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Input<Tidc, T, D, P, R, C, IT>::Input(P ptr) :
    BaseIteratorType(ptr),
    BaseRValueHandleType(RValueDefaultHandle)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Input<Tidc, T, D, P, R, C, IT>::Input(const Input<Tidc, T, D, 
    P, R, C, IT>& cpy) :
        BaseIteratorType(cpy),
        BaseRValueHandleType(cpy)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Input<Tidc, T, D, P, R, C, IT>::Input(Input<Tidc, T, D, P,
    R, C, IT>&& mov) :
        BaseIteratorType(mov),
        BaseRValueHandleType(mov)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Input<Tidc, T, D, P, R, C, IT>::
    SetRValueHandle(RValueHandleType rvalue_handle)
{
    BaseRValueHandleType::operator=(rvalue_handle);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Input<Tidc, T, D, P, R, C, IT>::
    SetRValueHandle(const Input<Tidc, T, D, P, R, C, IT>& cpy)
{
    BaseRValueHandleType::operator=(cpy);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Input<Tidc, T, D, P, R, C, IT>& Input<Tidc, T, D, P, R, C, IT>::
    operator=(const Input<Tidc, T, D, P, R, C, IT>& cpy)
{
    BaseIteratorType::operator=(cpy);
    SetRValueHandle(cpy);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Input<Tidc, T, D, P, R, C, IT>& 
Input<Tidc, T, D, P, R, C, IT>::operator=(P ptr)
{
    BaseIteratorType::operator=(ptr);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool Input<Tidc, T, D, P, R, C, IT>::
    operator==(const Input<Tidc, T, D, P, R, C, IT>& it) const
{
    return m_ptr == it.m_ptr;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool Input<Tidc, T, D, P, R, C, IT>::
    operator!=(const Input<Tidc, T, D, P, R, C, IT>& it) const
{
    return !(*this == it);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
const T& Input<Tidc, T, D, P, R, C, IT>::operator*() const
{
    if (static_cast<BaseRValueHandleType&>(*this))
        return BaseRValueHandleType::operator()(m_ptr);
    return RValueDefaultHandle(m_ptr);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
const T& Input<Tidc, T, D, P, R, C, IT>::operator->() const
{
    return *(*this);
}

}

}

#endif //!ITERATOR_INPUT_H_
