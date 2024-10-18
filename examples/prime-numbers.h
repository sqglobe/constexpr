#include <array>
#include <span>


constexpr bool is_prime(std::span<int> primes, int val) {
  for(auto i: primes) {
     if(val % i == 0 && i != 1) {
        return false;
     }
  }
  return true;
}

template<std::size_t N>
constexpr std::array<int, N> primes() {
   if constexpr (N == 0) {
       return {};
   } else {

      std::array<int, N> primes = {};
      primes[0] = 1;
      std::span<int> candidates{primes.begin(), 1};

      while(candidates.size() != N) {
         int candidate = candidates.back() + 1;
         while(!is_prime(candidates, candidate))
         {
            candidate++;
         }

         const auto number = candidates.size();
         primes[number] = candidate;
         candidates = std::span<int>{primes.begin(), number + 1};
      }
      return primes;
   }
}
