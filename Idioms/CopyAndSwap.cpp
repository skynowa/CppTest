/**
 * \file  CopyAndSwap.cpp
 * \brief To create an exception safe implementation of overloaded assignment operator
 *
 * \review
 *
 * There are at least 3 types of exception safety levels: basic, strong, and no-throw.
 * The copy-and-swap idiom allows an assignment operator to be implemented elegantly with strong
 * exception safety
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Werror=deprecated-copy"

class String
{
public:
	explicit String(const char *a_buff) :
		_buff{a_buff}
	{
	}

///@name  ops =
///@brief Old resources released when destructor of temp is called
///@{
	// Variant #1
	String &
	operator = (const String &a_str)
    {
		// Copy-constructor - RAII
        String temp(a_str);
		// Non-throwing swap
		temp.swap(*this);

        return *this;
    }

	// Variant #2
	String &
	operatorEqV2 /* operator = */ (const String &a_str)
    {
        if (this != &a_str) {
			// Copy-constructor and non-throwing swap
            String(a_str).swap(*this);
        }

        return *this;
    }

	// Variant #3 - the pass-by-value parameter serves as a temporary
	String &
	operatorEqV3 /* operator = */ (String a_str)
	{
		// Non-throwing swap
		a_str.swap(*this);

		return *this;
	}
///@}

    void swap(String &a_str) throw()
    {
		// Also see the non-throwing swap idiom
        std::swap(this->_buff, a_str._buff);
    }

	const char *buff() const
	{
		return _buff;
	}

private:
    const char *_buff {};
};

#pragma GCC diagnostic pop
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	String strA("aaa");
	String strB("bbb");

	strB = strA;

    std::cout << TRACE_VAR(strA.buff()) << std::endl;
    std::cout << TRACE_VAR(strB.buff()) << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

strA.buff(): aaa
strB.buff(): aaa

#endif
