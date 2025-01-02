/**
 * \file  main_CString.cpp
 * \brief
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#include "CString.h"
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    /*******************************************************************************
    *    public, constructors
    *
    *******************************************************************************/

    // CString()
    {
        {
            CString s;
            s.print();
        }

        {
            // CString s();

            // warning C4930: 'CString s(void)':
            // prototyped function not called (was a variable definition intended?)	28
        }

        {
            CString *s = new CString();
            s->print();
            delete s;
        }
    }

    // CString(const char *str)
    {
        const char *str = "default constructor";

        CString s(str);
        s.print();
    }

    // CString(const CString &a_str)
    {
        {
            const char *str = "copy constructor 1";

            CString s_copy(str);
            CString s(s_copy);
            s.print();
        }

        {
            const char *str = "copy constructor 2";

            CString s = str;
            s.print();
        }
    }


    /*******************************************************************************
    *    public, methods
    *
    *******************************************************************************/

    // isEmpty()
    {
        {
            CString s("isEmpty()");
            STD_TEST(!s.isEmpty());
        }

        {
            CString s;
            STD_TEST(s.isEmpty());
        }
    }

    // data()
    {
        CString s("data()");
        STD_TEST(s == "data()");
    }

    // print()
    {
        CString("print").print();
    }


    /*******************************************************************************
    *    public, operators
    *
    *******************************************************************************/

    // operator char * ()
    {
        CString s("operator char * ()");

        char *p = s;
        STD_TEST(p == (char *)s);
    }

    // operator const char * ()
    {
        CString s("operator char * ()");

        const char *p = s;
        STD_TEST(p == s);
    }

    // operator + (const CString &a_str)
    {
        CString rv;
        CString s1("s1");
        CString s2("s2");

        rv = s1 + s2;
        STD_TEST(rv == "s1s2");
    }

    // operator = (const CString &a_str)
    {
        const char *str = "operator =";

        CString s;

        s = str;
        STD_TEST(s == str);
    }

    // operator == (const CString &a_str)
    {
        CString s1("s1");
        CString s2("s1");

        STD_TEST(s1 == s2);
    }

    // operator != (const CString &a_str)
    {
        CString s1("s1");
        CString s2("s2");

        STD_TEST(s1 != s2);
    }

    // operator () ()
    {
        CString s;

        s();
    }

    // operator [] (size_t i)
    {
        CString s("abc");
        STD_TEST(s[size_t(0)] == 'a');
        STD_TEST(s[size_t(1)] == 'b');
        STD_TEST(s[size_t(2)] == 'c');
    }

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

<empty>
<empty>
default constructor
copy constructor 1
copy constructor 2
print
operator ()

#endif
