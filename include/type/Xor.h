#ifndef TYPE_XOR_H_
#define TYPE_XOR_H_

#include "And.h"
#include "Or.h"

namespace simple
{

namespace type
{

template<typename Tt, typename Targ, typename... Targs>
struct Xor 
{
    static constexpr bool Value =
        simple::type::Or<Tt, Targ, Targs...>::Value && 
        !simple::type::And<Tt, Targ, Targs...>::Value;
    static constexpr bool value = Xor<Tt, Targ, Targs...>::Value;
};

}

}

#endif //!TYPE_XOR_H_
