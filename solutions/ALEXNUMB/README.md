# [Magic Pairs (ALEXNUMB)](https://www.codechef.com/problems/ALEXNUMB)
- **Difficulty Rating**: 1245
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to count the number of ordered pairs of indices `(i, j)` such that `1 <= i, j <= n`, `i != j`, and `a_i < a_j`. We are given `n` distinct integers `a_1, a_2, ..., a_n`.

## Intuition & Mathematical Observation

The key information here is that all `n` integers `a_1, a_2, ..., a_n` are **distinct**. This simplifies the problem significantly.

Let's consider any two distinct indices `i` and `j` from `1` to `n`. Since `a_i` and `a_j` are distinct (because all `a_k` are distinct), exactly one of the following two conditions must be true:
1.  `a_i < a_j`
2.  `a_j < a_i`

This means that for every unique *unordered* pair of distinct indices `{i, j}`, exactly one of the two possible *ordered* pairs `(i, j)` or `(j, i)` will satisfy the condition `a_x < a_y`.

For example, if we have `n=3` and `a = [5, 2, 8]`:
*   The unique unordered pairs of distinct indices are:
    *   `{1, 2}`: `a_1 = 5`, `a_2 = 2`. Here, `a_2 < a_1` is true. So, `(2, 1)` is a valid ordered pair.
    *   `{1, 3}`: `a_1 = 5`, `a_3 = 8`. Here, `a_1 < a_3` is true. So, `(1, 3)` is a valid ordered pair.
    *   `{2, 3}`: `a_2 = 2`, `a_3 = 8`. Here, `a_2 < a_3` is true. So, `(2, 3)` is a valid ordered pair.
*   The total number of valid ordered pairs `(i, j)` such that `a_i < a_j` is 3.

The number of ways to choose 2 distinct items from a set of `n` items (i.e., the number of unique unordered pairs of distinct indices) is given by the combination formula "n choose 2", which is:
$$ C(n, 2) = \frac{n \times (n - 1)}{2} $$

Since for each such unordered pair, exactly one ordered pair satisfies the `a_x < a_y` condition, the total count of such ordered pairs `(i, j)` is simply `n * (n - 1) / 2`.

Crucially, the actual values of `a_i` do not matter at all, only their count `n` and the fact that they are distinct. Therefore, we only need to read `n`, then read and discard the `n` integers `a_i`, and finally compute `n * (n - 1) / 2`.

## Complexity Analysis

*   **Time Complexity**:
    *   For each test case:
        *   Reading `n`: $O(1)$
        *   Reading `n` integers `a_i` (and discarding them): $O(n)$
        *   Calculating `n * (n - 1) / 2`: $O(1)$
    *   So, the time complexity per test case is $O(n)$.
    *   The problem constraints state that the sum of `N` over all test cases will not exceed $10^5$. Therefore, the total time complexity across all test cases is $O(\sum N)$, which is $O(10^5)$. This is highly efficient and well within typical time limits.

*   **Space Complexity**:
    *   We only use a few integer variables (`T`, `n`, `temp_a`, `result`) to store input and intermediate calculations. No arrays or data structures are used to store the `a_i` values.
    *   Therefore, the space complexity is $O(1)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, vector, etc.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop through each test case
        int n;
        cin >> n; // Read the integer n

        // The problem states n distinct integers a1, a2, ..., an are given.
        // However, their actual values are not needed for the solution.
        // We only need to read them to consume the input.
        for (int i = 0; i < n; ++i) {
            int temp_a;
            cin >> temp_a; // Read and discard each a_i
        }

        // The core logic:
        // We need to count pairs (i, j) such that a_i < a_j.
        // Since all a_k are distinct:
        // 1. If i = j, then a_i < a_i is false. So no pairs (i, i) are counted.
        // 2. If i != j, then either a_i < a_j OR a_j < a_i must be true.
        //    Exactly one of these conditions will hold.
        // This means for every unique unordered pair of distinct indices {i, j},
        // exactly one of the ordered pairs (i, j) or (j, i) will satisfy the condition.
        // The number of unique unordered pairs of distinct indices from n items is
        // given by the combination formula "n choose 2", which is n * (n - 1) / 2.

        // Calculate the result.
        // Cast n to long long before multiplication to prevent potential overflow,
        // as n * (n - 1) can exceed the maximum value of an int for n up to 100,000.
        long long result = (long long)n * (n - 1) / 2;

        // Output the result for the current test case, followed by a newline.
        cout << result << "\n";
    }

    return 0; // Indicate successful execution
}
```