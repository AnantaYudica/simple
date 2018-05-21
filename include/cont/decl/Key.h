#ifndef CONTAINER_DECLARATION_KEY_H_
#define CONTAINER_DECLARATION_KEY_H_

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
constexpr auto _GetKey0(T) ->
    decltype(std::declval<T::key_type>());
template<typename T>
constexpr void _GetKey0(...);

template<typename T>
constexpr auto _GetKey1(T) ->
    decltype(std::declval<T::KeyType>());
template<typename T>
constexpr void _GetKey1(...);

template<typename T>
using _SwitchKey = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetKey0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetKey1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _Key
{};

template<typename T>
struct _Key<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchKey<T>::Type Type;
    typedef typename _Key<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{
    
template<typename Tc>
struct HasKey
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchKey<Tc>::Index != simple::_helper::_cont::_decl::
        _SwitchKey<Tc>::Size;
    static constexpr bool value = HasKey<Tc>::Value;
}; 

template<typename Tc>
using Key = simple::_helper::_cont::_decl::
    _Key<simple::cont::decl::
        HasKey<Tc>::Value, Tc>;
        
}

}

}

#endif //!CONTAINER_DECLARATION_KEY_H_
