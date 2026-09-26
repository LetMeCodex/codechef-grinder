# [Airlines (SPCP2)](https://www.codechef.com/problems/SPCP2)
- **Difficulty Rating**: 712
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum number of new aircraft an airline must purchase to transport a given number of passengers. We are provided with:
1.  `X`: The number of aircraft the airline currently owns.
2.  `N`: The total number of passengers that need to be transported.

Each aircraft has a maximum capacity of 100 passengers. We need to output the count of additional aircraft required.

## Intuition & Mathematical Observation

The core of this problem lies in two steps:
1.  Calculate the total number of aircraft *required* to transport `N` passengers.
2.  Compare the required aircraft with the owned aircraft (`X`) to find out how many more need to be purchased.

**Step 1: Calculating `planes_needed`**
Each aircraft can carry up to 100 passengers. If we have `N` passengers, the number of planes needed is `N` divided by 100. However, this division must account for any remainder. For example, if there are 101 passengers, `101 / 100` (integer division) would yield 1, but we actually need 2 planes (one for the first 100, and another for the remaining 1). This is a classic "ceiling division" scenario.

The ceiling of `A / B` (i.e., `ceil(A / B)`) for positive integers `A` and `B` can be calculated using integer arithmetic as `(A + B - 1) / B`.
In our case, `A = N` and `B = 100`. So, the number of planes needed is `(N + 100 - 1) / 100`, which simplifies to `(N + 99) / 100`.

Let's test this formula:
*   If `N = 100`: `(100 + 99) / 100 = 199 / 100 = 1` (Correct, 1 plane needed)
*   If `N = 101`: `(101 + 99) / 100 = 200 / 100 = 2` (Correct, 2 planes needed)
*   If `N = 1`: `(1 + 99) / 100 = 100 / 100 = 1` (Correct, 1 plane needed)

**Step 2: Calculating `planes_to_buy`**
Once we have `planes_needed`, we compare it with `X` (planes owned):
*   If `planes_needed > X`, the airline needs to buy `planes_needed - X` new aircraft.
*   If `planes_needed <= X`, the airline already has enough or more planes than required, so it needs to buy 0 new aircraft.

This logic can be concisely implemented using the `std::max` function: `max(0, planes_needed - X)`. This ensures that the result is never negative.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The solution involves a loop that iterates `T` times, once for each test case. Inside the loop, we perform a fixed number of arithmetic operations (addition, division, subtraction) and a comparison (`max`), along with input/output operations. All these operations take constant time, $O(1)$. Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`T`, `X`, `N`, `planes_needed`, `planes_to_buy`) to store input and intermediate results. The amount of memory used by these variables is constant and does not depend on the input values (other than fitting within standard integer types). Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// Using namespace std; is requested by the problem statement.
using namespace std;

int main() {
    // Fast I/O setup as requested for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.

    while (T--) { // Loop T times for each test case.
        int X, N;
        cin >> X >> N; // Read the number of aircraft owned (X) and passengers (N).

        // Calculate the minimum number of planes required to carry N passengers.
        // Each aircraft can carry up to 100 passengers.
        // This is equivalent to ceil(N / 100.0).
        // In integer arithmetic, ceil(A / B) for positive integers A, B can be calculated as (A + B - 1) / B.
        // Here, A = N and B = 100.
        int planes_needed = (N + 99) / 100;

        // Determine the number of new planes the airline must purchase.
        // If the number of planes needed is greater than the planes already owned (X),
        // the airline must buy the difference: planes_needed - X.
        // If planes_needed is less than or equal to X, the airline already has enough planes,
        // so it needs to buy 0 new planes.
        // The std::max function handles this concisely: max(0, value).
        int planes_to_buy = max(0, planes_needed - X);

        cout << planes_to_buy << "\n"; // Output the result for the current test case.
    }

    return 0; // Indicate successful execution.
}
```