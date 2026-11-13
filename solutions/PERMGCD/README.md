# [Permutation GCD (PERMGCD)](https://www.codechef.com/problems/PERMGCD)
- **Difficulty Rating**: 1328
- **Solved in**: 1 attempt(s)

## Problem Summary

Given two integers `N` and `X`, we need to find a permutation `P` of length `N` (containing numbers from `1` to `N` exactly once) such that the sum of `F_i` is exactly `X`. The values `F_i` are defined as:
- `F_1 = P_1`
- `F_i = gcd(F_{i-1}, P_i)` for `i > 1`

If no such permutation exists, we should print `-1`.
The constraints are `1 <= N <= 1000` and `1 <= X <= 2*N - 1`.

## Intuition & Mathematical Observation

Let's first understand the definition of `F_i`:
- `F_1 = P_1`
- `F_2 = gcd(F_1, P_2) = gcd(P_1, P_2)`
- `F_3 = gcd(F_2, P_3) = gcd(gcd(P_1, P_2), P_3) = gcd(P_1, P_2, P_3)`
In general, `F_i = gcd(P_1, P_2, ..., P_i)`.

From the properties of GCD, we know that `gcd(a, b) <= min(a, b)`. This implies:
1. `F_i <= F_{i-1}` for `i > 1`.
2. Since `P_j >= 1` for all `j`, `F_i` must also be at least `1`.
So, we have a non-increasing sequence: `P_1 = F_1 >= F_2 >= F_3 >= ... >= F_N >= 1`.

Now, let's determine the minimum and maximum possible values for the sum `S = F_1 + F_2 + ... + F_N`.

### Minimum Possible Sum

To minimize the sum, we want all `F_i` to be as small as possible, which is `1`.
Can we make all `F_i = 1`?
If we choose `P_1 = 1`, then `F_1 = 1`.
Then, `F_2 = gcd(F_1, P_2) = gcd(1, P_2) = 1`.
Similarly, `F_3 = gcd(F_2, P_3) = gcd(1, P_3) = 1`, and so on.
If `P_1 = 1`, all `F_i` will be `1`.
A simple permutation that achieves this is `P = [1, 2, 3, ..., N]`.
In this case, the sum `S = 1 + 1 + ... + 1` (`N` times) = `N`.
Therefore, the minimum possible sum is `N`. If `X < N`, it's impossible to achieve the target sum, so we should print `-1`.

### Maximum Possible Sum

To maximize the sum, we want `F_1` to be as large as possible, and subsequent `F_i` to be as large as possible.
`F_1 = P_1`. The maximum value `P_1` can take is `N`. So, `F_1 = N`.
Now consider `F_2 = gcd(F_1, P_2) = gcd(N, P_2)`. Since `P_2` must be a number from `[1, N]` different from `N`, `P_2` cannot be `N`. The largest possible value for `gcd(N, P_2)` (where `P_2 < N`) is `1` (e.g., if `P_2 = N-1`, then `gcd(N, N-1) = 1`).
If `F_2 = 1`, then `F_3 = gcd(F_2, P_3) = gcd(1, P_3) = 1`, and so on. All subsequent `F_i` will be `1`.
So, a permutation that maximizes the sum would have `F_1 = N` and `F_i = 1` for `i = 2, ..., N`.
The sum would be `N + 1 + 1 + ... + 1` (`N-1` times) = `N + (N-1) = 2*N - 1`.
A permutation that achieves this is `P = [N, N-1, N-2, ..., 1]`.
In this case, `F_1 = N`, `F_2 = gcd(N, N-1) = 1`, `F_3 = gcd(1, N-2) = 1`, and so on.
The sum is `2*N - 1`.
Therefore, the maximum possible sum is `2*N - 1`.

The problem constraints state `1 <= X <= 2*N - 1`. Combining our observations:
- If `X < N`, it's impossible.
- If `N <= X <= 2*N - 1`, a solution always exists.

### Constructing a Solution for `N <= X <= 2*N - 1`

We need to achieve a sum `X`. Our strategy is to construct a permutation where `F_1 = K` and `F_i = 1` for all `i = 2, ..., N`.
The sum for such a permutation would be `K + (N-1)*1 = K + N - 1`.
We want this sum to be equal to `X`.
So, `X = K + N - 1`, which implies `K = X - N + 1`.

Let's check the range of `K`:
- If `X = N` (minimum sum), `K = N - N + 1 = 1`.
- If `X = 2*N - 1` (maximum sum), `K = (2*N - 1) - N + 1 = N`.
Since `N <= X <= 2*N - 1`, `K` will always be an integer in the range `[1, N]`. This means `K` is a valid number to be `P_1`.

Now, we construct the permutation `P`:
1.  Set `P_1 = K`. This makes `F_1 = K`.
2.  To ensure `F_2 = 1` (and consequently all `F_i = 1` for `i >= 2`), we need `gcd(P_1, P_2) = gcd(K, P_2) = 1`.
    The simplest way to achieve this is to pick `P_2 = 1`, provided `K != 1`. If `K = 1`, then `P_1` is already `1`, and `F_1 = 1`, so `F_i` will be `1` for all `i` regardless of `P_2`.
3.  For the remaining elements `P_3, ..., P_N`, we can place the unused numbers from `[1, N]` in any order. Since `F_2` (or `F_1` if `K=1`) is already `1`, `F_i = gcd(1, P_i) = 1` for all subsequent `i`. A simple approach is to print the remaining numbers in increasing order.

Combining these steps:
- Print `K` (this is `P_1`).
- If `K != 1`, print `1` (this is `P_2`).
- Then, iterate from `i = 2` to `N`. If `i` is not `K` (and not `1` if `K != 1`), print `i`. This ensures all numbers from `2` to `N` (except `K` if `K` is in this range) are printed.

