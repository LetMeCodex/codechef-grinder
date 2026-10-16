# Melt Gold (MELTGOLD)
- **Difficulty Rating**: 835
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the minimum number of minutes required for a piece of gold to melt. We are given the melting point `x` and the current temperature `y`. In the first minute, the temperature increases by 1 degree. In the second minute, it increases by 2 degrees, and so on. In the $k$-th minute, the temperature increases by $k$ degrees. We need to find the smallest integer `m` such that the temperature after `m` minutes is greater than or equal to `x`.

## Intuition & Mathematical Observation
The core of the problem is to simulate the temperature increase over time and stop when the melting point is reached.

Let $T_0 = y$ be the initial temperature.
After 1 minute, the temperature becomes $T_1 = y + 1$.
After 2 minutes, the temperature becomes $T_2 = y + 1 + 2$.
After 3 minutes, the temperature becomes $T_3 = y + 1 + 2 + 3$.
...
After $m$ minutes, the temperature becomes $T_m = y + (1 + 2 + 3 + \dots + m)$.

The sum of the first $m$ positive integers is given by the formula:
$1 + 2 + 3 + \dots + m = \frac{m(m+1)}{2}$

So, the temperature after $m$ minutes is:
$T_m = y + \frac{m(m+1)}{2}$

We are looking for the smallest integer $m \ge 0$ such that $T_m \ge x$.
$y + \frac{m(m+1)}{2} \ge x$

The problem statement implies that we start melting from the current temperature `y`. If `y` is already greater than or equal to `x`, then 0 minutes are needed. However, the loop condition `current_temp < x` in the provided solution handles this implicitly: if `y >= x`, the loop won't execute, and `minutes` will remain 0.

The most straightforward approach is to simulate the process minute by minute. We start with the current temperature `y` and a count of minutes as 0. In each step, we increment the minute count and add the current minute number to the temperature. We continue this until the temperature reaches or exceeds the melting point `x`.

Let's trace an example: $x = 10, y = 3$.
- Initial: `current_temp = 3`, `minutes = 0`.
- `current_temp < x` (3 < 10) is true.
- Minute 1: `minutes = 1`, `current_temp = 3 + 1 = 4`.
- `current_temp < x` (4 < 10) is true.
- Minute 2: `minutes = 2`, `current_temp = 4 + 2 = 6`.
- `current_temp < x` (6 < 10) is true.
- Minute 3: `minutes = 3`, `current_temp = 6 + 3 = 9`.
- `current_temp < x` (9 < 10) is true.
- Minute 4: `minutes = 4`, `current_temp = 9 + 4 = 13`.
- `current_temp < x` (13 < 10) is false.
The loop terminates. The answer is `minutes = 4`.

The provided code implements this simulation approach directly. It initializes `current_temp` to `y` and `minutes` to 0. Then, it enters a `while` loop that continues as long as `current_temp` is less than `x`. Inside the loop, it increments `minutes` and adds the new `minutes` value to `current_temp`.

## Complexity Analysis
- **Time Complexity**: $O(\sqrt{x-y})$
The loop continues until $y + \frac{m(m+1)}{2} \ge x$. This inequality can be approximated as $\frac{m^2}{2} \approx x-y$, which means $m^2 \approx 2(x-y)$, and thus $m \approx \sqrt{2(x-y)}$. In the worst case, $y$ is small and $x$ is large, so the number of iterations is proportional to the square root of the difference between $x$ and $y$. Since the maximum value of $x$ and $y$ is not specified but is typically within integer limits for competitive programming problems, this complexity is efficient enough.

- **Space Complexity**: $O(1)$
The solution uses a fixed number of variables (`t`, `x`, `y`, `current_temp`, `minutes`) regardless of the input size. Therefore, the space complexity is constant.

## Solution Code
```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int x, y; // x: melting point, y: current temperature
        std::cin >> x >> y;

        int current_temp = y; // Initialize current temperature
        int minutes = 0;      // Initialize minutes counter

        // Simulate the temperature increase minute by minute
        // The loop continues as long as the current temperature is below the melting point
        while (current_temp < x) {
            minutes++;            // Increment the minute counter
            current_temp += minutes; // Add the current minute's temperature increase
        }

        // Output the minimum number of minutes required
        std::cout << minutes << "\n";
    }
    return 0;
}
```