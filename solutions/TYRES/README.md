# [Cars and Bikes (TYRES)](https://www.codechef.com/problems/TYRES)
- **Difficulty Rating**: 809
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef's friend can purchase a bike. We are given `N` tyres. Chef has a priority: first, he manufactures as many cars as possible. Each car requires 4 tyres. After exhausting the tyres for cars, any remaining tyres are used to manufacture bikes. Each bike requires 2 tyres. We are guaranteed that `N` will always be an even number.

## Intuition & Mathematical Observation

The core of the problem lies in understanding how tyres are allocated and what remains.

1.  **Chef's Priority**: Chef first uses tyres to make cars. Each car needs 4 tyres.
2.  **Remaining Tyres**: After making the maximum possible number of cars, the number of tyres left will be `N % 4`. For example, if `N = 10`, Chef makes `10 / 4 = 2` cars using `2 * 4 = 8` tyres. `10 % 4 = 2` tyres remain.
3.  **Bike Manufacturing**: Any remaining tyres are then used to make bikes. Each bike needs 2 tyres.
4.  **Friend's Purchase**: Chef's friend can purchase a bike if and only if at least one bike is manufactured. This means there must be at least 2 tyres remaining after car manufacturing.

Now, let's consider the crucial constraint: `N` is always an even number.
When `N` is an even number, `N % 4` can only result in two possible values:
*   **Case 1: `N % 4 == 0`**
    *   This occurs when `N` is a multiple of 4 (e.g., 4, 8, 12, 16, ...).
    *   In this scenario, all `N` tyres are perfectly used to manufacture `N / 4` cars.
    *   Number of remaining tyres = 0.
    *   Since there are no tyres left, no bikes can be manufactured.
    *   Therefore, Chef's friend **cannot** purchase a bike.

*   **Case 2: `N % 4 == 2`**
    *   This occurs when `N` is an even number but not a multiple of 4 (e.g., 2, 6, 10, 14, ...).
    *   In this scenario, `N - 2` tyres are used to manufacture `(N - 2) / 4` cars.
    *   Number of remaining tyres = 2.
    *   These 2 remaining tyres can be used to manufacture exactly one bike (`2 / 2 = 1`).
    *   Since at least one bike is manufactured, Chef's friend **can** purchase a bike.

Based on these observations, the solution simplifies to checking the remainder of `N` when divided by 4. If `N % 4 == 0`, the answer is "NO". If `N % 4 == 2`, the answer is "YES".

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   For each test case, we perform a single modulo operation (`N % 4`) and a comparison, which are constant time operations.
    *   Since there are `T` test cases, the total time complexity is directly proportional to `T`.
*   **Space Complexity**: $O(1)$
    *   We only use a few integer variables (`T`, `N`) to store input and loop counters. The amount of memory used does not depend on the input value `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as per instruction

// Using namespace std; as per instruction
using namespace std;

int main() {
    // Fast I/O as per instruction
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times
        int N;
        cin >> N; // Read N for each test case

        // Chef prioritizes manufacturing cars. Each car needs 4 tyres.
        // After manufacturing the maximum number of cars, the remaining tyres
        // will be N % 4.
        // Since N is guaranteed to be even, N % 4 can only be 0 or 2.
        //
        // Case 1: N % 4 == 0
        // This means N is a multiple of 4 (e.g., 4, 8, 12, ...).
        // Chef will use all N tyres to make N/4 cars.
        // Remaining tyres = 0.
        // No bikes can be manufactured. Chef's friend cannot purchase a bike.
        if (N % 4 == 0) {
            cout << "NO\n";
        }
        // Case 2: N % 4 == 2
        // This means N is an even number but not a multiple of 4 (e.g., 2, 6, 10, ...).
        // Chef will use (N - 2) tyres to make (N-2)/4 cars.
        // Remaining tyres = 2.
        // These 2 tyres can be used to make 1 bike (2 / 2 = 1).
        // Since at least one bike is manufactured, Chef's friend can purchase a bike.
        else { // N % 4 == 2
            cout << "YES\n";
        }
    }
    return 0;
}
```