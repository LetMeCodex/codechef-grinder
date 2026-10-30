# [Snape and Ladder (SNAPE)](https://www.codechef.com/problems/SNAPE)
- **Difficulty Rating**: 828
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum and maximum possible lengths of the right side (RS) of a ladder, given the length of its base (B) and the length of its left side (LS). The ladder forms a triangle with the ground, where B is the distance between the feet of the left and right sides. The height of the ladder's apex (the point where the two sides meet) can vary.

## Intuition & Mathematical Observation

Let's denote the height of the ladder's apex from the ground as $H$. The base $B$ can be thought of as the sum of two segments, $x_1$ and $x_2$, where $x_1$ is the horizontal distance from the foot of the left side to the point directly below the apex, and $x_2$ is the horizontal distance from the foot of the right side to the point directly below the apex. Thus, $B = x_1 + x_2$.

Using the Pythagorean theorem, we can relate the sides:
$LS^2 = H^2 + x_1^2$
$RS^2 = H^2 + x_2^2$

We need to find the minimum and maximum possible values for $RS$.

### Maximum RS

To maximize $RS$, we want to maximize the terms $H^2$ and $x_2^2$. This occurs when the left side (LS) is positioned vertically.
In this configuration:
1. The horizontal distance $x_1$ becomes $0$.
2. The height $H$ becomes equal to $LS$ (since $LS^2 = H^2 + 0^2 \Rightarrow H = LS$).
3. The entire base $B$ becomes $x_2$ (since $B = x_1 + x_2 = 0 + x_2 \Rightarrow x_2 = B$).

Now, substituting these into the equation for $RS$:
$RS_{max}^2 = H^2 + x_2^2 = LS^2 + B^2$
Therefore, the maximum length of the right side is:
$RS_{max} = \sqrt{LS^2 + B^2}$

This configuration forms a right-angled triangle where $LS$ and $B$ are the legs, and $RS$ is the hypotenuse.

### Minimum RS

The minimum length of $RS$ depends on the relationship between $LS$ and $B$.

**Case 1: $LS \ge B$**
If the left side $LS$ is long enough (at least as long as the base $B$), the minimum $RS$ occurs when the right side (RS) is positioned vertically.
In this configuration:
1. The horizontal distance $x_2$ becomes $0$.
2. The height $H$ becomes equal to $RS$ (since $RS^2 = H^2 + 0^2 \Rightarrow H = RS$).
3. The entire base $B$ becomes $x_1$ (since $B = x_1 + x_2 = x_1 + 0 \Rightarrow x_1 = B$).

Now, substituting these into the equation for $LS$:
$LS^2 = H^2 + x_1^2 = RS^2 + B^2$
Rearranging to solve for $RS^2$:
$RS_{min}^2 = LS^2 - B^2$
Therefore, the minimum length of the right side is:
$RS_{min} = \sqrt{LS^2 - B^2}$
This is valid because $LS \ge B$ ensures $LS^2 - B^2 \ge 0$. This configuration forms a right-angled triangle where $LS$ is the hypotenuse, and $RS$ and $B$ are the legs.

**Case 2: $LS < B$**
If the left side $LS$ is shorter than the base $B$, the configuration from Case 1 (where RS is vertical and LS is the hypotenuse) is not possible, as $LS$ cannot be the hypotenuse of a right triangle with a leg of length $B$ if $LS < B$.
In this scenario, the minimum $RS$ occurs when the ladder is "flattest," meaning the height $H$ approaches $0$. This forms a degenerate triangle where the apex, the foot of LS, and the foot of RS are collinear (all lie on the ground).
The apex is positioned *between* the feet of LS and RS.
The distance from the foot of LS to the apex is $LS$.
The distance from the foot of RS to the apex is $RS$.
The total base $B$ is the sum of these two segments: $B = LS + RS$.
Therefore, the minimum length of the right side is:
$RS_{min} = B - LS$

Combining these observations, the solution involves calculating $RS_{max}$ using the Pythagorean theorem and then determining $RS_{min}$ based on the comparison between $LS$ and $B$.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The solution processes $T$ test cases. For each test case, it performs a fixed number of arithmetic operations (multiplications, additions, subtractions, square roots) and input/output operations. Each of these operations takes constant time. Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of memory to store variables such as `T`, `B`, `LS`, `min_rs`, and `max_rs`. The memory usage does not scale with the input values or the number of test cases, as these variables are reused for each test case.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (cin, cout)
#include <cmath>    // Required for mathematical functions like sqrt
#include <iomanip>  // Required for output formatting (fixed, setprecision)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        double B, LS; // Declare B and LS as double to handle floating-point calculations
        std::cin >> B >> LS; // Read the base (B) and left side length (LS) for the current test case

        double min_rs, max_rs; // Variables to store the minimum and maximum right side lengths

        // Calculate Maximum RS:
        // The maximum length of RS occurs when the left side (LS) is vertical.
        // In this configuration, LS, B, and RS form a right-angled triangle where RS is the hypotenuse.
        // By Pythagorean theorem: RS^2 = LS^2 + B^2
        max_rs = std::sqrt(LS * LS + B * B);

        // Calculate Minimum RS:
        // There are two cases for the minimum length of RS, depending on the relationship between LS and B.
        if (LS >= B) {
            // Case 1: LS is greater than or equal to B.
            // The minimum RS occurs when the right side (RS) is vertical.
            // In this configuration, RS, B, and LS form a right-angled triangle where LS is the hypotenuse.
            // By Pythagorean theorem: LS^2 = RS^2 + B^2  =>  RS^2 = LS^2 - B^2
            min_rs = std::sqrt(LS * LS - B * B);
        } else {
            // Case 2: LS is less than B.
            // In this scenario, RS cannot be vertical because LS is not long enough to be the hypotenuse
            // of a right triangle with leg B.
            // The minimum RS occurs when the ladder is "flattest" (height H approaches 0)
            // and the apex is positioned between the feet of LS and RS.
            // This forms a degenerate triangle where the apex, foot of LS, and foot of RS are collinear.
            // The distance from the foot of LS to the apex is LS. The distance from the foot of LS to the foot of RS is B.
            // If the apex is between the feet, then LS + RS = B, which implies RS = B - LS.
            min_rs = B - LS;
        }

        // Output the minimum and maximum RS values.
        // std::fixed ensures that floating-point numbers are printed in fixed-point notation.
        // std::setprecision(5) sets the number of digits after the decimal point to 5.
        std::cout << std::fixed << std::setprecision(5) << min_rs << " " << max_rs << "\n";
    }

    return 0; // Indicate successful execution
}
```