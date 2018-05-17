#ifndef CONTAINER_HANDLE_CONST_REVERSE_BEGIN_H_
#define CONTAINER_HANDLE_CONST_REVERSE_BEGIN_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../Handle.h"
#include "../../type/Switch.h"

namespace simple
{
namespace _helper
{
namespace _const_reverse_begin
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.crbegin(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.ConstReverseBegin(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(crbegin(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(ConstReverseBegin(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(crbegin(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(ConstReverseBegin(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename K, typename Tc, typename Tr, typename... Targs>
using _SwitchDefaultHandleType = simple::type::Switch<K, std::false_type,
	decltype(simple::_helper::_const_reverse_begin::
		_IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_const_reverse_begin::
		_IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_const_reverse_begin::
		_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_const_reverse_begin::
		_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_const_reverse_begin::
		_IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_const_reverse_begin::
		_IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))>;

template<typename K, typename Tc, typename Tr, typename... Targs>
using _HasDefaultHandle = std::integral_constant<bool,
	simple::_helper::_const_reverse_begin::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index !=
	simple::_helper::_const_reverse_begin::
		_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Size>;

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 0, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.crbegin(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 1, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.ConstReverseBegin(args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 2, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return crbegin(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 3, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return ConstReverseBegin(c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 4, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return crbegin(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_const_reverse_begin::
	_SwitchDefaultHandleType<K, Tc, Tr, Targs...>::Index == 5, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return ConstReverseBegin(&c, args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
typename std::enable_if<!_HasDefaultHandle<K, Tc, Tr, Targs...>::value,
	 Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	assert(!"do not have handle crbegin or ConstReverseBegin function ");
}

}

}

namespace cont
{
namespace handle
{

struct ConstReverseBeginKey;

template<typename K, typename Tc, typename Tr, typename... Targs>
class ConstReverseBegin : 
    public simple::Handle<ConstReverseBeginKey, Tr, Tc&, Targs...>
{
public:
	typedef K KeyType;
	typedef std::function<Tr(Tc&, Targs...)> HandleType;
public:
	ConstReverseBegin();
	ConstReverseBegin(HandleType handle);
	ConstReverseBegin(const ConstReverseBegin<K, Tc, Tr, Targs...>& cpy);
	ConstReverseBegin(ConstReverseBegin<K, Tc, Tr, Targs...>&& mov);
public:
	ConstReverseBegin<K, Tc, Tr, Targs...>& 
		operator=(const ConstReverseBegin<K, Tc, Tr, Targs...>& cpy);
	ConstReverseBegin<K, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<K, Tc, Tr, Targs...>::ConstReverseBegin()
{
	if (simple::_helper::_const_reverse_begin::
		_HasDefaultHandle<K, Tc, Tr, Targs...>::value)
		Set(&simple::_helper::_const_reverse_begin::
			_DefaultHandle<K, Tc, Tr, Targs...>);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<K, Tc, Tr, Targs...>::ConstReverseBegin(HandleType handle) :
	simple::Handle<ConstReverseBeginKey, Tr, Tc&, Targs...>(handle)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<K, Tc, Tr, Targs...>::
	ConstReverseBegin(const ConstReverseBegin<K, Tc, Tr, Targs...>& cpy) :
		simple::Handle<ConstReverseBeginKey, Tr, Tc&, Targs...>(cpy)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<K, Tc, Tr, Targs...>::
    ConstReverseBegin(ConstReverseBegin<K, Tc, Tr, Targs...>&& mov) :
	    simple::Handle<ConstReverseBeginKey, Tr, Tc&, Targs...>(mov)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<K, Tc, Tr, Targs...>& 
    ConstReverseBegin<K, Tc, Tr, Targs...>::
	    operator=(const ConstReverseBegin<K, Tc, Tr, Targs...>& cpy)
{
	simple::Handle<ConstReverseBeginKey, Tr, Tc&, Targs...>::operator=(cpy);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<K, Tc, Tr, Targs...>& 
    ConstReverseBegin<K, Tc, Tr, Targs...>::operator=(HandleType handle)
{
	simple::Handle<ConstReverseBeginKey, Tr, Tc&, Targs...>::operator=(handle);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Tr ConstReverseBegin<K, Tc, Tr, Targs...>::
    operator()(Tc& cont, Targs... val_args)
{
	return simple::Handle<ConstReverseBeginKey, Tr, Tc&, Targs...>::
		operator()(cont, val_args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<K, Tc, Tr, Targs...>::operator bool() const
{
	return simple::Handle<ConstReverseBeginKey, Tr, Tc&, Targs...>::
        operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_CONST_REVERSE_BEGIN_H_
