# [Candy Love (CNDLOVE)](https://www.codechef.com/problems/CNDLOVE)
- **Difficulty Rating**: 1054
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem presents `N` candy packs, with the `i`-th pack containing `A_i` candies. We are asked to determine if a specific condition related to dividing all candies into two parts is met. Based on the provided solution code and the example test cases on CodeChef, the problem effectively asks: **Is the total sum of all candies an odd number?** If the total sum is odd, we should output "YES"; otherwise, we output "NO".

## Intuition & Mathematical Observation
The core idea behind the solution is to calculate the total number of candies available and then check its parity (whether it's odd or even).

1.  **Calculate the Total Sum**: We need to sum up the number of candies from all `N` packs. We can do this by initializing a `sum_candies` variable to 0 and then iterating `N` times, reading each `A_i` and adding it to `sum_candies`.
    Let this total sum be `S`.
    $$S = \sum_{i=1}^{N} A_i$$
2.  **Check Parity**: Once we have the total sum `S`, the problem (as interpreted by the solution and examples) requires us to check its parity:
    *   If `S` modulo 2 is 1 (`S % 2 == 1`), it means `S` is an odd number. In this case, the output should be "YES".
    *   If `S` modulo 2 is 0 (`S % 2 == 0`), it means `S` is an even number. In this case, the output should be "NO".

This straightforward parity check of the total sum directly implements the logic observed in the provided solution code and matches the example test cases on CodeChef.

## Complexity Analysis
-   **Time Complexity**: $O(N)$
    For each test case, the program iterates `N` times to read the `A_i` values and accumulate their sum. This loop dominates the execution time, making it $O(N)$. Reading `N` and performing the final parity check are constant time operations, $O(1)$. Since there are `T` test cases, the total time complexity would be $O(T \cdot N)$.
-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables such as `N`, `sum_candies`, and `A_i` (which is read one at a time). This space requirement does not grow with the input size `N`.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, etc.

using namespace std; // Use the standard namespace

void solve() {
    int N;
    cin >> N; // Read the number of candy packs

    int sum_candies = 0; // Initialize total candies to 0
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the number of candies in the current pack
        sum_candies += A_i; // Add to the total sum
    }

    // If the total sum of candies is odd, output YES.
    // Otherwise (if it's even), output NO.
    if (sum_candies % 2 == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```