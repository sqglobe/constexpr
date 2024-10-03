#include <iostream>
#include <chrono>
#include "prime-numbers.h"

using std::chrono::high_resolution_clock;

int main() {
  // make it works clang++-15 -fconstexpr-steps=999999999 -std=c++20 goto.cpp
  auto begin= high_resolution_clock::now();
  constexpr std::array<int, 2000> p = primes<2000>();
  auto end = high_resolution_clock::now();

  std::cout << "Generation time: " << (end - begin)  << std::endl;
  
  for(auto e: p) {
     std::cout << e << " ";
  }
  std::cout << std::endl;
  return 0;
}
