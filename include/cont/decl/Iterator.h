#ifndef CONTAINER_DECLARATION_ITERATOR_H_
#define CONTAINER_DECLARATION_ITERATOR_H_

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
constexpr auto _GetIterator0(T) ->
    decltype(std::declval<T::iterator>());
template<typename T>
constexpr void _GetIterator0(...);

template<typename T>
constexpr auto _GetIterator1(T) ->
    decltype(std::declval<T::IteratorType>());
template<typename T>
constexpr void _GetIterator1(...);

template<typename T>
using _SwitchIterator = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetIterator0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetIterator1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _Iterator
{};

template<typename T>
struct _Iterator<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchIterator<T>::Type Type;
    typedef typename _Iterator<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{
 
template<typename Tc>
struct HasIterator
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchIterator<Tc>::Index != simple::_helper::_cont::_decl::
        _SwitchIterator<Tc>::Size;
    static constexpr bool value = HasIterator<Tc>::Value;
}; 

template<typename Tc>
using Iterator = simple::_helper::_cont::_decl::
    _Iterator<simple::cont::decl::
        HasIterator<Tc>::Value, Tc>;
           
}

}

}

#endif //!CONTAINER_DECLARATION_ITERATOR_H_
