#ifndef TYPE_OR_H_
#define TYPE_OR_H_

#include <type_traits>

namespace simple
{
namespace _helper
{
namespace _type
{

template<typename Tt, typename Tc, typename... Targs>
struct _Or : _Or<Tt, Targs...>
{
    static constexpr bool Value = _Or<Tt, Targs>::Value;
};

template<typename Tt, typename Tc>
struct _Or<Tt, Tc>
{
    static constexpr bool Value = std::is_same<Tt, Tc>::value;
};

template<typename Tt, typename Targ, typename... Targs>
struct _Or<Tt, Tt, Targ, Targs...>
{
    static constexpr bool Value = true;
};

}

}

namespace type
{

template<typename Tt, typename Targ, typename... Targs>
struct Or 
{
    static constexpr bool Value =
        simple::_helper::_type::_Or<Tt, Targ, Targs...>::Value;
    static constexpr bool value = Or<Tt, Targ, Targs...>::Value;
};

}

}

#endif //!TYPE_OR_H_
