# [Keplers Law (KEPLERSLAW)](https://www.codechef.com/problems/KEPLERSLAW)
- **Difficulty Rating**: 992
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if two planets, given their orbital periods ($T_1$, $T_2$) and the semi-major axes of their orbits ($R_1$, $R_2$), obey Kepler's Third Law of Planetary Motion. Kepler's Third Law states that the square of the orbital period of a planet is directly proportional to the cube of the semi-major axis of its orbit.

## Intuition & Mathematical Observation
Kepler's Third Law can be mathematically expressed as:
$T^2 \propto R^3$

This proportionality implies that for any two planets orbiting the same star, the ratio of the square of their periods to the cube of their semi-major axes should be constant:
$\frac{T_1^2}{R_1^3} = \frac{T_2^2}{R_2^3}$

To avoid potential issues with floating-point precision and division by zero (though the problem constraints likely prevent division by zero), we can rearrange this equation by cross-multiplying:
$T_1^2 \times R_2^3 = T_2^2 \times R_1^3$

This equation allows us to compare the two planets' orbital characteristics using only integer arithmetic, which is generally more robust and precise.

The input values for $T$ and $R$ are up to $10$.
- $T^2$ will be at most $10^2 = 100$.
- $R^3$ will be at most $10^3 = 1000$.
- The product $T^2 \times R^3$ will be at most $100 \times 1000 = 100,000$.
A standard `int` in C++ can typically hold values up to $2 \times 10^9$, so `int` would be sufficient for these calculations. However, using `long long` is a good practice in competitive programming to prevent potential overflows, especially when dealing with intermediate products or larger constraints. The provided solution uses `long long` for safety and good practice.

The core logic is to read the four values ($t_1, t_2, r_1, r_2$), calculate $t_1^2 \times r_2^3$ and $t_2^2 \times r_1^3$, and then compare these two results. If they are equal, the planets obey Kepler's Third Law, and we print "Yes". Otherwise, we print "No".

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a fixed number of arithmetic operations (multiplication, comparison) for each test case, regardless of the input values. Therefore, the time complexity per test case is constant. If there are $t$ test cases, the total time complexity is $O(t)$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed amount of memory to store a few variables ($t, t_1, t_2, r_1, r_2$, and their squared/cubed counterparts). This memory usage does not depend on the input size, making the space complexity constant.

## Solution Code
```cpp
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout, so cin operations don't flush cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long t1, t2, r1, r2; // Orbital periods and semi-major axes
        std::cin >> t1 >> t2 >> r1 >> r2;

        // Kepler's 3rd Law states T^2 is proportional to R^3.
        // This means T^2 / R^3 should be a constant for planets orbiting the same star.
        // So, we need to check if (T1^2 / R1^3) == (T2^2 / R2^3).
        // To avoid floating-point precision issues and potential division by zero (though constraints prevent it here),
        // we can cross-multiply: T1^2 * R2^3 == T2^2 * R1^3.

        // Calculate T^2 and R^3. Use long long to prevent overflow,
        // although with the given constraints (T, R <= 10),
        // T^2 <= 100 and R^3 <= 1000, so even int might be sufficient.
        // However, it's good practice for competitive programming.
        long long t1_squared = t1 * t1;
        long long r1_cubed = r1 * r1 * r1;
        long long t2_squared = t2 * t2;
        long long r2_cubed = r2 * r2 * r2;

        // Check the proportionality by comparing the cross-multiplied values.
        if (t1_squared * r2_cubed == t2_squared * r1_cubed) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}
```