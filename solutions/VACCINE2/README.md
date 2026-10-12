# [Vaccine Distribution (VACCINE2)](https://www.codechef.com/problems/VACCINE2)
- **Difficulty Rating**: 1219
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum number of days required to vaccinate `N` people. We are given `D`, which is the maximum number of people that can be vaccinated per day.

People are categorized into two groups based on their age:
1.  **At-risk**: People whose age is either less than or equal to 9, OR greater than or equal to 80.
2.  **Not at-risk**: All other people.

A crucial constraint is that on any given day, you can only vaccinate people from *one* category. That is, you cannot vaccinate both an at-risk person and a not-at-risk person on the same day. We need to find the total minimum days to vaccinate everyone.

## Intuition & Mathematical Observation

1.  **Categorization is Key**: The first step is to separate the `N` people into the two distinct groups: "at-risk" and "not at-risk". We can do this by iterating through all `N` people, reading their age, and incrementing respective counters (`risk_count` and `non_risk_count`).

2.  **Independent Vaccination Schedules**: The problem explicitly states that at-risk and not-at-risk people cannot be vaccinated on the same day. This implies that the vaccination process for these two groups must be entirely independent. We can calculate the minimum days required for each group separately and then sum these days to get the total minimum days.

3.  **Calculating Days for a Group**: For any group of `X` people, if we can vaccinate `D` people per day, the number of days required is `ceil(X / D)`.
    *   For example, if there are 10 people in a group (`X=10`) and we can vaccinate 3 people per day (`D=3`), we need `ceil(10/3) = ceil(3.33) = 4` days. (3 people on day 1, 3 on day 2, 3 on day 3, and 1 on day 4).

4.  **Ceiling Division Formula**: In integer arithmetic, `ceil(A / B)` for positive integers `A` and `B` can be computed using the formula `(A + B - 1) / B`.
    *   If `A` is a multiple of `B` (e.g., `A=9, B=3`): `(9 + 3 - 1) / 3 = 11 / 3 = 3`. Correct.
    *   If `A` is not a multiple of `B` (e.g., `A=10, B=3`): `(10 + 3 - 1) / 3 = 12 / 3 = 4`. Correct.
    *   This formula also correctly handles the case where `A=0`. If `risk_count` or `non_risk_count` is 0, then `(0 + D - 1) / D` will evaluate to `0` (since `D-1 < D` for `D >= 1`), which is correct as 0 people need 0 days.

5.  **Total Days**: The total minimum days will be `days_for_risk + days_for_non_risk`.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    *   We iterate through `N` people once to categorize them, which takes $O(N)$ time.
    *   All other operations (reading `N`, `D`, calculations, printing) take constant time, $O(1)$.
    *   Since there are `T` test cases, the total time complexity would be $O(T \cdot N)$. Given typical constraints for `N` and `T` (e.g., `N` up to $10^5$, `T` up to $10^3$), this approach is efficient enough.

*   **Space Complexity**: $O(1)$.
    *   We only use a few integer variables to store counts and intermediate results (`N`, `D`, `risk_count`, `non_risk_count`, `age`, `days_for_risk`, `days_for_non_risk`, `total_days`). The memory usage does not depend on the input size `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested

// Using the standard namespace, as requested
using namespace std;

void solve() {
    int N, D;
    cin >> N >> D; // Read N (total people) and D (capacity per day)

    int risk_count = 0;       // Counter for people at risk
    int non_risk_count = 0;   // Counter for people not at risk

    for (int i = 0; i < N; ++i) {
        int age;
        cin >> age; // Read age of current person
        // A person is at risk if age is >= 80 OR age is <= 9
        if (age >= 80 || age <= 9) {
            risk_count++; // Person is at risk
        } else {
            non_risk_count++; // Person is not at risk
        }
    }

    // Calculate days needed for at-risk people.
    // The formula (A + B - 1) / B correctly computes ceil(A/B) for positive integers A, B.
    // It also correctly handles A=0, resulting in 0 days.
    int days_for_risk = (risk_count + D - 1) / D;

    // Calculate days needed for not-at-risk people.
    int days_for_non_risk = (non_risk_count + D - 1) / D;

    // The problem states that on any day, you cannot vaccinate both an at-risk
    // person and a not-at-risk person. This means the two groups must be
    // vaccinated on separate days. Therefore, the total minimum days is the
    // sum of days required for each group independently.
    int total_days = days_for_risk + days_for_non_risk;

    cout << total_days << "\n"; // Print the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```