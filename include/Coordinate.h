#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <tuple>

#include "IdentifierConstant.h"
#include "id_const/Validation.h"
#include "Value.h"

namespace simple
{

struct CoordinateIDConst : simple::IdentifierConstant {};

template<typename Tidc, typename T>
class Coordinate
{
public:
    typedef typename simple::id_const::
        Validation<Tidc>::type IdConstType;
    typedef T ValueType;
private:
    Value<CoordinateTidcey, T> m_value;
public:
    Coordinate();
    template<typename... Ts>
    Coordinate(const Ts&... values);
    Coordinate(const T& value)
    Coordinate(const Coordinate<Tidc, T>& cpy);
    Coordinate(Coordinate<Tidc, T>&& mov);
public:
    Coordinate<Tidc, T>& operator=(const T& val);
    Coordinate<Tidc, T>& operator=(const Coordinate<Tidc, T>& cpy);
    template<std::size_t I>
    typename std::tuple_element<I, T>::type& Get();
    template<std::size_t I>
    const typename std::tuple_element<I, T>::type& Get() const;
    template<typename... Targs>
    void Set(const Targs&... val_args);
};

template<typename Tidc, typename T>
Coordinate<Tidc, T>::Coordinate()
{}

template<typename Tidc, typename T>
template<typename... Ts>
Coordinate<Tidc, T>::Coordinate(const Ts&... val_args) :
    m_value(T(val_args...))
{}

template<typename Tidc, typename T>
Coordinate<Tidc, T>::Coordinate(const T& val) :
    m_value(val)
{}

template<typename Tidc, typename T>
Coordinate<Tidc, T>::Coordinate(const Coordinate<Tidc, T>& cpy) :
    m_value(cpy.m_value)
{}

template<typename Tidc, typename T>
Coordinate<Tidc, T>::Coordinate(Coordinate<Tidc, T>&& mov) :
    m_value(mov.m_value)
{}

template<typename Tidc, typename T>
Coordinate<Tidc, T>& Coordinate<Tidc, T>::operator=(const T& val)
{
    m_value.operator=(val);
    return *this;
}

template<typename Tidc, typename T>
Coordinate<Tidc, T>& Coordinate<Tidc, T>::operator=(const Coordinate<Tidc, T>& cpy)
{
    m_value.operator=(cpy.m_value);
    return *this;
}

template<typename Tidc, typename T>
template<std::size_t I>
typename std::tuple_element<I, T>::type& Coordinate<Tidc, T>::Get()
{
    return std::get<I>(m_value.Get());
}

template<typename Tidc, typename T>
template<std::size_t I>
const typename std::tuple_element<I, T>::type& Coordinate<Tidc, T>::Get() const
{
    return std::get<I>(m_value.Get());
}

template<typename Tidc, typename T>
template<typename... Targs>
void Coordinate<Tidc, T>::Set(const Targs&... val_args)
{
    m_value.Get() = std::tie(val_args);
}

}

#endif //!COORDINATE_H_
