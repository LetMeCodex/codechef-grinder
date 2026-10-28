# Chef And Salary Pay (HCAGMAM1)
- **Difficulty Rating**: 1269
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to calculate Chef's total salary for a month. Chef works for a fixed number of days, earning a base salary $X$ for each day worked. Additionally, Chef receives a bonus $Y$ for each day within their longest consecutive streak of working days. The input consists of $X$, $Y$, and a binary string of length 30 representing the month's work schedule, where '1' denotes a working day and '0' denotes a day off.

## Intuition & Mathematical Observation
The core of the problem lies in identifying the longest consecutive streak of '1's in the given binary string.

1.  **Base Salary Calculation**: The base salary is straightforward. For every '1' in the binary string, Chef earns $X$. So, we can simply count the number of '1's and multiply it by $X$.

2.  **Bonus Salary Calculation**: The bonus is awarded based on the longest consecutive sequence of working days. To find this, we can iterate through the binary string and maintain a `current_streak` counter.
    *   If we encounter a '1', we increment `current_streak`.
    *   If we encounter a '0', it signifies the end of a streak. We then compare `current_streak` with a `max_streak` variable and update `max_streak` if `current_streak` is larger. After updating `max_streak`, we reset `current_streak` to 0.
    *   A crucial edge case is when the longest streak extends to the very end of the 30-day period. The loop might finish before we have a chance to compare the final `current_streak` with `max_streak`. Therefore, after the loop finishes, we must perform one final comparison: `max_streak = std::max(max_streak, current_streak)`.

3.  **Total Salary**: The total salary is the sum of the base salary and the bonus salary. The bonus salary is calculated as `max_streak * Y`.

Let's consider an example:
$X = 100$, $Y = 50$, String = "11011101" (assuming a shorter string for illustration)

*   **Iteration 1**: `s[0] = '1'`. `actual_salary = 100`, `current_streak = 1`.
*   **Iteration 2**: `s[1] = '1'`. `actual_salary = 200`, `current_streak = 2`.
*   **Iteration 3**: `s[2] = '0'`. `max_streak = max(0, 2) = 2`. `current_streak = 0`.
*   **Iteration 4**: `s[3] = '1'`. `actual_salary = 300`, `current_streak = 1`.
*   **Iteration 5**: `s[4] = '1'`. `actual_salary = 400`, `current_streak = 2`.
*   **Iteration 6**: `s[5] = '1'`. `actual_salary = 500`, `current_streak = 3`.
*   **Iteration 7**: `s[6] = '0'`. `max_streak = max(2, 3) = 3`. `current_streak = 0`.
*   **Iteration 8**: `s[7] = '1'`. `actual_salary = 600`, `current_streak = 1`.

After loop: `max_streak = max(3, 1) = 3`.
Bonus salary = `max_streak * Y = 3 * 50 = 150`.
Total salary = `actual_salary + bonus_salary = 600 + 150 = 750`.

The problem statement guarantees the string length is exactly 30. This simplifies things as we don't need to handle variable string lengths.

## Complexity Analysis
- **Time Complexity**: $O(L)$, where $L$ is the length of the binary string. Since the string length is fixed at 30, the time complexity is effectively $O(1)$ for each test case. We iterate through the string once to calculate the base salary and find the maximum streak.
- **Space Complexity**: $O(L)$ for storing the input string. Since $L$ is fixed at 30, this is effectively $O(1)$ space complexity.

## Solution Code
```cpp
#include <cstdio>   // For scanf, printf
#include <algorithm> // For std::max

int main() {
    // No need for std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); with C-style I/O
    int t;
    scanf("%d", &t); // Read number of test cases
    while (t--) {
        long long x, y;
        scanf("%lld %lld", &x, &y); // Read X and Y
        char s[31]; // Character array for the string (length 30 + null terminator)
        scanf("%s", s); // Read the binary string

        long long actual_salary = 0;
        int max_streak = 0;
        int current_streak = 0;

        // Iterate through the string. The problem states string length is exactly 30.
        for (int i = 0; i < 30; ++i) {
            if (s[i] == '1') {
                actual_salary += x; // Add X for each working day
                current_streak++;   // Increment current streak
            } else {
                max_streak = std::max(max_streak, current_streak); // Update max streak if current streak is longer
                current_streak = 0; // Reset current streak on leave day
            }
        }
        // After the loop, check if the longest streak ends at the very end of the string
        max_streak = std::max(max_streak, current_streak);

        long long bonus_salary = (long long)max_streak * y; // Calculate bonus salary
        long long total_salary = actual_salary + bonus_salary; // Calculate total salary

        printf("%lld\n", total_salary); // Print the result
    }
    return 0;
}
```