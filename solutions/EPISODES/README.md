# [Episodes (EPISODES)](https://www.codechef.com/problems/EPISODES)
- **Difficulty Rating**: 498
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total duration of a series of episodes in hours and minutes. We are given two integers: `N`, the number of episodes, and `K`, the duration of each episode in minutes. We need to output the total time in the format "H M", where `H` is the total hours and `M` is the remaining minutes.

## Intuition & Mathematical Observation
The core idea is to first calculate the total time in minutes and then convert this total into hours and remaining minutes.

1.  **Calculate Total Minutes**: If there are `N` episodes and each episode lasts `K` minutes, the total time spent watching all episodes will simply be `N * K` minutes.
    `total_minutes = N * K`

2.  **Convert Total Minutes to Hours and Remaining Minutes**:
    *   To find the number of full hours (`H`), we can perform integer division of `total_minutes` by 60 (since there are 60 minutes in an hour). Integer division automatically truncates any fractional part, giving us only the full hours.
        `H = total_minutes / 60`
    *   To find the remaining minutes (`M`) after accounting for the full hours, we can use the modulo operator (`%`) with 60. This gives us the remainder when `total_minutes` is divided by 60, which will always be a value less than 60.
        `M = total_minutes % 60`

3.  **Constraints Check**:
    *   `N` is between 1 and 30.
    *   `K` is between 1 and 59.
    *   The maximum possible `total_minutes` would be `30 * 59 = 1770`. This value is small enough to fit comfortably within a standard `int` data type, so there's no concern about integer overflow.

The solution involves these simple arithmetic operations for each test case.

## Complexity Analysis
*   **Time Complexity**: $O(T)$
    For each test case, the program performs a constant number of arithmetic operations (multiplication, division, modulo) and two input/output operations. These operations take a fixed amount of time regardless of the values of `N` and `K`. Since there are `T` test cases, the total time complexity is directly proportional to `T`.

*   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`T`, `N`, `K`, `total_minutes`, `H`, `M`) to store input and intermediate calculations. The memory usage does not grow with the input values `N` or `K`. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested by the problem

using namespace std; // Uses the standard namespace, as requested by the problem

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, K; // Declare integer variables N and K for episodes and minutes per episode.
        cin >> N >> K; // Read N and K for the current test case.

        // Calculate the total time in minutes.
        // N * K will not overflow an int because N <= 30 and K < 60,
        // so max total_minutes = 30 * 59 = 1770.
        int total_minutes = N * K;

        // Calculate the number of full hours.
        // Integer division automatically truncates the decimal part.
        int H = total_minutes / 60;

        // Calculate the remaining minutes.
        // The modulo operator (%) gives the remainder, which will be < 60.
        int M = total_minutes % 60;

        // Output the calculated hours and minutes, separated by a space,
        // followed by a newline character for the next test case's output.
        cout << H << " " << M << "\n";
    }

    return 0; // Indicate successful program execution.
}
```