#ifndef CONTAINER_HANDLE_PUSH_FRONT_H_
#define CONTAINER_HANDLE_PUSH_FRONT_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../IdentifierConstant.h"
#include "../../id_const/Validation.h"
#include "../../Handle.h"
#include "../../type/Switch.h"

namespace simple
{
namespace _helper
{
namespace _cont
{
namespace _handle
{
namespace _push_front
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.push_front(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.PushFront(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(push_front(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(PushFront(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(push_front(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(PushFront(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename Tc, typename Tr, typename... Targs>
using _SwitchDefaultHandle = simple::type::Switch<std::false_type,
	decltype(simple::_helper::_cont::_handle::_push_front::
		_IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_push_front::
		_IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_push_front::
		_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_push_front::
		_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_push_front::
		_IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_push_front::
		_IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))>;

template<typename Tc, typename Tr, typename... Targs>
using _HasDefaultHandle = std::integral_constant<bool,
	simple::_helper::_cont::_handle::_push_front::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Index !=
	simple::_helper::_cont::_handle::_push_front::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Size>;

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_push_front::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 0, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.push_front(args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_push_front::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 1, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.PushFront(args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_push_front::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 2, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return push_front(c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_push_front::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 3, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return PushFront(c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_push_front::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 4, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return push_front(&c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_push_front::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 5, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return PushFront(&c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<!simple::_helper::_cont::_handle::_push_front::
	_HasDefaultHandle<Tc, Tr, Targs...>::value, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	assert(!"do not have handle push_front or PushFront function ");
}

}

}

}

}

namespace cont
{
namespace handle
{

struct PushFrontIDConst : simple::IdentifierConstant {};

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
class PushFront : public simple::Handle<simple::cont::handle::PushFrontIDConst,
	Tr, Tc&, Targs...>
{
public:
	typedef typename simple::id_const::Validation<Tidc>::Type IDConstType;
	typedef typename simple::Handle<simple::cont::handle::PushFrontIDConst,
		Tr, Tc&, Targs...>::FunctionType HandleType;
private:
	typedef simple::Handle<simple::cont::handle::PushFrontIDConst,
		Tr, Tc&, Targs...> BaseHandleType;
public:
	PushFront();
	PushFront(HandleType handle);
	PushFront(const PushFront<Tidc, Tc, Tr, Targs...>& cpy);
	PushFront(PushFront<Tidc, Tc, Tr, Targs...>&& mov);
public:
	PushFront<Tidc, Tc, Tr, Targs...>& 
		operator=(const PushFront<Tidc, Tc, Tr, Targs...>& cpy);
	PushFront<Tidc, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
PushFront<Tidc, Tc, Tr, Targs...>::PushFront()
{
	if (simple::_helper::_cont::_handle::_push_front::
        _HasDefaultHandle<Tc, Tr, Targs...>::value)
			Set(&simple::_helper::_cont::_handle::_push_front::
            	_DefaultHandle<Tc, Tr, Targs...>);
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
PushFront<Tidc, Tc, Tr, Targs...>::PushFront(HandleType handle) :
	BaseHandleType(handle)
{}  

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
PushFront<Tidc, Tc, Tr, Targs...>::
	PushFront(const PushFront<Tidc, Tc, Tr, Targs...>& cpy) :
		BaseHandleType(cpy)
{}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
PushFront<Tidc, Tc, Tr, Targs...>::
	PushFront(PushFront<Tidc, Tc, Tr, Targs...>&& mov) :
		BaseHandleType(mov)
{}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
PushFront<Tidc, Tc, Tr, Targs...>& PushFront<Tidc, Tc, Tr, Targs...>::
	operator=(const PushFront<Tidc, Tc, Tr, Targs...>& cpy)
{
	BaseHandleType::operator=(cpy);
	return *this;
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
PushFront<Tidc, Tc, Tr, Targs...>& PushFront<Tidc, Tc, Tr, Targs...>::
	operator=(HandleType handle)
{
	BaseHandleType::operator=(handle);
	return *this;
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Tr PushFront<Tidc, Tc, Tr, Targs...>::operator()(Tc& cont, Targs... val_args)
{
    return BaseHandleType::operator()(cont, val_args...);
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
PushFront<Tidc, Tc, Tr, Targs...>::operator bool() const
{
	return BaseHandleType::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_PUSH_FRONT_H_
