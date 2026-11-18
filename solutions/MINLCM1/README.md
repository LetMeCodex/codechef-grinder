# [Min Max LCM (MINLCM1)](https://www.codechef.com/problems/MINLCM1)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum and maximum possible values of `LCM(i, j)` (Least Common Multiple of `i` and `j`) given two integers `X` and `K`. The constraints for `i` and `j` are `X <= i < j <= N`, where `N = X * K`. We are given that `X >= 1` and `K >= 2`. The product `X * K` will not exceed `10^9`.

## Intuition & Mathematical Observation

Let `N = X * K`. We are looking for `LCM(i, j)` such that `X <= i < j <= N`.
Recall the formula for LCM: `LCM(i, j) = (i * j) / GCD(i, j)`.

### 1. Minimum LCM

To minimize `LCM(i, j)`, we want to choose `i` and `j` to be as small as possible, and ideally, have a large `GCD(i, j)`.

*   The smallest possible value for `i` is `X`. Let's try to fix `i = X`.
*   Now we need to find the smallest `j` such that `X < j <= N` and `LCM(X, j)` is minimized.
*   Consider the pair `(i, j) = (X, 2X)`.
    *   **Validity Check**:
        *   Is `X <= X`? Yes.
        *   Is `X < 2X`? Yes, since `X \ge 1`.
        *   Is `2X <= N`? Yes, because `N = X \cdot K` and the problem states `K \ge 2`. Therefore, `N \ge X \cdot 2 = 2X`.
    *   For this pair, `LCM(X, 2X) = 2X`. This is a valid candidate for the minimum LCM.

*   Can we achieve an LCM smaller than `2X`?
    *   If `i = X`:
        *   If `j` is a multiple of `X` (i.e., `j = mX` for some integer `m`), then `LCM(X, mX) = mX`. Since `j > X`, `m` must be at least 2. The smallest such value is `2X` (when `m=2`).
        *   If `j` is not a multiple of `X`, then `GCD(X, j)` will be a proper divisor of `X` (or 1). `LCM(X, j) = (X \cdot j) / GCD(X, j)`. Since `j > X`, `LCM(X, j)` will be at least `j`. For example, `LCM(3, 4) = 12`, `LCM(3, 5) = 15`. Both are greater than `2X = 6`.
    *   If `i > X`:
        *   Then `i \ge X + 1`.
        *   The smallest possible LCM for any `i` is `2i` (achieved with `j = 2i`). Since `i > X`, `2i > 2X`.
*   Therefore, the minimum possible LCM is `2X`.

### 2. Maximum LCM

To maximize `LCM(i, j)`, we want to choose `i` and `j` to be as large as possible, and ideally, have `GCD(i, j) = 1` (to avoid dividing the product `i * j` by a large number).

*   The largest possible value for `j` is `N`. Let's try to fix `j = N`.
*   Now we need to find the largest `i` such that `X \le i < N` and `LCM(i, N)` is maximized.
*   The largest possible `i` less than `N` is `N - 1`.
*   Consider the pair `(i, j) = (N - 1, N)`.
    *   **Validity Check**:
        *   Is `X <= N - 1`? Yes. We know `N = X \cdot K` and `K \ge 2`. So `N \ge 2X`. This implies `N - 1 \ge 2X - 1`. Since `X \ge 1`, `2X - 1 \ge X` (e.g., if `X=1`, `2(1)-1=1`, so `1 \ge 1`; if `X=2`, `2(2)-1=3`, so `3 \ge 2`). Thus, `X \le N - 1` is always true.
        *   Is `N - 1 < N`? Yes, trivially true.
        *   Is `N <= N`? Yes.
    *   For this pair, `GCD(N - 1, N) = 1` because any two consecutive integers are coprime.
    *   Therefore, `LCM(N - 1, N) = ((N - 1) \cdot N) / GCD(N - 1, N) = (N - 1) \cdot N / 1 = (N - 1) \cdot N`.
*   This product `(N - 1) \cdot N` is the largest possible product of two distinct integers less than or equal to `N`. Since their GCD is 1, this choice maximizes the LCM. Any other pair `(i, j)` would either have a smaller product `i \cdot j` or a `GCD(i, j) > 1` (which would reduce the LCM), or both.
*   Therefore, the maximum possible LCM is `(N - 1) \cdot N`.

### Data Types

*   `X` and `K` can be up to `10^8`.
*   `N = X * K` can be up to `10^9` (as per problem constraints, `X*K <= 10^9`).
*   `min_lcm = 2 * X` can be up to `2 * 10^8`, which fits comfortably in a `long long`.
*   `max_lcm = (N - 1) * N` can be up to approximately `(10^9 - 1) * 10^9 \approx 10^{18}`. This value **requires** a `long long` data type to prevent overflow.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution performs a constant number of arithmetic operations (multiplication, subtraction) and input/output operations. If there are `T` test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution uses a few variables (`T`, `X`, `K`, `N`, `min_lcm`, `max_lcm`) to store values. This is a constant amount of memory, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of testcases

    while (T--) {
        long long X, K;
        std::cin >> X >> K; // Read X and K for the current testcase

        // Calculate N = X * K.
        // N can be up to 10^9 (10^8 * 10^8 is not possible due to X*K <= 10^9 constraint),
        // so 'long long' is appropriate for N to avoid overflow if X or K are large.
        long long N = X * K;

        // Calculate the minimum LCM:
        // As derived, the minimum LCM is 2 * X.
        // This is achieved by picking i = X and j = 2X.
        // This pair is always valid because:
        // 1. X <= X (true)
        // 2. X < 2X (true for X >= 1)
        // 3. 2X <= N (true because N = X * K and K >= 2, so N >= 2X)
        // The result 2*X can be up to 2 * 10^8, which fits in 'long long'.
        long long min_lcm = 2 * X;

        // Calculate the maximum LCM:
        // As derived, the maximum LCM is (N - 1) * N.
        // This is achieved by picking i = N - 1 and j = N.
        // This pair is always valid because:
        // 1. X <= N - 1 (true, as N >= 2X and X >= 1 implies N-1 >= X)
        // 2. N - 1 < N (true)
        // 3. N <= N (true)
        // For consecutive integers, GCD(N-1, N) = 1, which minimizes the denominator
        // in LCM(i, j) = (i * j) / GCD(i, j).
        // The product (N-1) * N can be up to (10^9 - 1) * 10^9 approx 10^18,
        // which requires 'long long'.
        long long max_lcm = (N - 1) * N;

        // Output the minimum and maximum LCM values, separated by a space,
        // followed by a newline character.
        std::cout << min_lcm << " " << max_lcm << "\n";
    }

    return 0; // Indicate successful execution
}
```