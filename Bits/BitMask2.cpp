#include <iostream>

using namespace std;

int main()
{
    for (uint64_t i = 0; i < 70; ++ i) {
		const uint64_t g_id = i;

		const auto mask_bad = (1    << (g_id - 1));
		const auto mask_ok  = (1ULL << (g_id - 1ULL));

        cout << g_id << " - Bad mask: " << mask_bad << ", OK mask: " << mask_ok << endl;
    }

    return 0;
}