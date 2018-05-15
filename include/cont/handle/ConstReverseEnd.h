#ifndef CONTAINER_HANDLE_CONST_REVERSE_END_H_
#define CONTAINER_HANDLE_CONST_REVERSE_END_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../Handle.h"

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

template<typename Tc, typename Tr, typename... Targs>
struct _Validation
{
	static constexpr bool _HasFunctionMember0 =
		decltype(simple::_helper::_const_reverse_end::
            _IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionMember1 =
		decltype(simple::_helper::_const_reverse_end::
            _IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionReference0 =
		decltype(simple::_helper::_const_reverse_end::
            _IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionReference1 =
		decltype(simple::_helper::_const_reverse_end::
            _IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionPointer0 =
		decltype(simple::_helper::_const_reverse_end::
            _IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionPointer1 =
		decltype(simple::_helper::_const_reverse_end::
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
		return c.crend(args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionMember1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return c.ConstReverseEnd(args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference0, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return crend(c, args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference0 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return ConstReverseEnd(c, args...);
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
		return crend(&c, args...);
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
		return ConstReverseEnd(&c, args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionPointer0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionPointer1, Tr>::type
		DefaultHandle(...)
	{
		assert(!"do not have handle crend or ConstReverseEnd function ");
	}
};

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
		_Validation<Tc, Tr, Targs...>::_HasFunction)
	{
		Set(&simple::_helper::_const_reverse_begin::
			_Call::DefaultHandle<Tc, Tr, Targs...>);
	}
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
