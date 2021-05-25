/**
 * \file  Move.cpp
 * \brief
 *
 * [review]
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class File
{
public:
    explicit File(const char *filename)
    {
        _handle = fopen(filename, "r");
        if (_handle == nullptr) {
            /// throw std::runtime_error("blah blah blah");
        }

        std::cout << "File(const char *)" << std::endl;
    }

    File(const File &) = delete;

    File(File &&that)
    {
        _handle      = that._handle;
        that._handle = nullptr;

        std::cout << "File(File &&)" << std::endl;
    }

    File &
    operator = (File &&that)
    {
        std::swap(_handle, that._handle);

        std::cout << "operator = (File &&)" << std::endl;

        return *this;
    }

    void operator = (const File &) = delete;

    ~File()
    {
        if (_handle != nullptr) {
            fclose(_handle);
            _handle = nullptr;
        }

        std::cout << "~File()" << std::endl;
    }

private:
    FILE *_handle {};
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    {
        std::vector<File> files;

        {
            std::cout << "\n::::: files.push_back('data1.txt') :::::" << std::endl;
            files.push_back( File("data1.txt") );

            std::cout << "\n::::: files.push_back('data2.txt') :::::" << std::endl;
            files.push_back( File("data2.txt") );
        }

        {
            std::cout << "\n::::: files.erase() :::::" << std::endl;

            files.erase( files.cbegin() );
        }

        {
            std::cout << "\n::::: files - dtor :::::" << std::endl;
        }
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

::::: files.push_back('data1.txt') :::::
File(const char *)
File(File &&)
~File()

::::: files.push_back('data2.txt') :::::
File(const char *)
File(File &&)
File(File &&)
~File()
~File()

::::: files.erase() :::::
operator = (File &&)
~File()

::::: files - dtor :::::
~File()


#endif
