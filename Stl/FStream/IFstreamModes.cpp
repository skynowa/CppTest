/**
 * \file  IFstreamModes.cpp
 * \brief Difference Between Text File and Binary File
 *
 * Text file:
 * Is the one in which data is stored in the form of ASCII characters and is normally used
 * for storing a stream of characters. Text files are organized around lines, each of which
 * ends with a newline character (‘\n’). The source code files are themselves text files.
 *
 * Binary file:
 * Is the one in which data is stored in the file in the same way as it is stored
 * in the main memory for processing. It is stored in binary format instead of ASCII characters.
 * It is normally used for storing numeric information (int, float, double).
 * Normally a binary file can be created only from within a program and its contents
 * can be read only by a program.
 *
 * \see https://www.geeksforgeeks.org/difference-between-cpp-text-file-and-binary-file/
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
    /// const std::string filePath = "IFstreamTest.txt";
    const std::string filePath = "test.jpg";
    const std::string str      = "Test string\n\ntest\r\n";

    // Create temp file
    {
	    std::ofstream ofs(filePath);
        ofs << str;
    }

    const std::ios_base::openmode openModes[]
	{
		std::ios_base::in,
		std::ios_base::binary
	};

	for (const auto it_openMode : openModes) {
		std::ifstream ifs(filePath, it_openMode);
		STD_TEST(ifs.is_open());
		STD_TEST(!ifs.fail());

		std::streampos fileSize {};
		{
			ifs.seekg(0, std::ios_base::end);
			fileSize = ifs.tellg();
			ifs.seekg(0, std::ios_base::beg);

			std::cout << STD_TRACE_VAR2(it_openMode, fileSize) << std::endl;
		}

		STD_TEST(static_cast<size_t>(fileSize) == str.size());
	} // for (openModes)

	// Delete temp file
	if (0) {
		int iRv = std::remove(filePath.c_str());
		STD_TEST(iRv == 0);
	}

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

it_openMode: 8, fileSize: 11
it_openMode: 4, fileSize: 11

#endif
