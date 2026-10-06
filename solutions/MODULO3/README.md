# [Divisible by 3 (MODULO3)](https://www.codechef.com/problems/MODULO3)
- **Difficulty Rating**: 978
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to make at least one of two given integers, `A` and `B`, divisible by 3. The allowed operation is: choose one of the numbers (say `X`) and replace it with `|X - Y|`, where `Y` is the other number.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how the operation `X = |X - Y|` affects the numbers modulo 3. We are interested in making a number divisible by 3, which means its remainder when divided by 3 should be 0.

Let's denote `remA = A % 3` and `remB = B % 3`. The possible remainders are 0, 1, or 2.

Consider the effect of the operation `X = |X - Y|` on the remainders:
The new remainder of `X` will be `|X - Y| % 3`.
We know that `(X - Y) % 3 = (X % 3 - Y % 3 + 3) % 3`. (Adding 3 ensures a non-negative result before the final modulo).
Since `|X - Y|` is either `(X - Y)` or `(Y - X)`, its remainder modulo 3 will be either `(X - Y) % 3` or `(Y - X) % 3`. These two values are either identical (if `(X-Y)` is divisible by 3) or sum to 3 (e.g., if `(X-Y)%3 = 1`, then `(Y-X)%3 = 2`). The key is that the absolute value operation doesn't change whether the number is divisible by 3 or not. If `(X-Y)` is divisible by 3, then `|X-Y|` is also divisible by 3.

Let's analyze the possible cases for `(remA, remB)`:

1.  **Case 0: `remA == 0` or `remB == 0`**
    If either `A` or `B` is already divisible by 3, then 0 operations are needed.

2.  **Case 1: `remA == remB` (and neither is 0)**
    This means `(remA, remB)` is either `(1, 1)` or `(2, 2)`.
    If we perform the operation, say `A = |A - B|`:
    The new `A % 3` will be `|A - B| % 3`.
    Since `A % 3 = B % 3`, it implies `(A - B) % 3 = (A % 3 - B % 3 + 3) % 3 = (remA - remB + 3) % 3 = (0 + 3) % 3 = 0`.
    Therefore, `|A - B|` will be divisible by 3.
    So, in 1 operation, we can make one of the numbers divisible by 3.
    *Example:* `A=4, B=7`. `remA=1, remB=1`. Replace `A` with `|4-7|=3`. Now `A` is divisible by 3. (1 operation)
    *Example:* `A=5, B=8`. `remA=2, remB=2`. Replace `A` with `|5-8|=3`. Now `A` is divisible by 3. (1 operation)

3.  **Case 2: `remA != remB` (and neither is 0)**
    This means `(remA, remB)` is either `(1, 2)` or `(2, 1)`.
    Let's assume `(remA, remB) = (1, 2)`.
    If we choose `A` and replace it with `|A - B|`:
    The new `A % 3` will be `|A - B| % 3`.
    Since `A % 3 = 1` and `B % 3 = 2`, `(A - B) % 3 = (1 - 2 + 3) % 3 = 2`.
    So, the new `remA` becomes 2. The state of remainders becomes `(2, 2)`.
    Now we are in Case 1 (`remA == remB == 2`). From this state, we know it takes 1 more operation to make a number divisible by 3.
    Total operations: 1 (to reach `(2, 2)`) + 1 (to make a number 0) = 2 operations.

    Similarly, if we chose `B` and replaced it with `|B - A|`:
    The new `B % 3` will be `|B - A| % 3`.
    Since `B % 3 = 2` and `A % 3 = 1`, `(B - A) % 3 = (2 - 1 + 3) % 3 = 1`.
    So, the new `remB` becomes 1. The state of remainders becomes `(1, 1)`.
    Again, we are in Case 1 (`remA == remB == 1`). From this state, it takes 1 more operation.
    Total operations: 1 (to reach `(1, 1)`) + 1 (to make a number 0) = 2 operations.

    In summary, if `remA` and `remB` are different and neither is 0, it always takes 2 operations.
    *Example:* `A=4, B=2`. `remA=1, remB=2`.
    1.  Replace `A` with `|4-2|=2`. Numbers are now `(2, 2)`. `remA=2, remB=2`.
    2.  Replace `A` with `|2-2|=0`. Numbers are now `(0, 2)`. `A` is divisible by 3. (2 operations total)

This covers all possible combinations of remainders. The logic is straightforward:
- If `remA == 0` or `remB == 0`: 0 operations.
- Else if `remA == remB`: 1 operation.
- Else (`remA != remB` and neither is 0): 2 operations.

## Complexity Analysis

-   **Time Complexity**: The `solve` function performs a constant number of arithmetic operations (modulo, comparisons) and prints a result. This is an $O(1)$ operation. Since the `solve` function is called `t` times for `t` test cases, the total time complexity is $O(t)$.
-   **Space Complexity**: The `solve` function uses a few variables (`A`, `B`, `remA`, `remB`) which require a constant amount of memory. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace for convenience
using namespace std;

void solve() {
    long long A, B; // A and B can be up to 10^9, long long is safe.
    cin >> A >> B;

    int remA = A % 3; // Remainder of A when divided by 3
    int remB = B % 3; // Remainder of B when divided by 3

    if (remA == 0 || remB == 0) {
        // If A or B is already divisible by 3, 0 operations are needed.
        cout << 0 << "\n";
    } else if (remA == remB) {
        // If A % 3 == B % 3 (and neither is 0, so both are 1 or both are 2),
        // then |A - B| will be divisible by 3.
        // For example, if A=4, B=1, then A%3=1, B%3=1. |A-B|=3.
        // We can change A to |A-B| (A becomes 3), or B to |A-B| (B becomes 3).
        // In 1 operation, one number becomes divisible by 3.
        cout << 1 << "\n";
    } else {
        // This case implies (remA, remB) is (1,2) or (2,1) (or their symmetric versions).
        // Neither is 0, and they are not equal.
        // As derived in the thought process, it takes 2 operations to make one number divisible by 3.
        // In one operation, we can reach a state where remA == remB (e.g., (1,1) or (2,2)).
        // From that state, one more operation makes a number divisible by 3.
        // Total 2 operations.
        cout << 2 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```