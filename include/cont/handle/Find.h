#ifndef CONTAINER_HANDLE_FIND_H_
#define CONTAINER_HANDLE_FIND_H_

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
namespace _find
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.find(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.Find(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(find(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(Find(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(find(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(Find(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename Tc, typename Tr, typename... Targs>
using _SwitchDefaultHandleType = simple::type::Switch<std::false_type,
	decltype(simple::_helper::_find::
		_IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_find::
		_IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_find::
		_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_find::
		_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_find::
		_IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_find::
		_IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))>;

template<typename Tc, typename Tr, typename... Targs>
using _HasDefaultHandle = std::integral_constant<bool,
	simple::_helper::_find::
		_SwitchDefaultHandleType<Tc, Tr, Targs...>::Index !=
	simple::_helper::_find::
		_SwitchDefaultHandleType<Tc, Tr, Targs...>::Size>;

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_find::
	_SwitchDefaultHandleType<Tc, Tr, Targs...>::Index == 0, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.find(args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_find::
	_SwitchDefaultHandleType<Tc, Tr, Targs...>::Index == 1, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.Find(args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_find::
	_SwitchDefaultHandleType<Tc, Tr, Targs...>::Index == 2, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return find(c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_find::
	_SwitchDefaultHandleType<Tc, Tr, Targs...>::Index == 3, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return Find(c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_find::
	_SwitchDefaultHandleType<Tc, Tr, Targs...>::Index == 4, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return find(&c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_find::
	_SwitchDefaultHandleType<Tc, Tr, Targs...>::Index == 5, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return Find(&c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<!_HasDefaultHandle<Tc, Tr, Targs...>::value,
	 Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	assert(!"do not have handle find or Find function ");
}

}

}

namespace cont
{
namespace handle
{

struct FindIDConst : simple::IdentifierConstant {};

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
class Find : public simple::Handle<simple::cont::handle::FindIDConst, 
	Tr, Tc&, Targs...>
{
public:
	typedef typename simple::id_const::Validation<Tidc>::Type IDConstType;
	typedef typename simple::Handle<simple::cont::handle::FindIDConst, 
		Tr, Tc&, Targs...>::FunctionType HandleType;
private:
	typedef simple::Handle<simple::cont::handle::FindIDConst, 
		Tr, Tc&, Targs...> BaseHandleType;
public:
	Find();
	Find(HandleType handle);
	Find(const Find<Tidc, Tc, Tr, Targs...>& cpy);
	Find(Find<Tidc, Tc, Tr, Targs...>&& mov);
public:
	Find<Tidc, Tc, Tr, Targs...>& 
		operator=(const Find<Tidc, Tc, Tr, Targs...>& cpy);
	Find<Tidc, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Find<Tidc, Tc, Tr, Targs...>::Find()
{
	if (simple::_helper::_find::_HasDefaultHandle<Tc, Tr, Targs...>::value)
		Set(&simple::_helper::_find::_DefaultHandle<Tc, Tr, Targs...>);
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Find<Tidc, Tc, Tr, Targs...>::Find(HandleType handle) :
	BaseHandleType(handle)
{}  

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Find<Tidc, Tc, Tr, Targs...>::
	Find(const Find<Tidc, Tc, Tr, Targs...>& cpy) :
		BaseHandleType(cpy)
{}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Find<Tidc, Tc, Tr, Targs...>::
	Find(Find<Tidc, Tc, Tr, Targs...>&& mov) :
		BaseHandleType(mov)
{}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Find<Tidc, Tc, Tr, Targs...>& Find<Tidc, Tc, Tr, Targs...>::
	operator=(const Find<Tidc, Tc, Tr, Targs...>& cpy)
{
	BaseHandleType::operator=(cpy);
	return *this;
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Find<Tidc, Tc, Tr, Targs...>& Find<Tidc, Tc, Tr, Targs...>::
	operator=(HandleType handle)
{
	BaseHandleType::operator=(handle);
	return *this;
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Tr Find<Tidc, Tc, Tr, Targs...>::operator()(Tc& cont, Targs... val_args)
{
    return BaseHandleType::operator()(cont, val_args...);
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Find<Tidc, Tc, Tr, Targs...>::operator bool() const
{
	return BaseHandleType::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_FIND_H_
