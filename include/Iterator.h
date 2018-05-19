#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <iterator>
#include <functional>

#include "id_const/Validation.h"

#include "Handle.h"

namespace simple
{

struct IteratorIDConst : simple::IdentifierConstant {};

namespace iter
{

struct IncrementIDConst : simple::IteratorIDConst {};

}

template<typename Tidc, typename C, typename T, typename D = std::ptrdiff_t,
    typename P = T*, typename R = T&, 
    typename IT = std::iterator<C, T, D, P, R>>
class Iterator : public IT, 
    public Handle<simple::iter::IncrementIDConst, void, P*>
{
public:
    typedef typename simple::id_const::
        Validation<Tidc>::type IDConstType; 
    typedef C CategoryType;
    typedef T ValueType;
    typedef D DistanceType;
    typedef P PointerType;
    typedef R ReferenceType;
    typedef typename Handle<simple::iter::IncrementIDConst, 
        void, P*>::FunctionType IncrementHandleType;
private:
    typedef Handle<simple::iter::IncrementIDConst, 
        void, P*> BaseIncrementHandleType;
private:
    static void IncrementDefaultHandle(P* d_ptr);
protected:
    P m_ptr;
protected:
    Iterator();
    Iterator(P ptr);
    Iterator(const Iterator<Tidc, C, T, D, P, R, IT>& cpy);
    Iterator(Iterator<Tidc, C, T, D, P, R, IT>&& mov);
public:
    void Set(IncrementHandleType) = delete;
    void SetIncrementHandle(IncrementHandleType increment_handle);
    void SetIncrementHandle(const Iterator<Tidc, C, T, D, P, R, IT>& cpy);
public:
    Iterator<Tidc, C, T, D, P, R, IT>& 
        operator=(const Iterator<Tidc, C, T, D, P, R, IT>& cpy);
    Iterator<Tidc, C, T, D, P, R, IT>& operator=(P ptr);
    Iterator<Tidc, C, T, D, P, R, IT>& operator++();
    Iterator<Tidc, C, T, D, P, R, IT> operator++(int);
};


template<typename Tidc, typename C, typename T, typename D,
    typename P, typename R, typename IT>
void Iterator<Tidc, C, T, D, P, R, IT>::IncrementDefaultHandle(P* d_ptr)
{
    if (d_ptr != nullptr)
        ++(*d_ptr);
}

template<typename Tidc, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<Tidc, C, T, D, P, R, IT>::Iterator() :
    BaseIncrementHandleType(&IncrementDefaultHandle),
    m_ptr(nullptr)
{}

template<typename Tidc, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<Tidc, C, T, D, P, R, IT>::Iterator(P ptr) :
    BaseIncrementHandleType(IncrementDefaultHandle),
    m_ptr(ptr)
{}

template<typename Tidc, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<Tidc, C, T, D, P, R, IT>::
    Iterator(const Iterator<Tidc, C, T, D, P, R, IT>& cpy) :
        BaseIncrementHandleType(cpy),
        m_ptr(cpy.m_ptr)
{}

template<typename Tidc, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<Tidc, C, T, D, P, R, IT>::
    Iterator(Iterator<Tidc, C, T, D, P, R, IT>&& mov) :
        BaseIncrementHandleType(mov),
        m_ptr(mov.m_ptr)
{}

template<typename Tidc, typename C, typename T, typename D,
    typename P, typename R, typename IT>
void Iterator<Tidc, C, T, D, P, R, IT>::
    SetIncrementHandle(IncrementHandleType increment_handle)
{
    BaseIncrementHandleType::operator=(increment_handle);
}

template<typename Tidc, typename C, typename T, typename D,
    typename P, typename R, typename IT>
void Iterator<Tidc, C, T, D, P, R, IT>::
    SetIncrementHandle(const Iterator<Tidc, C, T, D, P, R, IT>& cpy)
{
    BaseIncrementHandleType::operator=(cpy);
}

template<typename Tidc, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<Tidc, C, T, D, P, R, IT>& 
    Iterator<Tidc, C, T, D, P, R, IT>::
        operator=(const Iterator<Tidc, C, T, D, P, R, IT>& cpy)
{
    BaseIncrementHandleType::operator=(cpy);
    m_ptr = cpy.m_ptr;
    return *this;
}

template<typename Tidc, typename C, typename T, typename D,
typename P, typename R, typename IT>
Iterator<Tidc, C, T, D, P, R, IT>& 
    Iterator<Tidc, C, T, D, P, R, IT>::operator=(P ptr)
{
    m_ptr = ptr;
    return *this;
}

template<typename Tidc, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<Tidc, C, T, D, P, R, IT>& 
    Iterator<Tidc, C, T, D, P, R, IT>::operator++()
{
    if (static_cast<BaseIncrementHandleType&>(*this))
        BaseIncrementHandleType::operator()(&m_ptr);
    else
        IncrementDefaultHandle(&m_ptr);
    return *this;  
}

template<typename Tidc, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<Tidc, C, T, D, P, R, IT> 
    Iterator<Tidc, C, T, D, P, R, IT>::operator++(int)
{
    Iterator<Tidc, C, T, D, P, R, IT> cpy(*this);
    ++(*this);
    return cpy;
}

}

#endif //!ITERATOR_H_
