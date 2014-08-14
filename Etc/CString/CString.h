 /*
 * \file  CString.cpp
 * \brief simple string class
 */


//------------------------------------------------------------------------------
#include <string.h>
#include <iostream>
#include <assert.h>
//------------------------------------------------------------------------------
class CString
{
public:
                         CString               ();
    /*explicit*/         CString               (const char *str);
    /*explicit*/         CString               (const CString &str);
                        ~CString               ();

    bool                 isEmpty               () const;
    const char *         data                  () const;
    void                 print                 () const;

                         operator char *       ();
                         operator const char * ();
   CString               operator +            (const CString &str) const;
   CString &             operator =            (const CString &str);
   bool                  operator ==           (const CString &str) const;
   bool                  operator !=           (const CString &str) const;
   bool                  operator ==           (const char *str) const;
   bool                  operator !=           (const char *str) const;
   void                  operator ()           () const;
   const char &          operator []           (std::size_t i) const;
   char &                operator []           (std::size_t i);

   // don't forget comparison operators

   friend std::istream & operator >>           (std::istream &is, CString &obj);
   friend std::ostream & operator <<           (std::ostream &os, const CString &obj);

private:
    char *               _m_pszData;
};
//------------------------------------------------------------------------------
