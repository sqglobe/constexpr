#include <iostream>
#include "prime-numbers.h"

int main() {
  std::array<int, 2000> p = primes<2000>();
  
  for(auto e: p) {
     std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
