# [Two vs Ten (TWOVSTEN)](https://www.codechef.com/problems/TWOVSTEN)
- **Difficulty Rating**: 936
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of turns required to make a given integer $X$ divisible by 10. In one turn, we can multiply $X$ by 2. If it's impossible to make $X$ divisible by 10, we should output -1. We need to solve this for multiple test cases.

## Intuition & Mathematical Observation

The core of this problem lies in understanding divisibility rules and how the allowed operation (multiplying by 2) affects the factors of a number.

1.  **Divisibility by 10**: A number is divisible by 10 if and only if it is divisible by both 2 and 5. This means its prime factorization must include at least one factor of 2 and at least one factor of 5.

2.  **The Operation**: We can multiply $X$ by 2 in one turn. This operation only introduces or increases the count of factor 2 in $X$'s prime factorization. It *never* introduces a factor of 5.

Let's analyze the possible scenarios for $X$:

*   **Case 1: $X$ is already divisible by 10.**
    *   If $X$ is already divisible by 10, it means $X$ already has both a factor of 2 and a factor of 5.
    *   No turns are needed. The answer is 0.
    *   This can be checked using `X % 10 == 0`.

*   **Case 2: $X$ is not divisible by 10, but is divisible by 5.**
    *   If $X$ is divisible by 5, it means $X$ has a factor of 5.
    *   Since $X$ is *not* divisible by 10, it must be an odd multiple of 5 (e.g., 5, 15, 25, 35, etc.). This implies $X$ lacks a factor of 2 (or enough factors of 2 to make it divisible by 10).
    *   To make $X$ divisible by 10, we need to introduce a factor of 2.
    *   Multiplying $X$ by 2 once will introduce the necessary factor of 2. For example, if $X=5$, after 1 turn it becomes $5 \times 2 = 10$. If $X=25$, after 1 turn it becomes $25 \times 2 = 50$. Both 10 and 50 are divisible by 10.
    *   Therefore, exactly 1 turn is needed. The answer is 1.
    *   This can be checked using `X % 5 == 0` (and implicitly `X % 10 != 0` from the previous condition).

*   **Case 3: $X$ is not divisible by 5.**
    *   If $X$ is not divisible by 5, it means $X$ does not have a factor of 5 in its prime factorization.
    *   Since our only allowed operation is multiplying by 2, we can only add factors of 2 to $X$. We can never introduce a factor of 5.
    *   Without a factor of 5, $X$ can never become divisible by 10.
    *   Therefore, it's impossible. The answer is -1.
    *   This is the `else` case after checking the first two conditions.

These three cases cover all possibilities and lead directly to the solution logic.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, the `solve()` function performs a constant number of operations: one input read, two modulo operations (`%`), and one output print. Since there are $T$ test cases, the total time complexity is proportional to $T$.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory for variables like `x` and `t`, regardless of the input values or the number of test cases. This makes the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested

using namespace std; // Allows direct use of names like cin, cout, etc., as requested

// Function to solve a single test case
void solve() {
    int x; // Declare an integer variable x to store the input number
    cin >> x; // Read the value of x from standard input

    // Condition 1: If X is already divisible by 10
    // A number is divisible by 10 if its remainder when divided by 10 is 0.
    // In this case, 0 turns are needed.
    if (x % 10 == 0) {
        cout << 0 << "\n"; // Print 0 followed by a newline character
    } 
    // Condition 2: If X is not divisible by 10, but is divisible by 5
    // This implies X is an odd multiple of 5 (e.g., 5, 15, 25, 35, ...).
    // To make it divisible by 10, it needs to be divisible by both 2 and 5.
    // It already has a factor of 5. Since it's an odd number, it lacks a factor of 2.
    // Multiplying X by 2 once (1 turn) will introduce the factor of 2,
    // making it an even multiple of 5, and thus divisible by 10.
    // Example: If X = 25, after 1 turn it becomes 25 * 2 = 50, which is divisible by 10.
    else if (x % 5 == 0) {
        cout << 1 << "\n"; // Print 1 followed by a newline character
    } 
    // Condition 3: If X is not divisible by 5
    // If X does not have a factor of 5, multiplying it by 2 (which only adds factors of 2)
    // will never introduce a factor of 5. Therefore, it's impossible to make X divisible by 10.
    // Example: If X = 1, 2, 3, 4, 6, 7, 8, 9, etc., it will never become divisible by 5.
    else {
        cout << -1 << "\n"; // Print -1 followed by a newline character
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    cin.tie(NULL); // Prevents cin from flushing cout before each input operation

    int t; // Declare an integer variable t for the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```