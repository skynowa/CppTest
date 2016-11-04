/**
 * \file  main.cpp
 * \brief
 */


#include "../../StdTest.h"
#include <memory>


//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
	// std::auto_ptr
	{
		std::cout << "std::auto_ptr" << std::endl;

		std::auto_ptr<int> a(new int(10));
		std::auto_ptr<int> b;

		// implicitly transfers ownership
		b = a;

		std::cout << _xTRACE_PTR(a.get()) << std::endl;
		std::cout << _xTRACE_PTR(b.get()) << std::endl;
		std::cout << std::endl;
	}

	// std::unique_ptr
	{
		std::cout << "std::unique_ptr" << std::endl;

		std::unique_ptr<int> a(new int(10));
		std::unique_ptr<int> b;

		// ownership must be transferred explicitly
		b = std::move(a);

		std::cout << _xTRACE_PTR(a.get()) << std::endl;
		std::cout << _xTRACE_PTR(b.get()) << std::endl;
		std::cout << std::endl;
	}

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

std::auto_ptr
a.get(): {0, 0}
b.get(): {0x55e445c75c30, 10}

std::unique_ptr
a.get(): {0, 0}
b.get(): {0x55e445c75c30, 10}

#endif

/**
 * FAQ
 *
 * - std::unique_ptr - can be stored in containers
 * - unique_ptr can handle arrays correctly (it will call delete[], while auto_ptr will attempt to call delete
 * - права владения ресурсов уходят в y_ptr и x_ptr начинает указывать на null pointer
 *   (сделает элемент вектора невалидным)
 * - В отличии от auto_ptr, unique_ptr запрещает копирование
 *   Изменение прав владения ресурсом осуществляется с помощью вспомогательной функции std::move
 * - The boost::shared_ptr template makes it easy to handle multiple pointers to the same object,
 *   and the object is only deleted after the last reference to it went out of scope.
 */
