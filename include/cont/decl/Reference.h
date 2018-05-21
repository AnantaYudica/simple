#ifndef CONTAINER_DECLARATION_REFERENCE_H_
#define CONTAINER_DECLARATION_REFERENCE_H_

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
constexpr auto _GetReference0(T) ->
    decltype(std::declval<T::reference>());
template<typename T>
constexpr void _GetReference0(...);

template<typename T>
constexpr auto _GetReference1(T) ->
    decltype(std::declval<T::ReferenceType>());
template<typename T>
constexpr void _GetReference1(...);

template<typename T>
using _SwitchReference = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetReference0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetReference1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _Reference
{};

template<typename T>
struct _Reference<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchReference<T>::Type Type;
    typedef typename _Reference<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{
 
template<typename Tc>
struct HasReference
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchReference<Tc>::Index != simple::_helper::_cont::_decl::
        _SwitchReference<Tc>::Size;
    static constexpr bool value = HasReference<Tc>::Value;
}; 

template<typename Tc>
using Reference = simple::_helper::_cont::_decl::
    _Reference<simple::cont::decl::
        HasReference<Tc>::Value, Tc>;
           
}

}

}

#endif //!CONTAINER_DECLARATION_REFERENCE_H_
