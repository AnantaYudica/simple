#ifndef CONTAINER_DECLARATION_CONST_POINTER_H_
#define CONTAINER_DECLARATION_CONST_POINTER_H_

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
constexpr auto _GetConstPointer0(T) ->
    decltype(std::declval<T::const_pointer>());
template<typename T>
constexpr void _GetConstPointer0(...);

template<typename T>
constexpr auto _GetConstPointer1(T) ->
    decltype(std::declval<T::ConstPointerType>());
template<typename T>
constexpr void _GetConstPointer1(...);

template<typename T>
using _SwitchConstPointer = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetConstPointer0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetConstPointer1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _ConstPointer
{};

template<typename T>
struct _ConstPointer<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchConstPointer<T>::Type Type;
    typedef typename _ConstPointer<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{

template<typename Tc>
struct HasConstPointer
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchConstPointer<Tc>::Index != 
        simple::_helper::_cont::_decl::_SwitchConstPointer<Tc>::Size;
    static constexpr bool value = HasConstPointer<Tc>::Value;
}; 

template<typename Tc>
using ConstPointer = simple::_helper::_cont::_decl::
    _ConstPointer<simple::cont::decl::
        HasConstPointer<Tc>::Value, Tc>;
    
}

}

}

#endif //!CONTAINER_DECLARATION_CONST_POINTER_H_
