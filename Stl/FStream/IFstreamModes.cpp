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
    const std::string txtFilePath = "IFstreamTest.txt";
    const std::string txtStr      = "Test string\n\ntest\r\n";
    const std::size_t txtFileSize = txtStr.size();
    const bool        isTxtFile   = (txtFilePath.find(".txt") != std::string::npos);

    // Bin files - std::ios_base::openmode does not affect for field size determination
    /// const std::string binfilePath = "test.jpg";
    /// const std::size_t binFileSize = 77480;

    // Create temp file
    if (isTxtFile) {
	    std::ofstream ofs(txtFilePath);
        ofs << txtStr;
    }

    const std::ios_base::openmode openModes[]
	{
		std::ios_base::in,
		std::ios_base::binary
	};

	for (const auto it_openMode : openModes) {
		std::ifstream ifs(txtFilePath, it_openMode);
		STD_TEST(ifs.is_open());
		STD_TEST(!ifs.fail());

		std::streampos fileSize {};
		{
			ifs.seekg(0, std::ios_base::end);
			fileSize = ifs.tellg();
			ifs.seekg(0, std::ios_base::beg);

			std::cout << STD_TRACE_VAR2(it_openMode, fileSize) << std::endl;
		}

		STD_TEST(static_cast<size_t>(fileSize) == txtFileSize);
	} // for (openModes)

	// Delete temp file
	if (isTxtFile) {
		int iRv = std::remove(txtFilePath.c_str());
		STD_TEST(iRv == 0);
	}

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

// Txt
it_openMode: 8, fileSize: 11
it_openMode: 4, fileSize: 11

// Bin
it_openMode: 8, fileSize: 77480
it_openMode: 4, fileSize: 77480

#endif
