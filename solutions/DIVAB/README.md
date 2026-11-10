# To Divide or Not To Divide (DIVAB)
- **Difficulty Rating**: 1224
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the smallest integer $X$ such that $X \ge n$, $X$ is divisible by $a$, and $X$ is NOT divisible by $b$. If no such integer exists, we should output -1.

## Intuition & Mathematical Observation

We are looking for the smallest number $X$ satisfying three conditions:
1. $X \ge n$
2. $X \pmod a = 0$
3. $X \pmod b \ne 0$

Let's break down how to find such an $X$.

**Step 1: Find the smallest multiple of `a` that is greater than or equal to `n`.**
Any number $X$ that satisfies condition 2 must be a multiple of $a$. To satisfy condition 1 ($X \ge n$) and condition 2 ($X \pmod a = 0$) simultaneously, the smallest possible candidate for $X$ would be the smallest multiple of $a$ that is at least $n$.

If $n$ is already a multiple of $a$, then $n$ itself is the smallest candidate.
If $n$ is not a multiple of $a$, we need to find the next multiple of $a$ after $n$. This can be calculated as follows:
Let $n = q \cdot a + r$, where $0 < r < a$.
The smallest multiple of $a$ greater than $n$ is $(q+1) \cdot a$.
This can be computed using integer division as `(n / a + 1) * a`.
A more general way to compute the smallest multiple of `a` that is $\ge n$ is `((n + a - 1) / a) * a`.
However, a simpler check is: if `n % a == 0`, the candidate is `n`. Otherwise, it's `(n / a + 1) * a`. Let's call this `start_candidate`.

**Step 2: Check the divisibility by `b`.**

Now we have `start_candidate`, which is the smallest number $\ge n$ and divisible by $a$. We need to check if it satisfies condition 3 ($X \pmod b \ne 0$).

*   **Case 1: `start_candidate` is NOT divisible by `b`.**
    If `start_candidate % b != 0`, then `start_candidate` satisfies all three conditions. Since we found the *smallest* multiple of $a$ that is $\ge n$, and it also satisfies the condition of not being divisible by $b$, this `start_candidate` is our answer.

*   **Case 2: `start_candidate` IS divisible by `b`.**
    If `start_candidate % b == 0`, then `start_candidate` does not satisfy condition 3. We need to find the *next* smallest number that is $\ge n$, divisible by $a$, and not divisible by $b$.
    The numbers we are considering are multiples of $a$: `start_candidate`, `start_candidate + a`, `start_candidate + 2*a`, `start_candidate + 3*a`, and so on.
    We know `start_candidate` is divisible by both $a$ and $b$.
    We need to find the smallest $k \ge 1$ such that `(start_candidate + k * a) % b != 0`.

    Let's analyze the condition `(start_candidate + k * a) % b == 0`.
    Since `start_candidate % b == 0`, this simplifies to `(k * a) % b == 0`.
    This means `k * a` must be a multiple of $b$.
    The smallest positive integer $k$ for which `k * a` is a multiple of $b$ occurs when `k * a` is the least common multiple (LCM) of $a$ and $b$.
    So, `k * a = lcm(a, b)`.
    This implies `k = lcm(a, b) / a`.
    We know that `lcm(a, b) = (a * b) / gcd(a, b)`.
    Therefore, `k = ((a * b) / gcd(a, b)) / a = b / gcd(a, b)`.

    Let $P = b / gcd(a, b)$. Then `k * a` is divisible by $b$ if and only if $k$ is a multiple of $P$.
    We are looking for the smallest $k \ge 1$ such that `(start_candidate + k * a) % b != 0`. This means we need the smallest $k \ge 1$ such that $k$ is NOT a multiple of $P$.

    Now, consider the scenario where `start_candidate % b == 0`.
    If `a % b == 0`, it means $b$ divides $a$. In this case, any multiple of $a$ is also a multiple of $b$. So, no number can be divisible by $a$ and NOT divisible by $b$. Thus, if `a % b == 0`, the answer is -1. This is a crucial edge case.

    If `a % b != 0` (which must be true if we reach this part of the logic, as the `a % b == 0` case is handled separately), then $b$ does not divide $a$. This implies `gcd(a, b) < b`.
    Therefore, $P = b / gcd(a, b) > 1$.
    Since $P > 1$, the smallest positive integer $k$ that is NOT a multiple of $P$ is $k=1$.
    This means that `start_candidate + 1 * a` will not be divisible by $b$.
    Let's verify: `(start_candidate + a) % b = (start_candidate % b + a % b) % b`.
    Since `start_candidate % b == 0`, this becomes `(0 + a % b) % b = a % b`.
    Because we are in the case where `a % b != 0`, `a % b` is a non-zero remainder.
    So, `(start_candidate + a) % b != 0`.
    Thus, `start_candidate + a` is the smallest number greater than `start_candidate` that is divisible by $a$, and it is not divisible by $b$. This is our answer.

