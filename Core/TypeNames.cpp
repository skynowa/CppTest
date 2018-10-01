/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"
#include "../Stl.h"


/**************************************************************************************************
*
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename T>
const char *getTypeName();

#define MAKE_TEMPLATE_NAME(T) \
  template<> \
  const char *getTypeName<T>() { return #T; }
//-------------------------------------------------------------------------------------------------
struct Foo {};
class Bar {};

MAKE_TEMPLATE_NAME(int);
MAKE_TEMPLATE_NAME(float);
MAKE_TEMPLATE_NAME(Foo);
MAKE_TEMPLATE_NAME(Bar);
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<typename T>
std::string TypeOf(T)
{
    std::string Type="unknown";
    if(std::is_same<T,int>::value) Type="int";
    if(std::is_same<T,std::string>::value) Type="String";
    if(std::is_same<T,std::map_tstring_t>::value) Type="std::map_tstring_t";

    return Type;
}

template<typename T1, typename T2>
const char*
typeofStr(std::map<T1, T2>&)
{
	T1 t1;
	T2 t2;

	static std::string s(std::string("map<") + typeofStr(t1) + ", " + typeofStr(t2) + ">");

	return s.c_str();
}
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::cout << STD_TRACE_VAR(::getTypeName<int>()) << std::endl;
	std::cout << STD_TRACE_VAR(::getTypeName<float>()) << std::endl;
	std::cout << STD_TRACE_VAR(::getTypeName<Foo>()) << std::endl;
	std::cout << STD_TRACE_VAR(::getTypeName<Bar>()) << std::endl;

    // std::cout << STD_TRACE_VAR("") << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

::getTypeName<int>(): int
::getTypeName<float>(): float
::getTypeName<Foo>(): Foo
::getTypeName<Bar>(): Bar

#endif
