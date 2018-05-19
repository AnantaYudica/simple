#ifndef IDENTIFIER_CONSTANT_HAS_DECLARATION_H_
#define IDENTIFIER_CONSTANT_HAS_DECLARATION_H_

namespace simple
{
namespace _helper
{
namespace _id_const
{

template<typename T>
constexpr auto _HasDeclation0(T) ->
    decltype(std::declval<typename T::IdentifierConstantType>(), 
        std::true_type());
template<typename T>
constexpr std::false_type _HasDeclation0(...);

template<typename T>
constexpr auto _HasDeclation1(T) ->
    decltype(std::declval<typename T::IDConstType>(), 
        std::true_type());
template<typename T>
constexpr std::false_type _HasDeclation1(...);

template<typename T>
using _SwitchDeclaration = simple::type::Switch<
    std::false_type,
    decltype(simple::_helper::_id_const::
        _HasDeclation0<T>(std::declval<T>())),
    decltype(simple::_helper::_id_const::
        _HasDeclation1<T>(std::declval<T>()))>;

}

}

namespace id_const
{

template<typename IDConst, typename T>
struct HasDeclaration
{
    static constexpr bool Value =
        simple::_helper::_id_const::
            _SwitchDeclaration<T>::Size != 
        simple::_helper::_id_const::
            _SwitchDeclaration<T>::Index;
    static constexpr bool value = simple::id_const::HasDeclaration<T>::Value;
}; 

}

}

#endif //!IDENTIFIER_CONSTANT_HAS_DECLARATION_H_
