/**
 * \file  main.cpp
 * \brief std::filesystem
 *
 * https://en.cppreference.com/w/cpp/header/filesystem
 *
 * The new std::filesystem library provides a standard way to manipulate files, directories,
 * and paths in a filesystem.
 *
 * Here, a big file is copied to a temporary path if there is available space:
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	using namespace std;

	namespace fs = std::filesystem;

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
	}

	// Work with a fs::path object:
	{
		fs::path file_path("./dir1/dir2/file.txt");
		cout << file_path.parent_path() << '\n'; // It'll print "/dir1/dir2"
		cout << file_path.filename() << '\n'; // It'll print "file.txt"
		cout << file_path.extension() << '\n'; // It'll print ".txt"

		file_path.replace_filename("file2.txt");
		file_path.replace_extension(".cpp");
		cout << file_path << '\n'; // It'll print "/dir1/dir2/file2.cpp"

		fs::path dir_path("./dir1");
		dir_path.append("dir2/file.txt");
		cout << dir_path << '\n'; // It'll print "/dir1/dir2/file.txt"
	}

	// Working with directories:
	{
		// Getting the current working directory
		fs::path current_path = fs::current_path();

		// Creating a directory
		fs::create_directory("./dir");

		// Creating several directories
		fs::create_directories("./dir/subdir1/subdir2");

		// Verifying the existence of a directory
		if (fs::exists("./dir/subdir1")) {
			cout << "yes\n";
		}

		// Non-recursive directory traversal
		for (auto &p : fs::directory_iterator(current_path)) {
			cout << p.path() << '\n';
		}

		// Recursive directory traversal
		for (auto &p : fs::recursive_directory_iterator(current_path)) {
			cout << p.path() << '\n';
		}

		// Nonrecursive directory copy
		fs::copy("./dir", "./dir_copy");

		// Recursive directory copy
		fs::copy("./dir", "./dir_copy", fs::copy_options::recursive);

		// Removal of the directory with all contents, if it exists
		fs::remove_all("./dir");

		// std::cout << TRACE_VAR("") << std::endl;
	}

	// Working with files:
	{
		// Verifying the existence of a file
		if (fs::exists("./dir/file.txt")) {
			cout << "yes\n";
		}

		// Copying a file
		fs::copy_file("./dir/file.txt", "./dir/file_copy.txt",
		fs::copy_options::overwrite_existing);

		// Getting the file size (in bytes)
		uintmax_t size = fs::file_size("./dir/file.txt");

		// Renaming a file
		fs::rename("./dir/file.txt", "./dir/file2.txt");

		// Deleting a file if it exists
		fs::remove("./dir/file2.txt");
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
