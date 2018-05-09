#ifndef ITERATOR_FORWARD_H_
#define ITERATOR_FORWARD_H_

#include <iterator>

#include "../Iterator.h"
#include "Input.h"
#include "Output.h"

namespace simple
{
namespace iter
{

template<typename K, typename T, typename D = std::ptrdiff_t, typename P = T*,
    typename R = T&, typename C = std::forward_iterator_tag,
    typename IT = std::iterator<C, T, D, P, R>>
class Forward: public Input<K, T, D, P, R, C, IT>, 
    public Output<K, T, D, P, R, C, IT>,
    public virtual Iterator<K, C, T, D, P, R, IT>
{
public:
    Forward();
    Forward(P ptr);
    Forward(const Forward<K, T, D, P, R, C, IT>& cpy);
    Forward(Forward<K, T, D, P, R, C, IT>&& mov);
public:
    Forward<K, T, D, P, R, C, IT>& 
        operator=(const Forward<K, T, D, P, R, C, IT>& cpy);
    Forward<K, T, D, P, R, C, IT>& operator=(P ptr);
    R operator*();
    R operator->();
    const R operator*() const;
    const R operator->() const;
};

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<K, T, D, P, R, C, IT>::Forward() :
    Iterator<K, C, T, D, P, R, IT>(nullptr)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<K, T, D, P, R, C, IT>::Forward(P ptr) :
    Iterator<K, C, T, D, P, R, IT>(ptr)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<K, T, D, P, R, C, IT>::
    Forward(const Forward<K, T, D, P, R, C, IT>& cpy) :
        Iterator<K, C, T, D, P, R, IT>(cpy),
        Input<K, T, D, P, R, C, IT>(cpy),
        Output<K, T, D, P, R, C, IT>(cpy)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<K, T, D, P, R, C, IT>::Forward(Forward<K, T, D, P, R, C, IT>&& mov) :
    Iterator<K, C, T, D, P, R, IT>(mov),
    Input<K, T, D, P, R, C, IT>(mov),
    Output<K, T, D, P, R, C, IT>(mov)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<K, T, D, P, R, C, IT>& Forward<K, T, D, P, R, C, IT>::
    operator=(const Forward<K, T, D, P, R, C, IT>& cpy)
{
    Iterator<K, C, T, D, P, R, IT>::operator=(cpy);
    Input<K, T, D, P, R, C, IT>::SetRValueHandle(cpy);
    Output<K, T, D, P, R, C, IT>::SetLValueHandle(cpy);
    return *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Forward<K, T, D, P, R, C, IT>& Forward<K, T, D, P, R, C, IT>::operator=(P ptr)
{
    Iterator<K, C, T, D, P, R, IT>::operator=(ptr);
    return *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R Forward<K, T, D, P, R, C, IT>::operator*()
{
    return Output<K, T, D, P, R, C, IT>::operator*();
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R Forward<K, T, D, P, R, C, IT>::operator->()
{
    return *(*this);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
const R Forward<K, T, D, P, R, C, IT>::operator*() const
{
    return Input<K, T, D, P, R, C, IT>::operator*();
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
const R Forward<K, T, D, P, R, C, IT>::operator->() const
{
    return *(*this);
}

}

}

#endif //!ITERATOR_FORWARD_H_
