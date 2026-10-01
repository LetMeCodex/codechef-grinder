# [Hackerman (PRIMEDICE)](https://www.codechef.com/problems/PRIMEDICE)
- **Difficulty Rating**: 643
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game between Alice and Bob involving two standard six-sided dice. Alice rolls the first die, and Bob rolls the second. They then calculate the sum of the numbers shown on their dice. If this sum is a prime number, Alice wins. Otherwise, Bob wins. We are given the results of Alice's and Bob's dice rolls for several test cases and need to determine the winner for each case.

## Intuition & Mathematical Observation

The core of the problem lies in determining whether a given number (the sum of the two dice rolls) is prime.

1.  **Dice Rolls**: A standard six-sided die can show numbers from 1 to 6.
2.  **Sum of Rolls**: If Alice rolls `a` and Bob rolls `b`, the sum is `a + b`. The minimum possible sum is `1 + 1 = 2`, and the maximum possible sum is `6 + 6 = 12`.
3.  **Prime Check**: We need a way to check if a number `N` is prime. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
    *   The most straightforward way to check for primality is to iterate from 2 up to the square root of `N`. If any number in this range divides `N` evenly, then `N` is not prime. If no such divisor is found, `N` is prime.
    *   Since the maximum sum is only 12, the numbers we need to check for primality are very small (2, 3, 4, ..., 12).
    *   The prime numbers in this range are: 2, 3, 5, 7, 11.

The strategy is simple:
1.  Read Alice's roll (`a`) and Bob's roll (`b`).
2.  Calculate their sum `S = a + b`.
3.  Check if `S` is a prime number using a primality test function.
4.  If `S` is prime, print "Alice".
5.  Otherwise, print "Bob".

## Complexity Analysis

*   **Time Complexity**:
    *   The `isPrime(int n)` function iterates from `i = 2` up to `sqrt(n)`. In the worst case, this takes $O(\sqrt{n})$ time.
    *   In this problem, the maximum possible value for `n` (the sum of two dice rolls) is `6 + 6 = 12`.
    *   Therefore, `sqrt(n)` is at most `sqrt(12)` which is approximately `3.46`. This means the `isPrime` function performs a very small, constant number of operations (at most 2-3 iterations).
    *   Let's denote the time taken by `isPrime` for `n <= 12` as $O(C)$, where $C$ is a small constant.
    *   The `main` function runs for `t` test cases. In each test case, it performs constant time operations (reading inputs, summing) and then calls `isPrime(sum)`.
    *   Thus, the total time complexity is $O(t \cdot C)$, which simplifies to $O(t)$.

*   **Space Complexity**:
    *   The solution uses a few integer variables (`t`, `a`, `b`, `sum`, `n`, `i`) to store inputs and intermediate calculations.
    *   No dynamic data structures or arrays are used that scale with input size.
    *   Therefore, the space complexity is $O(1)$ (constant space).

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int a, b;
        std::cin >> a >> b; // Read the dice rolls for Alice and Bob

        int sum = a + b; // Calculate the sum of the dice rolls

        // Check if the sum is a prime number
        if (isPrime(sum)) {
            std::cout << "Alice\n"; // Alice wins if the sum is prime
        } else {
            std::cout << "Bob\n"; // Bob wins otherwise
        }
    }

    return 0;
}

```