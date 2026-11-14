# [Decorating Christmas Tree (CHRISDECOR)](https://www.codechef.com/problems/CHRISDECOR)
- **Difficulty Rating**: 1102
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to decorate `N` leaves of a Christmas tree given a total of `X` large ornaments and `Y` small ornaments. There are two distinct ways to decorate a single leaf:

1.  **Type 1 Decoration**: Uses 1 large ornament and 3 small ornaments.
2.  **Type 2 Decoration**: Uses 2 large ornaments and 0 small ornaments.

We need to output "YES" if all `N` leaves can be decorated without exceeding the available ornaments, and "NO" otherwise.

## Intuition & Mathematical Observation

The core idea is to determine if there's a valid distribution of the two decoration types that satisfies all constraints. Let's define variables for the number of leaves decorated with each type:

*   Let `L1` be the number of leaves decorated using **Type 1** (1 large, 3 small).
*   Let `L2` be the number of leaves decorated using **Type 2** (2 large, 0 small).

From the problem statement, we know that all `N` leaves must be decorated. This gives us our first equation:
`L1 + L2 = N`
From this, we can express `L2` in terms of `N` and `L1`:
`L2 = N - L1`

Now, let's consider the constraints imposed by the available ornaments:

**1. Constraint on Small Ornaments (Y):**
Each `L1` leaf uses 3 small ornaments. `L2` leaves use 0 small ornaments.
The total small ornaments used must not exceed `Y`:
`3 * L1 + 0 * L2 <= Y`
`3 * L1 <= Y`

From this, we can derive an upper bound for `L1`:
`L1 <= Y / 3` (using integer division)

Additionally, `L1` cannot be more than the total number of leaves `N`, and it must be non-negative.
So, `0 <= L1 <= N`.

Combining these conditions, the maximum possible value for `L1` is:
`L1_max_possible = min(N, Y / 3)`

**2. Constraint on Large Ornaments (X):**
Each `L1` leaf uses 1 large ornament. Each `L2` leaf uses 2 large ornaments.
The total large ornaments used must not exceed `X`:
`1 * L1 + 2 * L2 <= X`

Now, substitute `L2 = N - L1` into this inequality:
`L1 + 2 * (N - L1) <= X`
`L1 + 2N - 2L1 <= X`
`2N - L1 <= X`

Rearranging this inequality to find a lower bound for `L1`:
`-L1 <= X - 2N`
`L1 >= 2N - X` (multiplying by -1 reverses the inequality sign)

Again, `L1` must be non-negative.
So, `L1 >= 0`.

Combining these conditions, the minimum required value for `L1` is:
`L1_min_required = max(0LL, 2 * N - X)`
(We use `0LL` to ensure the `max` function operates with `long long` types, preventing potential issues with type promotion).

**Existence of a Solution:**
For a valid solution to exist, there must be an integer value for `L1` that satisfies both the minimum requirement and the maximum possibility. This means:
`L1_min_required <= L1 <= L1_max_possible`

If `L1_min_required <= L1_max_possible`, then at least one such integer `L1` exists (for example, `L1_min_required` itself). If this condition holds, it's possible to decorate all `N` leaves, and we output "YES". Otherwise, it's impossible, and we output "NO".

**Data Type Consideration:**
The problem constraints state that `N, X, Y` can be up to `10^18`. Standard `int` in C++ typically handles values up to `2 * 10^9`. Therefore, `long long` must be used for `N, X, Y` and any intermediate calculations involving them (like `Y / 3` or `2 * N - X`) to prevent integer overflow.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The `solve()` function performs a fixed number of arithmetic operations (division, multiplication, subtraction, addition) and two `std::min`/`std::max` calls. These operations take constant time, regardless of the magnitude of `N, X, Y` (as long as they fit within `long long`). The `main()` function calls `solve()` `T` times. Therefore, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$
    The `solve()` function uses a few `long long` variables (`N, X, Y, L1_max_possible, L1_min_required`). These variables consume a constant amount of memory. The space used does not depend on the input values `N, X, Y`. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Required for std::min and std::max

void solve() {
    // Changed N, X, Y to long long to handle potentially large values and prevent overflow.
    long long N, X, Y;
    std::cin >> N >> X >> Y;

    // Let L1 be the number of leaves decorated with (1 large, 3 small) ornaments.
    // Let L2 be the number of leaves decorated with (2 large) ornaments.
    // Total leaves: L1 + L2 = N

    // Constraint 1: Total small ornaments used must not exceed Y.
    // Each L1 leaf uses 3 small ornaments. L2 leaves use 0 small ornaments.
    // So, 3 * L1 <= Y
    // This implies L1 <= Y / 3 (integer division)
    // Also, L1 cannot be more than N (total leaves) and must be non-negative.
    // So, 0 <= L1 <= std::min(N, Y / 3)
    // L1_max_possible also changed to long long.
    long long L1_max_possible = std::min(N, Y / 3);

    // Constraint 2: Total large ornaments used must not exceed X.
    // Each L1 leaf uses 1 large ornament. Each L2 leaf uses 2 large ornaments.
    // So, 1 * L1 + 2 * L2 <= X
    // Substitute L2 = N - L1:
    // L1 + 2 * (N - L1) <= X
    // L1 + 2N - 2L1 <= X
    // 2N - L1 <= X
    // Rearranging for L1:
    // L1 >= 2N - X
    // Also, L1 must be non-negative.
    // So, L1 >= std::max(0LL, 2 * N - X)
    // L1_min_required also changed to long long.
    // Used 0LL to ensure the literal 0 is treated as a long long.
    long long L1_min_required = std::max(0LL, 2 * N - X);

    // A solution exists if there is any integer L1 that satisfies both bounds.
    // This means L1_min_required <= L1_max_possible.
    if (L1_min_required <= L1_max_possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // T can remain int as it's up to 10^4
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```