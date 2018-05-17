#ifndef CONTAINER_HANDLE_CONST_REVERSE_END_H_
#define CONTAINER_HANDLE_CONST_REVERSE_END_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../Handle.h"
#include "../../type/Switch.h"

namespace simple
{
namespace _helper
{
namespace _const_reverse_end
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.crend(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.ConstReverseEnd(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(crend(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(ConstReverseEnd(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(crend(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(ConstReverseEnd(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename K, typename Tc, typename Tr, typename... Targs>
using _SwitchDefaultHandleType = simple::type::Switch<K, std::false_type,
	decltype(simple::_helper::_const_reverse_end::
		_IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_const_reverse_end::
		_IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_const_reverse_end::
		_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_const_reverse_end::
		_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_const_reverse_end::
		_IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_const_reverse_end::
		_IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))>;

template<typename K, typename Tc, typename Tr, typename... Targs>
using _HasDefaultHandle = std::integral_constant<bool,
	simple::_helper::_const_reverse_end::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index !=
	simple::_helper::_const_reverse_end::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Size>;

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_end::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 0, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.crend(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_end::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 1, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.ConstReverseEnd(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_end::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 2, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return crend(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_end::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 3, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return ConstReverseEnd(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_end::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 4, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return crend(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_end::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 5, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return ConstReverseEnd(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<!_HasDefaultHandle<K, Tc, Tr, Targs...>::value,
	 Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	assert(!"do not have handle crend or ConstReverseEnd function ");
}

}

}

namespace cont
{
namespace handle
{

struct ConstReverseEndKey;

template<typename K, typename Tc, typename Tr, typename... Targs>
class ConstReverseEnd : 
    public simple::Handle<ConstReverseEndKey, Tr, Tc&, Targs...>
{
public:
	typedef K KeyType;
	typedef std::function<Tr(Tc&, Targs...)> HandleType;
public:
	ConstReverseEnd();
	ConstReverseEnd(HandleType handle);
	ConstReverseEnd(const ConstReverseEnd<K, Tc, Tr, Targs...>& cpy);
	ConstReverseEnd(ConstReverseEnd<K, Tc, Tr, Targs...>&& mov);
public:
	ConstReverseEnd<K, Tc, Tr, Targs...>& 
		operator=(const ConstReverseEnd<K, Tc, Tr, Targs...>& cpy);
	ConstReverseEnd<K, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseEnd<K, Tc, Tr, Targs...>::ConstReverseEnd()
{
	if (simple::_helper::_const_reverse_begin::
		_HasDefaultHandle<K, Tc, Tr, Targs...>::value)
	Set(&simple::_helper::_const_reverse_begin::
			_DefaultHandle<K, Tc, Tr, Targs...>);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseEnd<K, Tc, Tr, Targs...>::ConstReverseEnd(HandleType handle) :
	simple::Handle<ConstReverseEndKey, Tr, Tc&, Targs...>(handle)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseEnd<K, Tc, Tr, Targs...>::
	ConstReverseEnd(const ConstReverseEnd<K, Tc, Tr, Targs...>& cpy) :
		simple::Handle<ConstReverseEndKey, Tr, Tc&, Targs...>(cpy)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseEnd<K, Tc, Tr, Targs...>::
    ConstReverseEnd(ConstReverseEnd<K, Tc, Tr, Targs...>&& mov) :
	    simple::Handle<ConstReverseEndKey, Tr, Tc&, Targs...>(mov)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseEnd<K, Tc, Tr, Targs...>& 
    ConstReverseEnd<K, Tc, Tr, Targs...>::
	    operator=(const ConstReverseEnd<K, Tc, Tr, Targs...>& cpy)
{
	simple::Handle<ConstReverseEndKey, Tr, Tc&, Targs...>::operator=(cpy);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseEnd<K, Tc, Tr, Targs...>& 
    ConstReverseEnd<K, Tc, Tr, Targs...>::operator=(HandleType handle)
{
	simple::Handle<ConstReverseEndKey, Tr, Tc&, Targs...>::operator=(handle);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Tr ConstReverseEnd<K, Tc, Tr, Targs...>::
    operator()(Tc& cont, Targs... val_args)
{
	return simple::Handle<ConstReverseEndKey, Tr, Tc&, Targs...>::
		operator()(cont, val_args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseEnd<K, Tc, Tr, Targs...>::operator bool() const
{
	return simple::Handle<ConstReverseEndKey, Tr, Tc&, Targs...>::
        operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_CONST_REVERSE_END_H_
