# [Literacy Rate (LITRATE)](https://www.codechef.com/problems/LITRATE)
- **Difficulty Rating**: 512
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a country's literacy rate meets a specific criterion. We are given two integers: `P`, the total population of the country, and `L`, the number of literate people in that country. The literacy rate is calculated as `(L / P) * 100`. We need to output "YES" if the literacy rate is greater than or equal to 75%, and "NO" otherwise. The input includes multiple test cases.

## Intuition & Mathematical Observation

The core of the problem is to check the condition `(L / P) * 100 >= 75`.

A common pitfall in competitive programming when dealing with percentages or fractions is to use floating-point arithmetic directly. Floating-point numbers (like `float` or `double` in C++) can introduce precision errors, especially with division, which might lead to incorrect results for boundary cases.

To avoid floating-point issues, we can transform the inequality into an equivalent form using only integer arithmetic.

1.  **Start with the given condition**:
    `(L / P) * 100 >= 75`

2.  **Multiply both sides by `P`**: Since `P` is the total population and is always positive (given `1 <= L <= P`), multiplying by `P` does not change the direction of the inequality.
    `L * 100 >= 75 * P`

3.  **Simplify the coefficients**: Both 100 and 75 are divisible by 25. Dividing both sides of the inequality by 25 (a positive number) will further simplify the expression without changing its truth value.
    `(L * 100) / 25 >= (75 * P) / 25`
    `L * 4 >= P * 3`
    or equivalently,
    `4 * L >= 3 * P`

This final inequality `4 * L >= 3 * P` uses only integer multiplication and comparison, completely avoiding floating-point numbers.

**Constraints Check**:
The problem states `1 <= L <= P <= 100`.
*   The maximum value for `4 * L` would be `4 * 100 = 400`.
*   The maximum value for `3 * P` would be `3 * 100 = 300`.
These values are small and fit comfortably within a standard `int` data type, so there's no risk of integer overflow.

Thus, for each test case, we simply read `P` and `L`, calculate `4 * L` and `3 * P`, and compare them.

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a constant number of operations: two integer multiplications, one integer comparison, and one input/output operation. This takes constant time, $O(1)$. Since there are $T$ test cases, the total time complexity will be $O(T)$.

*   **Space Complexity**: We only use a few integer variables (`P`, `L`, `T`) to store input and intermediate results. This amount of memory is constant and does not depend on the input size. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries as requested

using namespace std; // Allows using standard library elements without std:: prefix

void solve() {
    int P, L;
    cin >> P >> L; // Read total population P and literate people L

    // The literacy rate is (L/P) * 100.
    // We need to check if (L/P) * 100 >= 75.
    // To avoid floating-point arithmetic and potential precision errors,
    // we transform the inequality into an integer-only comparison:
    // L * 100 >= 75 * P
    // Both 100 and 75 are divisible by 25. Dividing both sides by 25:
    // L * (100 / 25) >= P * (75 / 25)
    // L * 4 >= P * 3
    // This is equivalent to 4 * L >= 3 * P.

    // Constraints: 1 <= L <= P <= 100.
    // Maximum value for 4 * L is 4 * 100 = 400.
    // Maximum value for 3 * P is 3 * 100 = 300.
    // These values fit comfortably within an 'int' type, so no overflow issues.

    if (4 * L >= 3 * P) {
        cout << "YES\n"; // If the condition is met, print YES
    } else {
        cout << "NO\n";  // Otherwise, print NO
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```