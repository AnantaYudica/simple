#ifndef VALUE_H_
#define VALUE_H_

namespace simple
{

template<typename K, typename T>
class Value
{
public:
    typedef K KeyType;
    typedef T ValueType;
private:
    T m_value;
public:
    Value();
    Value(const T& val);
    Value(const Value<K, T>& cpy);
    Value(Value<K, T>&& mov);
public:
    Value<K, T>& operator=(const T& val);
    Value<K, T>& operator=(const Value<K, T>& cpy);
    T& Get();
    const T& Get() const;
    operator T&();
    operator const T&() const;
};

template<typename K, typename T>
Value<K, T>::Value()
{}

template<typename K, typename T>
Value<K, T>::Value(const T& val) :
    m_value(val)
{}

template<typename K, typename T>
Value<K, T>::Value(const Value<K, T>& cpy) :
    m_value(cpy.m_value)
{}

template<typename K, typename T>
Value<K, T>::Value(Value<K, T>&& mov) :
     m_value(mov.m_value)
{}

template<typename K, typename T>
Value<K, T>& Value<K, T>::operator=(const T& val)
{
    this->m_value = val;
    return *this;
}

template<typename K, typename T>
Value<K, T>& Value<K, T>::operator=(const Value<K, T>& cpy)
{
    this->m_value = cpy.m_value;
    return *this;
}

template<typename K, typename T>
T& Value<K, T>::Get()
{
    return m_value;
}

template<typename K, typename T>
const T& Value<K, T>::Get() const
{
    return m_value;
}

template<typename K, typename T>
Value<K, T>::operator T&()
{
    return Get();
}

template<typename K, typename T>
Value<K, T>::operator const T&() const
{
    return Get();
}

}

#endif //!VALUE_H_
