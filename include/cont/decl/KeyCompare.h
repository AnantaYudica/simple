#ifndef CONTAINER_DECLARATION_KEY_COMPARE_H_
#define CONTAINER_DECLARATION_KEY_COMPARE_H_

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
constexpr auto _GetKeyCompare0(T) ->
    decltype(std::declval<T::key_compare>());
template<typename T>
constexpr void _GetKeyCompare0(...);

template<typename T>
constexpr auto _GetKeyCompare1(T) ->
    decltype(std::declval<T::KeyCompareType>());
template<typename T>
constexpr void _GetKeyCompare1(...);

template<typename T>
using _SwitchKeyCompare = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetKeyCompare0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetKeyCompare1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _KeyCompare
{};

template<typename T>
struct _KeyCompare<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchKeyCompare<T>::Type Type;
    typedef typename _KeyCompare<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{

template<typename Tc>
struct HasKeyCompare
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchKeyCompare<Tc>::Index != 
        simple::_helper::_cont::_decl::_SwitchKeyCompare<Tc>::Size;
    static constexpr bool value = HasKeyCompare<Tc>::Value;
}; 

template<typename Tc>
using KeyCompare = simple::_helper::_cont::_decl::
    _KeyCompare<simple::cont::decl::
        HasKeyCompare<Tc>::Value, Tc>;
            
}

}

}

#endif //!CONTAINER_DECLARATION_KEY_COMPARE_H_
