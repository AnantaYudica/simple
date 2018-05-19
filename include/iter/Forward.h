#ifndef ITERATOR_FORWARD_H_
#define ITERATOR_FORWARD_H_

#include <iterator>

#include "../id_const/Validation.h"

#include "../Iterator.h"
#include "Input.h"
#include "Output.h"

namespace simple
{
namespace iter
{

struct ForwardIDConst : simple::iter::InputIDConst,
    simple::iter::OutputIDConst {};

template<typename Tidc, typename T, typename D = std::ptrdiff_t, 
    typename P = T*, typename R = T&, typename C = std::forward_iterator_tag,
    typename IT = std::iterator<C, T, D, P, R>>
class Forward: public simple::iter::Input<Tidc, T, D, P, R, C, IT>, 
    public simple::iter::Output<Tidc, T, D, P, R, C, IT>,
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
private:
    typedef simple::iter::Input<Tidc, T, D, P, R, C, IT> BaseInputIteratorType;
    typedef simple::iter::Output<Tidc, T, D,
         P, R, C, IT> BaseOutputIteratorType;
    typedef simple::Iterator<Tidc, C, T, D, P, R, IT> BaseIteratorType;
public:
    Forward();
    Forward(P ptr);
    Forward(const Forward<Tidc, T, D, P, R, C, IT>& cpy);
    Forward(Forward<Tidc, T, D, P, R, C, IT>&& mov);
public:
    Forward<Tidc, T, D, P, R, C, IT>& 
        operator=(const Forward<Tidc, T, D, P, R, C, IT>& cpy);
    Forward<Tidc, T, D, P, R, C, IT>& operator=(P ptr);
    R operator*();
    R operator->();
    const R operator*() const;
    const R operator->() const;
};

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<Tidc, T, D, P, R, C, IT>::Forward() :
    BaseIteratorType(nullptr)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<Tidc, T, D, P, R, C, IT>::Forward(P ptr) :
    BaseIteratorType(ptr),
    BaseInputIteratorType(ptr),
    BaseOutputIteratorType(ptr)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<Tidc, T, D, P, R, C, IT>::
    Forward(const Forward<Tidc, T, D, P, R, C, IT>& cpy) :
        BaseIteratorType(cpy),
        BaseInputIteratorType(cpy),
        BaseOutputIteratorType(cpy)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<Tidc, T, D, P, R, C, IT>::
    Forward(Forward<Tidc, T, D, P, R, C, IT>&& mov) :
        BaseIteratorType(mov),
        BaseInputIteratorType(mov),
        BaseOutputIteratorType(mov)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<Tidc, T, D, P, R, C, IT>& Forward<Tidc, T, D, P, R, C, IT>::
    operator=(const Forward<Tidc, T, D, P, R, C, IT>& cpy)
{
    BaseIteratorType::operator=(cpy);
    BaseInputIteratorType::SetRValueHandle(cpy);
    BaseOutputIteratorType::SetLValueHandle(cpy);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<Tidc, T, D, P, R, C, IT>& 
    Forward<Tidc, T, D, P, R, C, IT>::operator=(P ptr)
{
    BaseIteratorType::operator=(ptr);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R Forward<Tidc, T, D, P, R, C, IT>::operator*()
{
    return BaseOutputIteratorType::operator*();
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R Forward<Tidc, T, D, P, R, C, IT>::operator->()
{
    return *(*this);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
const R Forward<Tidc, T, D, P, R, C, IT>::operator*() const
{
    return BaseInputIteratorType::operator*();
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
const R Forward<Tidc, T, D, P, R, C, IT>::operator->() const
{
    return *(*this);
}

}

}

#endif //!ITERATOR_FORWARD_H_
