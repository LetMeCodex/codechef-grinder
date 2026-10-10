# [FIND A and B (FINDK3)](https://www.codechef.com/problems/FINDK3)
- **Difficulty Rating**: 802
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find two positive integers, `A` and `B`, given three positive integers `X`, `Y`, and `Z`. The conditions that `A` and `B` must satisfy are:
1. `A` must be a multiple of `X`.
2. `B` must be a multiple of `Y`.
3. `A + B` must be a multiple of `Z`.

If such `A` and `B` exist, we should print them. Otherwise, we should print `-1`. The constraints on `X, Y, Z` are `1 <= X, Y, Z <= 1000`.

## Intuition & Mathematical Observation

The problem requires us to find *any* pair of positive integers `(A, B)` that satisfy the given conditions. The constraints on `X, Y, Z` are small, suggesting that `A` and `B` don't need to be excessively large.

Let's analyze the conditions:
1. `A = k_X * X` for some positive integer `k_X`.
2. `B = k_Y * Y` for some positive integer `k_Y`.
3. `(A + B) % Z == 0`.

A straightforward approach to satisfy these conditions is to make `A` a multiple of both `X` and `Z`, and `B` a multiple of both `Y` and `Z`.
The simplest positive multiple of `X` and `Z` is `X * Z`. So, we can set `A = X * Z`.
The simplest positive multiple of `Y` and `Z` is `Y * Z`. So, we can set `B = Y * Z`.

Let's check if this pair `(A = X * Z, B = Y * Z)` satisfies all conditions:
1. `A` is a multiple of `X`: `(X * Z) % X == 0`. This is always true.
2. `B` is a multiple of `Y`: `(Y * Z) % Y == 0`. This is always true.
3. `A + B` is a multiple of `Z`: `(X * Z + Y * Z) % Z == 0`. This simplifies to `((X + Y) * Z) % Z == 0`, which is always true.

Since `X, Y, Z` are positive, `A = X * Z` and `B = Y * Z` will also be positive.
This construction `(A = X * Z, B = Y * Z)` *always* provides a valid solution. Therefore, theoretically, the problem should never require printing `-1`.

### Analysis of the Provided Solution Code

The provided solution code attempts to find a solution by trying three specific constructions for `A` and `B`. It sets one variable to be the product of two of `X, Y, Z` and the other variable to be the remaining single input. For each construction, it checks *one* specific divisibility condition. If that condition is met, it prints the pair and returns. If none of the three constructions satisfy their respective checked conditions, it prints `-1`.

Let's analyze each case as implemented in the code:

**Case 1: `A = Y * Z`, `B = X`**
- **Code's check**: `if ((Y * Z) % X == 0)`
- **Output if true**: `Y * Z` (for `A`) and `X` (for `B`).
- **Required conditions for validity**:
    1. `A` is a multiple of `X`: `(Y * Z) % X == 0`. (This is the condition checked by the code.)
    2. `B` is a multiple of `Y`: `X % Y == 0`. (This is **not** checked by the code.)
    3. `A + B` is a multiple of `Z`: `(Y * Z + X) % Z == 0`, which simplifies to `X % Z == 0`. (This is **not** checked by the code.)
- **Observation**: This branch only guarantees the first condition. The solution might be invalid if `X` is not a multiple of `Y` or `Z`.

**Case 2: `A = X * Z`, `B = Y`**
- **Code's check**: `if ((X * Z) % Y == 0)`
- **Output if true**: `X * Z` (for `A`) and `Y` (for `B`).
- **Required conditions for validity**:
    1. `A` is a multiple of `X`: `(X * Z) % X == 0`. (This is **always true** for positive `X, Z`.)
    2. `B` is a multiple of `Y`: `Y % Y == 0`. (This is **always true** for positive `Y`.)
    3. `A + B` is a multiple of `Z`: `(X * Z + Y) % Z == 0`, which simplifies to `Y % Z == 0`. (This is **not** checked by the code.)
- **Observation**: The condition `(X * Z) % Y == 0` checked by the code is an additional check that is not directly one of the three problem requirements for this specific `A` and `B`. The actual condition needed for `A+B` to be a multiple of `Z` (`Y % Z == 0`) is not checked.

**Case 3: `A = X * Y`, `B = Z`**
- **Code's check**: `if ((X * Y) % Z == 0)`
- **Output if true**: `X * Y` (for `A`) and `Z` (for `B`).
- **Required conditions for validity**:
    1. `A` is a multiple of `X`: `(X * Y) % X == 0`. (This is **always true** for positive `X, Y`.)
    2. `B` is a multiple of `Y`: `Z % Y == 0`. (This is **not** checked by the code.)
    3. `A + B` is a multiple of `Z`: `(X * Y + Z) % Z == 0`, which simplifies to `(X * Y) % Z == 0`. (This is the condition checked by the code.)
- **Observation**: This branch guarantees the first and third conditions. The solution might be invalid if `Z` is not a multiple of `Y`.

**Conclusion on the provided code's logic:**
The provided solution code attempts to find a solution by trying three specific constructions for `A` and `B`. However, in each case, it only checks a subset of the necessary conditions (or an irrelevant one in Case 2). Despite these logical gaps, the solution passed on CodeChef, suggesting that the test cases for this problem might be weak, or there's an implicit property of the test data that makes these partial checks sufficient.

A more robust and always-correct solution would be `A = X * Z` and `B = Y * Z`, which satisfies all conditions without needing any `if` checks and would never print `-1`. The provided code, however, implements a different strategy.

## Complexity Analysis

-   **Time Complexity**: For each test case, the solution performs a fixed number of arithmetic operations (multiplications, modulo, comparisons). These operations take constant time. Since there are `T` test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: The solution uses a few variables to store `X, Y, Z`, and `T`. This is a constant amount of memory, regardless of the input values. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, etc.

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    long long X, Y, Z; // Using long long for X, Y, Z and products to be safe,
                       // though int would suffice given constraints (max product 10^8).
    cin >> X >> Y >> Z;

    // Possibility 1: A = Y * Z, B = X
    // Check if A (Y*Z) is a multiple of X.
    // The code implicitly assumes B (X) is a multiple of Y, and A+B is a multiple of Z (i.e., X is a multiple of Z).
    if ((Y * Z) % X == 0) {
        cout << (Y * Z) << " " << X << "\n";
        return; // Found a solution, print and return
    }

    // Possibility 2: A = X * Z, B = Y
    // Check if A (X*Z) is a multiple of Y.
    // Note: A (X*Z) is always a multiple of X. B (Y) is always a multiple of Y.
    // For A+B (X*Z + Y) to be a multiple of Z, Y must be a multiple of Z.
    // The condition checked here ((X*Z) % Y == 0) is not directly one of the problem's requirements for this construction.
    if ((X * Z) % Y == 0) {
        cout << (X * Z) << " " << Y << "\n";
        return; // Found a solution, print and return
    }

    // Possibility 3: A = X * Y, B = Z
    // Check if A+B (X*Y + Z) is a multiple of Z, which simplifies to (X*Y) % Z == 0.
    // Note: A (X*Y) is always a multiple of X.
    // The code implicitly assumes B (Z) is a multiple of Y.
    if ((X * Y) % Z == 0) {
        cout << (X * Y) << " " << Z << "\n";
        return; // Found a solution, print and return
    }

    // If no solution is found after checking all possibilities
    // (This branch is reached if none of the specific conditions for the three constructions are met)
    cout << -1 << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```