**Summary of Logic:**
1. Calculate `start_candidate`: the smallest multiple of `a` such that `start_candidate >= n`.
   - If `n % a == 0`, `start_candidate = n`.
   - Else, `start_candidate = (n / a + 1) * a`.
2. Check if `a` is divisible by `b`. If `a % b == 0`, output -1. This is because any multiple of `a` will also be a multiple of `b`, making it impossible to satisfy the condition $X \pmod b \ne 0$.
3. If `start_candidate % b != 0`, output `start_candidate`.
4. If `start_candidate % b == 0`, output `start_candidate + a`.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a few arithmetic operations (division, modulo, addition, multiplication) and a conditional check. The `gcd` function, if implemented using the Euclidean algorithm, also takes logarithmic time with respect to the input numbers. However, since the numbers are within the `long long` range and the operations are constant time for fixed-size integers, the overall time complexity is effectively constant for each test case.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store input values and intermediate results, regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <numeric> // For std::gcd in C++17, but we implement our own for broader compatibility

// Function to compute GCD using Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

// Function to compute LCM (not strictly needed for the final logic, but good for understanding)
// long long lcm(long long a, long long b) {
//     if (a == 0 || b == 0) return 0;
//     return std::abs(a * b) / gcd(a, b);
// }

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long a, b, n;
        std::cin >> a >> b >> n;

        // We are looking for the smallest number X such that:
        // 1. X >= n
        // 2. X is divisible by a (X % a == 0)
        // 3. X is NOT divisible by b (X % b != 0)

        // First, find the smallest multiple of 'a' that is >= 'n'.
        // If n is already a multiple of a, then start_candidate = n.
        // Otherwise, start_candidate = n + (a - (n % a)) % a.
        // A simpler way using integer division:
        long long start_candidate;
        if (n % a == 0) {
            start_candidate = n;
        } else {
            // This calculates the next multiple of 'a' after 'n'.
            // Example: n=10, a=3. n/a = 3. (3+1)*3 = 12.
            // Example: n=12, a=3. n%a == 0, so start_candidate = 12.
            start_candidate = (n / a + 1) * a;
        }

        // Now, we need to check multiples of 'a' starting from start_candidate.
        // We want k * a, where k * a >= n and k * a % b != 0.

        // Crucial edge case: If 'a' is a multiple of 'b' (i.e., b divides a).
        // This means any number divisible by 'a' is also divisible by 'b'.
        // If a % b == 0, then any number divisible by 'a' is also divisible by 'b'.
        // In this scenario, no number can satisfy both conditions (divisible by 'a' AND not divisible by 'b').
        // So, if a % b == 0, the answer is -1.
        if (a % b == 0) {
            std::cout << -1 << "\n";
            continue; // Move to the next test case
        }

        // If we reach here, it means a % b != 0.
        // We have 'start_candidate', the smallest multiple of 'a' >= n.
        // Check if 'start_candidate' satisfies the condition of not being divisible by 'b'.
        if (start_candidate % b != 0) {
            // If it's not divisible by 'b', then 'start_candidate' is our answer.
            std::cout << start_candidate << "\n";
        } else {
            // If 'start_candidate' IS divisible by 'b', we need to find the next multiple of 'a'
            // that is NOT divisible by 'b'.
            // The sequence of candidates is: start_candidate, start_candidate + a, start_candidate + 2*a, ...
            // We know start_candidate % b == 0.
            // We need the smallest k >= 1 such that (start_candidate + k * a) % b != 0.
            // This simplifies to finding the smallest k >= 1 such that (k * a) % b != 0.
            //
            // As derived in the thought process:
            // (k * a) % b == 0 if and only if k is a multiple of (b / gcd(a, b)).
            // Let P = b / gcd(a, b).
            // Since a % b != 0, we know b does not divide a, so gcd(a, b) < b.
            // This implies P = b / gcd(a, b) > 1.
            //
            // We need the smallest k >= 1 such that k is NOT a multiple of P.
            // Since P > 1, the smallest such k is 1.
            //
            // Therefore, start_candidate + 1 * a is the next multiple of 'a'
            // and it will not be divisible by 'b'.
            std::cout << start_candidate + a << "\n";
        }
    }
    return 0;
}
```