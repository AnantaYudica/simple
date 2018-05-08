#ifndef COORDINATE_X_H_
#define COORDINATE_X_H_

#include <tuple>

#include "Cartesian.h"

namespace simple
{
namespace coord
{

template<typename K, typename Tx, typename D = Cartesian<K, Tx>>
class X : public D
{
public:
    typedef K KeyType;
public:
    X();
    X(const Tx& x_val);
    X(const std::tuple<Tx>& val);
    X(const X<K, Tx, D>& cpy);
    X(X<K, Tx, D>&& mov);
protected:
    template<typename... Targs>
    X(const Targs&... val_args);
public:
    X<K, Tx, D>& operator=(const std::tuple<Tx>& val);
    X<K, Tx, D>& operator=(const X<K, Tx, D>& cpy);
public:
    Tx& GetX();
    const Tx& GetX() const;
    void SetX(const Tx& x_val);
    void Set(const Tx& x_val);
};

template<typename K, typename Tx, typename D>
X<K, Tx, D>::X()
{}

template<typename K, typename Tx, typename D>
X<K, Tx, D>::X(const Tx& x_val) :
    D(x_val)
{}

template<typename K, typename Tx, typename D>
X<K, Tx, D>::X(const std::tuple<Tx>& val) :
    D(val)
{}

template<typename K, typename Tx, typename D>
X<K, Tx, D>::X(const X<K, Tx, D>& cpy) :
    D(cpy)
{}

template<typename K, typename Tx, typename D>
X<K, Tx, D>::X(X<K, Tx, D>&& mov) :
    D(mov)
{}

template<typename K, typename Tx, typename D>
template<typename... Targs>
X<K, Tx, D>::X(const Targs&... val_args) :
    D(val_args...)
{}

template<typename K, typename Tx, typename D>
X<K, Tx, D>& X<K, Tx, D>::operator=(const std::tuple<Tx>& val)
{
    D::operator=(val);
    return *this;
}

template<typename K, typename Tx, typename D>
X<K, Tx, D>& X<K, Tx, D>::operator=(const X<K, Tx, D>& cpy)
{
    D::operator=(cpy);
    return *this;
}

template<typename K, typename Tx, typename D>
Tx& X<K, Tx, D>::GetX()
{
    return D::Get<0>();
}

template<typename K, typename Tx, typename D>
const Tx& X<K, Tx, D>::GetX() const
{
    return D::Get<0>();
}

template<typename K, typename Tx, typename D>
void X<K, Tx, D>::SetX(const Tx& x_val)
{
    D::Set(x_val);
}

template<typename K, typename Tx, typename D>
void X<K, Tx, D>::Set(const Tx& x_val)
{
    D::Set(x_val);
}

}

}

#endif //!COORDINATE_X_H_
