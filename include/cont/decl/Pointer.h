#ifndef CONTAINER_DECLARATION_POINTER_H_
#define CONTAINER_DECLARATION_POINTER_H_

#include "../../type/Switch.h"

namespace simple
{
namespace _helper
{
namespace _cont
{
namespace _decl
{

template<typename T>
constexpr auto _GetPointer0(T) ->
    decltype(std::declval<T::pointer>());
template<typename T>
constexpr void _GetPointer0(...);

template<typename T>
constexpr auto _GetPointer1(T) ->
    decltype(std::declval<T::PointerType>());
template<typename T>
constexpr void _GetPointer1(...);

template<typename T>
using _SwitchPointer = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetPointer0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetPointer1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _Pointer
{};

template<typename T>
struct _Pointer<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchPointer<T>::Type Type;
    typedef typename _Pointer<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{
 
template<typename Tc>
struct HasPointer
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchPointer<Tc>::Index != simple::_helper::_cont::_decl::
        _SwitchPointer<Tc>::Size;
    static constexpr bool value = HasPointer<Tc>::Value;
}; 

template<typename Tc>
using Pointer = simple::_helper::_cont::_decl::
    _Pointer<simple::cont::decl::
        HasPointer<Tc>::Value, Tc>;
           
}

}

}

#endif //!CONTAINER_DECLARATION_POINTER_H_
