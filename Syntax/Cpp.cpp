/**
 * \file  Cpp.cpp
 * \brief Test C++ syntax for IDEs
 *
 * \see   VSCode - https://code.visualstudio.com/docs/cpp/colorization-cpp
 *
 * \todo
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
// PP
#define PP_VAR      "pp_test"
#define PP_VAR_2(x) PP_VAR "_" x
//--------------------------------------------------------------------------------------------------
bool globalVar {false};
//--------------------------------------------------------------------------------------------------
class SyntaxCpp
{
public:
    enum class Type
    {
        No  = 0,
        Yes = 1
    };

    SyntaxCpp() = default;
    ~SyntaxCpp() = default;

    void fooMethod(const bool isDebug) const;

    static int fooMethodStatic(bool &isDebug);

private:
    Type _type   {Type::No};
    int  _member {0};

    static int _memberStatic;
};
//--------------------------------------------------------------------------------------------------
int SyntaxCpp::_memberStatic {-1};
//--------------------------------------------------------------------------------------------------
void
SyntaxCpp::fooMethod(
    const bool a_isDebug ///< [in]
) const
{
    if (a_isDebug) {
        return;
    }

    /// TODO: impl
}
//--------------------------------------------------------------------------------------------------
/* static */
int
SyntaxCpp::fooMethodStatic(
    bool &out_isDebug   ///< [out]
)
{
    // [out]
    out_isDebug = false;

    return out_isDebug ? 0 : _memberStatic;
}
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	// PP
	{
		STD_TRACE_FUNC;

		std::cout << STD_TRACE_VAR(PP_VAR) << std::endl;

		std::string str = PP_VAR_2("2");
		std::cout << STD_TRACE_VAR(str) << std::endl;
	}

	std::cout << STD_TRACE_VAR(::globalVar) << std::endl;

    SyntaxCpp syntax;
    syntax.fooMethod(::globalVar);
    syntax.fooMethodStatic(::globalVar);

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
