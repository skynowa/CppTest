/**
 * \file
 * \brief
 *
 * \todo
 */


#include <string>

// Class to handle all File operations in a platform-dependent manner
class FileRouter
{
public:
    static bool exists(const std::string & path);
    static bool isDirectory(const std::string & path);
};

#include <FileRouter.inl>
