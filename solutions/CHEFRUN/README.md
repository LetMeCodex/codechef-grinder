# [Secret Recipe (CHEFRUN)](https://www.codechef.com/problems/CHEFRUN)
- **Difficulty Rating**: 888
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine who reaches a specific meeting point `X3` first: Chef or Kefa.
Chef starts at position `X1` and moves towards `X3` with speed `V1`.
Kefa starts at position `X2` and moves towards `X3` with speed `V2`.
We are given that `X1 < X3 < X2`, meaning `X3` is located strictly between `X1` and `X2`.
We need to output "Chef" if Chef reaches `X3` first, "Kefa" if Kefa reaches `X3` first, or "Draw" if they reach at the same time.

## Intuition & Mathematical Observation
The core idea is to calculate the time taken by Chef and Kefa to reach the meeting point `X3` and then compare these times. The fundamental formula for time is `Time = Distance / Speed`.

1.  **Calculate Chef's Time:**
    *   Chef's starting position: `X1`
    *   Chef's destination: `X3`
    *   Chef's distance to travel: `dist_chef = X3 - X1` (since `X1 < X3`)
    *   Chef's speed: `V1`
    *   Time taken by Chef: `time_chef = (X3 - X1) / V1`

2.  **Calculate Kefa's Time:**
    *   Kefa's starting position: `X2`
    *   Kefa's destination: `X3`
    *   Kefa's distance to travel: `dist_kefa = X2 - X3` (since `X3 < X2`)
    *   Kefa's speed: `V2`
    *   Time taken by Kefa: `time_kefa = (X2 - X3) / V2`

3.  **Compare Times:**
    *   If `time_chef < time_kefa`, Chef reaches first.
    *   If `time_kefa < time_chef`, Kefa reaches first.
    *   If `time_chef == time_kefa`, it's a Draw.

**Avoiding Floating-Point Precision Issues:**
Directly performing division `(distance / speed)` might result in floating-point numbers. Comparing floating-point numbers for equality or even inequality can be problematic due to potential precision errors. To circumvent this, we can use cross-multiplication.

To compare two fractions `A/B` and `C/D` (where `B` and `D` are positive, which is true for speeds `V1` and `V2`):
*   `A/B < C/D` is equivalent to `A * D < C * B`
*   `A/B > C/D` is equivalent to `A * D > C * B`
*   `A/B == C/D` is equivalent to `A * D == C * B`

Applying this to our problem:
We need to compare `(X3 - X1) / V1` with `(X2 - X3) / V2`.
This is mathematically equivalent to comparing `(X3 - X1) * V2` with `(X2 - X3) * V1`.

**Data Type Considerations:**
The maximum values for `X_i` are `2 * 10^5` and `V_i` are `10^5`.
*   `dist_chef` and `dist_kefa` can be up to `2 * 10^5`.
*   The products `(dist_chef * V2)` and `(dist_kefa * V1)` can be as large as `(2 * 10^5) * (10^5) = 2 * 10^{10}`.
An `int` typically stores values up to `2 * 10^9`, which is insufficient for `2 * 10^{10}`. Therefore, `long long` data type must be used for these products to prevent integer overflow.

## Complexity Analysis
-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of arithmetic operations (subtractions, multiplications) and comparisons. These operations take constant time. Thus, processing each test case is $O(1)$. With $T$ test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store input values and intermediate calculations, regardless of the magnitude of the input numbers (within their allowed range). This means the memory usage remains constant per test case. Hence, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Include all standard libraries

// Using namespace std; is common in competitive programming
using namespace std;

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        // Declare variables using long long to safely handle intermediate products
        // (X_i values and V_i values fit in int, but their products might exceed int limits)
        long long X1, X2, X3, V1, V2; 
        cin >> X1 >> X2 >> X3 >> V1 >> V2;

        // Calculate distances for Chef and Kefa
        // The problem guarantees X1 < X3 < X2, so distances are always positive.
        long long dist_chef = X3 - X1;
        long long dist_kefa = X2 - X3;

        // To compare times (distance / speed) without using floating-point numbers,
        // we cross-multiply:
        // Compare (dist_chef / V1) with (dist_kefa / V2)
        // is equivalent to comparing (dist_chef * V2) with (dist_kefa * V1)
        // These products can be up to (2 * 10^5) * (10^5) = 2 * 10^10,
        // which requires 'long long' to prevent overflow.
        long long time_chef_scaled_numerator = dist_chef * V2;
        long long time_kefa_scaled_numerator = dist_kefa * V1;

        // Compare the scaled numerators to determine who reaches first
        if (time_chef_scaled_numerator < time_kefa_scaled_numerator) {
            cout << "Chef\n"; // Chef's time is less
        } else if (time_kefa_scaled_numerator < time_chef_scaled_numerator) {
            cout << "Kefa\n"; // Kefa's time is less
        } else {
            cout << "Draw\n"; // Times are equal
        }
    }
    return 0; // Indicate successful execution
}
```