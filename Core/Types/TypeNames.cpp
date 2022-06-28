/**
 * \file  TypeNames.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

/**************************************************************************************************
* getTypeName_1
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename T>
const char *getTypeName_1();

#define MAKE_TEMPLATE_NAME(T) \
    template<> \
    const char *getTypeName_1<T>() { return #T; }
//-------------------------------------------------------------------------------------------------
struct Foo {};
class  Bar {};

MAKE_TEMPLATE_NAME(int)
MAKE_TEMPLATE_NAME(float)
MAKE_TEMPLATE_NAME(Foo)
MAKE_TEMPLATE_NAME(Bar)
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
* getTypeName_2
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename T>
std::string
getTypeName_2(T)
{
    std::string type = "unknown";

    if (std::is_same<T, int>::value) {
        type = "int";
    }

    if (std::is_same<T, std::string>::value) {
        type = "std::string";
    }

    if (std::is_same<T, std::map<int, std::string>>::value) {
        type = "std::map<int, std::string>";
    }

    return type;
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
* getTypeName_3
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename T> const char* getTypeName_3(T &)    { return "unknown"; }    // default
template<> const char* getTypeName_3(bool &)           { return "bool"; }
template<> const char* getTypeName_3(int &)            { return "int"; }
template<> const char* getTypeName_3(short &)          { return "short"; }
template<> const char* getTypeName_3(long &)           { return "long"; }
template<> const char* getTypeName_3(unsigned &)       { return "unsigned"; }
template<> const char* getTypeName_3(unsigned short &) { return "unsigned short"; }
template<> const char* getTypeName_3(unsigned long &)  { return "unsigned long"; }
template<> const char* getTypeName_3(float &)          { return "float"; }
template<> const char* getTypeName_3(double &)         { return "double"; }
template<> const char* getTypeName_3(long double &)    { return "long double"; }
template<> const char* getTypeName_3(std::string &)    { return "std::string"; }
template<> const char* getTypeName_3(char &)           { return "char"; }
template<> const char* getTypeName_3(signed char &)    { return "signed char"; }
template<> const char* getTypeName_3(unsigned char &)  { return "unsigned char"; }
template<> const char* getTypeName_3(char* &)          { return "char*"; }
template<> const char* getTypeName_3(signed char* &)   { return "signed char*"; }
template<> const char* getTypeName_3(unsigned char* &) { return "unsigned char*"; }

template<typename T1, typename T2>
const char *
getTypeName_3(std::map<T1, T2> &a_value)
{
    auto &it = *a_value.begin();

    std::cout << STD_TRACE_VAR( getTypeName_3(it.first) ) << std::endl;
    std::cout << STD_TRACE_VAR( getTypeName_3(it.second) ) << std::endl;

	static std::string s(std::string("map<") + getTypeName_3(it.first) + ", " + getTypeName_3(it.second) + ">");

	return s.c_str();
}
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    // getTypeName_1
    {
        std::cout << "\n::: getTypeName_1 :::" << std::endl;

        std::cout
            << STD_TRACE_VAR(::getTypeName_1<int>())   << "\n"
            << STD_TRACE_VAR(::getTypeName_1<float>()) << "\n"
            << STD_TRACE_VAR(::getTypeName_1<Foo>())   << "\n"
            << STD_TRACE_VAR(::getTypeName_1<Bar>())   << "\n" << std::endl;
    }

    // getTypeName_2
    {
        std::cout << "\n::: getTypeName_2 :::" << std::endl;

        std::map<int, std::string> m;
        std::cout << getTypeName_2(m) << "\n" << std::endl;
    }

    // getTypeName_3
    {
        std::cout << "\n::: getTypeName_3 :::" << std::endl;

        std::map<double, bool> m;
        m[7.7] = false;

        std::cout << getTypeName_3(m) << "\n" << std::endl;
    }

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

::: getTypeName_1 :::
::getTypeName_1<int>(): int
::getTypeName_1<float>(): float
::getTypeName_1<Foo>(): Foo
::getTypeName_1<Bar>(): Bar


::: getTypeName_2 :::
std::map<int, std::string>


::: getTypeName_3 :::
getTypeName_3(it.first): unknown
getTypeName_3(it.second): bool
map<unknown, bool>

#endif
