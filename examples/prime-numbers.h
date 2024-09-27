#include <array>
#include <vector>


constexpr bool is_prime(const std::vector<int> &primes, int val) {
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
      std::vector<int> res;
      res.push_back(1);
      
      while(res.size() != N) {
         int candidate = res.back() + 1;
         while(!is_prime(res, candidate))
         {
            candidate++;
         }
         res.push_back(candidate);
      }
      std::array<int, N> primes;
      std::copy(res.cbegin(), res.cend(), primes.begin());
      return primes;
   }
}
