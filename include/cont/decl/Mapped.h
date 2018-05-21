#ifndef CONTAINER_DECLARATION_MAPPED_H_
#define CONTAINER_DECLARATION_MAPPED_H_

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
constexpr auto _GetMapped0(T) ->
    decltype(std::declval<T::mapped_type>());
template<typename T>
constexpr void _GetMapped0(...);

template<typename T>
constexpr auto _GetMapped1(T) ->
    decltype(std::declval<T::MappedType>());
template<typename T>
constexpr void _GetMapped1(...);

template<typename T>
using _SwitchMapped = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetMapped0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetMapped1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _Mapped
{};

template<typename T>
struct _Mapped<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchMapped<T>::Type Type;
    typedef typename _Mapped<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{
    
template<typename Tc>
struct HasMapped
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchMapped<Tc>::Index != simple::_helper::_cont::_decl::
        _SwitchMapped<Tc>::Size;
    static constexpr bool value = HasMapped<Tc>::Value;
}; 

template<typename Tc>
using Mapped = simple::_helper::_cont::_decl::
    _Mapped<simple::cont::decl::
        HasMapped<Tc>::Value, Tc>;
        
}

}

}

#endif //!CONTAINER_DECLARATION_MAPPED_H_
