#ifndef IDENTIFIER_CONSTANT_IS_BASE_H_
#define IDENTIFIER_CONSTANT_IS_BASE_H_

#include <type_traits>

#include "../IdentifierConstant.h"

namespace simple
{
namespace _helper
{
namespace _id_const
{

template<typename T>
constexpr std::true_type _IsBase(const T&);

template<typename T>
constexpr std::false_type _IsBase(...);

}

}

namespace id_const
{

template<typename T, typename Tb = simple::IdentifierConstant>
struct IsBase
{
    static constexpr bool Value = 
        decltype(simple::_helper::_id_const::_IsBase<
            simple::IdentifierConstant>(std::declval<T>()))::value &&
        decltype(simple::_helper::_id_const::_IsBase<
            Tb>(std::declval<T>()))::value &&
        !std::is_same<T, simple::IdentifierConstant>::value;
    static constexpr bool value = IsBase<T, Tb>::Value;

};

template<typename T>
struct IsBase<T, simple::IdentifierConstant>
{
    static constexpr bool Value = 
        decltype(simple::_helper::_id_const::_IsBase<
            simple::IdentifierConstant>(std::declval<T>()))::value &&
        !std::is_same<T, simple::IdentifierConstant>::value;
    static constexpr bool value = IsBase<T, simple::IdentifierConstant>::Value;
};

}

}

#endif //!IDENTIFIER_CONSTANT_IS_BASE_H_
