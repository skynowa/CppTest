/**
 * \file
 * \brief
 *
 * \todo
 */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef int aiIntArray[3][4];
aiIntArray a = {
   {4,  6,  8,  10},
   {14, 16, 18, 20},
   {24, 26, 28, 30}
};

void show(const aiIntArray &a, int m, int n) {
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            int x = *(*(a + i) + j);

            std::cout << x << ", ";
        }

        std::cout << std::endl;
    }
}

int main () {
    show(a, 3, 4);

    return 0;
}