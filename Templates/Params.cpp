/**
 * \file  Params.cpp
 * \brief Template params
 *
 * \review
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
template <typename T>
class A
{
public:
    explicit A(const T &t)
    {
        _t = t;
    }

    void print()
    {
        std::cout << "_t: " << _t << std::endl;
    }

private:
    T _t {};
};
//-------------------------------------------------------------------------------------------------
template <typename T, int iValue>
class B
{
public:
    explicit B(const T &t)
    {
        _t      = t;
        _iValue = iValue;
    }

    void print()
    {
        std::cout
            << "_t: "      << _t
            << "_iValue: " << _iValue
            << std::endl;
    }

private:
    T   _t {};
    int _iValue {};
};
//-------------------------------------------------------------------------------------------------
#if 0

// error C2993: 'double' : illegal type for non-type template parameter 'dValue'

template <typename T, double dValue>
class C
{
public:
    explicit C(const T &t)
    {
        // std::cout << __FUNCTION__ << std::endl;

        _t      = t;
        _dValue = dValue;
    }

    void print()
    {
        std::cout
            << "_t: "    << _t
            << "_dValue" << _dValue
            << std::endl;
    }

private:
    T      _t {};
    double _dValue {};
};

#endif
//---------------------------------------------------------------------------
int main(int, char **)
{
    // template <typename T> class A
    {
        A<int>          ( 1 ).print();
        A<unsigned int> ( 2U ).print();
        A<unsigned long>( 3UL ).print();
        A<double>       ( 4.0 ).print();
        A<const char *> ( "5" ).print();
        A<std::string>  ( std::string("6") ).print();
        A<bool>         ( true ).print();
    }

    // template <typename T, int iValue> class B
    {
        B<int, 1>          ( 1 ).print();
        B<unsigned int, 2> ( 2U ).print();
        B<unsigned long, 3>( 3UL ).print();
        B<double, 4>       ( 4.0 ).print();
        B<const char *, 5> ( "5" ).print();
        B<std::string, 6>  ( std::string("6") ).print();
        B<bool, 7>         ( true ).print();
    }

    // template <typename T, double dValue> class C
    {
    #if 0
        C<int, 1.0>          ( 1 ).print();
        C<unsigned int, 2.0> ( 2U ).print();
        C<unsigned long, 3.0>( 3UL ).print();
        C<double, 4.0>       ( 4.0 ).print();
        C<const char *, 5.0> ( "5" ).print();
        C<std::string, 6.0>  ( std::string("6") ).print();
        C<bool, 7.0>         ( true ).print();
    #endif
    }

    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------


#if OUTPUT

// class A
_t: 1
_t: 2
_t: 3
_t: 4
_t: 5
_t: 6
_t: 1

// class B
_t: 1_iValue: 1
_t: 2_iValue: 2
_t: 3_iValue: 3
_t: 4_iValue: 4
_t: 5_iValue: 5
_t: 6_iValue: 6
_t: 1_iValue: 7

// class C
// not compile :
// error C2993: 'double' : illegal type for non-type template parameter 'dValue'

#endif