#ifndef CONTAINER_DECLARATION_DIFFERENCE_H_
#define CONTAINER_DECLARATION_DIFFERENCE_H_

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
constexpr auto _GetDifference0(T) ->
    decltype(std::declval<T::difference_type>());
template<typename T>
constexpr void _GetDifference0(...);

template<typename T>
constexpr auto _GetDifference1(T) ->
    decltype(std::declval<T::DifferenceType>());
template<typename T>
constexpr void _GetDifference0(...);

template<typename T>
using _SwitchDifference = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetDifference0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetDifference1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _Difference
{};

template<typename T>
struct _Difference<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchDifference<T>::Type Type;
    typedef typename _Difference<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{

template<typename Tc>
struct HasDifference
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchDifference<Tc>::Index != 
        simple::_helper::_cont::_decl::_SwitchDifference<Tc>::Size;
    static constexpr bool value = HasDifference<Tc>::Value;
}; 

template<typename Tc>
using Difference = simple::_helper::_cont::_decl::
    _Difference<simple::cont::decl::
        HasDifference<Tc>::Value, Tc>;
            
}

}

}

#endif //!CONTAINER_DECLARATION_DIFFERENCE_H_
