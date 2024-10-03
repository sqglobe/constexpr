# constexpr influence on compile and run-time

1. What is the constexpr
2. What might be done with constexpr

## Test description

In order to assess the impact of `constexpr`, we created a [code example](examples) that includes a prime number generator algorithm. This algorithm can be executed both at compile time and at runtime, and it is defined in [prime-numbers.h](examples/prime-numbers.h).

We then created two targets in the [CMakeLists.txt](examples/CMakeLists.txt):
  * `constexpr` - which executes the algorithm during compilation
  * `runtime` - which executes the algorithm at runtime
  
By analyzing the two generated binaries, we can evaluate the various side effects of using `constexpr` on:
  * Binary size
  * Compile time
  * Runtime performance
  * Generated assembly code

Compile-time is obtained through `-ftime-trace` clang compiler flag per target, so it's very precise. 
 
## Compile-time calculation

For the compile-time calculation we have following numbers:
 * execution: 137 ns
 * compilation: 34 910,703 ms
 * binary size: 30K

2. Which asembly we have as an outcome

## The same on run-time

For the runtime we have following numbers:
 * execution time: 8.891488 ms
 * compilation time: 2 110,985 ms
 * binary size: 23KB

## Conclusion

`constexpr` is an excellent tool to accelerate computations when you have a function that can be evaluated
at compile time. However, it can also have significant drawbacks, particularly by increasing both
compile time and binary size.

