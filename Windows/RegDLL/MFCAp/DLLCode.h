/**
 * \file
 * \brief
 *
 * \todo
 */


/*****************************************************************************************
   File name: DLLCode.h

   This file contains MFC objects, hints, it needs a MFC Client.

   Notice: we use the same header file for compiling the .dll and the .exe (application).
   This header file defines a macro which export the target DLL objects if we are building
   a DLL, otherwise it import the DLL objects into an application which uses the DLL. If
   we define DLLDIR_EX (a preprocessor identifier), then the preprocessor define macro
   DLLDIR (a mnemonic for DLL, import/export, Direction) becomes an export instruction,
   otherwise its an import instruction by default.
*****************************************************************************************/

#ifdef DLLDIR_EX
   #define DLLDIR  __declspec(dllexport)
#else
   #define DLLDIR  __declspec(dllimport)
#endif

// This prevent the C++ compiler from using decorated (modified) names for the functions
extern "C" {
       // Function DLLfun1, defined in the W32DLL DLL, writes to a console, not a window,
	   // so, it is not appropriate to call it from a MFC Client.
       int  DLLDIR DLLfun2(int);
       void DLLDIR DrawEllipse ( CRect, CDC* ); // a MFC function call

};

extern int  DLLDIR DLLArg;

class DLLDIR Dllclass
{
   public:
      Dllclass();          // Class Constructor
      ~Dllclass();         // Class destructor
      int Add(int, int);   // Class function Add
      int Sub(int, int);   // Class function Subtract
      int Arg;
};
