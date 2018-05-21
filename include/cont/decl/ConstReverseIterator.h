#ifndef CONTAINER_DECLARATION_CONST_REVERSE_ITERATOR_H_
#define CONTAINER_DECLARATION_CONST_REVERSE_ITERATOR_H_

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
constexpr auto _HasConstReverseIterator0(T) ->
    decltype(std::declval<T::const_reverse_iterator>());
template<typename T>
constexpr void _HasConstReverseIterator0(...);

template<typename T>
constexpr auto _HasConstReverseIterator1(T) ->
    decltype(std::declval<T::ConstReverseIteratorType>());
template<typename T>
constexpr void _HasConstReverseIterator1(...);

template<typename T>
using _SwitchConstReverseIterator = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _HasConstReverseIterator0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _HasConstReverseIterator1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _ConstReverseIterator
{};

template<typename T>
struct _ConstReverseIterator<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchConstReverseIterator<T>::Type Type;
    typedef typename _ConstReverseIterator<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{
 
template<typename Tc>
struct HasConstReverseIterator
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchConstReverseIterator<Tc>::Index != 
        simple::_helper::_cont::_decl::
            _SwitchConstReverseIterator<Tc>::Size;
    static constexpr bool value = HasConstReverseIterator<Tc>::Value;
}; 

template<typename Tc>
using ConstReverseIterator = simple::_helper::_cont::_decl::
    _ConstReverseIterator<simple::cont::decl::
        HasConstReverseIterator<Tc>::Value, Tc>;

}

}

}

#endif //!CONTAINER_DECLARATION_CONST_REVERSE_ITERATOR_H_
