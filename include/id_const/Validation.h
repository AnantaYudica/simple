#ifndef IDENTIFIER_CONSTANT_VALIDATION_H_
#define IDENTIFIER_CONSTANT_VALIDATION_H_

#include <type_traits>

#include "../type/And.h"
#include "../IdentifierConstant.h"
#include "IsBase.h"

namespace simple
{
namespace _helper
{
namespace _id_const
{

template<typename T, bool>
struct _Validation 
{
    typedef bool ValueType;
    typedef bool value_type;
    typedef T Type;
    typedef T type;
    static constexpr bool Value = true;
    static constexpr bool value = true;
};

template<typename T>
struct _Validation<T, false>
{
    typedef bool ValueType;
    typedef bool value_type;
    static constexpr bool Value = false;
    static constexpr bool value = false;
};

}

}

namespace id_const
{

template<typename T, typename... Targs>
using Validation = simple::_helper::_id_const::_Validation<T, 
    simple::type::And<std::integral_constant<bool, true>,
        std::integral_constant<bool,
            simple::id_const::IsBase<T, simple::IdentifierConstant>::Value>,
        std::integral_constant<bool, 
            simple::id_const::IsBase<T, Targs>::Value>...>::Value>;

}

}

#endif //!IDENTIFIER_CONSTANT_VALIDATION_H_
