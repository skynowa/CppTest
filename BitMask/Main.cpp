 /*
 * \file  main.cpp
 * \brief bit mask
 */

 /*
    logical OR: a || b
    logical NOT: !a
    logical AND: a && b
    bitwise OR: a | v
    bitwise NOT: ~a
    bitwise AND:  a & b
    bitwise shift left: a << b
    bitwise shift right:  a >> b
 */

//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
enum EValues {
    VALUE_0 = 0,
    VALUE_1 = 1 << 0,
    VALUE_2 = 1 << 1,
    VALUE_3 = 1 << 2,
    VALUE_4 = 1 << 3,
    VALUE_5 = 1 << 4,
    VALUE_6 = 1 << 5
};
//---------------------------------------------------------------------------
int main()
{


    std::cout << "EValues::VALUE_0: " << EValues::VALUE_0 << std::endl;
    std::cout << "EValues::VALUE_1: " << EValues::VALUE_1 << std::endl;
    std::cout << "EValues::VALUE_2: " << EValues::VALUE_2 << std::endl;
    std::cout << "EValues::VALUE_3: " << EValues::VALUE_3 << std::endl;
    std::cout << "EValues::VALUE_4: " << EValues::VALUE_4 << std::endl;
    std::cout << "EValues::VALUE_5: " << EValues::VALUE_5 << std::endl;
    std::cout << "EValues::VALUE_6: " << EValues::VALUE_6 << std::endl;

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

EValues::VALUE_0: 0
EValues::VALUE_1: 1
EValues::VALUE_2: 2
EValues::VALUE_3: 4
EValues::VALUE_4: 8
EValues::VALUE_5: 16
EValues::VALUE_6: 32

#endif