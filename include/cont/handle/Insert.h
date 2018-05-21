#ifndef CONTAINER_HANDLE_INSERT_H_
#define CONTAINER_HANDLE_INSERT_H_

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
namespace _insert
{
template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember0(Tc c) ->
	decltype(c.insert(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionMember1(Tc c) ->
	decltype(c.Insert(std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionMember1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference0(Tc c) ->
	decltype(insert(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionReference1(Tc c) ->
	decltype(Insert(c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionReference1(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer0(Tc c) ->
	decltype(insert(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer0(...);

template<typename Tc, typename... Targs>
static constexpr auto _IsHasFunctionPointer1(Tc c) ->
	decltype(Insert(&c, std::declval<Targs>()...), std::true_type());
template<typename Tc, typename... Targs>
static constexpr std::false_type _IsHasFunctionPointer1(...);

template<typename Tc, typename Tr, typename... Targs>
using _SwitchDefaultHandle = simple::type::Switch<std::false_type,
	decltype(simple::_helper::_cont::_handle::_insert::
		_IsHasFunctionMember0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_insert::
		_IsHasFunctionMember1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_insert::
		_IsHasFunctionReference0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_insert::
		_IsHasFunctionReference1<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_insert::
		_IsHasFunctionPointer0<Tc, Targs...>(std::declval<Tc>())),
	decltype(simple::_helper::_cont::_handle::_insert::
		_IsHasFunctionPointer1<Tc, Targs...>(std::declval<Tc>()))>;

template<typename Tc, typename Tr, typename... Targs>
using _HasDefaultHandle = std::integral_constant<bool,
	simple::_helper::_cont::_handle::_insert::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Index !=
	simple::_helper::_cont::_handle::_insert::
		_SwitchDefaultHandle<Tc, Tr, Targs...>::Size>;

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_insert::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 0, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.insert(args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_insert::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 1, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return c.Insert(args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_insert::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 2, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return insert(c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_insert::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 3, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return Insert(c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_insert::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 4, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return insert(&c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<simple::_helper::_cont::_handle::_insert::
	_SwitchDefaultHandle<Tc, Tr, Targs...>::Index == 5, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	return Insert(&c, args...);
}

template<typename Tc, typename Tr, typename... Targs>
typename std::enable_if<!simple::_helper::_cont::_handle::_insert::
	_HasDefaultHandle<Tc, Tr, Targs...>::value, Tr>::type
	_DefaultHandle(Tc& c, Targs... args)
{
	assert(!"do not have handle insert or Insert function ");
}

}

}

}

}

namespace cont
{
namespace handle
{

struct InsertIDConst : simple::IdentifierConstant {};

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
class Insert : public simple::Handle<simple::cont::handle::InsertIDConst,
	Tr, Tc&, Targs...>
{
public:
	typedef typename simple::id_const::Validation<Tidc>::Type IDConstType;
	typedef typename simple::Handle<simple::cont::handle::InsertIDConst,
		Tr, Tc&, Targs...>::FunctionType HandleType;
private:
	typedef simple::Handle<simple::cont::handle::InsertIDConst,
		Tr, Tc&, Targs...> BaseHandleType;
public:
	Insert();
	Insert(HandleType handle);
	Insert(const Insert<Tidc, Tc, Tr, Targs...>& cpy);
	Insert(Insert<Tidc, Tc, Tr, Targs...>&& mov);
public:
	Insert<Tidc, Tc, Tr, Targs...>& 
		operator=(const Insert<Tidc, Tc, Tr, Targs...>& cpy);
	Insert<Tidc, Tc, Tr, Targs...>&
		operator=(HandleType handle);
	Tr operator()(Tc& cont, Targs... val_args);
	operator bool() const;
};

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Insert<Tidc, Tc, Tr, Targs...>::Insert()
{
	if (simple::_helper::_cont::_handle::_insert::
		_HasDefaultHandle<Tc, Tr, Targs...>::value)
			Set(&simple::_helper::_cont::_handle::_insert::
				_DefaultHandle<Tc, Tr, Targs...>);
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Insert<Tidc, Tc, Tr, Targs...>::Insert(HandleType handle) :
	BaseHandleType(handle)
{}  

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Insert<Tidc, Tc, Tr, Targs...>::
	Insert(const Insert<Tidc, Tc, Tr, Targs...>& cpy) :
		BaseHandleType(cpy)
{}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Insert<Tidc, Tc, Tr, Targs...>::
	Insert(Insert<Tidc, Tc, Tr, Targs...>&& mov) :
		BaseHandleType(mov)
{}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Insert<Tidc, Tc, Tr, Targs...>& Insert<Tidc, Tc, Tr, Targs...>::
	operator=(const Insert<Tidc, Tc, Tr, Targs...>& cpy)
{
	BaseHandleType::operator=(cpy);
	return *this;
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Insert<Tidc, Tc, Tr, Targs...>& Insert<Tidc, Tc, Tr, Targs...>::
	operator=(HandleType handle)
{
	BaseHandleType::operator=(handle);
	return *this;
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Tr Insert<Tidc, Tc, Tr, Targs...>::operator()(Tc& cont, Targs... val_args)
{
    return BaseHandleType::operator()(cont, val_args...);
}

template<typename Tidc, typename Tc, typename Tr, typename... Targs>
Insert<Tidc, Tc, Tr, Targs...>::operator bool() const
{
	return BaseHandleType::operator bool();
}

}

}

}

#endif //!CONTAINER_HANDLE_INSERT_H_
