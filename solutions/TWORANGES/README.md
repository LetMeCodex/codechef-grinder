# [Two Ranges (TWORANGES)](https://www.codechef.com/problems/TWORANGES)
- **Difficulty Rating**: 918
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the total number of unique integers present in the union of two given integer ranges. We are provided with two ranges: `[A, B]` and `[C, D]`. Our task is to calculate the count of distinct integers that fall into either the first range, the second range, or both. This operation needs to be performed for `T` independent test cases.

## Intuition & Mathematical Observation

The core of this problem lies in applying the **Principle of Inclusion-Exclusion** for sets. For any two sets, $S_1$ and $S_2$, the number of unique elements in their union ($S_1 \cup S_2$) is given by the formula:

$|S_1 \cup S_2| = |S_1| + |S_2| - |S_1 \cap S_2|$

In our case, $S_1$ is the range `[A, B]` and $S_2$ is the range `[C, D]`. Let's break down how to calculate each term:

1.  **Size of the first range, $|S_1|$**:
    For an inclusive integer range `[P, Q]`, the number of integers it contains is `Q - P + 1`.
    So, for `[A, B]`, `size1 = B - A + 1`.

2.  **Size of the second range, $|S_2|$**:
    Similarly, for `[C, D]`, `size2 = D - C + 1`.

3.  **Size of the intersection of the two ranges, $|S_1 \cap S_2|$**:
    The intersection of two ranges `[A, B]` and `[C, D]` is also an integer range.
    The start of the intersection range is `max(A, C)`.
    The end of the intersection range is `min(B, D)`.

    Let `intersect_start = max(A, C)` and `intersect_end = min(B, D)`.

    If `intersect_start > intersect_end`, it means the two ranges do not overlap at all, and their intersection is empty. In this scenario, `intersection_size = 0`.
    Otherwise, the number of integers in the intersection is `intersect_end - intersect_start + 1`.

Once we have `size1`, `size2`, and `intersection_size`, we can directly apply the inclusion-exclusion principle:
`total_unique_integers = size1 + size2 - intersection_size`.

**Important Note on Data Types**: The problem constraints state that `A, B, C, D` can be up to $10^9$. This means that the size of a range (`B - A + 1`) can also be up to $10^9$. The sum of two such range sizes could exceed the maximum value of a 32-bit signed integer (approximately $2 \times 10^9$). Therefore, it's crucial to use `long long` for `size1`, `size2`, `intersection_size`, and `total_unique_integers` to prevent overflow. The endpoints `A, B, C, D` themselves can be stored in `int` variables.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution involves a fixed number of arithmetic operations (subtractions, additions) and comparisons (`max`, `min`). These operations take constant time. Since there are `T` test cases, the total time complexity will be $O(T)$.

*   **Space Complexity**: $O(1)$.
    The solution uses a constant number of variables to store the range endpoints, calculated sizes, and the final result. The memory usage does not depend on the input values (other than the fixed size of integer types).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using the standard namespace as requested.
using namespace std; 

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // Calculate the size of the first range [A, B]
    // Number of integers in [P, Q] is Q - P + 1
    long long size1 = B - A + 1;

    // Calculate the size of the second range [C, D]
    long long size2 = D - C + 1;

    // Calculate the intersection of the two ranges.
    // The intersection range is [max(A, C), min(B, D)].
    // If max(A, C) > min(B, D), the intersection is empty.
    int intersect_start = max(A, C);
    int intersect_end = min(B, D);

    long long intersection_size = 0;
    if (intersect_start <= intersect_end) {
        intersection_size = intersect_end - intersect_start + 1;
    }

    // Using the principle of inclusion-exclusion:
    // |R1 U R2| = |R1| + |R2| - |R1 intersect R2|
    long long total_unique_integers = size1 + size2 - intersection_size;

    cout << total_unique_integers << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}
```