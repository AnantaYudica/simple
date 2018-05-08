#ifndef COORDINATE_XYZ_H_
#define COORDINATE_XYZ_H_

#include <tuple>

#include "Cartesian.h"
#include "XY.h"

namespace simple
{
namespace coord
{

template<typename K, typename Tx, typename Ty = Tx, typename Tz = Ty, 
    typename D = Cartesian<K, Tx, Ty, Tz>>
class XYZ : public XY<K, Tx, Ty, D>
{
public:
    typedef K KeyType;
public:
    XYZ();
    XYZ(const Tx& x_val, const Ty& y_val, const Tz& z_val);
    XYZ(const std::tuple<Tx, Ty, Tz>& val);
    XYZ(const XYZ<K, Tx, Ty, Tz, D>& cpy);
    XYZ(XYZ<K, Tx, Ty, Tz, D>&& mov);
protected:
    template<typename... Targs>
    XYZ(const Targs&... val_args);
public:
    XYZ<K, Tx, Ty, Tz, D>& operator=(const std::tuple<Tx, Ty, Tz>& val);
    XYZ<K, Tx, Ty, Tz, D>& operator=(const XYZ<K, Tx, Ty, Tz, D>& cpy);
public:
    Tz& GetZ();
    const Tz& GetZ() const;
    void SetZ(const Ty& z_val);
    void Set(const Tx& x_val, const Ty& y_val, const Tz& z_val);
};

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
XYZ<K, Tx, Ty, Tz, D>::XYZ()
{}

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
XYZ<K, Tx, Ty, Tz, D>::XYZ(const Tx& x_val, const Ty& y_val, const Tz& z_val) :
    XY<K, Tx, Ty, D>(x_val, y_val, z_val)
{}

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
XYZ<K, Tx, Ty, Tz, D>::XYZ(const std::tuple<Tx, Ty, Tz>& val) :
    XY<K, Tx, Ty, D>(val)
{}

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
XYZ<K, Tx, Ty, Tz, D>::XYZ(const XYZ<K, Tx, Ty, Tz, D>& cpy) :
    XY<K, Tx, Ty, D>(cpy)
{}

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
XYZ<K, Tx, Ty, Tz, D>::XYZ(XYZ<K, Tx, Ty, Tz, D>&& mov) :
    XY<K, Tx, Ty, D>(mov)
{}

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
template<typename... Targs>
XYZ<K, Tx, Ty, Tz, D>::XYZ(const Targs&... val_args) :
    XY<K, Tx, Ty, D>(val_args...)
{}

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
XYZ<K, Tx, Ty, Tz, D>& 
XYZ<K, Tx, Ty, Tz, D>::operator=(const std::tuple<Tx, Ty, Tz>& val)
{
    D::operator=(val);
    return *this;
}

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
XYZ<K, Tx, Ty, Tz, D>& operator=(const XYZ<K, Tx, Ty, Tz, D>& cpy)
{
    D::operator=(cpy);
    return *this;
}

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
Tz& XYZ<K, Tx, Ty, Tz, D>::GetZ()
{
    return D::Get<2>();
}

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
const Tz& XYZ<K, Tx, Ty, Tz, D>::GetZ() const
{
    return D::Get<2>();
}

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
void XYZ<K, Tx, Ty, Tz, D>::SetZ(const Ty& z_val)
{
    D::Get<2>() = z_val;
}

template<typename K, typename Tx, typename Ty, typename Tz, typename D>
void XYZ<K, Tx, Ty, Tz, D>::Set(const Tx& x_val, 
    const Ty& y_val, const Tz& z_val)
{
    D::Set(x_val, y_val, z_val);
}

}

}

#endif //!COORDINATE_XYZ_H_
