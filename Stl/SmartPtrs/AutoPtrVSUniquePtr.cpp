/**
 * \file  AutoPtrVSUniquePtr.cpp
 * \brief
 *
 * \todo
 *
 * - The const std::auto_ptr Idiom
 * - std::auto_ptr and Exception Safety
 * - std::auto_ptr - can't be stored arrays
 *
 * - std::unique_ptr - can be stored in containers
 * - std::unique_ptr - can be stored arrays
 * - unique_ptr can handle arrays correctly (it will call delete[], while auto_ptr will attempt to call delete
 * - Объект этого класса теряет права владения ресурсом при копировании (присваивании,
 *   использовании в конструкторе копий, передаче в функцию по значению)
 * - права владения ресурсов уходят в y_ptr и x_ptr начинает указывать на null pointer
 *   (сделает элемент вектора невалидным)
 * - В отличии от auto_ptr, unique_ptr запрещает копирование
 *   Изменение прав владения ресурсом осуществляется с помощью вспомогательной функции std::move
 * - The boost::shared_ptr template makes it easy to handle multiple pointers to the same object,
 *   and the object is only deleted after the last reference to it went out of scope.
 *
 * http://archive.kalnitsky.org/2011/11/02/smart-pointers-in-cpp11/
 * http://www.gotw.ca/publications/using_auto_ptr_effectively.htm
 *
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

	// std::auto_ptr
	{
		std::cout << "std::auto_ptr" << std::endl;

		std::auto_ptr<int> a(new int(10));
		std::auto_ptr<int> b;

		// implicitly transfers ownership
		b = a;

		std::cout << STD_TRACE_PTR(a.get()) << std::endl;
		std::cout << STD_TRACE_PTR(b.get()) << std::endl;
		std::cout << std::endl;
	}

	// std::unique_ptr
	{
		std::cout << "std::unique_ptr" << std::endl;

		std::unique_ptr<int> a(new int(10));
		std::unique_ptr<int> b;

		// ownership must be transferred explicitly
		b = std::move(a);

		std::cout << STD_TRACE_PTR(a.get()) << std::endl;
		std::cout << STD_TRACE_PTR(b.get()) << std::endl;
		std::cout << std::endl;
	}

	// std::vector<std::auto_ptr<int>>
	{
		std::cout << "std::vector< std::auto_ptr<int> >" << std::endl;

		std::vector< std::auto_ptr<int> > vec;
		vec.push_back( std::auto_ptr<int>(new int(10)) );
		vec.push_back( std::auto_ptr<int>(new int(11)) );
		vec.push_back( std::auto_ptr<int>(new int(12)) );

		std::auto_ptr<int> tmp = vec[1];

		std::cout << STD_TRACE_PTR(vec[0].get()) << std::endl;
		std::cout << STD_TRACE_PTR(vec[1].get()) << std::endl;
		std::cout << STD_TRACE_PTR(vec[2].get()) << std::endl;
		std::cout << std::endl;
	}

	// std::vector<std::unique_ptr<int>>
	{
		std::cout << "std::vector< std::unique_ptr<int> >" << std::endl;

		std::vector< std::unique_ptr<int> > vec;
		vec.push_back( std::unique_ptr<int>(new int(10)) );
		vec.push_back( std::unique_ptr<int>(new int(11)) );
		vec.push_back( std::unique_ptr<int>(new int(12)) );

	#if 0
		// error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]’
		std::unique_ptr<int> tmp = vec[1];
	#else
		std::unique_ptr<int> tmp = std::move(vec[1]);
	#endif

		std::cout << STD_TRACE_PTR(vec[0].get()) << std::endl;
		std::cout << STD_TRACE_PTR(vec[1].get()) << std::endl;
		std::cout << STD_TRACE_PTR(vec[2].get()) << std::endl;
		std::cout << std::endl;
	}
#pragma GCC diagnostic pop

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

std::auto_ptr
a.get(): {0, 0}
b.get(): {0x5648001d3280, 10}

std::unique_ptr
a.get(): {0, 0}
b.get(): {0x5648001d3280, 10}

std::vector< std::auto_ptr<int> >
vec[0].get(): {0x5648001d3280, 10}
vec[1].get(): {0, 0}
vec[2].get(): {0x5648001d32a0, 12}

std::vector< std::unique_ptr<int> >
vec[0].get(): {0x5648001d32a0, 10}
vec[1].get(): {0, 0}
vec[2].get(): {0x5648001d3280, 12}

#endif
