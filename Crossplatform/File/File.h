/**
 * \file  File.h
 * \brief Platform-independent wrapper for the FileRouter class
 */


#include <string>
#include <FileRouter.h>
//--------------------------------------------------------------------------------------------------
class File
{
public:
    // Simply pass off all operations to the FileRouter class
    File(const std::string & filePath) :
        path(filePath)
    {
    }

    ~File()
    {
    }

    bool exists() const
    {
        return FileRouter::exists(path);
    }

    bool isDirectory() const
    {
        return FileRouter::isDirectory(path);
    }

protected:
    std::string path;
};
//--------------------------------------------------------------------------------------------------
