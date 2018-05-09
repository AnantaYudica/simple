#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <iterator>
#include <functional>

namespace simple
{

template<typename K, typename C, typename T, typename D = std::ptrdiff_t,
    typename P = T*, typename R = T&, typename IT = std::iterator<C, T, D, P, R>>
class Iterator : public IT
{
public:
    typedef K KeyType; 
    typedef C CategoryType;
    typedef T ValueType;
    typedef D DistanceType;
    typedef P PointerType;
    typedef R ReferenceType;
public:
    typedef std::function<void(P*)> IncrementHandleType;
private:
    static void IncrementDefaultHandle(P* d_ptr);
protected:
    P m_ptr;
private:
    IncrementHandleType m_increment_handle;
protected:
    Iterator();
    Iterator(P ptr);
    Iterator(const Iterator<K, C, T, D, P, R, IT>& cpy);
    Iterator(Iterator<K, C, T, D, P, R, IT>&& mov);
public:
    void SetIncrementHandle(IncrementHandleType increment_handle);
    void SetIncrementHandle(const Iterator<K, C, T, D, P, R, IT>& cpy);
public:
    Iterator<K, C, T, D, P, R, IT>& 
        operator=(const Iterator<K, C, T, D, P, R, IT>& cpy);
    Iterator<K, C, T, D, P, R, IT>& operator=(P ptr);
    Iterator<K, C, T, D, P, R, IT>& operator++();
    Iterator<K, C, T, D, P, R, IT> operator++(int);
};


template<typename K, typename C, typename T, typename D,
    typename P, typename R, typename IT>
void Iterator<K, C, T, D, P, R, IT>::IncrementDefaultHandle(P* d_ptr)
{
    if (d_ptr != nullptr)
        ++(*d_ptr);
}

template<typename K, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<K, C, T, D, P, R, IT>::Iterator() :
    m_ptr(nullptr),
    m_increment_handle(IncrementDefaultHandle)
{}

template<typename K, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<K, C, T, D, P, R, IT>::Iterator(P ptr) :
    m_ptr(ptr),
    m_increment_handle(IncrementDefaultHandle)
{}

template<typename K, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<K, C, T, D, P, R, IT>::
    Iterator(const Iterator<K, C, T, D, P, R, IT>& cpy) :
        m_ptr(cpy.m_ptr),
        m_increment_handle(cpy.m_increment_handle)
{}

template<typename K, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<K, C, T, D, P, R, IT>::
    Iterator(Iterator<K, C, T, D, P, R, IT>&& mov) :
        m_ptr(mov.m_ptr),
        m_increment_handle(mov.m_increment_handle)
{}

template<typename K, typename C, typename T, typename D,
    typename P, typename R, typename IT>
void Iterator<K, C, T, D, P, R, IT>::
    SetIncrementHandle(IncrementHandleType increment_handle)
{
    m_increment_handle = increment_handle;
}

template<typename K, typename C, typename T, typename D,
    typename P, typename R, typename IT>
void Iterator<K, C, T, D, P, R, IT>::
    SetIncrementHandle(const Iterator<K, C, T, D, P, R, IT>& cpy)
{
    SetIncrementHandle(cpy.m_increment_handle);
}

template<typename K, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<K, C, T, D, P, R, IT>& 
    Iterator<K, C, T, D, P, R, IT>::
        operator=(const Iterator<K, C, T, D, P, R, IT>& cpy)
{
    m_ptr = cpy.m_ptr;
    m_increment_handle = cpy.m_increment_handle;
    return *this;
}

template<typename K, typename C, typename T, typename D,
typename P, typename R, typename IT>
Iterator<K, C, T, D, P, R, IT>& 
    Iterator<K, C, T, D, P, R, IT>::operator=(P ptr)
{
    m_ptr = ptr;
    return *this;
}

template<typename K, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<K, C, T, D, P, R, IT>& 
    Iterator<K, C, T, D, P, R, IT>::operator++()
{
    if (m_increment_handle)
        m_increment_handle(&m_ptr);
    else
        IncrementDefaultHandle(&m_ptr);
    return *this;  
}

template<typename K, typename C, typename T, typename D,
    typename P, typename R, typename IT>
Iterator<K, C, T, D, P, R, IT> 
    Iterator<K, C, T, D, P, R, IT>::operator++(int)
{
    Iterator<K, C, T, D, P, R, IT> cpy(*this);
    ++(*this);
    return cpy;
}

}

#endif //!ITERATOR_H_
