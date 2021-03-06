/**
 * \file  FileRouter.inl
 * \brief
 */


// Check to make sure that the user wants a Posix compatible implementation
#ifdef USE_POSIXFILEROUTER

//--------------------------------------------------------------------------------------------------
#include <sys/stat.h>
//--------------------------------------------------------------------------------------------------
bool
FileRouter::isDirectory(const std::string & path)
{
    struct _stat sbuf {};

    if (stat(path.c_str(), &sbuf) == -1) {
        return false;
    }

    return (sbuf.st_mode & S_IFDIR) != 0;
}
//--------------------------------------------------------------------------------------------------
bool
FileRouter::exists(const std::string & path)
{
    struct stat sbuf {};

    return stat(path.c_str(), &sbuf) != -1;
}
//--------------------------------------------------------------------------------------------------

#endif
