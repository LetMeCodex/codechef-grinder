# [World Record (BOLT)](https://www.codechef.com/problems/BOLT)
- **Difficulty Rating**: 1128
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef can break the 100-meter world record, which is currently 9.58 seconds. Chef's base speed is given as `v` meters per second. This speed is modified by three factors: `k1`, `k2`, and `k3`. His final speed in the competition will be the product of his base speed and these three factors: `k1 * k2 * k3 * v`.

We need to calculate the time Chef takes to complete 100 meters using his final speed. A crucial detail is that the Olympics clock rounds the final time to 2 decimal places. After calculating and rounding Chef's time, we compare it with the world record. If Chef's rounded time is *strictly less than* 9.58 seconds, he breaks the record, and we should output "YES"; otherwise, we output "NO".

## Intuition & Mathematical Observation

1.  **Calculate Final Speed**: The problem statement clearly defines Chef's final speed as the product of his base speed `v` and the three modifying factors `k1, k2, k3`.
    $$ \text{final\_speed} = k1 \times k2 \times k3 \times v $$

2.  **Calculate Time Taken**: To cover a distance of 100 meters, the time taken is given by the classic formula:
    $$ \text{Time} = \frac{\text{Distance}}{\text{Speed}} $$
    In this case, `Distance = 100` meters.
    $$ \text{time\_taken} = \frac{100}{\text{final\_speed}} $$

3.  **Data Type for Precision**: Since `k1, k2, k3, v` can be floating-point numbers and the time needs to be precise and rounded to two decimal places, it's essential to use a floating-point data type like `double` for all calculations involving these values to maintain accuracy.

4.  **Rounding to 2 Decimal Places**: This is the most critical part of the problem. The problem specifies that the time is rounded to 2 decimal places. A standard way to round a number `x` to `N` decimal places is:
    *   Multiply `x` by $10^N$.
    *   Round the result to the nearest integer (e.g., using `std::round()` in C++).
    *   Divide the rounded integer back by $10^N$.
    For this problem, `N=2`, so we perform:
    $$ \text{rounded\_time} = \frac{\text{round}(\text{time\_taken} \times 100.0)}{100.0} $$
    For example, if `time_taken` is `9.575`, then `9.575 * 100.0 = 957.5`. `round(957.5)` is `958.0`. Dividing by `100.0` gives `9.58`.
    If `time_taken` is `9.574`, then `9.574 * 100.0 = 957.4`. `round(957.4)` is `957.0`. Dividing by `100.0` gives `9.57`.

5.  **Comparison with World Record**: After obtaining the `rounded_time`, we compare it with the world record of 9.58 seconds. Chef breaks the record if his time is *strictly less than* 9.58. If his time is exactly 9.58 or greater, he does not break it.
    $$ \text{If } \text{rounded\_time} < 9.58 \text{ then "YES" else "NO"} $$

These steps cover all the necessary calculations and conditions to solve the problem.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the solution performs a fixed number of arithmetic operations (multiplications, division, rounding) and a comparison. These operations take constant time. If there are $T$ test cases, the total time complexity will be $T$ times the constant time per test case, which simplifies to $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`k1, k2, k3, v, final_speed, time_taken, rounded_time, t`) regardless of the input values or the number of test cases. Therefore, the space used remains constant, resulting in $O(1)$ space complexity.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, cmath, etc. for standard operations

// Use the standard namespace as requested by the problem instructions.
using namespace std;

// Function to solve a single test case
void solve() {
    // Declare variables for the input factors and speed.
    // Using 'double' for floating-point numbers to maintain precision,
    // as the problem involves decimal values and precise comparisons.
    double k1, k2, k3, v;
    
    // Read the four float values for the current test case from standard input.
    cin >> k1 >> k2 >> k3 >> v;

    // Calculate Chef's final speed in competition.
    // This is the product of the practice speed 'v' and all three modifying factors.
    double final_speed = k1 * k2 * k3 * v;

    // Calculate the time taken to complete 100 meters.
    // The formula is Time = Distance / Speed. Distance is 100 meters.
    double time_taken = 100.0 / final_speed;

    // The problem states that the final time displayed by the Olympics clock
    // is rounded to 2 places of decimal. We must apply this rounding.
    // To round a number 'x' to 'N' decimal places:
    // 1. Multiply 'x' by 10^N. (Here, N=2, so multiply by 100.0)
    // 2. Round the result to the nearest integer using std::round().
    // 3. Divide the rounded integer back by 10^N.
    double rounded_time = round(time_taken * 100.0) / 100.0;

    // Compare the rounded time with the world record (9.58 seconds).
    // Chef breaks the record if his rounded time is *strictly less than* 9.58.
    if (rounded_time < 9.58) {
        // If Chef's time is strictly less than 9.58, he breaks the record.
        cout << "YES\n";
    } else {
        // Otherwise (if rounded_time is 9.58 or greater), he does not break the record.
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // 'ios_base::sync_with_stdio(false)' disables synchronization with C's stdio library.
    // 'cin.tie(NULL)' unties cin from cout, meaning cin will not flush cout before reading input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare a variable for the number of test cases.
    int t;
    // Read the number of test cases from standard input.
    cin >> t;
    
    // Loop through each test case.
    // The 'while (t--)' construct decrements 't' after each iteration
    // and continues as long as 't' is greater than 0.
    while (t--) {
        // Call the 'solve' function to process the current test case.
        solve();
    }

    // Return 0 to indicate successful program execution.
    return 0;
}
```