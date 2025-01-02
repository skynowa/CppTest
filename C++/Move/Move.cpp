/**
 * \file  Move.cpp
 * \brief
 *
 * [review]
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#define RULE_5_OPTION_LOG 1
#include <Idioms/RuleOf/Rule3Move.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    {
        std::vector<Rule3Move> files;

        {
            std::cout << "::::: files.push_back('data1.txt') :::::" << std::endl;
            files.push_back( Rule3Move("data1.txt") );

            std::cout << "::::: files.push_back('data2.txt') :::::" << std::endl;
            files.push_back( Rule3Move("data2.txt") );
        }

        {
            std::cout << "::::: files.erase() :::::" << std::endl;

            files.erase( files.cbegin() );
        }

        {
            std::cout << "::::: files - dtor :::::" << std::endl;
        }
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

[Ctor] const char *
[Ctor] Move
[Dtor]

::::: files.push_back('data2.txt') :::::
[Ctor] const char *
[Ctor] Move
[Ctor] Move
[Dtor]

[Dtor]

::::: files.erase() :::::
[Op] Move
[Dtor]

::::: files - dtor :::::
[Dtor]

#endif
