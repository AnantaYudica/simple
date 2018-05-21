#ifndef CONTAINER_DECLARATION_LOCAL_ITERATOR_H_
#define CONTAINER_DECLARATION_LOCAL_ITERATOR_H_

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
constexpr auto _GetLocalIterator0(T) ->
    decltype(std::declval<T::local_iterator>());
template<typename T>
constexpr void _GetLocalIterator0(...);

template<typename T>
constexpr auto _GetLocalIterator1(T) ->
    decltype(std::declval<T::LocalIteratorType>());
template<typename T>
constexpr void _GetLocalIterator1(...);

template<typename T>
using _SwitchLocalIterator = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetLocalIterator0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetLocalIterator1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _LocalIterator
{};

template<typename T>
struct _LocalIterator<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchLocalIterator<T>::Type Type;
    typedef typename _LocalIterator<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{
 
template<typename Tc>
struct HasLocalIterator
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchLocalIterator<Tc>::Index != 
        simple::_helper::_cont::_decl::_SwitchLocalIterator<Tc>::Size;
    static constexpr bool value = HasLocalIterator<Tc>::Value;
}; 

template<typename Tc>
using LocalIterator = simple::_helper::_cont::_decl::
    _LocalIterator<simple::cont::decl::
        HasLocalIterator<Tc>::Value, Tc>;
           
}

}

}

#endif //!CONTAINER_DECLARATION_LOCAL_ITERATOR_H_
