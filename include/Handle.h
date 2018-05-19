#ifndef HANDLE_H_
#define HANDLE_H_

#include <functional>

#include "id_const/Validation.h"

namespace simple
{

template<typename Tidc, typename Tr, typename... Targs>
class Handle
{
public:
    typedef typename simple::id_const::
        Validation<Tidc>::type IDConstType;
    typedef std::function<Tr(Targs...)> FunctionType;
private:
    FunctionType m_handle;
public:
    Handle();
    Handle(FunctionType handle);
    Handle(const Handle<Tidc, Tr, Targs...>& cpy);
    Handle(Handle<Tidc, Tr, Targs...>&& mov);
public:
    void Set(FunctionType handle);
public:
    Handle<Tidc, Tr, Targs...>& operator=(FunctionType handle);
    Handle<Tidc, Tr, Targs...>& operator=(const Handle<Tidc, Tr, Targs...>& cpy);
    Tr operator()(Targs... args);
    operator bool() const;
};

template<typename Tidc, typename Tr, typename... Targs>
Handle<Tidc, Tr, Targs...>::Handle() :
    m_handle(nullptr)
{}

template<typename Tidc, typename Tr, typename... Targs>
Handle<Tidc, Tr, Targs...>::Handle(FunctionType handle) :
    m_handle(handle)
{}

template<typename Tidc, typename Tr, typename... Targs>
Handle<Tidc, Tr, Targs...>::Handle(const Handle<Tidc, Tr, Targs...>& cpy) :
    m_handle(cpy.m_handle)
{}

template<typename Tidc, typename Tr, typename... Targs>
Handle<Tidc, Tr, Targs...>::Handle(Handle<Tidc, Tr, Targs...>&& mov) :
    m_handle(mov.m_handle)
{}

template<typename Tidc, typename Tr, typename... Targs>
void Handle<Tidc, Tr, Targs...>::Set(FunctionType handle)
{
    m_handle = handle;
}

template<typename Tidc, typename Tr, typename... Targs>
Handle<Tidc, Tr, Targs...>& 
    Handle<Tidc, Tr, Targs...>::operator=(FunctionType handle)
{
    m_handle = handle;
    return *this;
}

template<typename Tidc, typename Tr, typename... Targs>
Handle<Tidc, Tr, Targs...>& Handle<Tidc, Tr, Targs...>::
    operator=(const Handle<Tidc, Tr, Targs...>& cpy)
{
    m_handle = cpy.m_handle;
    return *this;
}

template<typename Tidc, typename Tr, typename... Targs>
Tr Handle<Tidc, Tr, Targs...>::operator()(Targs... args)
{
    if (static_cast<bool>(*this))
        return m_handle(args...);
}

template<typename Tidc, typename Tr, typename... Targs>
Handle<Tidc, Tr, Targs...>::operator bool() const
{
    return m_handle != nullptr;
}

}

#endif //!HANDLE_H_
