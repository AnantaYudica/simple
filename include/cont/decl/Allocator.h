#ifndef CONTAINER_DECLARATION_ALLOCATOR_H_
#define CONTAINER_DECLARATION_ALLOCATOR_H_

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
constexpr auto _GetAllocator0(T) ->
    decltype(std::declval<T::allocator_type>());
template<typename T>
constexpr void _GetAllocator0(...);

template<typename T>
constexpr auto _GetAllocator1(T) ->
    decltype(std::declval<T::AllocatorType>());
template<typename T>
constexpr void _GetAllocator1(...);

template<typename T>
using _SwitchAllocator = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetAllocator0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetAllocator1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _Allocator
{};

template<typename T>
struct _Allocator<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchAllocator<T>::Type Type;
    typedef typename _Allocator<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{

template<typename Tc>
struct HasAllocator
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchAllocator<Tc>::Index != simple::_helper::_cont::_decl::
        _SwitchAllocator<Tc>::Size;
    static constexpr bool value = HasAllocator<Tc>::Value;
}; 

template<typename Tc>
using Allocator = simple::_helper::_cont::_decl::
    _Allocator<simple::cont::decl::HasAllocator<Tc>::Value, Tc>;

}

}

}

#endif //!CONTAINER_DECLARATION_ALLOCATOR_H_
