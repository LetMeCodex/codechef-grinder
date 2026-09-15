# [Primality Test (PRB01)](https://www.codechef.com/problems/PRB01)
- **Difficulty Rating**: 794
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine whether a given integer `N` is a prime number. We need to perform this check for `T` independent test cases. For each `N`, the output should be "yes" if `N` is prime, and "no" otherwise. The constraints typically involve `N` up to $10^6$ and `T` up to $10^5$.

## Intuition & Mathematical Observation

A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself. Based on this definition, we can derive an efficient primality test:

1.  **Numbers less than or equal to 1 are not prime**: By definition, prime numbers must be greater than 1. So, `N <= 1` immediately means `N` is not prime.
2.  **The number 2 is prime**: It's the smallest prime number.
3.  **Even numbers greater than 2 are not prime**: Any even number `N > 2` is divisible by 2 (in addition to 1 and itself), so it cannot be prime. This allows us to quickly eliminate all even numbers except 2.
4.  **Optimization for odd numbers**: For any odd number `N`, we only need to check for odd divisors. Furthermore, we only need to check for divisors up to the square root of `N`.
    *   **Why `sqrt(N)`?**: If `N` has a divisor `d` such that `d > sqrt(N)`, then there must be another divisor `k = N / d` such that `k < sqrt(N)`. For example, if `N = 100` and `d = 20` (which is `> sqrt(100) = 10`), then `k = 100 / 20 = 5` (which is `< 10`). So, if `N` is composite, it must have at least one divisor less than or equal to `sqrt(N)`.
    *   **Avoiding floating-point `sqrt()`**: Instead of calculating `i <= sqrt(N)`, which involves floating-point operations and potential precision issues, we can use the equivalent integer comparison `i * i <= N`. This is generally faster and safer.

Combining these observations, the algorithm becomes:
*   Handle `N <= 1` (not prime).
*   Handle `N == 2` (prime).
*   Handle `N % 2 == 0` (not prime, for `N > 2`).
*   For odd `N`, iterate `i` from 3 up to `sqrt(N)` (or `i * i <= N`), incrementing `i` by 2 in each step. If `N % i == 0` for any `i`, then `N` is not prime.
*   If the loop completes without finding any divisors, `N` is prime.

## Complexity Analysis

*   **Time Complexity**: $O(T \cdot \sqrt{N_{max}})$
    *   The `isPrime` function performs a few constant-time checks initially.
    *   The main loop iterates from `i = 3` up to `sqrt(N)`, incrementing `i` by 2. This means the loop runs approximately `sqrt(N) / 2` times.
    *   Each iteration involves a modulo operation and a comparison, both of which are constant-time operations.
    *   Therefore, the time complexity for a single call to `isPrime(N)` is $O(\sqrt{N})$.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot \sqrt{N_{max}})$, where `N_{max}` is the maximum possible value of `N` across all test cases. Given `N_{max} = 10^6` and `T_{max} = 10^5`, the total operations would be roughly $10^5 \times \sqrt{10^6} = 10^5 \times 10^3 = 10^8$, which is efficient enough for the given constraints.

*   **Space Complexity**: $O(1)$
    *   The solution uses a fixed number of variables (`T`, `N`, `i`) regardless of the input size. No auxiliary data structures that grow with `N` or `T` are used. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, cmath, etc. for convenience

// Use the standard namespace as requested by competitive programming conventions
using namespace std;

/**
 * @brief Checks if a given integer N is a prime number.
 *
 * A prime number is a natural number greater than 1 that has no positive divisors
 * other than 1 and itself.
 *
 * @param n The integer to be tested for primality.
 * @return true if N is prime, false otherwise.
 */
bool isPrime(int n) {
    // According to the problem statement, 1 is not a prime number.
    // Numbers less than or equal to 1 are not prime.
    if (n <= 1) {
        return false;
    }
    // 2 is the only even prime number.
    if (n == 2) {
        return true;
    }
    // All other even numbers (greater than 2) are not prime,
    // as they are divisible by 2.
    if (n % 2 == 0) {
        return false;
    }
    // For odd numbers, we only need to check for odd divisors
    // starting from 3 up to the square root of n.
    // If n has a divisor greater than sqrt(n), it must also have a
    // corresponding divisor smaller than sqrt(n).
    // We use `i * i <= n` instead of `i <= sqrt(n)` to avoid
    // floating-point calculations and potential precision issues.
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            // If we find any divisor, n is not prime.
            return false;
        }
    }
    // If no divisors were found, n is a prime number.
    return true;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases.
    cin >> T;

    // Loop through each test case.
    while (T--) {
        int N;
        // Read the integer to be tested for primality.
        cin >> N;

        // Call the isPrime function and print the result.
        if (isPrime(N)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
```