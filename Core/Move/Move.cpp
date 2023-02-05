/**
 * \file  Move.cpp
 * \brief
 *
 * [review]
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>

#define RULEOF5_OPTION_LOG 1
#include <Idioms/Rule3Move.h>
//-------------------------------------------------------------------------------------------------
class File
{
public:
    explicit File(const char *filename)
    {
        _handle = std::fopen(filename, "r");
        if (_handle == nullptr) {
            throw std::runtime_error("blah blah blah");
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

    // Ops
    File & operator = (const File &) = delete;

    File & operator = (File &&that)
    {
        std::swap(_handle, that._handle);

        std::cout << "operator = (File &&)" << std::endl;

        return *this;
    }

    ~File()
    {
        if (_handle != nullptr) {
            std::fclose(_handle);
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
        std::vector<Rule3Move> files;

        {
            std::cout << "::::: files.push_back('data1.txt') :::::" << std::endl;
            files.push_back( Rule3Move("data1.txt") );

            std::cout << "::::: files.push_back('data2.txt') :::::" << std::endl;
            files.push_back( Rule3Move("data2.txt") );
        }

        {
            std::cout << "::::: files.erase() :::::" << std::endl;

            files.erase( files.cbegin() );
        }

        {
            std::cout << "::::: files - dtor :::::" << std::endl;
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

#if OUTPUT

[Ctor] const char *
[Ctor] Move
[Dtor]

::::: files.push_back('data2.txt') :::::
[Ctor] const char *
[Ctor] Move
[Ctor] Move
[Dtor]

[Dtor]

::::: files.erase() :::::
[Op] Move
[Dtor]

::::: files - dtor :::::
[Dtor]

#endif
