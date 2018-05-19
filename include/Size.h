#ifndef SIZE_H_
#define SIZE_H_

#include "IdentifierConstant.h"
#include "id_const/Validation.h"
#include "Value.h"

namespace simple
{

struct SizeIDConst : simple::IdentifierConstant {};

template<typename Tidc, typename T>
class Size : public Value<SizeIDConst, T>
{
public:
    typedef typename simple::id_const::
        Validation<Tidc>::type IDConstType;
    typedef T ValueType;
public:
    Size();
    Size(const T& val);
    Size(const Size<Tidc, T>& cpy);
    Size(Size<Tidc, T>&& mov);
public:
    Size<Tidc, T>& operator=(const Size<Tidc, T>& cpy);
    Size<Tidc, T>& operator=(const T& val);
    Size<Tidc, T>& operator=(const BaseType& val);
    using BaseType::operator T&();
    using BaseType::operator const T&() const;
};

template<typename Tidc, typename T>
Size<Tidc, T>::Size()
{}

template<typename Tidc, typename T>
Size<Tidc, T>::Size(const T& val) :
    Value<SizeIDConst, T>(val)
{}

template<typename Tidc, typename T>
Size<Tidc, T>::Size(const Size<Tidc, T>& cpy) :
    Value<SizeIDConst, T>(cpy)
{}

template<typename Tidc, typename T>
Size<Tidc, T>::Size(Size<Tidc, T>&& mov) :
    Value<SizeIDConst, T>(mov)
{}

template<typename Tidc, typename T>
Size<Tidc, T>& Size<Tidc, T>::operator=(const T& val)
{
    Value<SizeIDConst, T>::operator(val);
    return *this;
}

template<typename Tidc, typename T>
Size<Tidc, T>& Size<Tidc, T>::operator=(const BaseType& val)
{
    Value<SizeIDConst, T>::operator(val);
    return *this;
}

template<typename Tidc, typename T>
Size<Tidc, T>& Size<Tidc, T>::operator=(const Size<Tidc, T>& cpy)
{
    Value<SizeIDConst, T>::operator(cpy);
    return *this;
}

}

#endif //!SIZE_H_