/**
 * \file  main.cpp
 * \brief std::filesystem

The new std::filesystem library provides a standard way to manipulate files, directories, and paths in a filesystem.

Here, a big file is copied to a temporary path if there is available space:
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const auto bigFilePath {"bigFileToCopy"};
	if (std::filesystem::exists(bigFilePath)) {
	const auto bigFileSize {std::filesystem::file_size(bigFilePath)};
	std::filesystem::path tmpPath {"/tmp"};
	if (std::filesystem::space(tmpPath).available > bigFileSize) {
		std::filesystem::create_directory(tmpPath.append("example"));
		std::filesystem::copy_file(bigFilePath, tmpPath.append("newFile"));
	}
	}

    // std::cout << TRACE_VAR("") << std::endl;

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
