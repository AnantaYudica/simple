#ifndef ITERATOR_BIDIRECTIONAL_H_
#define ITERATOR_BIDIRECTIONAL_H_

#include <iterator>
#include <functional>

#include "../id_const/Validation.h"

#include "../Handle.h"

#include "../Iterator.h"
#include "Forward.h"

namespace simple
{
namespace iter
{

struct BidirectionalIDConst : simple::iter::ForwardIDConst {};

struct DecrementHandleIDConst : simple::iter::BidirectionalIDConst {};

template<typename Tidc, typename T, typename D = std::ptrdiff_t, 
    typename P = T*, typename R = T&, 
    typename C = std::bidirectional_iterator_tag,
    typename IT = std::iterator<C, T, D, P, R>>
class Bidirectional : public simple::iter::Forward<Tidc, T, D, P, R, C, IT>,
    public simple::Handle<simple::iter::DecrementHandleIDConst, void, P*>,
    public virtual simple::Iterator<Tidc, C, T, D, P, R, IT>
{
public:
    typedef typename simple::id_const::
        Validation<Tidc>::Type IDConstType;
    typedef C CategoryType;
    typedef T ValueType;
    typedef D DistanceType;
    typedef P PointerType;
    typedef R ReferenceType;
    typedef typename simple::Handle<simple::iter::
        DecrementHandleIDConst, void, P*>::FunctionType DecrementHandleType;
private:
    typedef simple::iter::Forward<Tidc, T, D, P, R, C, IT> BaseForwardType;
    typedef simple::Handle<simple::iter::
        DecrementHandleIDConst, void, P*> BaseDecrementHandleType;
    typedef simple::Iterator<Tidc, C, T, D, P, R, IT> BaseIteratorType;
private:
    void DecrementDefaultHandle(P* m_dptr);
public:
    Bidirectional();
    Bidirectional(P ptr);
    Bidirectional(const Bidirectional<Tidc, T, D, P, R, C, IT>& cpy);
    Bidirectional(Bidirectional<Tidc, T, D, P, R, C, IT>&& mov);
public:
    void Set(DecrementHandleType) = delete;
    void SetDecrementHandle(DecrementHandleType decrement_handle);
    void SetDecrementHandle(const Bidirectional<Tidc, T, D, P, R, C, IT>& cpy);
public:
    Bidirectional<Tidc, T, D, P, R, C, IT>& 
        operator=(const Bidirectional<Tidc, T, D, P, R, C, IT>& cpy);
    Bidirectional<Tidc, T, D, P, R, C, IT>& operator=(P ptr);
    Bidirectional<Tidc, T, D, P, R, C, IT>& operator--();
    Bidirectional<Tidc, T, D, P, R, C, IT> operator--(int);
};

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Bidirectional<Tidc, T, D, P, R, C, IT>::DecrementDefaultHandle(P* m_dptr)
{
    if (m_dptr != nullptr)
        --(*m_dptr);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<Tidc, T, D, P, R, C, IT>::Bidirectional() :
    BaseIteratorType(nullptr),
    BaseDecrementHandleType(DecrementDefaultHandle)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<Tidc, T, D, P, R, C, IT>::Bidirectional(P ptr) :
    BaseIteratorType(ptr),
    BaseForwardType(ptr),
    BaseDecrementHandleType(DecrementDefaultHandle)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<Tidc, T, D, P, R, C, IT>::
    Bidirectional(const Bidirectional<Tidc, T, D, P, R, C, IT>& cpy) :
        BaseIteratorType(cpy),
        BaseForwardType(cpy),
        BaseDecrementHandleType(cpy)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<Tidc, T, D, P, R, C, IT>::
    Bidirectional(Bidirectional<Tidc, T, D, P, R, C, IT>&& mov) :
        BaseIteratorType(mov),
        BaseForwardType(mov),
        BaseDecrementHandleType(mov)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Bidirectional<Tidc, T, D, P, R, C, IT>::
    SetDecrementHandle(DecrementHandleType decrement_handle)
{
    BaseDecrementHandleType::operator=(decrement_handle);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Bidirectional<Tidc, T, D, P, R, C, IT>::
    SetDecrementHandle(const Bidirectional<Tidc, T, D, P, R, C, IT>& cpy)
{
    BaseDecrementHandleType::operator=(cpy);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<Tidc, T, D, P, R, C, IT>& 
    Bidirectional<Tidc, T, D, P, R, C, IT>::
        operator=(const Bidirectional<Tidc, T, D, P, R, C, IT>& cpy)
{
    BaseForwardType::operator=(cpy);
    SetDecrementHandle(cpy);
    return *this;
}
    
template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<Tidc, T, D, P, R, C, IT>& 
    Bidirectional<Tidc, T, D, P, R, C, IT>::operator=(P ptr)
{
    BaseIteratorType::operator=(ptr);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<Tidc, T, D, P, R, C, IT>& 
    Bidirectional<Tidc, T, D, P, R, C, IT>::operator--()
{
    if (static_cast<BaseDecrementHandleType&>(*this))
        BaseDecrementHandleType::operator()(&m_ptr);
    else
        DecrementDefaultHandle(&m_ptr);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Bidirectional<Tidc, T, D, P, R, C, IT> 
    Bidirectional<Tidc, T, D, P, R, C, IT>::operator--(int)
{
    return --(*this);
}

}

}

#endif //!ITERATOR_BIDIRECTIONAL_H_
