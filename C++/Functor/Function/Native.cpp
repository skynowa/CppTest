/**
 * \file  Native.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
template <typename T>
class NaiveFunction;

template <typename ReturnValue, typename... Args>
class NaiveFunction<ReturnValue(Args...)>
{
public:
	template <typename T>
	NaiveFunction& operator=(T t)
	{
		callable_ = std::make_unique<CallableT<T>>(t);
		return *this;
	}

	ReturnValue operator()(Args... args) const
	{
		assert(callable_);
		return callable_->Invoke(args...);
	}

private:
	class ICallable
	{
	public:
		virtual ~ICallable() = default;
		virtual ReturnValue Invoke(Args...) = 0;
	};

	template <typename T>
	class CallableT :
		public ICallable
	{
	public:
		CallableT(const T& t) :
			_t(t)
		{
		}

		~CallableT() override = default;

		ReturnValue Invoke(Args... args) override
		{
			return _t(args...);
		}

	private:
		T _t {};
	};

	std::unique_ptr<ICallable> callable_ {};
};
//-------------------------------------------------------------------------------------------------
void func()
{
	std::cout << "func" << std::endl;
}
//-------------------------------------------------------------------------------------------------
struct Functor
{
	void operator()() const
	{
		std::cout << "Functor" << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		NaiveFunction<void()> f;
		f = func;

		f();
	}

	{
		NaiveFunction<void()> f;
		f = Functor();

		f();
	}

	{
		NaiveFunction<void()> f;
		f = []() -> void
		{
			std::cout << "lambda" << std::endl;
		};

		f();
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

func
Functor
lambda

#endif
