/**
 * \file  Cpp.cpp
 * \brief Test C++ syntax for IDEs
 *
 * \see   VSCode - https://code.visualstudio.com/docs/cpp/colorization-cpp
 *
 * \todo
 */


//--------------------------------------------------------------------------------------------------
// PP
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpessimizing-move"

// Impl - std::move

#pragma GCC diagnostic pop

#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#define PP_VAR      "pp_test"
#define PP_VAR_2(x) PP_VAR "_" x
//--------------------------------------------------------------------------------------------------
using namespace std::literals::string_view_literals; // Enables the sv suffix

namespace my
{
int varNamespace {5};
}

using namespace my;

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

    std::string_view get() const;
    bool             fooMethod(const bool isDebug) const;

    static int fooMethodStatic(bool &isDebug);

private:
    Type _type   {Type::No};
    int  _member {0};


    static int _memberStatic;
};
//--------------------------------------------------------------------------------------------------
int SyntaxCpp::_memberStatic {-1};
//--------------------------------------------------------------------------------------------------
std::string_view
SyntaxCpp::get() const
{
    return "[SyntaxCpp]"sv;
}
//--------------------------------------------------------------------------------------------------
bool
SyntaxCpp::fooMethod(
    const bool a_isDebug ///< [in]
) const
{
    return a_isDebug ? false : true;
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
inline std::ostream &
operator << (
    std::ostream    &out_os,
    const SyntaxCpp &a_value
)
{
	out_os << a_value.get();
	return out_os;
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

    std::cout << STD_TRACE_VAR(my::varNamespace) << std::endl;
	std::cout << STD_TRACE_VAR(::globalVar) << std::endl;

    SyntaxCpp syntax;
    syntax.fooMethod(::globalVar);
    syntax.fooMethodStatic(::globalVar);

    std::cout << syntax << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
