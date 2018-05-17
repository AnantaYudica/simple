#ifndef CONTAINER_HANDLE_LOWER_BOUND_H_
#define CONTAINER_HANDLE_LOWER_BOUND_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../Handle.h"
#include "../../type/Switch.h"

namespace simple
{
namespace _helper
{
namespace _lower_bound
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.lower_bound(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.LowerBound(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(lower_bound(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(LowerBound(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(lower_bound(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(LowerBound(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename K, typename Tc, typename Tr, typename... Targs>
using _SwitchDefaultHandleType = simple::type::Switch<K, std::false_type,
	decltype(simple::_helper::_lower_bound::
		_IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_lower_bound::
		_IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_lower_bound::
		_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_lower_bound::
		_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_lower_bound::
		_IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_lower_bound::
		_IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))>;

template<typename K, typename Tc, typename Tr, typename... Targs>
using _HasDefaultHandle = std::integral_constant<bool,
	simple::_helper::_lower_bound::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index !=
	simple::_helper::_lower_bound::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Size>;

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_lower_bound::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 0, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.lower_bound(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_lower_bound::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 1, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.LowerBound(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_lower_bound::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 2, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return lower_bound(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_lower_bound::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 3, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return LowerBound(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_lower_bound::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 4, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return lower_bound(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_lower_bound::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 5, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return LowerBound(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<!_HasDefaultHandle<K, Tc, Tr, Targs...>::value,
	 Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	assert(!"do not have handle lower_bound or LowerBound function ");
}

}

}

namespace cont
{
namespace handle
{

struct LowerBoundKey;

template<typename K, typename Tc, typename Tr, typename... Targs>
class LowerBound : public simple::Handle<LowerBoundKey, Tr, Tc&, Targs...>
{
public:
	typedef K KeyType;
	typedef std::function<Tr(Tc&, Targs...)> HandleType;
public:
	LowerBound();
	LowerBound(HandleType handle);
	LowerBound(const LowerBound<K, Tc, Tr, Targs...>& cpy);
	LowerBound(LowerBound<K, Tc, Tr, Targs...>&& mov);
public:
	LowerBound<K, Tc, Tr, Targs...>& 
		operator=(const LowerBound<K, Tc, Tr, Targs...>& cpy);
	LowerBound<K, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename K, typename Tc, typename Tr, typename... Targs>
LowerBound<K, Tc, Tr, Targs...>::LowerBound()
{
	if (simple::_helper::_lower_bound::
        _HasDefaultHandle<K, Tc, Tr, Targs...>::value)
		Set(&simple::_helper::_lower_bound::
            _DefaultHandle<K, Tc, Tr, Targs...>);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
LowerBound<K, Tc, Tr, Targs...>::LowerBound(HandleType handle) :
	simple::Handle<LowerBoundKey, Tr, Tc&, Targs...>(handle)
{}  

template<typename K, typename Tc, typename Tr, typename... Targs>
LowerBound<K, Tc, Tr, Targs...>::
	LowerBound(const LowerBound<K, Tc, Tr, Targs...>& cpy) :
		simple::Handle<LowerBoundKey, Tr, Tc&, Targs...>(cpy)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
LowerBound<K, Tc, Tr, Targs...>::
	LowerBound(LowerBound<K, Tc, Tr, Targs...>&& mov) :
		simple::Handle<LowerBoundKey, Tr, Tc&, Targs...>(mov)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
LowerBound<K, Tc, Tr, Targs...>& LowerBound<K, Tc, Tr, Targs...>::
	operator=(const LowerBound<K, Tc, Tr, Targs...>& cpy)
{
	simple::Handle<LowerBoundKey, Tr, Tc&, Targs...>::operator=(cpy);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
LowerBound<K, Tc, Tr, Targs...>& LowerBound<K, Tc, Tr, Targs...>::
	operator=(HandleType handle)
{
	simple::Handle<LowerBoundKey, Tr, Tc&, Targs...>::operator=(handle);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Tr LowerBound<K, Tc, Tr, Targs...>::operator()(Tc& cont, Targs... val_args)
{
    return simple::Handle<LowerBoundKey, Tr, Tc&, Targs...>
		::operator()(cont, val_args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
LowerBound<K, Tc, Tr, Targs...>::operator bool() const
{
	return simple::Handle<LowerBoundKey, Tr, Tc&, Targs...>::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_LOWER_BOUND_H_
