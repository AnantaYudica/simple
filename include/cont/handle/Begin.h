#ifndef CONTAINER_HANDLE_BEGIN_H_
#define CONTAINER_HANDLE_BEGIN_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../Handle.h"
#include "../../type/Switch.h"

namespace simple
{
namespace _helper
{
namespace _begin
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.begin(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.Begin(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(begin(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(Begin(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(begin(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(Begin(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename K, typename Tc, typename Tr, typename... Targs>
using _SwitchDefaultHandleType = simple::type::Switch<K, std::false_type,
	decltype(simple::_helper::_begin::
		_IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_begin::
		_IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_begin::
		_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_begin::
		_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_begin::
		_IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_begin::
		_IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))>;

template<typename K, typename Tc, typename Tr, typename... Targs>
using _HasDefaultHandle = std::integral_constant<bool,
	simple::_helper::_begin::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index !=
	simple::_helper::_begin::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Size>;

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 0, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.begin(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 1, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.Begin(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 2, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return begin(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 3, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return Begin(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 4, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return begin(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 5, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return Begin(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<!_HasDefaultHandle<K, Tc, Tr, Targs...>::value,
	 Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	assert(!"do not have handle begin or Begin function ");
}

}

}

namespace cont
{
namespace handle
{

struct BeginKey;

template<typename K, typename Tc, typename Tr, typename... Targs>
class Begin : public simple::Handle<BeginKey, Tr, Tc&, Targs...>
{
public:
	typedef K KeyType;
	typedef std::function<Tr(Tc&, Targs...)> HandleType;
public:
	Begin();
	Begin(HandleType handle);
	Begin(const Begin<K, Tc, Tr, Targs...>& cpy);
	Begin(Begin<K, Tc, Tr, Targs...>&& mov);
public:
	Begin<K, Tc, Tr, Targs...>& 
		operator=(const Begin<K, Tc, Tr, Targs...>& cpy);
	Begin<K, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename K, typename Tc, typename Tr, typename... Targs>
Begin<K, Tc, Tr, Targs...>::Begin()
{
	if (simple::_helper::_begin::_HasDefaultHandle<K, Tc, Tr, Targs...>::value)
		Set(&simple::_helper::_begin::_DefaultHandle<K, Tc, Tr, Targs...>);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Begin<K, Tc, Tr, Targs...>::Begin(HandleType handle) :
	simple::Handle<BeginKey, Tr, Tc&, Targs...>(handle)
{}  

template<typename K, typename Tc, typename Tr, typename... Targs>
Begin<K, Tc, Tr, Targs...>::
	Begin(const Begin<K, Tc, Tr, Targs...>& cpy) :
		simple::Handle<BeginKey, Tr, Tc&, Targs...>(cpy)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
Begin<K, Tc, Tr, Targs...>::
	Begin(Begin<K, Tc, Tr, Targs...>&& mov) :
		simple::Handle<BeginKey, Tr, Tc&, Targs...>(mov)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
Begin<K, Tc, Tr, Targs...>& Begin<K, Tc, Tr, Targs...>::
	operator=(const Begin<K, Tc, Tr, Targs...>& cpy)
{
	simple::Handle<BeginKey, Tr, Tc&, Targs...>::operator=(cpy);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Begin<K, Tc, Tr, Targs...>& Begin<K, Tc, Tr, Targs...>::
	operator=(HandleType handle)
{
	simple::Handle<BeginKey, Tr, Tc&, Targs...>::operator=(handle);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Tr Begin<K, Tc, Tr, Targs...>::operator()(Tc& cont, Targs... val_args)
{
    return simple::Handle<BeginKey, Tr, Tc&, Targs...>
		::operator()(cont, val_args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Begin<K, Tc, Tr, Targs...>::operator bool() const
{
	return simple::Handle<BeginKey, Tr, Tc&, Targs...>::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_BEGIN_H_