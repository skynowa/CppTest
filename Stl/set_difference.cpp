// set_symmetric_difference example
#include <iostream>     // std::cout
#include <algorithm>    // std::set_symmetric_difference, std::sort
#include <vector>       // std::vector

int main ()
{
    int first[]  = {5, 10, 15, 20, 25, 100};
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
        std::cout << ' ' << *it;
    }

    std::cout << '\n';

    return 0;
}
