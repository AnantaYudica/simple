#ifndef CONTAINER_DECLARATION_KEY_EQUAL_H_
#define CONTAINER_DECLARATION_KEY_EQUAL_H_

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
constexpr auto _GetKeyEqual0(T) ->
    decltype(std::declval<T::key_equal>());
template<typename T>
constexpr void _GetKeyEqual0(...);

template<typename T>
constexpr auto _GetKeyEqual1(T) ->
    decltype(std::declval<T::KeyEqualType>());
template<typename T>
constexpr void _GetKeyEqual1(...);

template<typename T>
using _SwitchKeyEqual = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetKeyEqual0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetKeyEqual1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _KeyEqual
{};

template<typename T>
struct _KeyEqual<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchKeyEqual<T>::Type Type;
    typedef typename _KeyEqual<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{

template<typename Tc>
struct HasKeyEqual
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchKeyEqual<Tc>::Index != simple::_helper::_cont::_decl::
        _SwitchKeyEqual<Tc>::Size;
    static constexpr bool value = HasKeyEqual<Tc>::Value;
}; 

template<typename Tc>
using KeyEqual = simple::_helper::_cont::_decl::
    _KeyEqual<simple::cont::decl::
        HasKeyEqual<Tc>::Value, Tc>;
            
}

}

}

#endif //!CONTAINER_DECLARATION_KEY_EQUAL_H_
