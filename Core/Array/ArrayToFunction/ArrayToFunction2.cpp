/**
 * \file
 * \brief
 *
 * \todo
 */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define xARRAY_SIZE(a)        ( sizeof(a) / sizeof((a)[0]) )

void
foo (const int *Array, size_t x, size_t y) {
   for (size_t i = 0; i < x; ++ i) {
      for (size_t j = 0; j < y; ++ j) {
            int var = Array[i * y + j];

            std::cout << var << ", ";
      }
      std::cout << std::endl;
   }
}

int main() {
   const int x[][4]= {
      {1,  2,  3,  4 },
      {11, 12, 13, 14},
      {21, 22, 23, 24}
   };

   foo((const int *)x, xARRAY_SIZE(x), 4);
}