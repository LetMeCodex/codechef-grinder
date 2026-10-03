# [Olympics 2024 (OLYMPICS24)](https://www.codechef.com/problems/OLYMPICS24)
- **Difficulty Rating**: 283
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the total number of additional medals Chefland needs to win to achieve a specific target. Chefland wants to have exactly 5 gold medals, 5 silver medals, and 5 bronze medals. We are given the current number of gold (`G`), silver (`S`), and bronze (`B`) medals Chefland has already won. We need to output the sum of additional gold, silver, and bronze medals required to reach the target.

## Intuition & Mathematical Observation

The core idea is to calculate the deficit for each medal type and then sum these deficits.

1.  **Target for each medal type**: Chefland aims for 5 gold, 5 silver, and 5 bronze medals.
2.  **Current medals**: We are given `G` gold, `S` silver, and `B` bronze medals.
3.  **Constraints**: The problem states that `1 <= G, S, B <= 5`. This is an important observation because it means Chefland will never have *more* than 5 medals of any type currently. Thus, we only need to calculate how many *more* are needed, not how many to remove.
4.  **Additional medals needed for each type**:
    *   Additional gold needed = `5 - G`
    *   Additional silver needed = `5 - S`
    *   Additional bronze needed = `5 - B`
5.  **Total additional medals**: The final answer is the sum of these three values: `(5 - G) + (5 - S) + (5 - B)`.

For example, if Chefland has 3 gold, 2 silver, and 5 bronze:
*   Needed gold = `5 - 3 = 2`
*   Needed silver = `5 - 2 = 3`
*   Needed bronze = `5 - 5 = 0`
*   Total needed = `2 + 3 + 0 = 5`

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values (reading three integers, three subtractions, two additions, and one print operation). These operations take constant time.

*   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables to store the medal counts and intermediate calculations. The memory usage does not scale with any input size, making it constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and prevents flushing
    // operations that can slow down execution, especially for large inputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the number of gold, silver,
    // and bronze medals won by Chefland, respectively.
    int G, S, B;

    // Read the three space-separated integers from the standard input.
    // These represent the current counts of gold, silver, and bronze medals.
    cin >> G >> S >> B;

    // Chef will be happy only if the team wins 5 medals of each type.
    // We need to calculate the additional medals required for each type.
    // Since the constraints state 1 <= G, S, B <= 5, the current medal counts
    // will never exceed the target of 5.
    // Therefore, the number of additional medals needed for a type is simply
    // 5 minus the current count for that type.

    // Calculate additional gold medals needed.
    // If G is 5, needed_gold will be 0. If G is less than 5, it will be 5 - G.
    int needed_gold = 5 - G;

    // Calculate additional silver medals needed.
    // If S is 5, needed_silver will be 0. If S is less than 5, it will be 5 - S.
    int needed_silver = 5 - S;

    // Calculate additional bronze medals needed.
    // If B is 5, needed_bronze will be 0. If B is less than 5, it will be 5 - B.
    int needed_bronze = 5 - B;

    // The total number of additional medals needed is the sum of additional
    // gold, silver, and bronze medals.
    int total_needed_medals = needed_gold + needed_silver + needed_bronze;

    // Output the calculated total number of additional medals to the standard output,
    // followed by a newline character as required.
    cout << total_needed_medals << "\n";

    // Indicate successful program execution.
    return 0;
}
```