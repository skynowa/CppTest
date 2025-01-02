 /*
 * \file  CString.inl
 * \brief simple string class
 */


/*******************************************************************************
*    public, constructors
*
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
CString::CString() :
    _m_pszData(nullptr)
{
    _m_pszData = nullptr;
}
//--------------------------------------------------------------------------------------------------
CString::CString(const char *a_str) :
    _m_pszData(nullptr)
{
    _m_pszData = new char[strlen(a_str) + 1]();
    strcpy(_m_pszData, a_str);
}
//--------------------------------------------------------------------------------------------------
CString::CString(const CString &a_str) :
    _m_pszData(nullptr)
{
    if (*this == a_str) {
        return;
    }

    _m_pszData = new char[strlen(a_str._m_pszData) + 1]();
    strcpy(_m_pszData, a_str._m_pszData);
}
//--------------------------------------------------------------------------------------------------
CString::~CString()
{
    delete[] _m_pszData;
    _m_pszData = nullptr;
}
//--------------------------------------------------------------------------------------------------


/*******************************************************************************
*    public, methods
*
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
bool
CString::isEmpty() const
{
    return (_m_pszData == nullptr) || (_m_pszData[0] == '\0');
}
//--------------------------------------------------------------------------------------------------
const char *
CString::data() const
{
    return _m_pszData;
}
//--------------------------------------------------------------------------------------------------
void
CString::print() const
{
    std::cout << *this << std::endl;
}
//--------------------------------------------------------------------------------------------------


/*******************************************************************************
*    public, operators
*
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
CString::operator char * ()
{
    return _m_pszData;
}
//--------------------------------------------------------------------------------------------------
CString::operator const char * ()
{
    return _m_pszData;
}
//--------------------------------------------------------------------------------------------------
CString
CString::operator + (const CString &a_str) const
{
    CString s;

    s._m_pszData = new char[strlen(_m_pszData) + strlen(a_str._m_pszData) + 1]();
    strcpy(s._m_pszData, _m_pszData);
    strcat(s._m_pszData, a_str._m_pszData);

    return s;
}
//--------------------------------------------------------------------------------------------------
CString &
CString::operator = (const CString &a_str)
{
    if (*this != a_str) {
        delete[] _m_pszData;
        _m_pszData = nullptr;

        _m_pszData = new char[strlen(a_str._m_pszData) + 1]();
        strcpy(_m_pszData, a_str._m_pszData);
    }

    return *this;
}
//--------------------------------------------------------------------------------------------------
bool
CString::operator == (const CString &a_str) const
{
    if (_m_pszData == a_str._m_pszData) {
        return true;
    }

    if (_m_pszData == nullptr || a_str._m_pszData == nullptr) {
        return false;
    }

    return (strcmp(_m_pszData, a_str._m_pszData) == 0);
}
//--------------------------------------------------------------------------------------------------
bool
CString::operator != (const CString &a_str) const
{
    return !(*this == a_str);
}
//--------------------------------------------------------------------------------------------------
bool
CString::operator == (const char *a_str) const
{
    if (_m_pszData == a_str) {
        return true;
    }

    if (_m_pszData == nullptr || a_str == nullptr) {
        return false;
    }

    return (strcmp(_m_pszData, a_str) == 0);
}
//--------------------------------------------------------------------------------------------------
bool
CString::operator != (const char *a_str) const
{
    return !(_m_pszData == a_str);
}
//--------------------------------------------------------------------------------------------------
void
CString::operator () () const
{
    std::cout << "operator ()" << std::endl;
}
//--------------------------------------------------------------------------------------------------
const char &
CString::operator [] (std::size_t i) const
{
    return _m_pszData[i];
}
//--------------------------------------------------------------------------------------------------
char &
CString::operator [] (std::size_t i)
{
    return _m_pszData[i];
}
//--------------------------------------------------------------------------------------------------

/*******************************************************************************
*    public, friends
*
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
std::istream &
operator >> (std::istream &is, CString &a_str)
{
    // TODO: is >> strVal;
    (void)a_str;

   return is;
}
//--------------------------------------------------------------------------------------------------
std::ostream &
operator << (std::ostream &os, const CString &a_str)
{
    if (a_str.isEmpty()) {
        os << "<empty>";
    } else {
        os << a_str.data();
    }

    return os;
}
//--------------------------------------------------------------------------------------------------
