/**
 * \file
 * \brief
 *
 * \todo
 */


#include <string>
#include <iostream>
#include <algorithm>
#include <map>

//-------------------------------------------------------------------------------------------------
int main ()
{
    std::map<std::string, int> a
    {
        {"a", 1},
        {"b", 2},
        {"c", 3},
        {"d", 4}
    };

    std::map<std::string, int> b
    {
        {"a", 1},
        {"b", 2},
        {"c", 3}
    };

    std::map<std::string, int> diff;

    std::set_symmetric_difference(
        a.begin(), a.end(),
        b.begin(), b.end(),
        std::inserter(diff, diff.end()));

    std::cout << "diff.size(): " << diff.size() << std::endl;

    for (auto it : diff) {
        std::cout << it.first << ", " << it.second << std::endl;
    }

    return 0;
}
//-------------------------------------------------------------------------------------------------
#if 0

diff.size(): 1
d, 4

#endif
//-------------------------------------------------------------------------------------------------
