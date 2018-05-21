#ifndef CONTAINER_DECLARATION_REVERSE_ITERATOR_H_
#define CONTAINER_DECLARATION_REVERSE_ITERATOR_H_

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
constexpr auto _GetReverseIterator0(T) ->
    decltype(std::declval<T::reverse_iterator>());
template<typename T>
constexpr void _GetReverseIterator0(...);

template<typename T>
constexpr auto _GetReverseIterator1(T) ->
    decltype(std::declval<T::ReverseIteratorType>());
template<typename T>
constexpr void _GetReverseIterator1(...);

template<typename T>
using _SwitchReverseIterator = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetReverseIterator0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetReverseIterator1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _ReverseIterator
{};

template<typename T>
struct _ReverseIterator<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchReverseIterator<T>::Type Type;
    typedef typename _ReverseIterator<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{

template<typename Tc>
struct HasReverseIterator
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchReverseIterator<Tc>::Index != 
        simple::_helper::_cont::_decl::
            _SwitchReverseIterator<Tc>::Size;
    static constexpr bool value = HasReverseIterator<Tc>::Value;
}; 

template<typename Tc>
using ReverseIterator = simple::_helper::_cont::_decl::
    _ReverseIterator<simple::cont::decl::
        HasReverseIterator<Tc>::Value, Tc>;
            
}

}

}

#endif //!CONTAINER_DECLARATION_REVERSE_ITERATOR_H_
