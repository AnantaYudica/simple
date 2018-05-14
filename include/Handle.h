#ifndef HANDLE_H_
#define HANDLE_H_

#include <functional>

namespace simple
{

template<typename K, typename Tr, typename... Targs>
class Handle
{
public:
    typedef K KetType;
    typedef std::function<Tr(Targs...)> FunctionType;
private:
    FunctionType m_handle;
public:
    Handle();
    Handle(FunctionType handle);
    Handle(const Handle<K, Tr, Targs...>& cpy);
    Handle(Handle<K, Tr, Targs...>&& mov);
public:
    void Set(FunctionType handle);
public:
    Handle<K, Tr, Targs...>& operator=(FunctionType handle);
    Handle<K, Tr, Targs...>& operator=(const Handle<K, Tr, Targs...>& cpy);
    Tr operator()(Targs... args);
    operator bool() const;
};

template<typename K, typename Tr, typename... Targs>
Handle<K, Tr, Targs...>::Handle() :
    m_handle(nullptr)
{}

template<typename K, typename Tr, typename... Targs>
Handle<K, Tr, Targs...>::Handle(FunctionType handle) :
    m_handle(handle)
{}

template<typename K, typename Tr, typename... Targs>
Handle<K, Tr, Targs...>::Handle(const Handle<K, Tr, Targs...>& cpy) :
    m_handle(cpy.m_handle)
{}

template<typename K, typename Tr, typename... Targs>
Handle<K, Tr, Targs...>::Handle(Handle<K, Tr, Targs...>&& mov) :
    m_handle(mov.m_handle)
{}

template<typename K, typename Tr, typename... Targs>
void Handle<K, Tr, Targs...>::Set(FunctionType handle)
{
    m_handle = handle;
}

template<typename K, typename Tr, typename... Targs>
Handle<K, Tr, Targs...>& 
    Handle<K, Tr, Targs...>::operator=(FunctionType handle)
{
    m_handle = handle;
    return *this;
}

template<typename K, typename Tr, typename... Targs>
Handle<K, Tr, Targs...>& 
    Handle<K, Tr, Targs...>::operator=(const Handle<K, Tr, Targs...>& cpy)
{
    m_handle = cpy.m_handle;
    return *this;
}

template<typename K, typename Tr, typename... Targs>
Tr Handle<K, Tr, Targs...>::operator()(Targs... args)
{
    if (static_cast<bool>(*this))
        return m_handle(args...);
}

template<typename K, typename Tr, typename... Targs>
Handle<K, Tr, Targs...>::operator bool() const
{
    return m_handle != nullptr;
}

}

#endif //!HANDLE_H_
