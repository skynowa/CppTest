/*
 * \file  main.cpp
 * \brief inserting into a list
 *
 * \todo
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
#define TRACE_VAR(v) \
    #v ": " << (v)

struct Item
{
    size_t id;
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::list<Item> items { {1}, {2}, {3}, {4}, {5} };

    for (auto it = items.begin(); it != items.end(); ++ it) {
        if (it->id == 3) {
            Item item {777};
            items.insert(++ it, item);
        }
    }

    std::cout << "items:";
    for (auto &it : items) {
        std::cout << ' ' << it.id;
    }
    std::cout << '\n';

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

items: 777 0 777 1 777 2 777 3 777 4

#endif
