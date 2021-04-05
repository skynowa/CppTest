/**
 * \file
 * \brief
 *
 * \todo
 */


//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <assert.h>
//---------------------------------------------------------------------------
template <typename T>
class A {
    public:
        explicit A (const T &t) {
            _m_t = t;
        }

        void     vPrint() {
            std::cout << "_m_t: " << _m_t << std::endl;
        }

    private:
        T _m_t;
};

template <typename T, int iValue>
class B {
    public:
        explicit B (const T &t) {
            _m_t = t;
            _m_iValue = iValue;
        }

        void     vPrint() {
            std::cout << "_m_t: "      << _m_t
                      << "_m_iValue: " << _m_iValue
                      << std::endl;
        }

    private:
        T   _m_t;
        int _m_iValue;
};

#if xNOT_COMPILE

// error C2993: 'double' : illegal type for non-type template parameter 'dValue'

template <typename T, double dValue>
class C {
    public:
        explicit C     (const T &t) {
            // std::cout << __FUNCTION__ << std::endl;

            _m_t = t;
            _m_dValue = dValue;
        }

        void     vPrint() {
            std::cout << "_m_t: "    << _m_t
                      << "_m_dValue" << _m_dValue
                      << std::endl;
        }

    private:
        T      _m_t;
        double _m_dValue;
};

#endif
//---------------------------------------------------------------------------
int main(int, char **)
{
    // template <typename T> class A
    {
        A<int>          ( 1 ).vPrint();
        A<unsigned int> ( 2U ).vPrint();
        A<unsigned long>( 3UL ).vPrint();
        A<double>       ( 4.0 ).vPrint();
        A<const char *> ( "5" ).vPrint();
        A<std::string>  ( std::string("6") ).vPrint();
        A<bool>         ( true ).vPrint();
    }

    // template <typename T, int iValue> class B
    {
        B<int, 1>          ( 1 ).vPrint();
        B<unsigned int, 2> ( 2U ).vPrint();
        B<unsigned long, 3>( 3UL ).vPrint();
        B<double, 4>       ( 4.0 ).vPrint();
        B<const char *, 5> ( "5" ).vPrint();
        B<std::string, 6>  ( std::string("6") ).vPrint();
        B<bool, 7>         ( true ).vPrint();
    }

    // template <typename T, double dValue> class C
    {
    #if xNOT_COMPILE
        C<int, 1.0>          ( 1 ).vPrint();
        C<unsigned int, 2.0> ( 2U ).vPrint();
        C<unsigned long, 3.0>( 3UL ).vPrint();
        C<double, 4.0>       ( 4.0 ).vPrint();
        C<const char *, 5.0> ( "5" ).vPrint();
        C<std::string, 6.0>  ( std::string("6") ).vPrint();
        C<bool, 7.0>         ( true ).vPrint();
    #endif
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

// class A
_m_t: 1
_m_t: 2
_m_t: 3
_m_t: 4
_m_t: 5
_m_t: 6
_m_t: 1

// class B
_m_t: 1_m_iValue: 1
_m_t: 2_m_iValue: 2
_m_t: 3_m_iValue: 3
_m_t: 4_m_iValue: 4
_m_t: 5_m_iValue: 5
_m_t: 6_m_iValue: 6
_m_t: 1_m_iValue: 7

// class C
// not compile :
// error C2993: 'double' : illegal type for non-type template parameter 'dValue'

#endif