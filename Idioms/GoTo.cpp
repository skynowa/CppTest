/**
 * \file  GoTo.cpp
 * \brief Go to idiom
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class Widget
{
public:
	Widget() = default;
	~Widget() = default;

	bool show()
	{
		return false;
	}

	bool isValid() const
	{
		return true;
	}

	void cleanup()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
};
//-------------------------------------------------------------------------------------------------
std::string
runWidget()
{
    std::string error;

    Widget a;
    if ( !a.show() ) {
		error = "a-error";
		goto lbl_exit;
    }

    Widget b;
    if ( !b.show() ) {
		error = "b-error";
		goto lbl_exit;
    }

    // ...

lbl_exit:
	if ( a.isValid() ) {
		a.cleanup();
	}

	if ( b.isValid() ) {
		b.cleanup();
	}

	return error;
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	::runWidget();

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

cleanup
cleanup

#endif
