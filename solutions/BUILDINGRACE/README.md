# [Building Race (BUILDINGRACE)](https://www.codechef.com/problems/BUILDINGRACE)
- **Difficulty Rating**: 739
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine who reaches their destination floor first: Chef or Chefina.
Chef needs to travel `A` floors and has a speed of `X` floors per unit of time.
Chefina needs to travel `B` floors and has a speed of `Y` floors per unit of time.
We need to output "Chef" if Chef takes less time, "Chefina" if Chefina takes less time, or "Both" if they take the same amount of time.

## Intuition & Mathematical Observation

1.  **Calculate Time Taken**:
    *   The time taken to travel a certain number of floors is `(Number of Floors) / (Speed)`.
    *   So, Chef's time `T_Chef = A / X`.
    *   Chefina's time `T_Chefina = B / Y`.

2.  **Compare Times**: We need to compare `T_Chef` and `T_Chefina`. That is, we need to compare `A / X` with `B / Y`.

3.  **Avoid Floating-Point Arithmetic**: Directly performing division and comparing floating-point numbers (like `double` or `float`) can lead to precision issues in competitive programming. It's generally safer and more robust to work with integers whenever possible.

4.  **Cross-Multiplication for Comparison**: To compare `A / X` and `B / Y` using only integer arithmetic, we can employ cross-multiplication. Since `X` and `Y` represent speeds, they are positive. Multiplying both sides of an inequality by `X * Y` (which is also positive) does not change the direction of the inequality:
    *   If `A / X < B / Y`, then `A * Y < B * X`.
    *   If `A / X > B / Y`, then `A * Y > B * X`.
    *   If `A / X == B / Y`, then `A * Y == B * X`.

    This allows us to compare the integer products `A * Y` and `B * X` instead of the floating-point quotients.

5.  **Integer Overflow Consideration**: The maximum values for `A, B, X, Y` are 100.
    *   The maximum product `A * Y` or `B * X` would be `100 * 100 = 10000`.
    *   A standard `int` in C++ can typically hold values up to `2 * 10^9`, so `10000` fits comfortably within an `int`.
    *   However, the provided solution uses `long long` for the products (`chef_time_numerator`, `chefina_time_numerator`). This is a good defensive programming practice. While not strictly necessary for these specific constraints, it prevents potential overflow issues if the constraints were larger (e.g., up to `10^9`, where products would exceed `int` capacity). It adds robustness without significant performance penalty.

Based on these observations, the strategy is to calculate `A * Y` and `B * X` and compare these two integer values to determine the winner.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside each test case, it performs a fixed number of operations: reading four integers, two multiplications, two type casts (to `long long`), and a few comparisons. All these operations take constant time, $O(1)$.
    *   Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of variables (`T`, `A`, `B`, `X`, `Y`, `chef_time_numerator`, `chefina_time_numerator`) regardless of the input values (other than `T` itself, which defines the number of iterations, not the size of data structures).
    *   No arrays, vectors, or other data structures whose size depends on the input values are used.
    *   Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for cin and cout

// Using the standard namespace to avoid prefixing std:: to every standard library element.
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int A, B, X, Y; // Declare integer variables for Chef's floor, Chefina's floor, Chef's speed, and Chefina's speed.
        cin >> A >> B >> X >> Y; // Read the four integers for the current test case.

        // Calculate "effective time" numerators for Chef and Chefina using cross-multiplication.
        // This avoids floating-point arithmetic and potential precision issues.
        // Chef's time = A/X. Chefina's time = B/Y.
        // Comparing A/X vs B/Y is equivalent to comparing A*Y vs B*X
        // (since X and Y are positive, multiplying by X*Y doesn't change inequality direction).
        
        // Using long long for intermediate products to be absolutely safe,
        // even though int is sufficient given the constraints (max 100*100 = 10000).
        // This is a common defensive programming practice in competitive programming
        // to prevent any potential, however unlikely, overflow issues or
        // platform-specific integer size quirks.
        long long chef_time_numerator = (long long)A * Y;
        long long chefina_time_numerator = (long long)B * X;

        // Compare the calculated integer products to determine who reaches first.
        if (chef_time_numerator < chefina_time_numerator) {
            // If Chef's effective time numerator is smaller, Chef takes less time.
            cout << "Chef\n";
        } else if (chef_time_numerator > chefina_time_numerator) {
            // If Chefina's effective time numerator is smaller, Chefina takes less time.
            cout << "Chefina\n";
        } else {
            // If both numerators are equal, both take the same amount of time.
            cout << "Both\n";
        }
    }

    return 0; // Indicate successful program execution.
}
```