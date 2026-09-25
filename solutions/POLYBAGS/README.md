# [Too many items (POLYBAGS)](https://www.codechef.com/problems/POLYBAGS)
- **Difficulty Rating**: 738
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum number of polybags required to store a given number of items, `N`. Each polybag has a capacity of at most 10 items. We need to solve this for multiple test cases.

## Intuition & Mathematical Observation

The core of this problem is to determine how many containers are needed when each container has a fixed maximum capacity. Since we want the *minimum* number of polybags, we should fill each polybag to its maximum capacity (10 items) whenever possible.

Consider the number of items `N`:

1.  **If `N` is a multiple of 10** (e.g., 20, 30, 100):
    In this case, `N / 10` polybags will be perfectly filled, and no items will be left over. So, `N / 10` polybags are needed.

2.  **If `N` is not a multiple of 10** (e.g., 24, 33, 1):
    Here, `N / 10` (integer division) polybags will be completely filled. There will be `N % 10` items remaining. Since `N % 10` will be greater than 0, these remaining items, no matter how few (even just 1 item), will require one additional polybag.
    So, `(N / 10) + 1` polybags are needed.

This pattern is a classic example of **ceiling division**. We need to calculate `ceil(N / 10)`.
In integer arithmetic, for positive integers `a` and `b`, `ceil(a / b)` can be efficiently calculated using the formula: `(a + b - 1) / b`.

Applying this formula to our problem where `a = N` and `b = 10`:
The minimum number of polybags needed is `(N + 10 - 1) / 10`, which simplifies to `(N + 9) / 10`.

Let's test this formula with a few examples:
*   If `N = 20`: `(20 + 9) / 10 = 29 / 10 = 2` (integer division). Correct, 2 polybags.
*   If `N = 24`: `(24 + 9) / 10 = 33 / 10 = 3` (integer division). Correct, 3 polybags (2 full, 1 for the remaining 4 items).
*   If `N = 1`: `(1 + 9) / 10 = 10 / 10 = 1` (integer division). Correct, 1 polybag for 1 item.
*   If `N = 10`: `(10 + 9) / 10 = 19 / 10 = 1` (integer division). Correct, 1 polybag for 10 items.

The formula `(N + 9) / 10` correctly handles all cases.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of arithmetic operations (addition, division) and an input/output operation. These operations take constant time, $O(1)$. Since there are `T` test cases, the total time complexity is proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution only uses a few integer variables (`T`, `N`, `polybags_needed`) to store input and intermediate results. The amount of memory used does not depend on the input size `N` or the number of test cases `T`. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which speeds up I/O operations significantly.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        int N; // Declare an integer variable N for the number of items
        cin >> N; // Read the number of items for the current test case

        // Calculate the minimum number of polybags needed.
        // Each polybag can contain at most 10 items.
        // This is a classic ceiling division problem: ceil(N / 10).
        // In integer arithmetic, for positive integers 'a' and 'b',
        // ceil(a / b) can be calculated as (a + b - 1) / b.
        // Here, 'a' is N and 'b' is 10.
        // So, the formula becomes (N + 10 - 1) / 10, which simplifies to (N + 9) / 10.
        //
        // Example:
        // N = 20: (20 + 9) / 10 = 29 / 10 = 2. (2 polybags)
        // N = 24: (24 + 9) / 10 = 33 / 10 = 3. (3 polybags)
        // N = 99: (99 + 9) / 10 = 108 / 10 = 10. (10 polybags)
        // N = 1: (1 + 9) / 10 = 10 / 10 = 1. (1 polybag)
        int polybags_needed = (N + 9) / 10;

        // Output the result for the current test case, followed by a newline character.
        // Using "\n" is generally faster than endl in competitive programming
        // because endl also forces a flush of the output buffer.
        cout << polybags_needed << "\n";
    }

    return 0; // Indicate successful program execution
}
```