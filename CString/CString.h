#include <string.h>
#include <iostream>

class CString
{
public:
                         CString               ();
                         CString               (const char *str);
                         CString               (const CString &str);
                        ~CString               ();

                         operator char *       ();
                         operator const char * ();
   CString               operator +            (const CString &q) const;
   CString &             operator =            (const CString &q);
   // don't forget comparison operators
   friend std::istream & operator >>           (std::istream &is, CString &obj);
   friend std::ostream & operator <<           (std::ostream &os, const CString &obj);

private:
    char *cstr;    
};
//------------------------------------------------------------------------------
CString::CString() {
    cstr = NULL;
}
//------------------------------------------------------------------------------
CString::CString(const char *str) {
    cstr = new char[strlen(str) + 1]();
    strcpy(cstr,str);
}
//------------------------------------------------------------------------------
CString::CString(const CString &q) {
    if (*this == q) {
        return;
    }
    
    cstr = new char[strlen(q.cstr) + 1]();
    strcpy(cstr,q.cstr);
}
//------------------------------------------------------------------------------
CString::~CString() {
    if (cstr) {
        delete[] cstr;
        cstr = NULL;
    }
}
//------------------------------------------------------------------------------
CString::operator char * () {
    return cstr;
}
//------------------------------------------------------------------------------
CString::operator const char * () {
    return cstr;
}
//------------------------------------------------------------------------------
CString 
CString::operator + (const CString &q) const {
    CString s;
    s.cstr = new char[strlen(cstr) + strlen(q.cstr) + 1]();
    strcpy(s.cstr, cstr);
    strcat(s.cstr, q.cstr);
    
    return s;
}
//------------------------------------------------------------------------------
CString & 
CString::operator = (const CString &q) {
    if (*this != q) {
        if (cstr) {
            delete[] cstr;
            cstr = NULL;
        }
        
        cstr = new char[strlen(q.cstr) + 1]();
        strcpy(cstr, q.cstr);
    }
    
    return *this;
}
//------------------------------------------------------------------------------
std::istream & 
operator >> (std::istream &is, CString &obj) {
   is >> strVal;
   return is;
}
//------------------------------------------------------------------------------
std::ostream & 
operator << (std::ostream &os, const CString &obj) {
   os << obj;
   return os;
}
//------------------------------------------------------------------------------
