#ifndef CONTAINER_HANDLE_MAXIMUM_BUCKET_COUNT_H_
#define CONTAINER_HANDLE_MAXIMUM_BUCKET_COUNT_H_

#include <type_traits>
#include <functional>
#include <cassert>

#include "../../IdentifierConstant.h"
#include "../../id_const/Validation.h"
#include "../../Handle.h"
#include "../../type/Switch.h"

namespace simple
{
namespace _helper
{
namespace _cont
{
namespace _handle
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
	decltype(MaximumBucketCount(c, std::declval<Targs>()...), 
		std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(max_bucket_count(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(MaximumBucketCount(&c, std::declval<Targs>()...), 
		std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename Tc, typename Tr, typename... Targs>
using _SwitchDefaultHandle = simple::type::Switch<std::false_type,
	decltype(simple::_helper::_cont::_handle::_maximum_bucket_count::
		_IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_maximum_bucket_count::
		_IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_maximum_bucket_count::
		_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_maximum_bucket_count::
		_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_maximum_bucket_count::
		_IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_maximum_bucket_count::
		_IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))>;

template<typename Tc, typename Tr, typename... Targs>
using _HasDefaultHandle = std::integral_constant<bool,
	simple::_helper::_cont::_handle::_maximum_bucket_count::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Index !=
	simple::_helper::_cont::_handle::_maximum_bucket_count::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Size>;

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<
	simple::_helper::_cont::_handle::_maximum_bucket_count::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 0, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.max_bucket_count(args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<
	simple::_helper::_cont::_handle::_maximum_bucket_count::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 1, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.MaximumBucketCount(args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<
	simple::_helper::_cont::_handle::_maximum_bucket_count::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 2, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return max_bucket_count(c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<
	simple::_helper::_cont::_handle::_maximum_bucket_count::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 3, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return MaximumBucketCount(c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<
	simple::_helper::_cont::_handle::_maximum_bucket_count::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 4, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return max_bucket_count(&c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<
	simple::_helper::_cont::_handle::_maximum_bucket_count::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 5, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return MaximumBucketCount(&c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<
	!simple::_helper::_cont::_handle::_maximum_bucket_count::
		_HasDefaultHandle<Tc, Tr, Targs...>::value, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	assert(!"do not have handle max_bucket_count or "
		"MaximumBucketCount function ");
}

}

}

}

}

namespace cont
{
namespace handle
{

struct MaximumBucketCountIDConst : simple::IdentifierConstant {};

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
class MaximumBucketCount : public simple::Handle<simple::cont::handle::
	MaximumBucketCountIDConst, Tr, Tc&, Targs...>
{
public:
	typedef typename simple::id_const::Validation<Tidc>::Type IDConstType;
	typedef typename simple::Handle<simple::cont::handle::
		MaximumBucketCountIDConst, Tr, Tc&, Targs...>::FunctionType HandleType;
private:
	typedef simple::Handle<simple::cont::handle::
		MaximumBucketCountIDConst, Tr, Tc&, Targs...> BaseHandleType;
public:
	MaximumBucketCount();
	MaximumBucketCount(HandleType handle);
	MaximumBucketCount(const MaximumBucketCount<Tidc, Tc, Tr, Targs...>& cpy);
	MaximumBucketCount(MaximumBucketCount<Tidc, Tc, Tr, Targs...>&& mov);
public:
	MaximumBucketCount<Tidc, Tc, Tr, Targs...>& 
		operator=(const MaximumBucketCount<Tidc, Tc, Tr, Targs...>& cpy);
	MaximumBucketCount<Tidc, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<Tidc, Tc, Tr, Targs...>::MaximumBucketCount()
{
	if (simple::_helper::_cont::_handle::maximum_bucket_count::
        _HasDefaultHandle<Tc, Tr, Targs...>::value)
			Set(&simple::_helper::_cont::_handle::maximum_bucket_count::
            	_DefaultHandle<Tc, Tr, Targs...>);
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<Tidc, Tc, Tr, Targs...>::
	MaximumBucketCount(HandleType handle) :
		BaseHandleType(handle)
{}  

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<Tidc, Tc, Tr, Targs...>::
	MaximumBucketCount(const MaximumBucketCount<Tidc, Tc, Tr, Targs...>& cpy) :
		BaseHandleType(cpy)
{}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<Tidc, Tc, Tr, Targs...>::
	MaximumBucketCount(MaximumBucketCount<Tidc, Tc, Tr, Targs...>&& mov) :
		BaseHandleType(mov)
{}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<Tidc, Tc, Tr, Targs...>& 
	MaximumBucketCount<Tidc, Tc, Tr, Targs...>::
		operator=(const MaximumBucketCount<Tidc, Tc, Tr, Targs...>& cpy)
{
	BaseHandleType::operator=(cpy);
	return *this;
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<Tidc, Tc, Tr, Targs...>& 
	MaximumBucketCount<Tidc, Tc, Tr, Targs...>::
		operator=(HandleType handle)
{
	BaseHandleType::operator=(handle);
	return *this;
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Tr MaximumBucketCount<Tidc, Tc, Tr, Targs...>::
	operator()(Tc& cont, Targs... val_args)
{
    return BaseHandleType::operator()(cont, val_args...);
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
MaximumBucketCount<Tidc, Tc, Tr, Targs...>::operator bool() const
{
	return BaseHandleType::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_MAXIMUM_BUCKET_COUNT_H_
