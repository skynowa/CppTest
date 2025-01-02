/**
 * \file  Overloading.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class A
{
public:
    A() = default;
    ~A() = default;

    void setIDList(const std::list<std::string> &val)
    {
        std::cout << "Param std::list<std::string> - " << STD_TRACE_VAR(val) << std::endl;
    }

    void setIDList(const std::vector<std::string> &val)
    {
        std::cout << "Param std::list<std::string> - " << STD_TRACE_VAR(val) << std::endl;
    }

    void setIDList(const std::string &val)
    {
        std::cout << "Param std::string - " << STD_TRACE_VAR(val) << std::endl;
    }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    const std::string str = "test";

    A a;
    a.setIDList( {str} );

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

Param std::string - val: test

#endif
