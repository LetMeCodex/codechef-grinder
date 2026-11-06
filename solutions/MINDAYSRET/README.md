Here's a clean, high-quality solution writeup in GitHub-Flavored Markdown for the CodeChef problem "Back to Campus (MINDAYSRET)".

---

# [Back to Campus (MINDAYSRET)](https://www.codechef.com/problems/MINDAYSRET)
- **Difficulty Rating**: 933
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum number of days required to send `N` students back to campus. We are given that `K` students can be sent back each day. We need to find this minimum number of days for several test cases.

## Intuition & Mathematical Observation

The core of this problem lies in a simple division. If we have `N` students and can send `K` students per day, we are essentially trying to figure out how many groups of `K` students we can form from `N` students, and if there's a remainder, that remainder forms an additional group.

This is a classic "ceiling division" problem. We need to find `ceil(N / K)`.

Let's consider a few examples:
*   If `N = 10` students and `K = 5` students per day:
    *   Day 1: 5 students sent.
    *   Day 2: 5 students sent.
    *   Total: 2 days. `ceil(10 / 5) = 2`.
*   If `N = 12` students and `K = 5` students per day:
    *   Day 1: 5 students sent. (7 remaining)
    *   Day 2: 5 students sent. (2 remaining)
    *   Day 3: 2 students sent. (0 remaining)
    *   Total: 3 days. `ceil(12 / 5) = ceil(2.4) = 3`.

In integer arithmetic, `ceil(a / b)` can be efficiently calculated using the formula `(a + b - 1) / b`.

Let's verify this formula:
*   For `N = 10, K = 5`: `(10 + 5 - 1) / 5 = 14 / 5 = 2` (integer division). Correct.
*   For `N = 12, K = 5`: `(12 + 5 - 1) / 5 = 16 / 5 = 3` (integer division). Correct.

This formula works because:
*   If `N` is a perfect multiple of `K` (e.g., `N = m * K`), then `(m * K + K - 1) / K` will result in `m` via integer division.
*   If `N` is not a perfect multiple of `K` (e.g., `N = m * K + r`, where `1 <= r < K`), then `(m * K + r + K - 1) / K = ((m + 1) * K + r - 1) / K`. Since `0 <= r - 1 < K - 1`, the integer division will correctly yield `m + 1`, which is `ceil(N / K)`.

Thus, the solution involves reading `N` and `K` and applying this integer arithmetic formula.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the solution performs a constant number of arithmetic operations (addition, subtraction, division) and input/output operations. These operations take constant time, $O(1)$. Since there are `T` test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution only uses a few integer variables (`N`, `K`, `days`, `T`) to store input and intermediate results. The amount of memory used does not depend on the input size `N` or `K`. Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and other standard libraries

// Use the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K;
    // Read the total number of students (N) and the capacity per day (K)
    cin >> N >> K;

    // Calculate the minimum number of days required.
    // This is equivalent to ceil(N / K).
    // Using integer division, ceil(a/b) can be calculated as (a + b - 1) / b
    int days = (N + K - 1) / K;

    // Print the result for the current test case, followed by a newline
    cout << days << "\n";
}

int main() {
    // Critical Instruction: Enable fast I/O
    // This unties cin from cout and disables synchronization with C's stdio,
    // significantly speeding up input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}
```