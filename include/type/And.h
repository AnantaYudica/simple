#ifndef TYPE_AND_H_
#define TYPE_AND_H_

#include <type_traits>

namespace simple
{
namespace _helper
{
namespace _type
{

template<typename Tt, typename Tc, typename... Targs>
struct _And
{
    static constexpr bool Value = std::is_same<Tt, Tc>::value
        && sizeof...(Targs) == 0;
};

template<typename Tt, typename Targ, typename... Targs>
struct _And<Tt, Tt, Targ, Targs...> : _And<Tt, Targ, Targs...>
{
    static constexpr bool Value = 
        _And<Tt, Targ, Targs...>::Value;
};

}

}

namespace type
{

template<typename Tt, typename Targ, typename... Targs>
struct And 
{
    static constexpr bool Value =
        simple::_helper::_type::_And<Tt, Targ, Targs...>::Value;
    static constexpr bool value = And<Tt, Targ, Targs...>::Value;
};

}

}

#endif //!TYPE_AND_H_
