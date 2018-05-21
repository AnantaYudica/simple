#ifndef CONTAINER_DECLARATION_CONTAINER_H_
#define CONTAINER_DECLARATION_CONTAINER_H_

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
constexpr auto _GetContainer0(T) ->
    decltype(std::declval<T::container_type>());
template<typename T>
constexpr void _GetContainer0(...);

template<typename T>
constexpr auto _GetContainer1(T) ->
    decltype(std::declval<T::ContainerType>());
template<typename T>
constexpr void _GetContainer1(...);

template<typename T>
using _SwitchContainer = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetContainer0<T>(std::declval<T>())),
    delctype(simple::_helper::_cont::_decl::
        _GetContainer1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _Container
{};

template<typename T>
struct _Container<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchContainer<T>::Type Type;
    typedef typename _Container<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{

template<typename Tc>
struct HasContainer
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchContainer<Tc>::Index != simple::_helper::_cont::_decl::
        _SwitchContainer<Tc>::Size;
    static constexpr bool value = HasContainer<Tc>::Value;
}; 
 
template<typename Tc>
using Container = simple::_helper::_cont::_decl::
    _Container<simple::cont::decl::
        HasContainer<Tc>::Value, Tc>;
         
}

}

}

#endif //!CONTAINER_DECLARATION_CONTAINER_H_
