# [Grade The Steel (FLOW014)](https://www.codechef.com/problems/FLOW014)
- **Difficulty Rating**: 838
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the grade of a steel sample based on three properties: Hardness, Carbon Content, and Tensile Strength. We are given specific conditions for each property:
1.  **Hardness**: Must be greater than 50.
2.  **Carbon Content**: Must be less than 0.7.
3.  **Tensile Strength**: Must be greater than 5600.

The grading system is hierarchical, meaning certain combinations of met conditions lead to higher grades. The grades are assigned as follows:
*   **Grade 10**: All three conditions are met.
*   **Grade 9**: Conditions 1 and 2 are met.
*   **Grade 8**: Conditions 2 and 3 are met.
*   **Grade 7**: Conditions 1 and 3 are met.
*   **Grade 6**: Only one of the three conditions is met.
*   **Grade 5**: None of the three conditions are met.

We need to process multiple test cases, reading the three properties for each steel sample and printing its corresponding grade.

## Intuition & Mathematical Observation

The core of this problem lies in evaluating three independent boolean conditions and then applying a specific hierarchy to determine the final grade.

1.  **Define Boolean Conditions**: The first step is to clearly define each of the three conditions as boolean variables. This makes the logic cleaner and easier to read.
    *   `cond1 = (hardness > 50)`
    *   `cond2 = (carbon_content < 0.7)`
    *   `cond3 = (tensile_strength > 5600)`

2.  **Apply Hierarchical Grading**: The problem specifies a clear hierarchy for assigning grades. This means we should check for the highest possible grade first, and if that condition isn't met, move to the next highest, and so on. An `if-else if` ladder is perfectly suited for this.

    *   **Grade 10 (Highest Priority)**: Check if `cond1 && cond2 && cond3` are all true. If so, assign Grade 10.
    *   **Grade 9**: If not Grade 10, check if `cond1 && cond2` are true. Since Grade 10 was already checked, if this condition is met, it implicitly means `cond3` must be false.
    *   **Grade 8**: If not Grade 10 or 9, check if `cond2 && cond3` are true. This implies `cond1` must be false.
    *   **Grade 7**: If not Grade 10, 9, or 8, check if `cond1 && cond3` are true. This implies `cond2` must be false.
    *   **Grade 6**: If none of the above (two or three conditions met) are true, we then check if *at least one* condition is met. A simple `cond1 || cond2 || cond3` check suffices here. If this is true, and none of the higher-grade conditions were met, it means exactly one condition must be true.
    *   **Grade 5 (Lowest Priority)**: If none of the above conditions are met, it means zero conditions are met, and the grade is 5. This will be the final `else` block.

This `if-else if` structure ensures that the most specific and highest-grade conditions are evaluated first, correctly implementing the problem's hierarchy.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, the program performs a fixed number of operations:
    *   Reading three input values.
    *   Performing three comparisons to determine the boolean conditions.
    *   Executing a series of `if-else if` checks, which involve constant-time boolean logic operations.
    Since these operations take constant time per test case, and there are `T` test cases, the total time complexity is directly proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory regardless of the input values or the number of test cases (beyond the loop counter `T`). It stores a few integer variables (`T`, `hardness`, `tensile_strength`, `grade`), a double variable (`carbon_content`), and three boolean variables (`cond1`, `cond2`, `cond3`). This memory usage is constant, hence the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header for competitive programming
using namespace std; // Required namespace for competitive programming

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the total number of testcases

    while (T--) { // Loop T times, once for each testcase
        int hardness;
        double carbon_content; // Carbon content can be a decimal value (e.g., 0.6, 0.7)
        int tensile_strength;

        // Read the three properties for the current steel sample
        cin >> hardness >> carbon_content >> tensile_strength;

        int grade; // Variable to store the calculated grade

        // Evaluate each of the three conditions
        bool cond1 = (hardness > 50);
        bool cond2 = (carbon_content < 0.7);
        bool cond3 = (tensile_strength > 5600);

        // Determine the grade based on the specified hierarchy of conditions
        if (cond1 && cond2 && cond3) {
            grade = 10; // Grade 10: All three conditions met
        } else if (cond1 && cond2) {
            grade = 9; // Grade 9: Conditions 1 and 2 met (and condition 3 is NOT met, otherwise it would be Grade 10)
        } else if (cond2 && cond3) {
            grade = 8; // Grade 8: Conditions 2 and 3 met (and condition 1 is NOT met)
        } else if (cond1 && cond3) {
            grade = 7; // Grade 7: Conditions 1 and 3 met (and condition 2 is NOT met)
        } else if (cond1 || cond2 || cond3) {
            grade = 6; // Grade 6: Only one condition is met.
                        // (If two or three conditions were met, they would have been caught by previous if/else if blocks)
        } else {
            grade = 5; // Grade 5: None of the three conditions are met
        }

        // Print the calculated grade for the current testcase, followed by a newline
        cout << grade << "\n";
    }

    return 0; // Indicate successful program execution
}
```