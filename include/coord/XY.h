#ifndef COORDINATE_XY_H_
#define COORDINATE_XY_H_

#include <tuple>

#include "Cartesian.h"
#include "X.h"

namespace simple
{
namespace coord
{

template<typename K, typename Tx, typename Ty = Tx, 
    typename D = Cartesian<K, Tx, Ty>>
class XY : public X<K, Tx, D>
{
public:
    typedef K KeyType;
public:
    XY();
    XY(const Tx& x_val, const Ty& y_val);
    XY(const std::tuple<Tx, Ty>& val);
    XY(const XY<K, Tx, Ty, D>& cpy);
    XY(XY<K, Tx, Ty, D>&& mov);
protected:
    template<typename... Targs>
    XY(const Targs&... val_args);
public:
    XY<K, Tx, Ty, D>& operator=(const std::tuple<Tx, Ty>& val);
    XY<K, Tx, Ty, D>& operator=(const XY<K, Tx, Ty, D>& cpy);
public:
    Ty& GetY();
    const Ty& GetY() const;
    void SetY(const Ty& y_val);
    void Set(const Tx& x_val, const Ty& y_val);
};

template<typename K, typename Tx, typename Ty, typename D>
XY<K, Tx, Ty, D>::XY()
{}

template<typename K, typename Tx, typename Ty, typename D>
XY<K, Tx, Ty, D>::XY(const Tx& x_val, const Ty& y_val) :
    X<K, Tx, D>(x_val, y_val)
{}

template<typename K, typename Tx, typename Ty, typename D>
XY<K, Tx, Ty, D>::XY(const std::tuple<Tx, Ty>& val) :
    X<K, Tx, D>(val)
{}

template<typename K, typename Tx, typename Ty, typename D>
XY<K, Tx, Ty, D>::XY(const XY<K, Tx, Ty, D>& cpy) :
    X<K, Tx, D>(cpy)
{}

template<typename K, typename Tx, typename Ty, typename D>
XY<K, Tx, Ty, D>::XY(XY<K, Tx, Ty, D>&& mov) :
    X<K, Tx, D>(mov)
{}

template<typename K, typename Tx, typename Ty, typename D>
template<typename... Targs>
XY<K, Tx, Ty, D>::XY(const Targs&... val_args) :
    X<K, Tx, D>(val_args...)
{}

template<typename K, typename Tx, typename Ty, typename D>
XY<K, Tx, Ty, D>& XY<K, Tx, Ty, D>::operator=(const std::tuple<Tx, Ty>& val)
{
    D::operator=(val);
    return *this;
}

template<typename K, typename Tx, typename Ty, typename D>
XY<K, Tx, Ty, D>& XY<K, Tx, Ty, D>::operator=(const XY<K, Tx, Ty, D>& cpy)
{
    D::operator=(cpy);
    return *this;
}

template<typename K, typename Tx, typename Ty, typename D>
Ty& XY<K, Tx, Ty, D>::GetY()
{
    return D::Get<1>();
}

template<typename K, typename Tx, typename Ty, typename D>
const Ty& XY<K, Tx, Ty, D>::GetY() const
{
    return D::Get<1>();
}

template<typename K, typename Tx, typename Ty, typename D>
void XY<K, Tx, Ty, D>::SetY(const Ty& y_val)
{
    D::Get<1>() = y_val;
}

template<typename K, typename Tx, typename Ty, typename D>
void XY<K, Tx, Ty, D>::Set(const Tx& x_val, const Ty& y_val)
{
    D::Set(x_val, y_val);
}

}

}

#endif //!COORDINATE_XY_H_
