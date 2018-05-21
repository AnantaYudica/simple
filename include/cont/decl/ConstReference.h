#ifndef CONTAINER_DECLARATION_CONST_REFERENCE_H_
#define CONTAINER_DECLARATION_CONST_REFERENCE_H_

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
constexpr auto _GetConstReference0(T) ->
    decltype(std::declval<T::const_reference>());
template<typename T>
constexpr void _GetConstReference0(...);

template<typename T>
constexpr auto _GetConstReference1(T) ->
    decltype(std::declval<T::ConstReferenceType>());
template<typename T>
constexpr void _GetConstReference1(...);

template<typename T>
using _SwitchConstReference = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetConstReference0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetConstReference1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _ConstReference
{};

template<typename T>
struct _ConstReference<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchConstReference<T>::Type Type;
    typedef typename _ConstReference<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{

template<typename Tc>
struct HasConstReference
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchConstReference<Tc>::Index != 
        simple::_helper::_cont::_decl::
            _SwitchConstReference<Tc>::Size;
    static constexpr bool value = HasConstReference<Tc>::Value;
}; 

template<typename Tc>
using ConstReference = simple::_helper::_cont::_decl::
    _ConstReference<simple::cont::decl::
        HasConstReference<Tc>::Value, Tc>;

}

}

}

#endif //!CONTAINER_DECLARATION_CONST_REFERENCE_H_
