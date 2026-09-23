# [Rating Improvement (ADVANCE)](https://www.codechef.com/problems/ADVANCE)
- **Difficulty Rating**: 400
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has a current CodeChef rating of `X`. To improve his rating, he is advised to solve problems with a difficulty `Y` such that `Y` falls within a specific range: `X <= Y <= X + 200`.

Given Chef's current rating `X` and the difficulty `Y` of a problem he is considering, the task is to determine if solving this problem would align with the recommended practice. Output "YES" if `Y` is within the recommended range, and "NO" otherwise.

The problem involves multiple test cases.

## Intuition & Mathematical Observation

The core of this problem lies in checking a simple range condition. Chef is following the recommended practice if and only if the problem difficulty `Y` satisfies two conditions simultaneously:
1. `Y` must be greater than or equal to Chef's current rating `X` (`Y >= X`).
2. `Y` must be less than or equal to Chef's current rating `X` plus 200 (`Y <= X + 200`).

If both of these conditions are true, then Chef is following the recommended practice, and we should output "YES". If either one or both conditions are false, then Chef is not following the recommended practice, and we should output "NO".

This can be directly translated into a conditional `if` statement using a logical AND operator (`&&`).

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the program performs a constant number of operations: reading two integers (`X` and `Y`), performing two comparisons (`Y >= X` and `Y <= X + 200`), and printing a string ("YES" or "NO"). Each of these operations takes constant time, $O(1)$. Since there are `T` test cases, the total time complexity is $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory regardless of the input values (other than the number of test cases `T` itself, which is typically small and fixed by problem constraints). It only stores a few integer variables (`X`, `Y`, `T`) at any given time. Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
// #include <bits/stdc++.h> is a common header in competitive programming
// that includes most standard library headers.
// For this specific problem, iostream is sufficient.

// Using the entire std namespace as requested by problem instructions.
using namespace std;

void solve() {
    int X, Y; // Declare two integer variables for Chef's rating X and problem difficulty Y
    cin >> X >> Y; // Read the values of X and Y from standard input

    // The recommended practice is to solve problems with difficulty Y
    // such that Y is in the range [X, X + 200].
    // This means two conditions must be met:
    // 1. Y must be greater than or equal to X (Y >= X)
    // 2. Y must be less than or equal to X + 200 (Y <= X + 200)
    if (Y >= X && Y <= X + 200) {
        // If both conditions are true, Chef is following the recommended practice.
        cout << "YES\n";
    } else {
        // Otherwise, Chef is not following the recommended practice.
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        solve(); // Call the solve function to handle each test case
    }

    return 0; // Indicate successful program execution
}
```