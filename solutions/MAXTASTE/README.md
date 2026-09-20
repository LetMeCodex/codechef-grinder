# [Maximise the Tastiness (MAXTASTE)](https://www.codechef.com/problems/MAXTASTE)
- **Difficulty Rating**: 627
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to prepare a dish that requires two ingredients.
For the first ingredient slot, Chef can choose between ingredient A and ingredient B.
For the second ingredient slot, Chef can choose between ingredient C and ingredient D.
Each ingredient has a specific tastiness value.
The goal is to determine the maximum possible total tastiness of the dish Chef can achieve by making the optimal choices for both ingredient slots.

## Intuition & Mathematical Observation

The core idea behind solving this problem is to recognize that the choices for the two ingredient slots are completely independent of each other. The tastiness gained from the first slot does not influence the tastiness values or choices available for the second slot, and vice-versa.

Therefore, to maximize the total tastiness of the dish, Chef should make the locally optimal choice for each ingredient slot independently:

1.  **For the first ingredient slot**: Chef can choose either ingredient A (with tastiness `a`) or ingredient B (with tastiness `b`). To maximize tastiness from this slot, Chef should simply pick the ingredient with the higher tastiness value. This can be represented as `max(a, b)`.

2.  **For the second ingredient slot**: Similarly, Chef can choose either ingredient C (with tastiness `c`) or ingredient D (with tastiness `d`). To maximize tastiness from this slot, Chef should pick the ingredient with the higher tastiness value. This can be represented as `max(c, d)`.

The maximum total tastiness of the dish will then be the sum of the maximum tastiness achieved from each independent slot: `max(a, b) + max(c, d)`.

This approach is a classic example of a greedy strategy that works because of the problem's independent subproblems structure.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    *   For each test case, we perform a constant number of operations: reading four integers, two `max` comparisons, one addition, and printing one integer. These operations take constant time.
    *   If there are $T$ test cases, the total time complexity will be $O(T)$.
*   **Space Complexity**: $O(1)$ per test case.
    *   We only use a few integer variables to store the input values and intermediate results (`a`, `b`, `c`, `d`, `max_tastiness_from_first_pair`, `max_tastiness_from_second_pair`, `total_max_tastiness`). The amount of memory used does not depend on the input values, making it constant space.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested.

using namespace std; // Uses the standard namespace, as requested.

void solve() {
    int a, b, c, d;
    // Read the tastiness values for ingredients A, B, C, and D.
    cin >> a >> b >> c >> d;

    // To maximize the total tastiness of the dish, Chef should make the optimal choice
    // for each ingredient slot independently.

    // For the first ingredient, Chef can choose either A or B.
    // To maximize tastiness, Chef should pick the one with higher tastiness.
    int max_tastiness_from_first_pair = max(a, b);

    // For the second ingredient, Chef can choose either C or D.
    // To maximize tastiness, Chef should pick the one with higher tastiness.
    int max_tastiness_from_second_pair = max(c, d);
    
    // The maximum possible tastiness of the dish is the sum of the maximums
    // from each ingredient slot.
    int total_max_tastiness = max_tastiness_from_first_pair + max_tastiness_from_second_pair;
    
    // Output the result for the current test case, followed by a newline.
    cout << total_max_tastiness << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases.
    cin >> t;
    // Loop through each test case.
    while (t--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}
```