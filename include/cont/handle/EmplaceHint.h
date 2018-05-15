#ifndef CONTAINER_HANDLE_EMPLACE_HINT_H_
#define CONTAINER_HANDLE_EMPLACE_HINT_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../Handle.h"

namespace simple
{
namespace _helper
{
namespace _emplace_hint
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.emplace_hint(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.EmplaceHint(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(emplace_hint(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(EmplaceHint(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(emplace_hint(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(EmplaceHint(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename Tc, typename Tr, typename... Targs>
struct _Validation
{
	static constexpr bool _HasFunctionMember0 =
		decltype(simple::_helper::_emplace_hint::
            _IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionMember1 =
		decltype(simple::_helper::_emplace_hint::
            _IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionReference0 =
		decltype(simple::_helper::_emplace_hint::
			_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionReference1 =
		decltype(simple::_helper::_emplace_hint::
			_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionPointer0 =
		decltype(simple::_helper::_emplace_hint::
            _IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionPointer1 =
		decltype(simple::_helper::_emplace_hint::
            _IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunction = (
		_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 ||
		_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 ||
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference0 ||
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference1 || 
		_Validation<Tc, Tr, Targs...>::_HasFunctionPointer0 ||
		_Validation<Tc, Tr, Targs...>::_HasFunctionPointer1);
};

struct _Call
{
	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		_Validation<Tc, Tr, Targs...>::_HasFunctionMember0, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return c.emplace_hint(args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionMember1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return c.EmplaceHint(args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference0, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return emplace_hint(c, args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference0 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return EmplaceHint(c, args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference1 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionPointer0, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return emplace_hint(&c, args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionPointer0 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionPointer1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return EmplaceHint(&c, args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionPointer0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionPointer1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		assert(!"do not have handle emplace_hint or EmplaceHint function ");
	}
};

}

}

namespace cont
{
namespace handle
{

struct EmplaceHintKey;

template<typename K, typename Tc, typename Tr, typename... Targs>
class EmplaceHint : public simple::Handle<EmplaceHintKey, Tr, Tc&, Targs...>
{
public:
	typedef K KeyType;
	typedef std::function<Tr(Tc&, Targs...)> HandleType;
public:
	EmplaceHint();
	EmplaceHint(HandleType handle);
	EmplaceHint(const EmplaceHint<K, Tc, Tr, Targs...>& cpy);
	EmplaceHint(EmplaceHint<K, Tc, Tr, Targs...>&& mov);
public:
	EmplaceHint<K, Tc, Tr, Targs...>& 
		operator=(const EmplaceHint<K, Tc, Tr, Targs...>& cpy);
	EmplaceHint<K, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename K, typename Tc, typename Tr, typename... Targs>
EmplaceHint<K, Tc, Tr, Targs...>::EmplaceHint()
{
	if (simple::_helper::_emplace_hint::
        _Validation<Tc, Tr, Targs...>::_HasFunction)
	{
		Set(&simple::_helper::_emplace_hint::
            _Call::DefaultHandle<Tc, Tr, Targs...>);
	}
}

template<typename K, typename Tc, typename Tr, typename... Targs>
EmplaceHint<K, Tc, Tr, Targs...>::EmplaceHint(HandleType handle) :
	simple::Handle<EmplaceHintKey, Tr, Tc&, Targs...>(handle)
{}  

template<typename K, typename Tc, typename Tr, typename... Targs>
EmplaceHint<K, Tc, Tr, Targs...>::
	EmplaceHint(const EmplaceHint<K, Tc, Tr, Targs...>& cpy) :
		simple::Handle<EmplaceHintKey, Tr, Tc&, Targs...>(cpy)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
EmplaceHint<K, Tc, Tr, Targs...>::
	EmplaceHint(EmplaceHint<K, Tc, Tr, Targs...>&& mov) :
		simple::Handle<EmplaceHintKey, Tr, Tc&, Targs...>(mov)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
EmplaceHint<K, Tc, Tr, Targs...>& EmplaceHint<K, Tc, Tr, Targs...>::
	operator=(const EmplaceHint<K, Tc, Tr, Targs...>& cpy)
{
	simple::Handle<EmplaceHintKey, Tr, Tc&, Targs...>::operator=(cpy);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
EmplaceHint<K, Tc, Tr, Targs...>& EmplaceHint<K, Tc, Tr, Targs...>::
	operator=(HandleType handle)
{
	simple::Handle<EmplaceHintKey, Tr, Tc&, Targs...>::operator=(handle);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Tr EmplaceHint<K, Tc, Tr, Targs...>::operator()(Tc& cont, Targs... val_args)
{
    return simple::Handle<EmplaceHintKey, Tr, Tc&, Targs...>
		::operator()(cont, val_args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
EmplaceHint<K, Tc, Tr, Targs...>::operator bool() const
{
	return simple::Handle<EmplaceHintKey, Tr, Tc&, Targs...>::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_EMPLACE_HINT_H_
