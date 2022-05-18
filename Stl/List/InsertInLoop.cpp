/*
 * \file  InsertInLoop.cpp
 * \brief Inserting into a list
 */


#include <StdStream/StdStream.h>
#include <StdTest/StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
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
            items.insert(++ it, Item{777});
        }
    }

    std::cout << "items:\n\n";
    for (auto &it : items) {
        std::cout << STD_TRACE_VAR(it.id) << std::endl;
    }

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

items:

it.id: 1
it.id: 2
it.id: 3
it.id: 777
it.id: 4
it.id: 5

#endif
