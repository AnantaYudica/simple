#ifndef CONTAINER_HANDLE_LOAD_FACTOR_H_
#define CONTAINER_HANDLE_LOAD_FACTOR_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../Handle.h"
#include "../../type/Switch.h"

namespace simple
{
namespace _helper
{
namespace _load_factor
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.load_factor(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.LoadFactor(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(load_factor(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(LoadFactor(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(load_factor(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(LoadFactor(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename K, typename Tc, typename Tr, typename... Targs>
using _SwitchDefaultHandleType = simple::type::Switch<K, std::false_type,
	decltype(simple::_helper::_load_factor::
		_IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_load_factor::
		_IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_load_factor::
		_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_load_factor::
		_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_load_factor::
		_IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_load_factor::
		_IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))>;

template<typename K, typename Tc, typename Tr, typename... Targs>
using _HasDefaultHandle = std::integral_constant<bool,
	simple::_helper::_load_factor::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index !=
	simple::_helper::_load_factor::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Size>;

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_load_factor::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 0, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.load_factor(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_load_factor::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 1, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.LoadFactor(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_load_factor::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 2, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return load_factor(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_load_factor::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 3, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return LoadFactor(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_load_factor::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 4, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return load_factor(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_load_factor::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 5, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return LoadFactor(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<!_HasDefaultHandle<K, Tc, Tr, Targs...>::value,
	 Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	assert(!"do not have handle load_factor or LoadFactor function ");
}

}

}

namespace cont
{
namespace handle
{

struct LoadFactorKey;

template<typename K, typename Tc, typename Tr, typename... Targs>
class LoadFactor : public simple::Handle<LoadFactorKey, Tr, Tc&, Targs...>
{
public:
	typedef K KeyType;
	typedef std::function<Tr(Tc&, Targs...)> HandleType;
public:
	LoadFactor();
	LoadFactor(HandleType handle);
	LoadFactor(const LoadFactor<K, Tc, Tr, Targs...>& cpy);
	LoadFactor(LoadFactor<K, Tc, Tr, Targs...>&& mov);
public:
	LoadFactor<K, Tc, Tr, Targs...>& 
		operator=(const LoadFactor<K, Tc, Tr, Targs...>& cpy);
	LoadFactor<K, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename K, typename Tc, typename Tr, typename... Targs>
LoadFactor<K, Tc, Tr, Targs...>::LoadFactor()
{
	if (simple::_helper::_load_factor::
        _HasDefaultHandle<K, Tc, Tr, Targs...>::value)
		Set(&simple::_helper::_load_factor::
            _DefaultHandle<K, Tc, Tr, Targs...>);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
LoadFactor<K, Tc, Tr, Targs...>::LoadFactor(HandleType handle) :
	simple::Handle<LoadFactorKey, Tr, Tc&, Targs...>(handle)
{}  

template<typename K, typename Tc, typename Tr, typename... Targs>
LoadFactor<K, Tc, Tr, Targs...>::
	LoadFactor(const LoadFactor<K, Tc, Tr, Targs...>& cpy) :
		simple::Handle<LoadFactorKey, Tr, Tc&, Targs...>(cpy)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
LoadFactor<K, Tc, Tr, Targs...>::
	LoadFactor(LoadFactor<K, Tc, Tr, Targs...>&& mov) :
		simple::Handle<LoadFactorKey, Tr, Tc&, Targs...>(mov)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
LoadFactor<K, Tc, Tr, Targs...>& LoadFactor<K, Tc, Tr, Targs...>::
	operator=(const LoadFactor<K, Tc, Tr, Targs...>& cpy)
{
	simple::Handle<LoadFactorKey, Tr, Tc&, Targs...>::operator=(cpy);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
LoadFactor<K, Tc, Tr, Targs...>& LoadFactor<K, Tc, Tr, Targs...>::
	operator=(HandleType handle)
{
	simple::Handle<LoadFactorKey, Tr, Tc&, Targs...>::operator=(handle);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Tr LoadFactor<K, Tc, Tr, Targs...>::operator()(Tc& cont, Targs... val_args)
{
    return simple::Handle<LoadFactorKey, Tr, Tc&, Targs...>
		::operator()(cont, val_args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
LoadFactor<K, Tc, Tr, Targs...>::operator bool() const
{
	return simple::Handle<LoadFactorKey, Tr, Tc&, Targs...>::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_LOAD_FACTOR_H_
