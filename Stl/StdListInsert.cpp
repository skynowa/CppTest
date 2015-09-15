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
    std::list<Item> items;
    {
        for (int i = 1; i <= 5; ++ i) {
            Item item = {i};    // 1 2 3 4 5

            items.push_back(item);
        }
    }

    std::list<Item>::iterator it = items.begin();
    ++ it; // it points now to number 2

    Item item = {777};
    items.insert(it, item); // 1 777 2 3 4 5

    std::cout << "items:";

    for (std::list<Item>::iterator it = items.begin(); it != items.end(); ++ it) {
        std::cout << ' ' << (*it).id;
    }

    std::cout << '\n';

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

items: 1 777 2 3 4 5

#endif

