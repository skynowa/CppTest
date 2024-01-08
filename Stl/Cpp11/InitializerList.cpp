/**
 * \file  InitializerList.cpp
 * \brief
 *
 * \see   https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//--------------------------------------------------------------------------------------------------
class ArrayInt
{
public:
	ArrayInt() = default;
	ArrayInt(const ArrayInt &) = delete; // to avoid shallow copies
	ArrayInt &operator = (const ArrayInt &) = delete; // to avoid shallow copies

	explicit ArrayInt(const std::size_t a_size) :
		_size {a_size},
		_data { new int[a_size] {} }
	{
	}

	// allow ArrayInt to be initialized via list initialization (pass by value)
	explicit ArrayInt(std::initializer_list<int> a_list) :
		ArrayInt( a_list.size() )
	{
		// Now initialize our array from the list
		std::size_t count {};

		for (const auto it_item : a_list) {
			_data[count] = it_item;
			++ count;
		}
	}

	~ArrayInt()
	{
		delete[] _data; _data = nullptr;
	}

	const int & operator [] (const std::size_t a_index) const
	{
		STD_TEST(a_index < _size);

		return _data[a_index];
	}

	std::size_t size() const
	{
		return _size;
	}

private:
	const std::size_t  _size {};
	int               *_data {};
};
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	const ArrayInt array {1, 3, 5, 7, 9, 11};

	for (std::size_t count {}; count < array.size(); ++ count) {
		std::cout << array[count] << ' ';
    }

	std::cout << std::endl;

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------


#if OUTPUT

1 3 5 7 9 11

#endif
