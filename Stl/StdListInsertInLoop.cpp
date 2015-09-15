/*
 * \file  main.cpp
 * \brief inserting into a list
 */


#include <string>
#include <iostream>
#include <cassert>
#include <list>
#include <vector>

//-------------------------------------------------------------------------------------------------
#define TRACE_VAR(v) \
    #v ": " << (v)

struct Item
{
    size_t id;
};
//-------------------------------------------------------------------------------------------------
int main(int argsNum, char **args)
{
    std::list<Item> items = { {0}, {1}, {2}, {3}, {4} };

    for (std::list<Item>::iterator it = items.begin(); it != items.end(); ++ it) {
        Item item {777};

        items.insert(it, item);
    }

    std::cout << "items:";
    for (std::list<Item>::iterator it = items.begin(); it != items.end(); ++ it) {
        std::cout << ' ' << it->id;
    }
    std::cout << '\n';

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

items: 777 0 777 1 777 2 777 3 777 4

#endif
