#ifndef ITERATOR_OUTPUT_H_
#define ITERATOR_OUTPUT_H_

#include <iterator>
#include <functional>

#include "../id_const/Validation.h"

#include "../Handle.h"

#include "../Iterator.h"

namespace simple
{
namespace iter
{

struct OutputIDConst : virtual simple::IteratorIDConst {};

struct LValueHandleIDConst : simple::iter::OutputIDConst {};

template<typename Tidc, typename T, typename D = std::ptrdiff_t, 
    typename P = T*, typename R = T&, typename C = std::output_iterator_tag,
    typename IT = std::iterator<C, T, D, P, R>>
class Output : public simple::Handle<simple::iter::RValueHandleIDConst, R, P>,
    public virtual simple::Iterator<Tidc, C, T, D, P, R, IT>
{
public:
    typedef typename simple::id_const::
        Validation<Tidc>::Type IDConstType; 
    typedef C CategoryType;
    typedef T ValueType;
    typedef D DistanceType;
    typedef P PointerType;
    typedef R ReferenceType;
    typedef typename simple::Handle<simple::iter::
        LValueHandleIDConst, R, P>::FunctionType LValueHandleType;
private:
    typedef simple::Handle<simple::iter::
        LValueHandleIDConst, R, P> BaseLValueHandleType;
    typedef simple::Iterator<Tidc, C, T, D, P, R, IT> BaseIteratorType;
private:
    static R LValueDefaultHandle(P ptr);
public:
    Output(P ptr);
    Output(const Output<Tidc, T, D, P, R, C, IT>& cpy);
    Output(Output<Tidc, T, D, P, R, C, IT>&& mov);
public:
    void Set(LValueHandleType) = delete;
    void SetLValueHandle(LValueHandleType lvalue_handle);
    void SetLValueHandle(const Output<Tidc, T, D, P, R, C, IT>& cpy);
public:
    Output<Tidc, T, D, P, R, C, IT>& 
        operator=(const Output<Tidc, T, D, P, R, C, IT>& cpy);
    Output<Tidc, T, D, P, R, C, IT>& operator=(P ptr);
    R operator*();
    R operator->();
};

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R Output<Tidc, T, D, P, R, C, IT>::LValueDefaultHandle(P ptr)
{
    return *ptr;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Output<Tidc, T, D, P, R, C, IT>::Output(P ptr) :
    BaseIteratorType(ptr),
    BaseLValueHandleType(LValueDefaultHandle)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Output<Tidc, T, D, P, R, C, IT>::Output(const Output<Tidc, T, D, P, R, C, IT>& cpy) :
    BaseIteratorType(cpy),
    BaseLValueHandleType(cpy)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Output<Tidc, T, D, P, R, C, IT>::Output(Output<Tidc, T, D, P, R, C, IT>&& mov) :
    BaseIteratorType(mov),
    BaseLValueHandleType(mov)
{}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Output<Tidc, T, D, P, R, C, IT>::
    SetLValueHandle(LValueHandleType lvalue_handle)
{
    BaseLValueHandleType::operator=(lvalue_handle);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
void Output<Tidc, T, D, P, R, C, IT>::
    SetLValueHandle(const Output<Tidc, T, D, P, R, C, IT>& cpy)
{
    BaseLValueHandleType::operator=(cpy);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
Output<Tidc, T, D, P, R, C, IT>& Output<Tidc, T, D, P, R, C, IT>::
    operator=(const Output<Tidc, T, D, P, R, C, IT>& cpy)
{
    BaseIteratorType::operator=(cpy);
    SetLValueHandle(cpy);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
typename R, typename C, typename IT>
Output<Tidc, T, D, P, R, C, IT>& Output<Tidc, T, D, P, R, C, IT>::operator=(P ptr)
{
    BaseIteratorType::operator=(ptr);
    return *this;
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R Output<Tidc, T, D, P, R, C, IT>::operator*()
{
    if (static_cast<BaseLValueHandleType&>(*this))
        return BaseLValueHandleType::operator()(m_ptr);
    return LValueDefaultHandle(m_ptr);
}

template<typename Tidc, typename T, typename D, typename P,
    typename R, typename C, typename IT>
R Output<Tidc, T, D, P, R, C, IT>::operator->()
{
    return *(*this);
}

}

}

#endif //!ITERATOR_OUTPUT_H_
