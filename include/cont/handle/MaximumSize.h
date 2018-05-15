#ifndef CONTAINER_HANDLE_MAXIMUM_SIZE_H_
#define CONTAINER_HANDLE_MAXIMUM_SIZE_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../Handle.h"

namespace simple
{
namespace _helper
{
namespace _maximum_size
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.max_size(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.MaximumSize(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(max_size(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(MaximumSize(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(max_size(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(MaximumSize(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename Tc, typename Tr, typename... Targs>
struct _Validation
{
	static constexpr bool _HasFunctionMember0 =
		decltype(simple::_helper::_maximum_size::
            _IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionMember1 =
		decltype(simple::_helper::_maximum_size::
            _IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionReference0 =
		decltype(simple::_helper::_maximum_size::
			_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionReference1 =
		decltype(simple::_helper::_maximum_size::
			_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionPointer0 =
		decltype(simple::_helper::_maximum_size::
            _IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionPointer1 =
		decltype(simple::_helper::_maximum_size::
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
		return c.max_size(args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionMember1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return c.MaximumSize(args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference0, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return max_size(c, args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference0 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return MaximumSize(c, args...);
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
		return max_size(&c, args...);
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
		return MaximumSize(&c, args...);
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
		assert(!"do not have handle max_size or MaximumSize function ");
	}
};

}

}

namespace cont
{
namespace handle
{

struct MaximumSizeKey;

template<typename K, typename Tc, typename Tr, typename... Targs>
class MaximumSize : public simple::Handle<MaximumSizeKey, Tr, Tc&, Targs...>
{
public:
	typedef K KeyType;
	typedef std::function<Tr(Tc&, Targs...)> HandleType;
public:
	MaximumSize();
	MaximumSize(HandleType handle);
	MaximumSize(const MaximumSize<K, Tc, Tr, Targs...>& cpy);
	MaximumSize(MaximumSize<K, Tc, Tr, Targs...>&& mov);
public:
	MaximumSize<K, Tc, Tr, Targs...>& 
		operator=(const MaximumSize<K, Tc, Tr, Targs...>& cpy);
	MaximumSize<K, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumSize<K, Tc, Tr, Targs...>::MaximumSize()
{
	if (simple::_helper::_maximum_size::
        _Validation<Tc, Tr, Targs...>::_HasFunction)
	{
		Set(&simple::_helper::_maximum_size::
            _Call::DefaultHandle<Tc, Tr, Targs...>);
	}
}

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumSize<K, Tc, Tr, Targs...>::MaximumSize(HandleType handle) :
	simple::Handle<MaximumSizeKey, Tr, Tc&, Targs...>(handle)
{}  

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumSize<K, Tc, Tr, Targs...>::
	MaximumSize(const MaximumSize<K, Tc, Tr, Targs...>& cpy) :
		simple::Handle<MaximumSizeKey, Tr, Tc&, Targs...>(cpy)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumSize<K, Tc, Tr, Targs...>::
	MaximumSize(MaximumSize<K, Tc, Tr, Targs...>&& mov) :
		simple::Handle<MaximumSizeKey, Tr, Tc&, Targs...>(mov)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumSize<K, Tc, Tr, Targs...>& MaximumSize<K, Tc, Tr, Targs...>::
	operator=(const MaximumSize<K, Tc, Tr, Targs...>& cpy)
{
	simple::Handle<MaximumSizeKey, Tr, Tc&, Targs...>::operator=(cpy);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumSize<K, Tc, Tr, Targs...>& MaximumSize<K, Tc, Tr, Targs...>::
	operator=(HandleType handle)
{
	simple::Handle<MaximumSizeKey, Tr, Tc&, Targs...>::operator=(handle);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Tr MaximumSize<K, Tc, Tr, Targs...>::operator()(Tc& cont, Targs... val_args)
{
    return simple::Handle<MaximumSizeKey, Tr, Tc&, Targs...>
		::operator()(cont, val_args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumSize<K, Tc, Tr, Targs...>::operator bool() const
{
	return simple::Handle<MaximumSizeKey, Tr, Tc&, Targs...>::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_MAXIMUM_SIZE_H_
