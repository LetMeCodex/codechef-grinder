# [Long Drive (LONGDRIVE)](https://www.codechef.com/problems/LONGDRIVE)
- **Difficulty Rating**: 939
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine the minimum number of additional hours, `H`, a driver needs to drive to achieve a total average speed of at least `Y` km/h. The driver has already completed 10 hours of driving at an average speed of `X` km/h. For the additional `H` hours, the driver will maintain a constant speed of 100 km/h. We are given `X` and `Y` for multiple test cases, with the constraints `1 <= X < Y < 100`.

## Intuition & Mathematical Observation

Let's break down the total journey into two parts: the initial 10 hours and the additional `H` hours.

1.  **Initial Journey:**
    *   Time: `10` hours
    *   Average Speed: `X` km/h
    *   Distance Covered: `10 * X` km

2.  **Additional Journey:**
    *   Time: `H` hours (this is what we need to find)
    *   Speed: `100` km/h
    *   Distance Covered: `H * 100` km

3.  **Total Journey:**
    *   Total Time: `10 + H` hours
    *   Total Distance: `(10 * X) + (H * 100)` km

The problem states that the total average speed must be at least `Y` km/h. The formula for average speed is Total Distance / Total Time. So, we can set up the inequality:

$$ \frac{10 \cdot X + H \cdot 100}{10 + H} \ge Y $$

Now, we need to solve this inequality for `H`. Since `H` must be non-negative, `10 + H` will always be positive. We can multiply both sides by `(10 + H)` without changing the direction of the inequality:

$$ 10 \cdot X + H \cdot 100 \ge Y \cdot (10 + H) $$
$$ 10 \cdot X + 100 \cdot H \ge 10 \cdot Y + H \cdot Y $$

Next, we gather all terms involving `H` on one side and constant terms on the other:

$$ 100 \cdot H - H \cdot Y \ge 10 \cdot Y - 10 \cdot X $$
$$ H \cdot (100 - Y) \ge 10 \cdot (Y - X) $$

From the problem constraints, we know `Y < 100`, which implies `(100 - Y)` is always a positive value. Also, `X < Y`, which implies `(Y - X)` is always a positive value. Since `(100 - Y)` is positive, we can divide both sides by it without changing the inequality direction:

$$ H \ge \frac{10 \cdot (Y - X)}{100 - Y} $$

Since `H` must be an integer (number of hours) and we are looking for the *minimum* such `H`, we need to take the ceiling of the right-hand side expression.
The ceiling function `ceil(A/B)` for positive integers `A` and `B` can be calculated using integer division as `(A + B - 1) / B`.

Let:
*   `numerator = 10 * (Y - X)`
*   `denominator = 100 - Y`

Both `numerator` and `denominator` are positive integers based on the problem constraints.
Therefore, the minimum integer `H` is:

$$ H = \frac{\text{numerator} + \text{denominator} - 1}{\text{denominator}} $$
(using integer division)

This formula directly gives us the required minimum additional hours.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The solution involves a loop that iterates `T` times (for each test case). Inside the loop, we perform a fixed number of arithmetic operations (subtraction, multiplication, addition, division) and input/output operations. These operations take constant time, $O(1)$. Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

*   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space regardless of the input values. We only declare a few integer variables (`T`, `X`, `Y`, `numerator`, `denominator`, `H`) to store intermediate results. This memory usage does not scale with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int X, Y;
        cin >> X >> Y; // Read X and Y for each test case

        // Calculate the numerator for the ceiling division formula.
        // This represents the "deficit" in total distance needed to reach target Y,
        // considering the initial 10 hours and the difference in speeds.
        // The inequality derived is: H * (100 - Y) >= 10 * (Y - X)
        // So, numerator = 10 * (Y - X)
        int numerator = 10 * (Y - X);

        // Calculate the denominator for the ceiling division formula.
        // This represents the "effective speed gain" per additional hour
        // relative to the target average speed Y.
        // (100 km/h - Y km/h) is the extra distance covered per hour
        // beyond what's needed to maintain Y km/h for that hour.
        // Denominator = 100 - Y
        int denominator = 100 - Y;
        
        // Calculate H using the ceiling division formula: (A + B - 1) / B
        // This gives the minimum integer H such that H >= numerator / denominator.
        // Constraints ensure denominator (100 - Y) is always positive (Y < 100),
        // and numerator (10 * (Y - X)) is always positive (X < Y).
        int H = (numerator + denominator - 1) / denominator;
        
        cout << H << "\n"; // Output the minimum number of additional hours
    }

    return 0;
}
```