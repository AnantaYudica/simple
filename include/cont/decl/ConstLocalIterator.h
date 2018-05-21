#ifndef CONTAINER_DECLARATION_CONST_LOCAL_ITERATOR_H_
#define CONTAINER_DECLARATION_CONST_LOCAL_ITERATOR_H_

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
constexpr auto _GetConstLocalIterator0(T) ->
    decltype(std::declval<T::const_local_iterator>());
template<typename T>
constexpr void _GetConstLocalIterator0(...);

template<typename T>
constexpr auto _GetConstLocalIterator1(T) ->
    decltype(std::declval<T::ConstLocalIteratorType>());
template<typename T>
constexpr void _GetConstLocalIterator1(...);

template<typename T>
using _SwitchConstLocalIterator = simple::type::Switch<void,
    decltype(simple::_helper::_cont::_decl::
        _GetConstLocalIterator0<T>(std::declval<T>())),
    decltype(simple::_helper::_cont::_decl::
        _GetConstLocalIterator1<T>(std::declval<T>()))>;

template<bool, typename T>
struct _ConstLocalIterator
{};

template<typename T>
struct _ConstLocalIterator<true, T>
{
    typedef typename simple::_helper::_cont::_decl::
        _SwitchConstLocalIterator<Tc>::Type Type;
    typedef typename _ConstLocalIterator<true, T>::Type type;
};

}

}

}
namespace cont
{
namespace decl
{
 
template<typename Tc>
struct HasConstLocalIterator
{
    static constexpr bool Value = simple::_helper::_cont::_decl::
        _SwitchConstLocalIterator<Tc>::Index != 
        simple::_helper::_cont::_decl::
            _SwitchConstLocalIterator<Tc>::Size;
    static constexpr bool value = HasConstLocalIterator<Tc>::Value;
}; 

template<typename Tc>
using ConstLocalIterator = simple::_helper::_cont::_decl::
    _ConstLocalIterator<simple::cont::decl::
        HasConstLocalIterator<Tc>::Value, Tc>;

}

}

}

#endif //!CONTAINER_DECLARATION_CONST_LOCAL_ITERATOR_H_
