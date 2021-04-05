/**
 * \file
 * \brief
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
class File
{
public:
    File(const char* filename)
    {
        if ( !(_handle = fopen(filename, "r")) ) {
            throw std::runtime_error("blah blah blah");
        }
    }

    File(File&& that)
    {
        _handle      = that._handle;
        that._handle = nullptr;
    }

    File& operator = (File&& that)
    {
        std::swap(_handle, that._handle);
        return *this;
    }

    File(const File&) = delete;
    void operator = (const File&) = delete;

    ~File()
    {
        if (_handle) {
            fclose(_handle);
        }
    }

private:
    FILE *_handle {};
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	std::vector<File> files;
	files.push_back(File("data1.txt"));
	files.push_back(File("data2.txt"));
	files.erase(files.begin());

    // std::cout << "" << std::endl;

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
