# constexpr influence on compile and run-time

`constexpr` specifies that the value of a variable or function can appear in constant expressions. For functions, it means that they might be called at both compile-time and runtime.

Before C++20, there were a lot of limitations on such functions, the most notable being memory allocation. But with C++20, more things became possible:
* Memory allocation (though that memory should be deallocated before the function returns, so you can't return `std::vector` or `std::string`).
* Throwing an exception (in a compile-time context, it leads to a compilation error).
* Loops and `constexpr` function calls.
* Even the invocation of virtual methods is now allowed.

All of this means that more algorithms can be moved to compile-time. In this article, I am investigating the impact of such a move.

## Test description

In order to assess the impact of `constexpr`, I created a [code example](examples) that includes a prime number generator algorithm. This algorithm can be executed both at compile time and at runtime, and it is defined in [prime-numbers.h](examples/prime-numbers.h).

We then created two targets in the [CMakeLists.txt](examples/CMakeLists.txt):
  * `constexpr` - which executes the algorithm during compilation
  * `runtime` - which executes the algorithm at runtime
  
By analyzing the two generated binaries with release build configuration, we can evaluate the various side effects of using `constexpr` on:
  * Binary size
  * Compile time
  * Runtime performance
  * Generated assembly code

Compile-time is obtained through `-ftime-trace` clang compiler flag per target, so it's very precise. 
 
## Compile-time calculation

For the compile-time calculation we have following numbers:
 * execution: 77ns
 * compilation: 9 653.913 ms
 * binary size: 26K

The compiler generates the array during compile-time and places it into the `.rodata` section of the executable, so it takes up an overall size of **8025 K**. Then, during execution, the function call doesn't happen, so it takes almost no time. To investigate that segment, you can use the following command: `objdump -s -j .rodata constexpr`.


## The same on run-time

For the runtime we have following numbers:
 * execution time: 2 624 651ns
 * compilation time: 660.069 ms
 * binary size: 18K

## Conclusion

`constexpr` is an excellent tool to accelerate computations when you have a function that can be evaluated
at compile time. However, it can also have significant drawbacks, particularly by increasing both
compile time and binary size.

