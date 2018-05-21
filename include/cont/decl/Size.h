#ifndef CONTAINER_DECLARATION_SIZE_H_
#define CONTAINER_DECLARATION_SIZE_H_

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
constexpr auto _GetSize0(T) ->
    decltype(std::declval<T::size_type>());
template<typename T>
constexpr void _GetSize0(...);

template<typename T>
constexpr auto _GetSize1(T) ->
    decltype(std::declval<T::size_type>());
template<typename T>
constexpr void _GetSize1(...);

template<typename T>
using _SwitchSize = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetSize0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetSize1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _Size
{};

template<typename T>
struct _Size<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchSize<T>::Type Type;
    typedef typename _Size<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{

template<typename Tc>
struct HasSize
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchSize<Tc>::Index != simple::_helper::_cont::_decl::
        _SwitchSize<Tc>::Size;
    static constexpr bool value = HasSize<Tc>::Value;
}; 

template<typename Tc>
using Size = simple::_helper::_cont::_decl::
    _Size<simple::cont::decl::
        HasSize<Tc>::Value, Tc>;
           
}

}

}

#endif //!CONTAINER_DECLARATION_SIZE_H_
