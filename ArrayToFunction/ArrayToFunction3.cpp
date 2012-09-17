#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define xARRAY_SIZE(a)        ( sizeof(a) / sizeof((a)[0]) )

void 
foo (const char *Array, size_t x, size_t y) {
   for (size_t i = 0; i < x; ++ i) {
      const char *var = &Array[i * y];
     
      std::cout << var << ", ";

      std::cout << std::endl;
   }  
}

int main() {
   const char x[][20]= {
      {"1,  2,  3,  4 "},
      {"11, 12, 13, 14"},
      {"21, 22, 23, 24"}
   };
   
   foo((const char *)x, xARRAY_SIZE(x), 20);
}