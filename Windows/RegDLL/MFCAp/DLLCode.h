/**
 * \file  DLLCode.h
 * \brief
 */


//-------------------------------------------------------------------------------------------------
#ifdef DLLDIR_EX
   #define DLLDIR  __declspec(dllexport)
#else
   #define DLLDIR  __declspec(dllimport)
#endif
//-------------------------------------------------------------------------------------------------
// This prevent the C++ compiler from using decorated (modified) names for the functions
extern "C"
{
    // Function DLLfun1, defined in the W32DLL DLL, writes to a console, not a window,
    // so, it is not appropriate to call it from a MFC Client.
    int  DLLDIR DLLfun2(int);
    void DLLDIR DrawEllipse ( CRect, CDC* ); // a MFC function call

};

extern int  DLLDIR DLLArg;
//-------------------------------------------------------------------------------------------------
class DLLDIR Dllclass
{
public:
    int Arg;

    Dllclass();          // Class Constructor
    ~Dllclass();         // Class destructor

    int Add(int, int);   // Class function Add
    int Sub(int, int);   // Class function Subtract
};
//-------------------------------------------------------------------------------------------------
