#ifndef VALUE_H_
#define VALUE_H_

#include "IdentifierConstant.h"
#include "id_const/Validation.h"

namespace simple
{

template<typename Tidc, typename T>
class Value
{
public:
    typedef typename simple::id_const::
        Validation<Tidc>::Type IDConstType;
    typedef T ValueType;
private:
    T m_value;
public:
    Value();
    Value(const T& val);
    Value(const Value<Tidc, T>& cpy);
    Value(Value<Tidc, T>&& mov);
public:
    Value<Tidc, T>& operator=(const T& val);
    Value<Tidc, T>& operator=(const Value<Tidc, T>& cpy);
    T& Get();
    const T& Get() const;
    operator T&();
    operator const T&() const;
};

template<typename Tidc, typename T>
Value<Tidc, T>::Value()
{}

template<typename Tidc, typename T>
Value<Tidc, T>::Value(const T& val) :
    m_value(val)
{}

template<typename Tidc, typename T>
Value<Tidc, T>::Value(const Value<Tidc, T>& cpy) :
    m_value(cpy.m_value)
{}

template<typename Tidc, typename T>
Value<Tidc, T>::Value(Value<Tidc, T>&& mov) :
     m_value(mov.m_value)
{}

template<typename Tidc, typename T>
Value<Tidc, T>& Value<Tidc, T>::operator=(const T& val)
{
    this->m_value = val;
    return *this;
}

template<typename Tidc, typename T>
Value<Tidc, T>& Value<Tidc, T>::operator=(const Value<Tidc, T>& cpy)
{
    this->m_value = cpy.m_value;
    return *this;
}

template<typename Tidc, typename T>
T& Value<Tidc, T>::Get()
{
    return m_value;
}

template<typename Tidc, typename T>
const T& Value<Tidc, T>::Get() const
{
    return m_value;
}

template<typename Tidc, typename T>
Value<Tidc, T>::operator T&()
{
    return Get();
}

template<typename Tidc, typename T>
Value<Tidc, T>::operator const T&() const
{
    return Get();
}

}

#endif //!VALUE_H_
