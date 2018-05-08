#ifndef COORDINATE_POLAR_H_
#define COORDINATE_POLAR_H_

#include <tuple>

#include "../Coordinate.h"

namespace simple
{
namespace coord
{

template<typename K, typename T1, typename T2>
struct Polar : public Coordinate<K, std::tuple<T1, T2>>
{
public:
    typedef K KeyType;
public:
    Polar();
    Polar(const T1& radial_val, const T2& angular_val);
    Polar(const std::tuple<T1, T2>& val);
    Polar(const Polar<K, T1, T2>& cpy);
    Polar(Polar<K, T1, T2>&& mov);
public:
    Polar<K, T1, T2>& operator=(const std::tuple<T1, T2>& val);
    Polar<K, T1, T2>& operator=(const Polar<K, T1, T2>& cpy);
public:
    T1& GetRadial();
    T2& GetAngular();
    const T1& GetRadial() const;
    const T2& GetAngular() const;
    void SetRadial(const T1& radial_val);
    void SetAngular(const T2& angular_val);
    void Set(const T1& radial_val, const T2& angular_val);
};

template<typename K, typename T1, typename T2>
Polar<K, T1, T2>::Polar()
{}

template<typename K, typename T1, typename T2>
Polar<K, T1, T2>::Polar(const T1& radial_val, const T2& angular_val) :
    Coordinate<K, std::tuple<T1, T2>>(radial_val, angular_val)
{}

template<typename K, typename T1, typename T2>
Polar<K, T1, T2>::Polar(const std::tuple<T1, T2>& val) :
    Coordinate<K, std::tuple<T1, T2>>(val)
{}

template<typename K, typename T1, typename T2>
Polar<K, T1, T2>::Polar(const Polar<K, T1, T2>& cpy) :
    Coordinate<K, std::tuple<T1, T2>>(cpy)
{}

template<typename K, typename T1, typename T2>
Polar<K, T1, T2>::Polar(Polar<K, T1, T2>&& mov) :
    Coordinate<K, std::tuple<T1, T2>>(mov)
{}

template<typename K, typename T1, typename T2>
Polar<K, T1, T2>& Polar<K, T1, T2>::operator=(const std::tuple<T1, T2>& val)
{
    Coordinate<K, std::tuple<T1, T2>>::operator=(val);
    return *this;
}

template<typename K, typename T1, typename T2>
Polar<K, T1, T2>& Polar<K, T1, T2>::operator=(const Polar<K, T1, T2>& cpy)
{
    Coordinate<K, std::tuple<T1, T2>>::operator=(cpy);
    return *this;
}

template<typename K, typename T1, typename T2>
T1& Polar<K, T1, T2>::GetRadial()
{
    return Coordinate<K, std::tuple<T1, T2>>::Get<0>();
}

template<typename K, typename T1, typename T2>
T2& Polar<K, T1, T2>::GetAngular()
{
    return Coordinate<K, std::tuple<T1, T2>>::Get<1>();
}

template<typename K, typename T1, typename T2>
const T1& Polar<K, T1, T2>::GetRadial() const
{
    return Coordinate<K, std::tuple<T1, T2>>::Get<0>();
}

template<typename K, typename T1, typename T2>
const T2& Polar<K, T1, T2>::GetAngular() const
{
    return Coordinate<K, std::tuple<T1, T2>>::Get<1>();
}

template<typename K, typename T1, typename T2>
void Polar<K, T1, T2>::SetRadial(const T1& radial_val)
{
    Coordinate<K, std::tuple<T1, T2>>::Set<0>(radial_val);
}

template<typename K, typename T1, typename T2>
void Polar<K, T1, T2>::SetAngular(const T2& angular_val)
{
    Coordinate<K, std::tuple<T1, T2>>::Set<1>(angular_val);
}

template<typename K, typename T1, typename T2>
void Polar<K, T1, T2>::Set(const T1& radial_val, const T2& angular_val)
{
    Coordinate<K, std::tuple<T1, T2>>::Set(radial_val, angular_val);    
}

}

}

#endif //!COORDINATE_POLAR_H_
