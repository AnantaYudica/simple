#ifndef ITERATOR_RANDOM_ACCESS_H_
#define ITERATOR_RANDOM_ACCESS_H_

#include <iterator>

#include "../Iterator.h"
#include "Bidirectional.h"

namespace simple
{
namespace iter
{

template<typename K, typename T, typename D = std::ptrdiff_t, typename P = T*,
    typename R = T&, typename C = std::random_access_iterator_tag,
    typename IT = std::iterator<C, T, D, P, R>>
class RandomAccess : public Bidirectional<K, T, D, P, R, C, IT>,
    public virtual Iterator<K, C, T, D, P, R, IT>
{
public:
    typedef std::function<void(P*, const D&)> AdditionHandleType;
    typedef std::function<void(P*, const D&)> SubtractionHandleType;
    typedef std::function<D(const P, const P)> DistanceHandleType;
private:
    void AdditionDefaultHandle(P* d_ptr, const D& distance);
    void SubtractionDefaultHandle(P* d_ptr, const D& distance);
    D DistanceDefaultHandle(const P a, const P b);
private:
    AdditionHandleType m_addition_handle;
    SubtractionHandleType m_subtraction_handle;
    DistanceHandleType m_distance_handle;
public:
    RandomAccess();
    RandomAccess(P ptr);
    RandomAccess(const RandomAccess<K, T, D, P, R, C, IT>& cpy);
    RandomAccess(RandomAccess<K, T, D, P, R, C, IT>&& mov);
public:
    void SetAdditionHandle(AdditionHandleType addition_handle);
    void SetAdditionHandle(const RandomAccess<K, T, D, P, R, C, IT>& cpy);
    void SetSubtractionHandle(SubtractionHandleType subtraction_handle);
    void SetSubtractionHandle(const RandomAccess<K, T, D, P, R, C, IT>& cpy);
    void SetDistanceHandle(DistanceHandleType distance_handle);
    void SetDistanceHandle(const RandomAccess<K, T, D, P, R, C, IT>& cpy);
    void SetHandle(const RandomAccess<K, T, D, P, R, C, IT>& cpy);
public:
    RandomAccess<K, T, D, P, R, C, IT>& 
        operator=(const RandomAccess<K, T, D, P, R, C, IT>& cpy);
    RandomAccess<K, T, D, P, R, C, IT>& operator=(P ptr);
    RandomAccess<K, T, D, P, R, C, IT>& operator+=(const D& off);
    RandomAccess<K, T, D, P, R, C, IT>& operator-=(const D& off);
    RandomAccess<K, T, D, P, R, C, IT> operator+(const D& off) const;
    RandomAccess<K, T, D, P, R, C, IT> operator-(const D& off) const;
    D operator-(const RandomAccess<K, T, D, P, R, C, IT>& b) const;
    R operator[](const D& off);
    const R operator[](const D& off) const;
    bool operator<(const RandomAccess<K, T, D, P, R, C, IT>& b) const;
    bool operator>(const RandomAccess<K, T, D, P, R, C, IT>& b) const;
    bool operator<=(const RandomAccess<K, T, D, P, R, C, IT>& b) const;
    bool operator>=(const RandomAccess<K, T, D, P, R, C, IT>& b) const;
};

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<K, T, D, P, R, C, IT>::
    AdditionDefaultHandle(P* d_ptr, const D& distance)
{
    if (d_ptr != nullptr)
        *d_ptr += distance;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<K, T, D, P, R, C, IT>::
    SubtractionDefaultHandle(P* d_ptr, const D& distance)
{
    if (d_ptr != nullptr)
        *d_ptr -= distance;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
D RandomAccess<K, T, D, P, R, C, IT>::
    DistanceDefaultHandle(const P a, const P b)
{
    return (a > b ? a - b : b - a);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<K, T, D, P, R, C, IT>::RandomAccess() :
    Iterator<K, C, T, D, P, R, IT>(nullptr),
    m_addition_handle(AdditionDefaultHandle),
    m_subtraction_handle(SubtractionDefaultHandle),
    m_distance_handle(DistanceDefaultHandle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<K, T, D, P, R, C, IT>::RandomAccess(P ptr) :
    Iterator<K, C, T, D, P, R, IT>(ptr),
    m_addition_handle(AdditionDefaultHandle),
    m_subtraction_handle(SubtractionDefaultHandle),
    m_distance_handle(DistanceDefaultHandle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<K, T, D, P, R, C, IT>::
    RandomAccess(const RandomAccess<K, T, D, P, R, C, IT>& cpy) :
        Iterator<K, C, T, D, P, R, IT>(cpy),
        Bidirectional<K, T, D, P, R, C, IT>(cpy),
        m_addition_handle(cpy.m_addition_handle),
        m_subtraction_handle(cpy.m_subtraction_handle),
        m_distance_handle(cpy.m_distance_handle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<K, T, D, P, R, C, IT>::
    RandomAccess(RandomAccess<K, T, D, P, R, C, IT>&& mov) :
        Iterator<K, C, T, D, P, R, IT>(mov),
        Bidirectional<K, T, D, P, R, C, IT>(mov),
        m_addition_handle(mov.m_addition_handle),
        m_subtraction_handle(mov.m_subtraction_handle),
        m_distance_handle(mov.m_distance_handle)
{}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<K, T, D, P, R, C, IT>::
    SetAdditionHandle(AdditionHandleType addition_handle)
{
    m_addition_handle = addition_handle;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<K, T, D, P, R, C, IT>::
    SetAdditionHandle(const RandomAccess<K, T, D, P, R, C, IT>& cpy)
{
    SetAdditionHandle(cpy.m_addition_handle);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<K, T, D, P, R, C, IT>::
    SetSubtractionHandle(SubtractionHandleType subtraction_handle)
{
    m_subtraction_handle = subtraction_handle;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<K, T, D, P, R, C, IT>::
    SetSubtractionHandle(const RandomAccess<K, T, D, P, R, C, IT>& cpy)
{
    SetSubtractionHandle(cpy.m_subtraction_handle);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<K, T, D, P, R, C, IT>::
    SetDistanceHandle(DistanceHandleType distance_handle)
{
    m_distance_handle = distance_handle;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<K, T, D, P, R, C, IT>::
    SetDistanceHandle(const RandomAccess<K, T, D, P, R, C, IT>& cpy)
{
    SetDistanceHandle(cpy.m_distance_handle);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<K, T, D, P, R, C, IT>::
    SetHandle(const RandomAccess<K, T, D, P, R, C, IT>& cpy)
{
    SetAdditionHandle(cpy);
    SetSubtractionHandle(cpy);
    SetDistanceHandle(cpy);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<K, T, D, P, R, C, IT>& RandomAccess<K, T, D, P, R, C, IT>::
    operator=(const RandomAccess<K, T, D, P, R, C, IT>& cpy)
{
    Bidirectional<K, T, D, P, R, C, IT>::operator=(cpy);
    SetHandle(cpy);
    return *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<K, T, D, P, R, C, IT>& 
    RandomAccess<K, T, D, P, R, C, IT>::operator=(P ptr)
{
    Iterator<K, C, T, D, P, R, IT>::operator=(ptr);
    return *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<K, T, D, P, R, C, IT>& 
    RandomAccess<K, T, D, P, R, C, IT>::operator+=(const D& off)
{
    if (m_addition_handle != nullptr)
        m_addition_handle(&m_ptr, off);
    else
        AdditionDefaultHandle(&m_ptr, off);
    return *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<K, T, D, P, R, C, IT>& 
    RandomAccess<K, T, D, P, R, C, IT>::operator-=(const D& off)
{
    if (m_subtraction_handle != nullptr)
        m_subtraction_handle(&m_ptr, off);
    else
        SubtractionDefaultHandle(&m_ptr, off);
    return *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<K, T, D, P, R, C, IT> 
    RandomAccess<K, T, D, P, R, C, IT>::operator+(const D& off) const
{
    RandomAccess<K, T, D, P, R, C, IT> cpy(*this);
    cpy += off;
    return cpy;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<K, T, D, P, R, C, IT> 
    RandomAccess<K, T, D, P, R, C, IT>::operator-(const D& off) const
{
    RandomAccess<K, T, D, P, R, C, IT> cpy(*this);
    cpy -= off;
    return cpy;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
D RandomAccess<K, T, D, P, R, C, IT>::
    operator-(const RandomAccess<K, T, D, P, R, C, IT>& b) const
{
    if (m_distance_handle != nullptr)
        return m_decrement_handle(m_ptr, b.m_ptr);
    return DistanceDefaultHandle(m_ptr, b.m_ptr);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R RandomAccess<K, T, D, P, R, C, IT>::operator[](const D& off)
{
    RandomAccess<K, T, D, P, R, C, IT> cpy(*this);
    cpy += off;
    return *cpy;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
const R RandomAccess<K, T, D, P, R, C, IT>::operator[](const D& off) const
{
    const RandomAccess<K, T, D, P, R, C, IT> cpy(*this);
    cpy += off;
    return *cpy;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool RandomAccess<K, T, D, P, R, C, IT>::
    operator<(const RandomAccess<K, T, D, P, R, C, IT>& b) const
{
     return (b - *this) > 0;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool RandomAccess<K, T, D, P, R, C, IT>::
    operator>(const RandomAccess<K, T, D, P, R, C, IT>& b) const
{
    return b < *this;
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool RandomAccess<K, T, D, P, R, C, IT>::
    operator<=(const RandomAccess<K, T, D, P, R, C, IT>& b) const
{
    return !(*this > b);
}

template<typename K, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool RandomAccess<K, T, D, P, R, C, IT>::
    operator>=(const RandomAccess<K, T, D, P, R, C, IT>& b) const
{
    return !(*this < b);
}

}

}

#endif //!ITERATOR_RANDOM_ACCESS_H_
