 /*
 * \file  FriendClass.cpp
 * \brief friend class
 */


#include <string>
#include <iostream>
#include <assert.h>
//--------------------------------------------------------------------------------------------------
class File
{
private:
    static bool _isExists()
    {
        std::cout << __FUNCTION__ << std::endl;
        return false;
    }

    friend class TestFriend;
};
//--------------------------------------------------------------------------------------------------
class TestFriend
{
public:
    bool test()
    {
        return File::_isExists();
    }
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    TestFriend t;
    t.test();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

File::_isExists

#endif