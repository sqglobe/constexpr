#include <iostream>
#include "prime-numbers.h"

int main() {
  // make it works clang++-15 -fconstexpr-steps=999999999 -std=c++20 goto.cpp
  constexpr std::array<int, 2000> p = primes<2000>();
  
  for(auto e: p) {
     std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
