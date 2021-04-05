/**
 * \file  main.cpp
 * \brief
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

using namespace std;
//-------------------------------------------------------------------------------------------------
template <typename T>
class naive_function;

template <typename ReturnValue, typename... Args>
class naive_function<ReturnValue(Args...)>
{
public:
	template <typename T>
	naive_function& operator=(T t)
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
		CallableT(const T& t)
			: t_(t)
		{
		}

		~CallableT() override = default;

		ReturnValue Invoke(Args... args) override
		{
			return t_(args...);
		}

	private:
		T t_;
	};

	std::unique_ptr<ICallable> callable_;
};
//-------------------------------------------------------------------------------------------------
void func()
{
	cout << "func" << endl;
}
//-------------------------------------------------------------------------------------------------
struct functor
{
	void operator()()
	{
		cout << "functor" << endl;
	}
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	naive_function<void()> f;
	f = func;
	f();

	f = functor();
	f();

	f = []() { cout << "lambda" << endl; };
	f();

    // std::cout << TRACE_VAR("") << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

func
functor
lambda

#endif
