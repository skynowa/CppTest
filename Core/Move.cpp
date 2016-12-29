/**
 * \file  main.cpp
 * \brief
 */


#include "../StdTest.h"

class File
{
    FILE* handle;
public:
    File(const char* filename) {
        if ( !(handle = fopen(filename, "r")) )
            throw std::runtime_error("blah blah blah");
    }
    ~File() { if (handle) fclose(handle); }

    File(File&& that) {
        handle = that.handle;
        that.handle = nullptr;
    }

    File& operator=(File&& that) {
        std::swap(handle, that.handle);
        return *this;
    }

    File(const File&) = delete; //запретить копирование
    void operator=(const File&) = delete; //запретить присваивание

    // ...
};

//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
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