Let's trace with an example: `N=5, X=7`.
1. `X >= N` (7 >= 5), so a solution exists.
2. Calculate `K = X - N + 1 = 7 - 5 + 1 = 3`.
3. Print `P_1 = K = 3`. Output: `3`
4. Since `K != 1`, print `P_2 = 1`. Output: `3 1`
5. Iterate `i` from `2` to `N=5`:
   - `i = 2`: `2 != K` (2 != 3). Print `2`. Output: `3 1 2`
   - `i = 3`: `3 == K`. Skip.
   - `i = 4`: `4 != K`. Print `4`. Output: `3 1 2 4`
   - `i = 5`: `5 != K`. Print `5`. Output: `3 1 2 4 5`
The permutation is `[3, 1, 2, 4, 5]`.
Let's verify the sum:
`F_1 = P_1 = 3`
`F_2 = gcd(F_1, P_2) = gcd(3, 1) = 1`
`F_3 = gcd(F_2, P_3) = gcd(1, 2) = 1`
`F_4 = gcd(F_3, P_4) = gcd(1, 4) = 1`
`F_5 = gcd(F_4, P_5) = gcd(1, 5) = 1`
Sum = `3 + 1 + 1 + 1 + 1 = 7`. This matches `X`.

This construction correctly generates a permutation for all valid `X`.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading input `N` and `X` takes $O(1)$ time.
    -   Calculating `K` takes $O(1)$ time.
    -   Printing the permutation involves printing `N` numbers. The loop runs `N-1` times. Each print operation is $O(1)$.
    -   Thus, for each test case, the time complexity is $O(N)$.
    -   Given `T` test cases, the total time complexity is $O(T \cdot N)$. With `T, N <= 1000`, this is $1000 \cdot 1000 = 10^6$ operations, which is well within typical time limits.

-   **Space Complexity**:
    -   The solution only uses a few integer variables (`N`, `X`, `K`, loop counter `i`).
    -   No auxiliary data structures (like arrays or vectors) are used to store the permutation. The permutation is printed directly.
    -   Therefore, the space complexity is $O(1)$ (constant space).

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout

void solve() {
    int N;
    int X; // X can be up to 2*N-1. For N=1000, X can be 1999. int is sufficient.
    std::cin >> N >> X;

    // Observation 1: Minimum possible sum of GCDs.
    // If P_1 = 1, then F_1 = 1.
    // F_i = gcd(F_{i-1}, P_i). Since F_1 = 1, F_2 = gcd(1, P_2) = 1.
    // By induction, all F_i will be 1.
    // The sum would be 1 + 1 + ... + 1 (N times) = N.
    // Example: P = [1, 2, ..., N]. Sum = 1 + 1 + ... + 1 = N.
    // Thus, if X < N, it's impossible.
    if (X < N) {
        std::cout << -1 << "\n";
        return;
    }

    // Observation 2: Maximum possible sum of GCDs.
    // F_1 = P_1. To maximize F_1, P_1 should be N. So F_1 = N.
    // F_2 = gcd(F_1, P_2) = gcd(N, P_2). To maximize F_2, P_2 should be a multiple of N,
    // but P_2 must be from {1, ..., N-1}. The largest possible gcd(N, P_2) for P_2 < N is 1
    // (e.g., if P_2 = N-1, gcd(N, N-1) = 1).
    // If F_2 = 1, then F_3 = gcd(1, P_3) = 1, and so on.
    // So, the maximum sum is N (for F_1) + 1 (for F_2) + ... + 1 (for F_N) = N + (N-1) = 2*N - 1.
    // Example: P = [N, N-1, N-2, ..., 1]. Sum = N + 1 + 1 + ... + 1 = 2*N - 1.
    // The problem constraints state 1 <= X <= 2*N - 1.
    // Combined with the minimum sum, this means a solution always exists if N <= X <= 2*N - 1.

    // Construction Strategy:
    // We aim for a permutation where F_1 = K and F_i = 1 for i = 2, ..., N.
    // The sum for such a permutation would be K + (N-1)*1 = K + N - 1.
    // We need this sum to be equal to X.
    // So, X = K + N - 1, which implies K = X - N + 1.

    // Let's check the range of K:
    // If X = N (minimum sum), K = N - N + 1 = 1.
    // If X = 2*N - 1 (maximum sum), K = (2*N - 1) - N + 1 = N.
    // So, K will always be an integer in the range [1, N], making it a valid choice for P_1.

    int K = X - N + 1;

    // Construct the permutation P:
    // 1. P_1 = K. This sets F_1 = K.
    std::cout << K;

    // 2. To make F_2 = 1 (and thus all subsequent F_i = 1), we need gcd(P_1, P_2) = 1.
    //    If K is not 1, we can set P_2 = 1. Then gcd(K, 1) = 1.
    //    If K is 1, then P_1 is already 1. We don't need to print 1 again.
    if (K != 1) {
        std::cout << " " << 1;
    }

    // 3. For the remaining elements, we print numbers from 2 to N, excluding K (and 1 if K != 1).
    //    Since F_2 (or F_1 if K=1) is already 1, any subsequent P_i will result in F_i = 1.
    //    (e.g., F_3 = gcd(F_2, P_3) = gcd(1, P_3) = 1).
    //    Printing them in increasing order (2, 3, ..., N, skipping K) is simple and valid.
    for (int i = 2; i <= N; ++i) {
        if (i != K) { // Ensure we don't print K again.
            std::cout << " " << i;
        }
    }
    std::cout << "\n";
}

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```