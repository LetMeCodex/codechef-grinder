# [Equal Integers (INCREAR)](https://www.codechef.com/problems/INCREAR)
- **Difficulty Rating**: 852
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations to make two integers, `X` and `Y`, equal. We are given two types of operations, each costing 1:
1. Increment `X` by 1 (`X := X + 1`).
2. Increment `Y` by 2 (`Y := Y + 2`).

We need to process `T` test cases, and for each test case, output the minimum total operations. The values of `X` and `Y` can be up to $10^9$.

## Intuition & Mathematical Observation

Let `a` be the number of times we apply the operation `X := X + 1`, and `b` be the number of times we apply the operation `Y := Y + 2`. Our goal is to minimize the total operations, which is `a + b`, such that the final values of `X` and `Y` are equal.

We can analyze this problem by considering two main cases:

### Case 1: `X <= Y`

If `X` is already less than or equal to `Y`, our objective is to make them equal.
- If we use the `Y := Y + 2` operation, `Y` will become even larger, increasing the difference `Y - X`. This would require `X` to be incremented even more to catch up, which is inefficient.
- The most direct and efficient way to make `X` equal to `Y` when `X <= Y` is to only increment `X`.
- We need to increment `X` by `Y - X` to make it equal to `Y`.
- Each `X := X + 1` operation costs 1.
- Therefore, the minimum number of operations is `Y - X`.

**Example:** `X = 5, Y = 7`
Operations needed: `7 - 5 = 2`. (Increment `X` twice: `5 -> 6 -> 7`)

### Case 2: `X > Y`

If `X` is greater than `Y`, we must increase `Y` to eventually make it equal to or greater than `X`. We can also increase `X`.
Let the final equal value be `V`.
After `a` operations of `X := X + 1` and `b` operations of `Y := Y + 2`, we will have:
`V = X + a`
`V = Y + 2b`

From these equations, we can write `X + a = Y + 2b`.
We want to minimize `a + b`.
Substitute `a = Y + 2b - X` into `a + b`:
`Total Operations = (Y + 2b - X) + b = Y + 3b - X`

To minimize `Y + 3b - X`, since `X` and `Y` are fixed, we need to minimize `3b`, which means minimizing `b`.

What is the minimum value `b` can take?
Since `a` represents the number of `X := X + 1` operations, `a` cannot be negative.
So, `a = Y + 2b - X >= 0`.
This implies `2b >= X - Y`.

Let `diff = X - Y`. Since `X > Y`, `diff` will be a positive integer.
We need `2b >= diff`.
The smallest integer `b` that satisfies this condition is `ceil(diff / 2.0)`.
In integer arithmetic, for any positive integer `D`, `ceil(D / 2.0)` can be calculated as `(D + 1) / 2`.
So, the minimum number of `Y := Y + 2` operations is `b = ( (X - Y) + 1 ) / 2`.

Once we have the minimum `b`:
1. Calculate the final value `Y` would reach: `Y_final = Y + 2 * b`.
2. Calculate the number of `X := X + 1` operations needed to make `X` equal to `Y_final`: `a = Y_final - X`. (Note: `a` will be non-negative because `b` was chosen such that `Y + 2b >= X`).
3. The total minimum operations will be `a + b`.

**Example:** `X = 10, Y = 5`
1. `diff = X - Y = 10 - 5 = 5`.
2. Minimum `b = (5 + 1) / 2 = 3`.
3. `Y_final = Y + 2 * b = 5 + 2 * 3 = 5 + 6 = 11`.
4. `a = Y_final - X = 11 - 10 = 1`.
5. Total operations = `a + b = 1 + 3 = 4`.

**Example:** `X = 10, Y = 6`
1. `diff = X - Y = 10 - 6 = 4`.
2. Minimum `b = (4 + 1) / 2 = 2`.
3. `Y_final = Y + 2 * b = 6 + 2 * 2 = 6 + 4 = 10`.
4. `a = Y_final - X = 10 - 10 = 0`.
5. Total operations = `a + b = 0 + 2 = 2`.

This logic covers all cases and finds the minimum operations.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution involves reading two integers, performing a comparison, and a few basic arithmetic operations (subtraction, addition, integer division). All these operations take constant time. Since there are `T` test cases, the total time complexity will be $O(T)$.

-   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of variables (`X`, `Y`, `diff`, `a`, `b`, `Y_final`) to store intermediate values. The memory usage does not depend on the magnitude of `X` or `Y` or the number of operations. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout

void solve() {
    long long X, Y; // Using long long for X and Y to safely handle values up to 10^9
    std::cin >> X >> Y;

    if (X <= Y) {
        // If X is less than or equal to Y, the most efficient way to make them equal
        // is to only increment X. Each X := X + 1 operation costs 1.
        // We need to increment X by (Y - X) to make it equal to Y.
        // The number of operations will be Y - X.
        std::cout << Y - X << "\n";
    } else { // X > Y
        // If X is greater than Y, we must increase Y (and possibly X) to make them equal.
        // Let 'b' be the number of Y := Y + 2 operations.
        // Let 'a' be the number of X := X + 1 operations.
        // We want to reach a state where X + a = Y + 2b, minimizing a + b.

        // The final value Y + 2b must be at least X.
        // So, Y + 2b >= X  =>  2b >= X - Y.
        // Let diff = X - Y. We need 2b >= diff.
        // The minimum integer 'b' satisfying this is ceil(diff / 2.0).
        // For any positive integer D, ceil(D / 2.0) can be calculated using integer division
        // as (D + 1) / 2.
        long long diff = X - Y;
        long long b = (diff + 1) / 2; // Minimum Y := Y+2 operations

        // After 'b' operations, Y will become Y_final = Y + 2 * b.
        // Now, X needs to be incremented to match Y_final.
        // The number of X := X + 1 operations needed is 'a' = Y_final - X.
        // Since b was chosen such that Y_final >= X, 'a' will be non-negative.
        long long Y_final = Y + 2 * b;
        long long a = Y_final - X;
        
        // The total minimum operations is the sum of 'a' and 'b'.
        std::cout << a + b << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input,
    // further speeding up I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {  // Loop T times, solving each test case
        solve();
    }

    return 0;
}
```