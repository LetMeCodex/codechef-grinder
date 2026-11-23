# [The product mystery (PRODUCT)](https://www.codechef.com/problems/PRODUCT)
- **Difficulty Rating**: 1180
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to find the smallest positive integer `A` for given positive integers `B` and `C`, such that the product `A * B` is a multiple of `C`. We need to solve this for `T` test cases. The constraints are `T` up to `10^5`, and `B`, `C` up to `10^9`.

## Intuition & Mathematical Observation
The core of the problem lies in the condition that `A * B` must be a multiple of `C`. This can be expressed mathematically as:
`A * B = k * C` for some positive integer `k`.

We are looking for the *smallest positive integer A*.

Let's use the concept of the Greatest Common Divisor (GCD). Let `g = gcd(B, C)`.
We can express `B` and `C` in terms of `g` and their coprime parts:
`B = g * B'`
`C = g * C'`
where `B'` and `C'` are coprime integers (i.e., `gcd(B', C') = 1`).

Now, substitute these expressions back into our original equation `A * B = k * C`:
`A * (g * B') = k * (g * C')`

Since `g` is a positive integer, we can divide both sides of the equation by `g`:
`A * B' = k * C'`

This equation tells us that `A * B'` must be a multiple of `C'`. Since `B'` and `C'` are coprime (they share no common prime factors), for `A * B'` to be divisible by `C'`, `A` must contain all the prime factors of `C'`. The smallest positive integer `A` that satisfies this condition is `C'` itself.

Therefore, `A = C'`.
From our earlier definitions, we know that `C' = C / g`.
Substituting `g = gcd(B, C)`, we get the final formula for `A`:
`A = C / gcd(B, C)`

This formula directly provides the smallest positive integer `A` that satisfies the problem's condition.

**Example:**
Let `B = 6` and `C = 9`.
1. Calculate `gcd(B, C)`: `gcd(6, 9) = 3`.
2. Calculate `A`: `A = C / gcd(B, C) = 9 / 3 = 3`.
3. Check: `A * B = 3 * 6 = 18`. Is `18` a multiple of `C=9`? Yes, `18 = 2 * 9`. This is indeed the smallest positive `A`.

## Complexity Analysis
- **Time Complexity**: The dominant operation for each test case is the calculation of the Greatest Common Divisor (GCD) using the Euclidean algorithm. The time complexity of `gcd(B, C)` is `O(log(min(B, C)))`. Since there are `T` test cases, the total time complexity will be `O(T * log(min(B, C)))`. Given `T <= 10^5` and `B, C <= 10^9`, `log(10^9)` (base 2) is approximately 30. Thus, the total operations are roughly `10^5 * 30 = 3 * 10^6`, which is very efficient and well within typical time limits (usually `10^8` operations per second).
- **Space Complexity**: The solution uses a constant number of variables to store `B`, `C`, `common_divisor`, `A`, and `T`. No data structures that grow with input size are used. Therefore, the space complexity is `O(1)`.

## Solution Code
```cpp
#include <iostream> // For standard input/output operations (cin, cout)
#include <numeric>  // For std::gcd (though we'll implement our own for robustness)
#include <algorithm> // For std::swap, used in the custom GCD function

// Custom GCD function using the Euclidean algorithm
// This is a robust and efficient implementation, often preferred in competitive programming
// to avoid potential platform-specific issues with std::gcd or older C++ standards.
long long custom_gcd(long long a, long long b) {
    while (b) { // Continue as long as b is not zero
        a %= b; // Replace a with the remainder of a divided by b
        std::swap(a, b); // Swap a and b. The old b becomes the new a, and the remainder becomes the new b.
    }
    return a; // When b becomes zero, a holds the greatest common divisor
}

void solve() {
    long long B, C; // Declare B and C as long long to handle values up to 10^9
    std::cin >> B >> C; // Read B and C for the current test case
    
    // Calculate the greatest common divisor of B and C using our custom function
    long long common_divisor = custom_gcd(B, C); 
    
    // According to the mathematical derivation, the minimum positive A is C / gcd(B, C)
    long long A = C / common_divisor; 
    
    std::cout << A << "\n"; // Output the result followed by a newline character
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for problems with a large number of test cases (T=10^5).
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T; // Declare T for the number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful program execution
}
```