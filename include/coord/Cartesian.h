#ifndef COORDINATE_CARTESIAN_H_
#define COORDINATE_CARTESIAN_H_

#include <tuple>

#include "../Coordinate.h"

namespace simple
{
namespace coord
{

template<typename K, typename... Targs>
class Cartesian : public Coordinate<K, std::tuple<Targs...>>
{
public:
    typedef K KeyType;
public:
    static constexpr std::size_t Dimensional = sizeof...(Targs...);
public:
    Cartesian();
    Cartesian(const Targs&... val_args);
    Cartesian(const std::tuple<Targs...>& val);
    Cartesian(const Cartesian<K, Targs...>& cpy);
    Cartesian(Cartesian<K, Targs...>&& mov)
public:
    Cartesian<K, Targs...>& operator=(const std::tuple<Targs...>& val);
    Cartesian<K, Targs...>& operator=(const Cartesian<K, Targs...>& cpy);
public:
    template<std::size_t AXIS_ID>
    auto Get();
    template<std::size_t AXIS_ID>
    auto Get() const;
    template<std::size_t AXIS_ID, typename T>
    void Set(const Targs&... val_args);
};

template<typename K, typename... Targs>
Cartesian<K, Targs...>::Cartesian()
{}

template<typename K, typename... Targs>
Cartesian<K, Targs...>::Cartesian(const Targs&... val_args) :
    Coordinate<K, std::tuple<Targs...>>(val_args)
{}

template<typename K, typename... Targs>
Cartesian<K, Targs...>::Cartesian(const std::tuple<Targs...>& val) :
    Coordinate<K, std::tuple<Targs...>>(val)
{}

template<typename K, typename... Targs>
Cartesian<K, Targs...>::Cartesian(const Cartesian<K, Targs...>& cpy) :
    Coordinate<K, std::tuple<Targs...>>(cpy)
{}

template<typename K, typename... Targs>
Cartesian<K, Targs...>::Cartesian(Cartesian<K, Targs...>&& mov) :
    Coordinate<K, std::tuple<Targs...>>(mov)
{}

template<typename K, typename... Targs>
Cartesian<K, Targs...>& 
Cartesian<K, Targs...>::operator=(const std::tuple<Targs...>& val)
{
    Coordinate<K, std::tuple<Targs...>>::operator=(val);
    return *this;
}

template<typename K, typename... Targs>
Cartesian<K, Targs...>& 
Cartesian<K, Targs...>::operator=(const Cartesian<K, Targs...>& cpy)
{
    Coordinate<K, std::tuple<Targs...>>::operator=(cpy);
    return *this;
}

template<typename K, typename... Targs>
template<std::size_t AXIS_ID>
auto Cartesian<K, Targs...>::Get()
{
    return Coordinate<K, std::tuple<Targs...>>::Get<AXIS_ID>();
}

template<typename K, typename... Targs>
template<std::size_t AXIS_ID>
auto Cartesian<K, Targs...>::Get() const
{
    return Coordinate<K, std::tuple<Targs...>>::Get<AXIS_ID>();
}

template<typename K, typename... Targs>
template<std::size_t AXIS_ID, typename T>
void Cartesian<K, Targs...>::Set(const Targs&... val_args)
{
    Coordinate<K, std::tuple<Targs...>>::Set<AXIS_ID>(val_args);
}

}

}

#endif //!COORDINATE_CARTESIAN_H_