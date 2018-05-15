#ifndef CONTAINER_HANDLE_PUSH_BACK_H_
#define CONTAINER_HANDLE_PUSH_BACK_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../Handle.h"

namespace simple
{
namespace _helper
{
namespace _push_back
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.push_back(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.PushBack(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(push_back(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(PushBack(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(push_back(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(PushBack(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename Tc, typename Tr, typename... Targs>
struct _Validation
{
	static constexpr bool _HasFunctionMember0 =
		decltype(simple::_helper::_push_back::
            _IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionMember1 =
		decltype(simple::_helper::_push_back::
            _IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionReference0 =
		decltype(simple::_helper::_push_back::
			_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionReference1 =
		decltype(simple::_helper::_push_back::
			_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionPointer0 =
		decltype(simple::_helper::_push_back::
            _IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionPointer1 =
		decltype(simple::_helper::_push_back::
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
		return c.push_back(args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionMember1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return c.PushBack(args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference0, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return push_back(c, args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference0 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return PushBack(c, args...);
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
		return push_back(&c, args...);
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
		return PushBack(&c, args...);
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
		assert(!"do not have handle push_back or PushBack function ");
	}
};

}

}

namespace cont
{
namespace handle
{

struct PushBackKey;

template<typename K, typename Tc, typename Tr, typename... Targs>
class PushBack : public simple::Handle<PushBackKey, Tr, Tc&, Targs...>
{
public:
	typedef K KeyType;
	typedef std::function<Tr(Tc&, Targs...)> HandleType;
public:
	PushBack();
	PushBack(HandleType handle);
	PushBack(const PushBack<K, Tc, Tr, Targs...>& cpy);
	PushBack(PushBack<K, Tc, Tr, Targs...>&& mov);
public:
	PushBack<K, Tc, Tr, Targs...>& 
		operator=(const PushBack<K, Tc, Tr, Targs...>& cpy);
	PushBack<K, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename K, typename Tc, typename Tr, typename... Targs>
PushBack<K, Tc, Tr, Targs...>::PushBack()
{
	if (simple::_helper::_push_back::
        _Validation<Tc, Tr, Targs...>::_HasFunction)
	{
		Set(&simple::_helper::_push_back::
            _Call::DefaultHandle<Tc, Tr, Targs...>);
	}
}

template<typename K, typename Tc, typename Tr, typename... Targs>
PushBack<K, Tc, Tr, Targs...>::PushBack(HandleType handle) :
	simple::Handle<PushBackKey, Tr, Tc&, Targs...>(handle)
{}  

template<typename K, typename Tc, typename Tr, typename... Targs>
PushBack<K, Tc, Tr, Targs...>::
	PushBack(const PushBack<K, Tc, Tr, Targs...>& cpy) :
		simple::Handle<PushBackKey, Tr, Tc&, Targs...>(cpy)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
PushBack<K, Tc, Tr, Targs...>::
	PushBack(PushBack<K, Tc, Tr, Targs...>&& mov) :
		simple::Handle<PushBackKey, Tr, Tc&, Targs...>(mov)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
PushBack<K, Tc, Tr, Targs...>& PushBack<K, Tc, Tr, Targs...>::
	operator=(const PushBack<K, Tc, Tr, Targs...>& cpy)
{
	simple::Handle<PushBackKey, Tr, Tc&, Targs...>::operator=(cpy);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
PushBack<K, Tc, Tr, Targs...>& PushBack<K, Tc, Tr, Targs...>::
	operator=(HandleType handle)
{
	simple::Handle<PushBackKey, Tr, Tc&, Targs...>::operator=(handle);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Tr PushBack<K, Tc, Tr, Targs...>::operator()(Tc& cont, Targs... val_args)
{
    return simple::Handle<PushBackKey, Tr, Tc&, Targs...>
		::operator()(cont, val_args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
PushBack<K, Tc, Tr, Targs...>::operator bool() const
{
	return simple::Handle<PushBackKey, Tr, Tc&, Targs...>::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_PUSH_BACK_H_
