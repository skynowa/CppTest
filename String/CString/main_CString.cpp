 /*
 * \file  main.cpp
 * \brief
 */


//----------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
#include "CString.h"
//----------------------------------------------------------------------------
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
            assert(!s.isEmpty());
        }

        {
            CString s;
            assert(s.isEmpty());
        }
    }

    // data()
    {
        CString s("data()");
        assert(s == "data()");
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
        assert(p == s);
    }

    // operator const char * ()
    {
        CString s("operator char * ()");

        const char *p = s;
        assert(p == s);
    }

    // operator + (const CString &a_str)
    {
        CString rv;
        CString s1("s1");
        CString s2("s2");

        rv = s1 + s2;
        assert(rv == "s1s2");
    }

    // operator = (const CString &a_str)
    {
        const char *str = "operator =";

        CString s;

        s = str;
        assert(s == str);
    }

    // operator == (const CString &a_str)
    {
        CString s1("s1");
        CString s2("s1");

        assert(s1 == s2);
    }

    // operator != (const CString &a_str)
    {
        CString s1("s1");
        CString s2("s2");

        assert(s1 != s2);
    }

    // operator () ()
    {
        CString s;

        s();
    }

    // operator [] (size_t i)
    {
        CString s("abc");
        assert(s[size_t(0)] == 'a');
        assert(s[size_t(1)] == 'b');
        assert(s[size_t(2)] == 'c');
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------
