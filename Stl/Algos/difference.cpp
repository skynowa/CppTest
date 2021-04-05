/**
 * \file
 * \brief
 *
 * \todo
 */


#include <iostream>
#include <algorithm>
#include <vector>
//-------------------------------------------------------------------------------------------------
int main ()
{
    int first[]  = {10, 20, 30, 40, 50, 60, 70};
    int second[] = {50, 40, 30, 20, 10};

    std::vector<int> v;

    std::sort (std::begin(first),  std::end(first));
    std::sort (std::begin(second), std::end(second));

    auto it = std::set_difference(
        std::begin(first),  std::end(first),
        std::begin(second), std::end(second),
        std::back_inserter(v));

    std::cout << "Difference has " << v.size() << " elements:\n";

    for (auto it : v) {
        std::cout << ' ' << it;
    }

    std::cout << '\n';

    return 0;
}
//-------------------------------------------------------------------------------------------------
#if 0

5 15 25 100

#endif
//-------------------------------------------------------------------------------------------------
