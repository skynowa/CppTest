 /*
 * \file  VariableArguments.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
/**
 * printVars
 *
 * takes a format string of the form "ifcs", where each character specifies the type of the
 * argument in that position.
 *
 * i = int
 * f = float
 * c = char
 * s = string (char *)
 *
 * Following the format specification is a variable list of arguments. Each argument corresponds to
 * a format character in the format string to which the format parameter points
 */
void
printVars(const char *format, ...)
{
    union Printer
    {
        int   i;
        float f;
        char  c;
        char *s;
    };

    va_list vl;

    // format is the last argument specified; you must access
    // all others using the variable-argument macros.
    va_start(vl, format);

    // Step through the list.
    for (std::size_t i = 0; format[i] != '\0'; ++ i) {
        Printer printer;

        switch (format[i]) {
        case 'i':
            printer.i = va_arg(vl, int);
            printf("%i\n", printer.i);
            break;
        case 'f':
            printer.f = va_arg(vl, double);
            printf("%f\n", printer.f);
            break;
        case 'c':
            // note automatic conversion to integral type
            printer.c = va_arg(vl, int);
            printf("%c\n", printer.c);
            break;
        case 's':
            printer.s = va_arg(vl, char *);
            printf("%s\n", printer.s);
            break;
        default:
            break;
        }
    }

    va_end(vl);
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    ::printVars("fcsi", 32.4f, 'a', "Test string", 4);

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

32.400002
a
Test string
4

#endif
