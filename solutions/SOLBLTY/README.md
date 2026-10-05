# Solubility (SOLBLTY)
- **Difficulty Rating**: 922
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a substance that dissolves in water. At an initial temperature of $X$ degrees, its solubility is $A$ grams per 100 mL of water. For every 1-degree Celsius increase in temperature, the solubility increases by $B$ grams per 100 mL. Chef can heat the water up to a maximum temperature of 100 degrees Celsius. Chef has 1 liter (1000 mL) of water. The problem asks us to calculate the maximum amount of the substance (in grams) that can be dissolved in 1 liter of water at 100 degrees Celsius.

## Intuition & Mathematical Observation
The problem states that the solubility changes linearly with temperature. We are given the solubility at an initial temperature $X$ and the rate of change of solubility with respect to temperature. We need to find the solubility at the maximum possible temperature, which is 100 degrees Celsius.

1.  **Temperature Difference**: The initial temperature is $X$ degrees Celsius, and the maximum temperature is 100 degrees Celsius. The total increase in temperature Chef can achieve is $100 - X$ degrees.

2.  **Solubility Increase**: For every 1-degree Celsius rise, the solubility increases by $B$ grams per 100 mL. Therefore, for a temperature rise of $(100 - X)$ degrees, the total increase in solubility will be $(100 - X) \times B$ grams per 100 mL.

3.  **Maximum Solubility per 100 mL**: The initial solubility at $X$ degrees is $A$ grams per 100 mL. After the temperature increase, the maximum solubility at 100 degrees Celsius will be the initial solubility plus the increase: $A + (100 - X) \times B$ grams per 100 mL.

4.  **Total Dissolvable Substance**: Chef has 1 liter of water, which is equal to 1000 mL. Since the solubility is given in grams per 100 mL, we need to scale this value for 1000 mL.
    1 liter = 1000 mL = 10 * 100 mL.
    So, the total amount of substance that can be dissolved in 1000 mL of water at 100 degrees Celsius is 10 times the solubility per 100 mL.
    Total dissolvable substance = $(A + (100 - X) \times B) \times 10$ grams.

    It's important to use a `long long` for the final result because the product of solubility and 10 could potentially exceed the range of a 32-bit integer, especially if $A$, $B$, and the temperature difference are large.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations for each test case. The number of test cases is read once, and then for each test case, we perform constant-time calculations. Thus, the time complexity per test case is $O(1)$. If $T$ is the number of test cases, the total time complexity is $O(T)$.

- **Space Complexity**: $O(1)$
    The solution uses a few integer variables to store the input values and intermediate calculations. The amount of memory used does not depend on the input size, making the space complexity $O(1)$.

## Solution Code
```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout, so that cin operations don't flush cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int x, a, b; // Initial temperature, initial solubility, solubility increase per degree
        std::cin >> x >> a >> b;

        // Calculate the temperature difference from the initial temperature to the maximum temperature (100 degrees).
        // The maximum temperature Chef can reach is 100 degrees.
        int temp_diff = 100 - x;

        // Calculate the increase in solubility due to the temperature rise.
        // Solubility increases by 'b' g/100mL for every 1-degree rise.
        int solubility_increase = temp_diff * b;

        // Calculate the maximum solubility at 100 degrees Celsius.
        // This is the initial solubility 'a' plus the total increase.
        // The solubility is given in g/100mL.
        int max_solubility_per_100ml = a + solubility_increase;

        // The amount of water is 1 liter, which is 1000 mL.
        // Since solubility is per 100 mL, and we have 1000 mL (which is 10 * 100 mL),
        // the total amount of sugar that can be dissolved is 10 times the solubility per 100 mL.
        // Use long long to prevent potential integer overflow for the final result.
        long long max_sugar_dissolved = (long long)max_solubility_per_100ml * 10;

        std::cout << max_sugar_dissolved << "\n";
    }
    return 0;
}
```