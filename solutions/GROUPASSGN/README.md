# [Group Assignment (GROUPASSGN)](https://www.codechef.com/problems/GROUPASSGN)
- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the partner's roll number for Chef, given the total number of groups `N` and Chef's roll number `X`. There are a total of `2N` students, with roll numbers ranging from `1` to `2N`. The students are paired into `N` groups according to a specific rule:
- Student with roll number `1` is paired with student `2N`.
- Student with roll number `2` is paired with student `2N - 1`.
- This pattern continues until student `N` is paired with student `N + 1`.

We need to output the roll number of Chef's partner for each test case.

## Intuition & Mathematical Observation

Let's analyze the pairing rule provided:
- Group 1: `(1, 2N)`
- Group 2: `(2, 2N - 1)`
- Group 3: `(3, 2N - 2)`
...
- Group N: `(N, N + 1)`

If we observe the sum of the roll numbers in each pair, we notice a consistent pattern:
- For `(1, 2N)`, the sum is `1 + 2N = 2N + 1`.
- For `(2, 2N - 1)`, the sum is `2 + (2N - 1) = 2N + 1`.
- For `(3, 2N - 2)`, the sum is `3 + (2N - 2) = 2N + 1`.
...
- For `(N, N + 1)`, the sum is `N + (N + 1) = 2N + 1`.

This means that for any pair of students `(A, B)` in a group, their roll numbers will always sum up to `2N + 1`.

Given Chef's roll number `X`, and letting `P` be the roll number of Chef's partner, we can establish the equation:
`X + P = 2N + 1`

To find Chef's partner's roll number `P`, we can simply rearrange the equation:
`P = (2N + 1) - X`

This formula directly gives us the partner's roll number for any given `N` and `X`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The solution processes `T` test cases. For each test case, it performs a constant number of operations: reading two integers (`N` and `X`), performing a few arithmetic calculations (multiplication, addition, subtraction), and printing an integer. These operations take constant time, $O(1)$. Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`T`, `N`, `X`, `partner_roll_number`) to store input and intermediate results. The memory usage does not depend on the input values `N` or `X` (within standard integer limits). Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common standard libraries like iostream

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, X;
        cin >> N >> X; // Read N (number of groups) and X (Chef's roll number)

        // The problem states that groups are formed such that:
        // (1, 2N), (2, 2N-1), ..., (N, N+1)
        // Observe that the sum of roll numbers in each pair is constant:
        // 1 + 2N = 2N + 1
        // 2 + (2N-1) = 2N + 1
        // ...
        // N + (N+1) = 2N + 1
        // So, if Chef's roll number is X, and his partner's roll number is P,
        // then X + P must equal 2N + 1.
        // Therefore, P = (2N + 1) - X.
        int partner_roll_number = (2 * N + 1) - X;

        // Output the calculated partner's roll number, followed by a newline.
        cout << partner_roll_number << "\n";
    }

    return 0; // Indicate successful execution
}
```