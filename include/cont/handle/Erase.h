#ifndef CONTAINER_HANDLE_ERASE_H_
#define CONTAINER_HANDLE_ERASE_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../Handle.h"
#include "../../type/Switch.h"

namespace simple
{
namespace _helper
{
namespace _erase
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.erase(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.Erase(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(erase(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(Erase(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(erase(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(Erase(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename K, typename Tc, typename Tr, typename... Targs>
using _SwitchDefaultHandleType = simple::type::Switch<K, std::false_type,
	decltype(simple::_helper::_erase::
		_IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_erase::
		_IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_erase::
		_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_erase::
		_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_erase::
		_IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_erase::
		_IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))>;

template<typename K, typename Tc, typename Tr, typename... Targs>
using _HasDefaultHandle = std::integral_constant<bool,
	simple::_helper::_erase::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index !=
	simple::_helper::_erase::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Size>;

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_erase::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 0, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.erase(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_erase::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 1, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.Erase(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_erase::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 2, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return erase(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_erase::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 3, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return Erase(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_erase::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 4, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return erase(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_erase::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 5, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return Erase(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<!_HasDefaultHandle<K, Tc, Tr, Targs...>::value,
	 Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	assert(!"do not have handle erase or Erase function ");
}

}

}

namespace cont
{
namespace handle
{

struct EraseKey;

template<typename K, typename Tc, typename Tr, typename... Targs>
class Erase : public simple::Handle<EraseKey, Tr, Tc&, Targs...>
{
public:
	typedef K KeyType;
	typedef std::function<Tr(Tc&, Targs...)> HandleType;
public:
	Erase();
	Erase(HandleType handle);
	Erase(const Erase<K, Tc, Tr, Targs...>& cpy);
	Erase(Erase<K, Tc, Tr, Targs...>&& mov);
public:
	Erase<K, Tc, Tr, Targs...>& 
		operator=(const Erase<K, Tc, Tr, Targs...>& cpy);
	Erase<K, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename K, typename Tc, typename Tr, typename... Targs>
Erase<K, Tc, Tr, Targs...>::Erase()
{
	if (simple::_helper::_erase::_HasDefaultHandle<K, Tc, Tr, Targs...>::value)
		Set(&simple::_helper::_erase::_DefaultHandle<K, Tc, Tr, Targs...>);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Erase<K, Tc, Tr, Targs...>::Erase(HandleType handle) :
	simple::Handle<EraseKey, Tr, Tc&, Targs...>(handle)
{}  

template<typename K, typename Tc, typename Tr, typename... Targs>
Erase<K, Tc, Tr, Targs...>::
	Erase(const Erase<K, Tc, Tr, Targs...>& cpy) :
		simple::Handle<EraseKey, Tr, Tc&, Targs...>(cpy)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
Erase<K, Tc, Tr, Targs...>::
	Erase(Erase<K, Tc, Tr, Targs...>&& mov) :
		simple::Handle<EraseKey, Tr, Tc&, Targs...>(mov)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
Erase<K, Tc, Tr, Targs...>& Erase<K, Tc, Tr, Targs...>::
	operator=(const Erase<K, Tc, Tr, Targs...>& cpy)
{
	simple::Handle<EraseKey, Tr, Tc&, Targs...>::operator=(cpy);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Erase<K, Tc, Tr, Targs...>& Erase<K, Tc, Tr, Targs...>::
	operator=(HandleType handle)
{
	simple::Handle<EraseKey, Tr, Tc&, Targs...>::operator=(handle);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Tr Erase<K, Tc, Tr, Targs...>::operator()(Tc& cont, Targs... val_args)
{
    return simple::Handle<EraseKey, Tr, Tc&, Targs...>
		::operator()(cont, val_args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Erase<K, Tc, Tr, Targs...>::operator bool() const
{
	return simple::Handle<EraseKey, Tr, Tc&, Targs...>::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_ERASE_H_
