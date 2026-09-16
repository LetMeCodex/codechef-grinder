# [Reach Home (REACH_HOME)](https://www.codechef.com/problems/REACH_HOME)
- **Difficulty Rating**: 395
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is at a certain location and needs to reach home. Chef has `X` litres of fuel. Each litre of fuel allows Chef to travel 5 kilometres. Chef's home is `Y` kilometres away. The problem asks whether Chef can reach home given the available fuel.

## Intuition & Mathematical Observation
The core of the problem lies in determining the maximum distance Chef can travel with the given fuel and comparing it to the distance to home.

1.  **Fuel Consumption:** Chef consumes 1 litre of fuel for every 5 kilometres traveled.
2.  **Maximum Reachable Distance:** If Chef has `X` litres of fuel, the maximum distance Chef can travel is `X * 5` kilometres.
3.  **Condition for Reaching Home:** Chef can reach home if and only if the maximum distance Chef can travel is greater than or equal to the distance to home (`Y`).

Therefore, the condition to check is: `X * 5 >= Y`.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations and comparisons for each test case. The number of test cases `T` is read, and then a loop runs `T` times. Inside the loop, the operations are constant time. Thus, the total time complexity is proportional to the number of test cases, but for each test case, it's $O(1)$.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`T`, `X`, `Y`, `max_distance_possible`) to store input and intermediate results. The amount of memory used does not grow with the input size (beyond the fixed number of variables), making it constant space.

## Solution Code

```cpp
#include <iostream> // Required for cin and cout

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before each cin, speeding up I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare integer variables X (fuel) and Y (distance).
        std::cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the maximum distance Chef can travel with X litres of fuel.
        // Chef can travel 5 kilometres per litre.
        int max_distance_possible = X * 5;

        // Check if the maximum distance Chef can travel is sufficient to reach home.
        if (max_distance_possible >= Y) {
            // If Chef can travel Y kilometres or more, output YES.
            std::cout << "YES\n";
        } else {
            // Otherwise, Chef cannot reach home, output NO.
            std::cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution.
}
```