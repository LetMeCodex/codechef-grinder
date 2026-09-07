# Practice makes us perfect (PRACTICEPERF)
- **Difficulty Rating**: 467
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine how many weeks Chef met his practice target. Chef has a target of solving at least 10 problems each week. We are given the number of problems solved by Chef in four consecutive weeks. We need to count how many of these four weeks Chef achieved his goal of solving 10 or more problems.

## Intuition & Mathematical Observation
The problem is straightforward. For each of the four weeks, we need to check if the number of problems solved is greater than or equal to 10. If it is, we increment a counter. After checking all four weeks, the value of the counter will be our answer.

Let $P_1, P_2, P_3, P_4$ be the number of problems solved in week 1, week 2, week 3, and week 4, respectively.
We need to calculate the sum of indicators:
$I(P_1 \ge 10) + I(P_2 \ge 10) + I(P_3 \ge 10) + I(P_4 \ge 10)$
where $I(\cdot)$ is the indicator function, which is 1 if the condition inside is true, and 0 otherwise.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The program reads four integer inputs and performs a constant number of comparisons (four `if` statements). The operations are independent of the input values' magnitude, making the time complexity constant.

- **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`p1`, `p2`, `p3`, `p4`, `weeks_met_target`) regardless of the input size. Therefore, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare four integer variables to store the number of problems
    // solved in each of the four weeks.
    int p1, p2, p3, p4;

    // Read the four integers from a single line of input.
    cin >> p1 >> p2 >> p3 >> p4;

    // Initialize a counter to keep track of how many weeks Chef met his target.
    int weeks_met_target = 0;

    // Check if Chef solved at least 10 problems in the first week.
    if (p1 >= 10) {
        weeks_met_target++; // If yes, increment the counter.
    }

    // Check for the second week.
    if (p2 >= 10) {
        weeks_met_target++;
    }

    // Check for the third week.
    if (p3 >= 10) {
        weeks_met_target++;
    }

    // Check for the fourth week.
    if (p4 >= 10) {
        weeks_met_target++;
    }

    // Output the final count of weeks where the target was met,
    // followed by a newline character.
    cout << weeks_met_target << "\n";

    return 0; // Indicate successful program execution.
}
```