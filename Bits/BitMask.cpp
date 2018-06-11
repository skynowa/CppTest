 /*
 * \file  main.cpp
 * \brief bit mask
 */

 /*
    logical OR: a || b
    logical AND: a && b
    logical NOT: !a

    bitwise OR: a | v
    bitwise NOT: ~a
    bitwise AND:  a & b
    bitwise shift left: a << b
    bitwise shift right:  a >> b
 */

//---------------------------------------------------------------------------
#include <StdTest.h>
//---------------------------------------------------------------------------
int main(int, char **)
{
    enum Values
    {
        Value0 = 0,
        Value1 = 1 << 0,
        Value2 = 1 << 1,
        Value3 = 1 << 2,
        Value4 = 1 << 3,
        Value5 = 1 << 4,
        Value6 = 1 << 5,
        Value7 = 1 << 6,
        Value8 = 1 << 7,
        Value9 = 1 << 8
    };

    enum Errors
    {
        Error0 = 0x000000,
        Error1 = 0x000001,
        Error2 = 0x000002,
        Error3 = 0x000004,
        Error4 = 0x000008,
        Error5 = 0x000010,
        Error6 = 0x000020,
        Error7 = 0x000040,
        Error8 = 0x000080,
        Error9 = 0x000100,
    };

    std::cout << STD_TRACE_VAR2(Value0, Error0) << std::endl;
    std::cout << STD_TRACE_VAR2(Value1, Error1) << std::endl;
    std::cout << STD_TRACE_VAR2(Value2, Error2) << std::endl;
    std::cout << STD_TRACE_VAR2(Value3, Error3) << std::endl;
    std::cout << STD_TRACE_VAR2(Value4, Error4) << std::endl;
    std::cout << STD_TRACE_VAR2(Value5, Error5) << std::endl;
    std::cout << STD_TRACE_VAR2(Value6, Error6) << std::endl;
    std::cout << STD_TRACE_VAR2(Value7, Error7) << std::endl;
    std::cout << STD_TRACE_VAR2(Value8, Error8) << std::endl;
    std::cout << STD_TRACE_VAR2(Value9, Error9) << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

Value0: 0, Error0: 0
Value1: 1, Error1: 1
Value2: 2, Error2: 2
Value3: 4, Error3: 4
Value4: 8, Error4: 8
Value5: 16, Error5: 16
Value6: 32, Error6: 32
Value7: 64, Error7: 64
Value8: 128, Error8: 128
Value9: 256, Error9: 256

#endif
