/*****************************************************************************************
   File name: DLLCode.h

   This file contains all the DLL interfacing object declarations, in this example: a
   class object, a global function object, and a global integer variable. 

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
       void DLLDIR DLLfun1(char*);
       int  DLLDIR DLLfun2(int);
};

extern int  DLLDIR DLLArg;

class DLLDIR Dllclass
{
   public:
      Dllclass();          // Class Constructor
      ~Dllclass();         // Class destructor
      int Add(int, int);   // Class function Add
      int Sub(int, int);   // Class function Subtract
      int Arg;             // Warming: you should not import class variables
                           // since the DLL object can be dynamically unloaded.
};
