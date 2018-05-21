#ifndef CONTAINER_DECLARATION_HASHER_H_
#define CONTAINER_DECLARATION_HASHER_H_

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
constexpr auto _GetHasher0(T) ->
    decltype(std::declval<T::hasher>());
template<typename T>
constexpr void _GetHasher0(...);

template<typename T>
constexpr auto _GetHasher1(T) ->
    decltype(std::declval<T::HasherType>());
template<typename T>
constexpr void _GetHasher1(...);

template<typename T>
using _SwitchHasher = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetHasher0<T>(std::declval<T>())),
    delctype(simple::_helper::_cont::_decl::
        _GetHasher1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _Hasher
{};

template<typename T>
struct _Hasher<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchHasher<T>::Type Type;
    typedef typename _Hasher<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{
 
template<typename Tc>
struct HasHasher
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchHasher<Tc>::Index != simple::_helper::_cont::_decl::
        _SwitchHasher<Tc>::Size;
    static constexpr bool value = HasHasher<Tc>::Value;
}; 

template<typename Tc>
using Hasher = simple::_helper::_cont::_decl::
    _Hasher<simple::cont::decl::
        HasHasher<Tc>::Value, Tc>;
           
}

}

}

#endif //!CONTAINER_DECLARATION_HASHER_H_
