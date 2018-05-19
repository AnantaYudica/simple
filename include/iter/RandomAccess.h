#ifndef ITERATOR_RANDOM_ACCESS_H_
#define ITERATOR_RANDOM_ACCESS_H_

#include <iterator>

#include "../id_const/Validation.h"

#include "../Handle.h"

#include "../Iterator.h"
#include "Bidirectional.h"

namespace simple
{
namespace iter
{

struct RandomAccessIDConst : simple::iter::BidirectionalIDConst {};

struct AdditionHandleIDConst : simple::iter::RandomAccessIDConst {};
struct SubtractionHandleIDConst : simple::iter::RandomAccessIDConst {};
struct DistanceHandleIDConst : simple::iter::RandomAccessIDConst {};

template<typename Tidc, typename T, typename D = std::ptrdiff_t, 
    typename P = T*, typename R = T&, 
    typename C = std::random_access_iterator_tag,
    typename IT = std::iterator<C, T, D, P, R>>
class RandomAccess : 
    public simple::iter::Bidirectional<Tidc, T, D, P, R, C, IT>,
    public simple::Handle<simple::iter::
        AdditionHandleIDConst, void, P*, const D&>,
    public simple::Handle<simple::iter::
		SubtractionHandleIDConst, void, P*, const D&>,
    public simple::Handle<simple::iter::
        DistanceHandleIDConst, D, const P, const P>,
    public virtual simple::Iterator<Tidc, C, T, D, P, R, IT>
{
public:
    typedef typename simple::id_const::Validation<Tidc>::Type IDConstType;
    typedef C CategoryType;
    typedef T ValueType;
    typedef D DistanceType;
    typedef P PointerType;
    typedef R ReferenceType;
    typedef typename simple::Handle<simple::iter::AdditionHandleIDConst, 
        void, P*, const D&>::FunctionType AdditionHandleType;
    typedef typename simple::Handle<simple::iter::SubtractionHandleIDConst, 
        void, P*, const D&>::FunctionType SubtractionHandleType;
    typedef typename simple::Handle<simple::iter::SubtractionHandleIDConst, 
        void, P*, const D&>::FunctionType DistanceHandleType;
private:
    typedef simple::iter::Bidirectional<Tidc, 
        T, D, P, R, C, IT> BaseBidirectionalType;
    typedef simple::Handle<simple::iter::AdditionHandleIDConst, 
        void, P*, const D&> BaseAdditionHandleType;
    typedef simple::Handle<simple::iter::SubtractionHandleIDConst, 
        void, P*, const D&> BaseSubtractionHandleType;
    typedef simple::Handle<simple::iter::DistanceHandleIDConst, 
        D, const P, const P> BaseDistanceHandleType;
    typedef simple::Iterator<Tidc, C, T, D, P, R, IT> BaseIteratorType;
private:
    void AdditionDefaultHandle(P* d_ptr, const D& distance);
    void SubtractionDefaultHandle(P* d_ptr, const D& distance);
    D DistanceDefaultHandle(const P a, const P b);
private:
    DistanceHandleType m_distance_handle;
public:
    RandomAccess();
    RandomAccess(P ptr);
    RandomAccess(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy);
    RandomAccess(RandomAccess<Tidc, T, D, P, R, C, IT>&& mov);
public:
    void Set(...) = delete;
    void SetAdditionHandle(AdditionHandleType addition_handle);
    void SetAdditionHandle(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy);
    void SetSubtractionHandle(SubtractionHandleType subtraction_handle);
    void SetSubtractionHandle(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy);
    void SetDistanceHandle(DistanceHandleType distance_handle);
    void SetDistanceHandle(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy);
    void SetHandle(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy);
public:
    RandomAccess<Tidc, T, D, P, R, C, IT>& 
        operator=(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy);
    RandomAccess<Tidc, T, D, P, R, C, IT>& operator=(P ptr);
    RandomAccess<Tidc, T, D, P, R, C, IT>& operator+=(const D& off);
    RandomAccess<Tidc, T, D, P, R, C, IT>& operator-=(const D& off);
    RandomAccess<Tidc, T, D, P, R, C, IT> operator+(const D& off) const;
    RandomAccess<Tidc, T, D, P, R, C, IT> operator-(const D& off) const;
    D operator-(const RandomAccess<Tidc, T, D, P, R, C, IT>& b) const;
    R operator[](const D& off);
    const R operator[](const D& off) const;
    bool operator<(const RandomAccess<Tidc, T, D, P, R, C, IT>& b) const;
    bool operator>(const RandomAccess<Tidc, T, D, P, R, C, IT>& b) const;
    bool operator<=(const RandomAccess<Tidc, T, D, P, R, C, IT>& b) const;
    bool operator>=(const RandomAccess<Tidc, T, D, P, R, C, IT>& b) const;
};

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<Tidc, T, D, P, R, C, IT>::
    AdditionDefaultHandle(P* d_ptr, const D& distance)
{
    if (d_ptr != nullptr)
        *d_ptr += distance;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<Tidc, T, D, P, R, C, IT>::
    SubtractionDefaultHandle(P* d_ptr, const D& distance)
{
    if (d_ptr != nullptr)
        *d_ptr -= distance;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
D RandomAccess<Tidc, T, D, P, R, C, IT>::
    DistanceDefaultHandle(const P a, const P b)
{
    return (a > b ? a - b : b - a);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<Tidc, T, D, P, R, C, IT>::RandomAccess() :
    BaseIteratorType(nullptr),
    BaseAdditionHandleType(AdditionDefaultHandle),
    BaseSubtractionHandleType(SubtractionDefaultHandle),
    BaseDistanceHandleType(DistanceDefaultHandle)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<Tidc, T, D, P, R, C, IT>::RandomAccess(P ptr) :
    BaseIteratorType(ptr),
    BaseBidirectionalType(ptr),
    BaseAdditionHandleType(AdditionDefaultHandle),
    BaseSubtractionHandleType(SubtractionDefaultHandle),
    BaseDistanceHandleType(DistanceDefaultHandle)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<Tidc, T, D, P, R, C, IT>::
    RandomAccess(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy) :
        BaseIteratorType(cpy),
        BaseBidirectionalType(cpy),
        BaseAdditionHandleType(cpy),
        BaseSubtractionHandleType(cpy),
        BaseDistanceHandleType(cpy)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<Tidc, T, D, P, R, C, IT>::
    RandomAccess(RandomAccess<Tidc, T, D, P, R, C, IT>&& mov) :
        BaseIteratorType(mov),
        BaseBidirectionalType(mov),
        BaseAdditionHandleType(mov),
        BaseSubtractionHandleType(mov),
        BaseDistanceHandleType(mov)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<Tidc, T, D, P, R, C, IT>::
    SetAdditionHandle(AdditionHandleType addition_handle)
{
    BaseAdditionHandleType::operator=(addition_handle);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<Tidc, T, D, P, R, C, IT>::
    SetAdditionHandle(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy)
{
    BaseAdditionHandleType::operator=(cpy);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<Tidc, T, D, P, R, C, IT>::
    SetSubtractionHandle(SubtractionHandleType subtraction_handle)
{
    BaseSubtractionHandleType::operator=(subtraction_handle);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<Tidc, T, D, P, R, C, IT>::
    SetSubtractionHandle(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy)
{
    BaseSubtractionHandleType::operator=(cpy);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<Tidc, T, D, P, R, C, IT>::
    SetDistanceHandle(DistanceHandleType distance_handle)
{
    BaseDistanceHandleType::operator=(distance_handle);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<Tidc, T, D, P, R, C, IT>::
    SetDistanceHandle(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy)
{
    BaseDistanceHandleType::operator=(cpy);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void RandomAccess<Tidc, T, D, P, R, C, IT>::
    SetHandle(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy)
{
    SetAdditionHandle(cpy);
    SetSubtractionHandle(cpy);
    SetDistanceHandle(cpy);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<Tidc, T, D, P, R, C, IT>& RandomAccess<Tidc, T, D, P, R, C, IT>::
    operator=(const RandomAccess<Tidc, T, D, P, R, C, IT>& cpy)
{
    BaseBidirectionalType::operator=(cpy);
    SetHandle(cpy);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<Tidc, T, D, P, R, C, IT>& 
    RandomAccess<Tidc, T, D, P, R, C, IT>::operator=(P ptr)
{
    BaseIteratorType::operator=(ptr);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<Tidc, T, D, P, R, C, IT>& 
    RandomAccess<Tidc, T, D, P, R, C, IT>::operator+=(const D& off)
{
    if (static_cast<BaseAdditionHandleType&>(*this))
        BaseAdditionHandleType::operator()(&m_ptr, off);
    else
        AdditionDefaultHandle(&m_ptr, off);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<Tidc, T, D, P, R, C, IT>& 
    RandomAccess<Tidc, T, D, P, R, C, IT>::operator-=(const D& off)
{
    if (static_cast<BaseSubtractionHandleType&>(*this))
        BaseSubtractionHandleType::operator()(&m_ptr, off);
    else
        SubtractionDefaultHandle(&m_ptr, off);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<Tidc, T, D, P, R, C, IT> 
    RandomAccess<Tidc, T, D, P, R, C, IT>::operator+(const D& off) const
{
    RandomAccess<Tidc, T, D, P, R, C, IT> cpy(*this);
    cpy += off;
    return cpy;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
RandomAccess<Tidc, T, D, P, R, C, IT> 
    RandomAccess<Tidc, T, D, P, R, C, IT>::operator-(const D& off) const
{
    RandomAccess<Tidc, T, D, P, R, C, IT> cpy(*this);
    cpy -= off;
    return cpy;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
D RandomAccess<Tidc, T, D, P, R, C, IT>::
    operator-(const RandomAccess<Tidc, T, D, P, R, C, IT>& b) const
{
    if (static_cast<BaseDistanceHandleType&>(*this))
        return BaseDistanceHandleType::operator()(m_ptr, b.m_ptr);
    return DistanceDefaultHandle(m_ptr, b.m_ptr);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R RandomAccess<Tidc, T, D, P, R, C, IT>::operator[](const D& off)
{
    RandomAccess<Tidc, T, D, P, R, C, IT> cpy(*this);
    cpy += off;
    return *cpy;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
const R RandomAccess<Tidc, T, D, P, R, C, IT>::operator[](const D& off) const
{
    const RandomAccess<Tidc, T, D, P, R, C, IT> cpy(*this);
    cpy += off;
    return *cpy;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool RandomAccess<Tidc, T, D, P, R, C, IT>::
    operator<(const RandomAccess<Tidc, T, D, P, R, C, IT>& b) const
{
     return (b - *this) > 0;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool RandomAccess<Tidc, T, D, P, R, C, IT>::
    operator>(const RandomAccess<Tidc, T, D, P, R, C, IT>& b) const
{
    return b < *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool RandomAccess<Tidc, T, D, P, R, C, IT>::
    operator<=(const RandomAccess<Tidc, T, D, P, R, C, IT>& b) const
{
    return !(*this > b);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
bool RandomAccess<Tidc, T, D, P, R, C, IT>::
    operator>=(const RandomAccess<Tidc, T, D, P, R, C, IT>& b) const
{
    return !(*this < b);
}

}

}


#endif //!ITERATOR_RANDOM_ACCESS_H_
