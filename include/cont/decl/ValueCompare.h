#ifndef CONTAINER_DECLARATION_VALUE_COMPARE_H_
#define CONTAINER_DECLARATION_VALUE_COMPARE_H_

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
constexpr auto _GetValueCompare0(T) ->
    decltype(std::declval<T::value_compare>());
template<typename T>
constexpr void _GetValueCompare0(...);

template<typename T>
constexpr auto _GetValueCompare1(T) ->
    decltype(std::declval<T::ValueCompareType>());
template<typename T>
constexpr void _GetValueCompare1(...);

template<typename T>
using _SwitchValueCompare = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetValueCompare0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetValueCompare1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _ValueCompare
{};

template<typename T>
struct _ValueCompare<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchValueCompare<T>::Type Type;
    typedef typename _ValueCompare<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{
   
template<typename Tc>
struct HasValueCompare
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchValueCompare<Tc>::Index != 
        simple::_helper::_cont::_decl::_SwitchValueCompare<Tc>::Size;
    static constexpr bool value = HasValueCompare<Tc>::Value;
}; 

template<typename Tc>
using ValueCompare = simple::_helper::_cont::_decl::
    _ValueCompare<simple::cont::decl::
        HasValueCompare<Tc>::Value, Tc>;
         
}

}

}

#endif //!CONTAINER_DECLARATION_VALUE_COMPARE_H_
