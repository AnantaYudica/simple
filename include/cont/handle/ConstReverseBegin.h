#ifndef CONTAINER_HANDLE_CONST_REVERSE_BEGIN_H_
#define CONTAINER_HANDLE_CONST_REVERSE_BEGIN_H_

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
	decltype(ConstReverseBegin(&c, std::declval<Targs>()...), 
		std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename Tc, typename Tr, typename... Targs>
using _SwitchDefaultHandle = simple::type::Switch<std::false_type,
	decltype(simple::_helper::_cont::_handle::_const_reverse_begin::
		_IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_const_reverse_begin::
		_IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_const_reverse_begin::
		_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_const_reverse_begin::
		_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_const_reverse_begin::
		_IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_const_reverse_begin::
		_IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))>;

template<typename Tc, typename Tr, typename... Targs>
using _HasDefaultHandle = std::integral_constant<bool,
	simple::_helper::_cont::_handle::_const_reverse_begin::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Index !=
	simple::_helper::_cont::_handle::_const_reverse_begin::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Size>;

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_const_reverse_begin::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 0, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.crbegin(args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_const_reverse_begin::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 1, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.ConstReverseBegin(args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_const_reverse_begin::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 2, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return crbegin(c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_const_reverse_begin::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 3, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return ConstReverseBegin(c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_const_reverse_begin::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 4, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return crbegin(&c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_const_reverse_begin::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 5, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return ConstReverseBegin(&c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<!simple::_helper::_cont::_handle::_const_reverse_begin::
	_HasDefaultHandle<Tc, Tr, Targs...>::value, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	assert(!"do not have handle crbegin or ConstReverseBegin function ");
}

}

}

}

}

namespace cont
{
namespace handle
{

struct ConstReverseBeginIDConst : simple::IdentifierConstant {};

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
class ConstReverseBegin : public simple::Handle<simple::cont::handle::
	ConstReverseBeginIDConst, Tr, Tc&, Targs...>
{
public:
	typedef typename simple::id_const::Validation<Tidc>::type IDConstType;
	typedef typename simple::Handle<simple::cont::handle::
		ConstReverseBeginIDConst, Tr, Tc&, Targs...>::FunctionType HandleType;
private:
	typedef simple::Handle<simple::cont::handle::
		ConstReverseBeginIDConst, Tr, Tc&, Targs...> BaseHandleType;
public:
	ConstReverseBegin();
	ConstReverseBegin(HandleType handle);
	ConstReverseBegin(const ConstReverseBegin<Tidc, Tc, Tr, Targs...>& cpy);
	ConstReverseBegin(ConstReverseBegin<Tidc, Tc, Tr, Targs...>&& mov);
public:
	ConstReverseBegin<Tidc, Tc, Tr, Targs...>& 
		operator=(const ConstReverseBegin<Tidc, Tc, Tr, Targs...>& cpy);
	ConstReverseBegin<Tidc, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<Tidc, Tc, Tr, Targs...>::ConstReverseBegin()
{
	if (simple::_helper::_cont::_handle::_const_reverse_begin::
		_HasDefaultHandle<Tc, Tr, Targs...>::value)
			Set(&simple::_helper::_cont::_handle::_const_reverse_begin::
				_DefaultHandle<Tc, Tr, Targs...>);
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<Tidc, Tc, Tr, Targs...>::
	ConstReverseBegin(HandleType handle) :
		BaseHandleType(handle)
{}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<Tidc, Tc, Tr, Targs...>::
	ConstReverseBegin(const ConstReverseBegin<Tidc, Tc, Tr, Targs...>& cpy) :
		BaseHandleType(cpy)
{}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<Tidc, Tc, Tr, Targs...>::
    ConstReverseBegin(ConstReverseBegin<Tidc, Tc, Tr, Targs...>&& mov) :
	    BaseHandleType(mov)
{}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<Tidc, Tc, Tr, Targs...>& 
    ConstReverseBegin<Tidc, Tc, Tr, Targs...>::
	    operator=(const ConstReverseBegin<Tidc, Tc, Tr, Targs...>& cpy)
{
	BaseHandleType::operator=(cpy);
	return *this;
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<Tidc, Tc, Tr, Targs...>& 
    ConstReverseBegin<Tidc, Tc, Tr, Targs...>::operator=(HandleType handle)
{
	BaseHandleType::operator=(handle);
	return *this;
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Tr ConstReverseBegin<Tidc, Tc, Tr, Targs...>::
    operator()(Tc& cont, Targs... val_args)
{
	return BaseHandleType::operator()(cont, val_args...);
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
ConstReverseBegin<Tidc, Tc, Tr, Targs...>::operator bool() const
{
	return BaseHandleType::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_CONST_REVERSE_BEGIN_H_
