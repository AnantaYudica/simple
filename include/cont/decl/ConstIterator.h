#ifndef CONTAINER_DECLARATION_CONST_ITERATOR_H_
#define CONTAINER_DECLARATION_CONST_ITERATOR_H_

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
constexpr auto _GetConstIterator0(T) ->
    decltype(std::declval<T::const_iterator>());
template<typename T>
constexpr void _GetConstIterator0(...);

template<typename T>
constexpr auto _GetConstIterator1(T) ->
    decltype(std::declval<T::ConstIteratorType>());
template<typename T>
constexpr void _GetConstIterator1(...);

template<typename T>
using _SwitchConstIterator = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetConstIterator0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetConstIterator1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _ConstIterator
{};

template<typename T>
struct _ConstIterator<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchConstIterator<T>::Type Type;
    typedef typename _ConstIterator<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{
 
template<typename Tc>
struct HasConstIterator
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchConstIterator<Tc>::Index != 
        simple::_helper::_cont::_decl::_SwitchConstIterator<Tc>::Size;
    static constexpr bool value = HasConstIterator<Tc>::Value;
}; 

template<typename Tc>
using ConstIterator = simple::_helper::_cont::_decl::
    _ConstIterator<simple::cont::decl::HasConstIterator<Tc>::Value, Tc>;   

}

}

}

#endif //!CONTAINER_DECLARATION_CONST_ITERATOR_H_
