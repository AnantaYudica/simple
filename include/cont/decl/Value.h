#ifndef CONTAINER_DECLARATION_VALUE_H_
#define CONTAINER_DECLARATION_VALUE_H_

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
constexpr auto _GetValue0(T) ->
    decltype(std::declval<T::value_type>());
template<typename T>
constexpr void _GetValue0(...);

template<typename T>
constexpr auto _GetValue1(T) ->
    decltype(std::declval<T::ValueType>());
template<typename T>
constexpr void _GetValue1(...);

template<typename T>
using _SwitchValue = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetValue0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetValue1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _Value
{};

template<typename T>
struct _Value<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchValue<T>::Type Type;
    typedef typename _Value<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{

template<typename Tc>
struct HasValue
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchValue<Tc>::Index != simple::_helper::_cont::_decl::
        _SwitchValue<Tc>::Size;
    static constexpr bool value = HasValue<Tc>::Value;
}; 

template<typename Tc>
using Value = simple::_helper::_cont::_decl::
    _Value<simple::cont::decl::
        HasValue<Tc>::Value, Tc>;
            
}

}

}

#endif //!CONTAINER_DECLARATION_VALUE_H_
