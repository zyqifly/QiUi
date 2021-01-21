#ifndef QI_BINDER_H
#define	QI_BINDER_H
#if _MSC_VER
#define PlaceHolder std::_Ph
#else
#define PlaceHolder std::_Placeholder
#endif

template<int N, int...I>
struct MakeSeqs : MakeSeqs<N - 1, N - 1, I...> {};

template<int...I>
struct MakeSeqs<1, I...>
{
	template<typename T, typename R, typename...Args>
	static auto bind(T* obj, R(T::* _Func)(Args...)) -> decltype(std::bind(_Func, obj, PlaceHolder<I>{}...))
	{
		return std::bind(_Func, obj, PlaceHolder<I>{}...);
	}
};

template <typename T, typename R, typename...Args>
auto Bind(T* t, R(T::* f)(Args...)) -> decltype(MakeSeqs<sizeof...(Args) + 1>::bind(t, f))
{
	return MakeSeqs<sizeof...(Args) + 1>::bind(t, f);
}

template <typename T, typename R, typename...Args>
auto Bind(R(T::* f)(Args...), T* t) -> decltype(MakeSeqs<sizeof...(Args) + 1>::bind(t, f))
{
	return MakeSeqs<sizeof...(Args) + 1>::bind(t, f);
}
#endif // !QI_BINDER_H

// C++14
//#if _MSC_VER
//#define PlaceHolder std::_Ph
//#else
//#define PlaceHolder std::_Placeholder
//#endif
//
//template<int N, int...I>
//struct MakeSeqs : MakeSeqs<N - 1, N - 1, I...> {};
//
//template<int...I>
//struct MakeSeqs<1, I...>
//{
//	template<class T, class _Fx>
//	static auto bind(T&& obj, _Fx&& _Func)
//	{
//		return std::bind(std::forward<_Fx>(_Func), std::forward<T>(obj), PlaceHolder<I>{}...);
//	}
//};
//
//template <class T, class R, typename...Args>
//auto Bind(T* t, R(T::* f)(Args...))
//{
//	return MakeSeqs<sizeof...(Args) + 1>::bind(t, f);
//}
//
//template <class T, class R, typename...Args>
//auto Bind(R(T::* f)(Args...), T* t)
//{
//	return MakeSeqs<sizeof...(Args) + 1>::bind(t, f);
//}