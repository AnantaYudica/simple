#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <tuple>
#include <array>

#include "Value.h"

namespace simple
{

struct CoordinateKey;

template<typename K, typename T>
class Coordinate
{
public:
    typedef K KeyType;
    typedef T ValueType;
private:
    Value<CoordinateKey, T> m_value;
public:
    Coordinate();
    template<typename... Ts>
    Coordinate(const Ts&... values);
    Coordinate(const T& value)
    Coordinate(const Coordinate<K, T>& cpy);
    Coordinate(Coordinate<K, T>&& mov);
public:
    Coordinate<K, T>& operator=(const T& val);
    Coordinate<K, T>& operator=(const Coordinate<K, T>& cpy);
    template<std::size_t I>
    typename std::tuple_element<I, T>::type& Get();
    template<std::size_t I>
    const typename std::tuple_element<I, T>::type& Get() const;
    template<typename... Targs>
    void Set(const Targs&... val_args);
};

template<typename K, typename T>
Coordinate<K, T>::Coordinate()
{}

template<typename K, typename T>
template<typename... Ts>
Coordinate<K, T>::Coordinate(const Ts&... val_args) :
    m_value(T(val_args...))
{}

template<typename K, typename T>
Coordinate<K, T>::Coordinate(const T& val) :
    m_value(val)
{}

template<typename K, typename T>
Coordinate<K, T>::Coordinate(const Coordinate<K, T>& cpy) :
    m_value(cpy.m_value)
{}

template<typename K, typename T>
Coordinate<K, T>::Coordinate(Coordinate<K, T>&& mov) :
    m_value(mov.m_value)
{}

template<typename K, typename T>
Coordinate<K, T>& Coordinate<K, T>::operator=(const T& val)
{
    m_value.operator=(val);
    return *this;
}

template<typename K, typename T>
Coordinate<K, T>& Coordinate<K, T>::operator=(const Coordinate<K, T>& cpy)
{
    m_value.operator=(cpy.m_value);
    return *this;
}

template<typename K, typename T>
template<std::size_t I>
typename std::tuple_element<I, T>::type& Coordinate<K, T>::Get()
{
    return std::get<I>(m_value.Get());
}

template<typename K, typename T>
template<std::size_t I>
const typename std::tuple_element<I, T>::type& Coordinate<K, T>::Get() const
{
    return std::get<I>(m_value.Get());
}

template<typename K, typename T>
template<typename... Targs>
void Coordinate<K, T>::Set(const Targs&... val_args)
{
    m_value.Get() = std::tie(val_args);
}

}

#endif //!COORDINATE_H_
