#ifndef CONTAINER_HANDLE_MAXIMUM_BUCKET_COUNT_H_
#define CONTAINER_HANDLE_MAXIMUM_BUCKET_COUNT_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../Handle.h"

namespace simple
{
namespace _helper
{
namespace _maximum_bucket_count
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.max_bucket_count(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.MaximumBucketCount(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(max_bucket_count(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(MaximumBucketCount(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(max_bucket_count(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(MaximumBucketCount(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename Tc, typename Tr, typename... Targs>
struct _Validation
{
	static constexpr bool _HasFunctionMember0 =
		decltype(simple::_helper::maximum_bucket_count::
            _IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionMember1 =
		decltype(simple::_helper::maximum_bucket_count::
            _IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionReference0 =
		decltype(simple::_helper::maximum_bucket_count::
			_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionReference1 =
		decltype(simple::_helper::maximum_bucket_count::
			_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionPointer0 =
		decltype(simple::_helper::maximum_bucket_count::
            _IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>()))::value;
	static constexpr bool _HasFunctionPointer1 =
		decltype(simple::_helper::maximum_bucket_count::
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
		return c.max_bucket_count(args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionMember1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return c.MaximumBucketCount(args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference0, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return max_bucket_count(c, args...);
	}

	template<typename Tc, typename Tr, typename... Targs>
	static typename std::enable_if<
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember0 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionMember1 &&
		!_Validation<Tc, Tr, Targs...>::_HasFunctionReference0 &&
		_Validation<Tc, Tr, Targs...>::_HasFunctionReference1, Tr>::type
		DefaultHandle(Tc& c, Targs... args)
	{
		return MaximumBucketCount(c, args...);
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
		return max_bucket_count(&c, args...);
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
		return MaximumBucketCount(&c, args...);
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
		assert(!"do not have handle max_bucket_count or "
            "MaximumBucketCount function ");
	}
};

}

}

namespace cont
{
namespace handle
{

struct MaximumBucketCountKey;

template<typename K, typename Tc, typename Tr, typename... Targs>
class MaximumBucketCount : public simple::Handle<MaximumBucketCountKey, Tr, Tc&, Targs...>
{
public:
	typedef K KeyType;
	typedef std::function<Tr(Tc&, Targs...)> HandleType;
public:
	MaximumBucketCount();
	MaximumBucketCount(HandleType handle);
	MaximumBucketCount(const MaximumBucketCount<K, Tc, Tr, Targs...>& cpy);
	MaximumBucketCount(MaximumBucketCount<K, Tc, Tr, Targs...>&& mov);
public:
	MaximumBucketCount<K, Tc, Tr, Targs...>& 
		operator=(const MaximumBucketCount<K, Tc, Tr, Targs...>& cpy);
	MaximumBucketCount<K, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<K, Tc, Tr, Targs...>::MaximumBucketCount()
{
	if (simple::_helper::maximum_bucket_count::
        _Validation<Tc, Tr, Targs...>::_HasFunction)
	{
		Set(&simple::_helper::maximum_bucket_count::
            _Call::DefaultHandle<Tc, Tr, Targs...>);
	}
}

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<K, Tc, Tr, Targs...>::MaximumBucketCount(HandleType handle) :
	simple::Handle<MaximumBucketCountKey, Tr, Tc&, Targs...>(handle)
{}  

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<K, Tc, Tr, Targs...>::
	MaximumBucketCount(const MaximumBucketCount<K, Tc, Tr, Targs...>& cpy) :
		simple::Handle<MaximumBucketCountKey, Tr, Tc&, Targs...>(cpy)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<K, Tc, Tr, Targs...>::
	MaximumBucketCount(MaximumBucketCount<K, Tc, Tr, Targs...>&& mov) :
		simple::Handle<MaximumBucketCountKey, Tr, Tc&, Targs...>(mov)
{}

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<K, Tc, Tr, Targs...>& MaximumBucketCount<K, Tc, Tr, Targs...>::
	operator=(const MaximumBucketCount<K, Tc, Tr, Targs...>& cpy)
{
	simple::Handle<MaximumBucketCountKey, Tr, Tc&, Targs...>::operator=(cpy);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<K, Tc, Tr, Targs...>& MaximumBucketCount<K, Tc, Tr, Targs...>::
	operator=(HandleType handle)
{
	simple::Handle<MaximumBucketCountKey, Tr, Tc&, Targs...>::operator=(handle);
	return *this;
}

template<typename K, typename Tc, typename Tr, typename... Targs>
Tr MaximumBucketCount<K, Tc, Tr, Targs...>::operator()(Tc& cont, Targs... val_args)
{
    return simple::Handle<MaximumBucketCountKey, Tr, Tc&, Targs...>
		::operator()(cont, val_args...);
}

template<typename K, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<K, Tc, Tr, Targs...>::operator bool() const
{
	return simple::Handle<MaximumBucketCountKey, Tr, Tc&, Targs...>::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_MAXIMUM_BUCKET_COUNT_H_
