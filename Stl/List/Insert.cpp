/*
 * \file  Insert.cpp
 * \brief Inserting into a list
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>
//-------------------------------------------------------------------------------------------------
struct Item
{
    size_t id;
};
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
    std::list<Item> items;
    {
        for (size_t i = 1; i <= 5; ++ i) {
            Item item {i};    // 1 2 3 4 5

            items.push_back(item);
        }
    }

    auto it = items.begin();

    ++ it; // it points now to number 2

    Item item {777};
    items.insert(it, item); // 1 777 2 3 4 5

    std::cout << "items:\n\n";

    for (auto it = items.cbegin(); it != items.cend(); ++ it) {
        std::cout << it->id << std::endl;
    }

    return 0;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT

items:

1
777
2
3
4
5

#endif
