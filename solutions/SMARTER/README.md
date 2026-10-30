# [Work Smarter, Not Harder (SMARTER)](https://www.codechef.com/problems/SMARTER)
- **Difficulty Rating**: 924
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the maximum integer wait time `W` (in seconds) that a hare can take before starting its race, such that it still wins against a tortoise. Both the hare and the tortoise travel a distance `L`. The tortoise runs at speed `V1`, and the hare runs at speed `V2`.

The winning condition is based on "reported times":
1.  If a participant's actual travel time is `X`, their reported time is $\lceil X \rceil$ (ceiling of X).
2.  The hare wins if its *reported total time* (wait time + running time) is strictly less than the tortoise's *reported time*.
3.  If the hare cannot win even by waiting 0 seconds, we should output -1.

## Intuition & Mathematical Observation

Let's denote the relevant times:

1.  **Tortoise's actual running time**: $T_{tortoise} = \frac{L}{V_1}$
2.  **Tortoise's reported time**: $R_{tortoise} = \lceil T_{tortoise} \rceil = \lceil \frac{L}{V_1} \rceil$

3.  **Hare's actual running time**: $T_{hare\_run} = \frac{L}{V_2}$
4.  **Hare's total actual time (including wait)**: $T_{hare\_total} = W + T_{hare\_run} = W + \frac{L}{V_2}$
5.  **Hare's reported time**: $R_{hare} = \lceil T_{hare\_total} \rceil = \lceil W + \frac{L}{V_2} \rceil$

The winning condition is $R_{hare} < R_{tortoise}$.
Since reported times are integers, "strictly less than $R_{tortoise}$" is equivalent to "less than or equal to $R_{tortoise} - 1$".
So, the condition becomes:
$\lceil W + \frac{L}{V_2} \rceil \le R_{tortoise} - 1$

A key property of the ceiling function is that for any real number $X$ and integer $Y$, if $\lceil X \rceil \le Y$, then it must be that $X \le Y$.
Applying this property to our inequality:
$W + \frac{L}{V_2} \le R_{tortoise} - 1$

Now, we need to find the maximum integer $W$. We can rearrange the inequality to isolate $W$:
$W \le R_{tortoise} - 1 - \frac{L}{V_2}$

To find the maximum integer $W$ that satisfies $W \le \text{some\_value}$, we simply take the floor of that value:
$W_{max} = \lfloor R_{tortoise} - 1 - \frac{L}{V_2} \rfloor$

Let's break down the calculation:
*   **Calculating $R_{tortoise}$**: For positive integers $A, B$, $\lceil A/B \rceil$ can be computed using integer division as $(A + B - 1) / B$. So, $R_{tortoise} = (L + V_1 - 1) / V_1$. This will be an integer.
*   **Calculating $L/V_2$**: This division might result in a non-integer. To maintain precision for the subtraction and floor operation, we should use floating-point numbers (e.g., `double`) for this part of the calculation.
*   **Final $W_{max}$**: After computing the right-hand side of the inequality using floating-point arithmetic, we cast the result to a `long long` after applying `std::floor`.

**Edge Case**: If the calculated `W_{max}` is negative, it means that even waiting 0 seconds does not allow the hare to win. In this scenario, the problem asks us to print -1. This is because if $W_{max} < 0$, then $\lfloor R_{tortoise} - 1 - \frac{L}{V_2} \rfloor < 0$, which implies $R_{tortoise} - 1 - \frac{L}{V_2} < 0$, or $\frac{L}{V_2} > R_{tortoise} - 1$. If $W=0$, the hare's reported time would be $\lceil \frac{L}{V_2} \rceil$. Since $\frac{L}{V_2} > R_{tortoise} - 1$, then $\lceil \frac{L}{V_2} \rceil \ge R_{tortoise}$, meaning the hare's reported time is not strictly less than the tortoise's reported time.

**Data Types**: `L, V1, V2` are up to 1000. `long long` is used for safety for these variables and `tortoise_reported_time`, although `int` would technically suffice given the constraints. For intermediate calculations involving division that might result in fractional parts, `double` is used to maintain precision before taking the floor.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution involves a few arithmetic operations (addition, subtraction, division) and one call to `std::floor`. All these operations take constant time, $O(1)$. Since there are `T` test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution uses a fixed number of variables (`L, V1, V2, tortoise_reported_time, value_for_floor, max_wait_time`) to store input and intermediate results. This requires constant extra space, $O(1)$, regardless of the input values.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <cmath>    // Required for std::floor

// Function to solve a single test case
void solve() {
    long long L, V1, V2; // L, V1, V2 can be up to 1000. long long is used for safety, int would also suffice.
    std::cin >> L >> V1 >> V2;

    // 1. Calculate the tortoise's reported time.
    // The tortoise takes L/V1 seconds. This time is rounded up.
    // For positive integers A, B, ceil(A/B) can be calculated as (A + B - 1) / B using integer division.
    long long tortoise_reported_time = (L + V1 - 1) / V1;

    // 2. Determine the maximum integer 'W' (wait time) for the hare.
    // The winning condition is: Hare's reported time < Tortoise's reported time.
    // Let K = tortoise_reported_time.
    // Hare's actual running time = L/V2.
    // Hare's total actual time (waiting + running) = W + L/V2.
    // Hare's reported time = ceil(W + L/V2).
    //
    // So, the condition is: ceil(W + L/V2) < K.
    // Since reported times are integers, "strictly less than K" means "less than or equal to K-1".
    // Thus, ceil(W + L/V2) <= K - 1.
    //
    // For any real number X and integer Y, if ceil(X) <= Y, it implies X <= Y.
    // So, W + L/V2 <= K - 1.
    //
    // Rearranging to solve for W:
    // W <= K - 1 - L/V2.
    //
    // To find the maximum integer W that satisfies W <= some_value, we take floor(some_value).
    // Let's calculate 'some_value' using double-precision floating point numbers.
    double value_for_floor = static_cast<double>(tortoise_reported_time) - 1.0 - (static_cast<double>(L) / V2);

    // The maximum integer W is floor(value_for_floor).
    long long max_wait_time = static_cast<long long>(std::floor(value_for_floor));

    // 3. Output the result.
    // If the calculated max_wait_time is negative, it means even waiting 0 seconds
    // does not allow the hare to win. In this scenario, the problem asks to print -1.
    if (max_wait_time < 0) {
        std::cout << -1 << "\n";
    } else {
        std::cout << max_wait_time << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```