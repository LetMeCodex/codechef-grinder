# [Gold Mining (CARRYGOLD)](https://www.codechef.com/problems/CARRYGOLD)
- **Difficulty Rating**: 880
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a group of people, consisting of Chef and $N$ friends, can carry a total of $X$ kg of gold. Each person in the group can carry a maximum of $Y$ kg of gold.

## Intuition & Mathematical Observation
The core of this problem lies in calculating the total carrying capacity of the group and comparing it with the total amount of gold that needs to be carried.

1.  **Total number of people**: The group consists of Chef and $N$ friends. Therefore, the total number of people is $1 + N$.

2.  **Maximum carrying capacity per person**: Each person can carry at most $Y$ kg of gold.

3.  **Total carrying capacity of the group**: To find the maximum amount of gold the entire group can carry, we multiply the total number of people by the maximum carrying capacity per person.
    Total Carrying Capacity = (Total number of people) $\times$ (Maximum carrying capacity per person)
    Total Carrying Capacity = $(1 + N) \times Y$

4.  **Decision**: If the `Total Carrying Capacity` is greater than or equal to the total amount of gold to be carried ($X$), then it is possible to carry all the gold. Otherwise, it is not.

    *   If $(1 + N) \times Y \ge X$, output "YES".
    *   If $(1 + N) \times Y < X$, output "NO".

The constraints on $N$, $X$, and $Y$ are up to 1000.
The maximum value for $(1+N) \times Y$ would be $(1+1000) \times 1000 = 1001 \times 1000 = 1,001,000$. This value fits well within a standard 32-bit signed integer type (like `int` in C++), which can typically hold values up to approximately $2 \times 10^9$. Therefore, no special data types like `long long` are strictly necessary for the calculation, although using them would also be correct and safe.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    For each test case, we perform a fixed number of arithmetic operations (addition, multiplication, comparison) and input/output operations. These operations take constant time. Since there are $T$ test cases, the total time complexity is $O(T \times 1) = O(T)$. However, if we consider the complexity per test case, it is $O(1)$.

-   **Space Complexity**: $O(1)$
    We only use a few variables to store the input values ($N$, $X$, $Y$) and intermediate results. The amount of memory used does not depend on the input size, making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested by the problem statement.

using namespace std; // Uses the standard namespace, as requested by the problem statement.

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to avoid TLE (Time Limit Exceeded) on large inputs.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams.
    cin.tie(NULL); // Unties cin from cout, preventing flushing of cout before each cin.

    int T;
    cin >> T; // Read the number of testcases.

    while (T--) { // Loop T times, processing each testcase.
        int N, X, Y;
        cin >> N >> X >> Y; // Read the three integers N, X, Y for the current testcase.

        // Calculate the total number of people going to the gold mine.
        // Chef + N friends = N + 1 people.
        int total_people = N + 1;

        // Calculate the maximum total amount of gold all people can carry together.
        // Each person can carry at most Y kg.
        // So, total_carrying_capacity = (total_people) * Y.
        // Given N, X, Y <= 1000, the maximum value for (N+1)*Y would be (1000+1)*1000 = 1,001,000.
        // This value fits comfortably within a standard 32-bit signed integer type (like 'int' in C++),
        // which typically holds values up to ~2 * 10^9. So, 'long long' is not strictly necessary but harmless.
        int total_carrying_capacity = total_people * Y;

        // Check if the total carrying capacity is sufficient to carry all the gold (X kg).
        if (total_carrying_capacity >= X) {
            cout << "YES\n"; // If capacity is enough or more, output "YES".
        } else {
            cout << "NO\n"; // Otherwise, output "NO".
        }
    }

    return 0; // Indicate successful program execution.
}
```