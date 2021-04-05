/**
 * \file
 * \brief
 *
 * \todo
 */


#include <string>

#ifdef _POSIX
    #include <unistd.h>
    #include <dirent.h>
    #include <sys/stat.h>
#elif defined(_WIN32)
    #include <windows.h>
    #include <sys/stat.h>
#else
    #error Couldn’t detect correct OS
#endif

using namespace std;
// File class, similar to java.io.File, though lacking functionality
class File
{
public:
    File(const string & filePath) :
        path(filePath)
    {
    }
    virtual ~File()
    {
    }

    // ensure that a File is a directory
    bool isDirectory() const
    {
    #ifdef _POSIX
        struct stat sbuf;
        if (stat(path.c_str(), &sbuf) == -1)
            return false;

        return (sbuf.st_mode & _S_IFDIR)!=0;
    #elif defined(_WIN32)
        struct _stati64 sbuf;
        if (_stati64(path.c_str(), &sbuf)==-1)
            return false;

        return (sbuf.st_mode & _S_IFDIR)!=0;
    #endif
    }

    // make sure that a file exists
    bool exists() const
    {
    #ifdef _POSIX
        struct stat sbuf;

        return stat(path.c_str(), &sbuf)!=-1;
    #elif defined(_WIN32)
        return GetFileAttributes(path.c_str()) != INVALID_FILE_ATTRIBUTES;
    #endif
    }

protected:
    string path; // the path to the file
};
