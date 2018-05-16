#ifndef TYPE_SWITCH_H_
#define TYPE_SWITCH_H_

#include <type_traits>

namespace simple
{
namespace _helper
{
namespace _type
{

template<typename K, typename Td, typename Tr, 
	std::size_t Idx, typename... Targs>
struct _Switch 
{
    typedef Tr Type; 
	static constexpr std::size_t Index =
		std::is_same<Td, Tr>::value ? Idx : Idx - 1;
};

template<typename K, typename Td, std::size_t Idx, 
	typename Targ, typename... Targs>
struct _Switch<K, Td, Td, Idx, Targ, Targs...> :
    public _Switch<K, Td, Targ, Idx + 1, Targs...>
{
	static constexpr std::size_t Index =
		_Switch<K, Td, Targ, Idx + 1, Targs...>::Index;
    typedef typename _Switch<K, Td, Targ, Idx + 1, Targs...>::Type Type;
	
};

}
}
namespace type
{
template<typename K, typename Td, typename... Targs>
struct Switch : public simple::_helper::_type::_Switch<K, Td, Td, 0, Targs...>
{
    typedef typename simple::_helper::_type::
        template _Switch<K, Td, Td, 0, Targs...>::Type Type;
	static constexpr std::size_t Index =
		simple::_helper::_type::_Switch<K, Td, Td, 0, Targs...>::Index;
	static constexpr std::size_t Size = sizeof...(Targs);
};

}

}

#endif //!TYPE_SWITCH_H_
