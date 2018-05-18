#ifndef TYPE_SWITCH_H_
#define TYPE_SWITCH_H_

#include <type_traits>

namespace simple
{
namespace _helper
{
namespace _type
{

template<typename Td, typename Tr, 
	std::size_t Idx, typename... Targs>
struct _Switch 
{
    typedef Tr Type; 
	static constexpr std::size_t Index =
		std::is_same<Td, Tr>::value ? Idx + 1 : Idx;
};

template<typename Td, std::size_t Idx, 
	typename Targ, typename... Targs>
struct _Switch<Td, Td, Idx, Targ, Targs...> :
    public _Switch<Td, Targ, Idx + 1, Targs...>
{
	static constexpr std::size_t Index =
		_Switch<Td, Targ, Idx + 1, Targs...>::Index;
    typedef typename _Switch<Td, Targ, Idx + 1, Targs...>::Type Type;
	
};

}

}

namespace type
{
template<typename Td, typename Targ, typename... Targs>
struct Switch
{
    typedef typename simple::_helper::_type::
        template _Switch<Td, Targ, 0, Targs...>::Type Type;
	typedef typename Switch<Td, Targ, Targs...>::Type type;
	static constexpr std::size_t Index =
		simple::_helper::_type::_Switch<Td, Targ, 0, Targs...>::Index;
	static constexpr std::size_t index = Switch<Td, Targ, Targs...>::Index;
	static constexpr std::size_t Size = sizeof...(Targs) + 1;
	static constexpr std::size_t size = Switch<Td, Targ, Targs...>::Size;
};

}

}

#endif //!TYPE_SWITCH_H_
