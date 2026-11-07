# [Divide into 3 (DIVIDE3)](https://www.codechef.com/problems/DIVIDE3)
- **Difficulty Rating**: 350
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to divide `N` toffees among 3 friends. Our goal is to minimize the "imbalance", which is defined as the difference between the maximum number of toffees any friend receives and the minimum number of toffees any friend receives. We need to output this minimum possible imbalance.

## Intuition & Mathematical Observation

Let the number of toffees received by the three friends be `a`, `b`, and `c`. We know that `a + b + c = N`, and `a, b, c` must be non-negative integers. The imbalance is `max(a, b, c) - min(a, b, c)`. To minimize this difference, `a`, `b`, and `c` should be as close to each other as possible.

We can analyze this based on the remainder when `N` is divided by 3:

1.  **Case 1: `N` is perfectly divisible by 3 (`N % 3 == 0`)**
    *   If `N` is a multiple of 3, say `N = 3k` for some integer `k`.
    *   We can distribute the toffees equally among the three friends: `(k, k, k)`.
    *   In this scenario, the maximum number of toffees any friend receives (`mx`) is `k`, and the minimum number of toffees any friend receives (`mn`) is also `k`.
    *   The imbalance is `mx - mn = k - k = 0`.
    *   Since the number of toffees cannot be negative, an imbalance cannot be negative. Therefore, 0 is the absolute minimum possible imbalance.

2.  **Case 2: `N` is not perfectly divisible by 3 (`N % 3 != 0`)**
    *   If `N` is not a multiple of 3, it's impossible to divide `N` into three *equal* integer parts. This means that at least two friends must receive a different number of toffees.
    *   Consequently, `mx` must be strictly greater than `mn`, which implies that the imbalance `(mx - mn)` must be at least 1.
    *   Now, let's see if we can always achieve an imbalance of 1 in these cases:

    *   **Subcase 2a: `N % 3 == 1`**
        *   `N` can be written as `3k + 1` for some integer `k`.
        *   We can distribute the toffees as `(k+1, k, k)`.
        *   The sum is `(k+1) + k + k = 3k + 1 = N`.
        *   Here, `mx = k+1` and `mn = k`.
        *   The imbalance is `(k+1) - k = 1`.
        *   *Example:* If `N=4` (`k=1`), we can give `(2, 1, 1)` toffees. Imbalance `2-1=1`.
        *   *Example:* If `N=7` (`k=2`), we can give `(3, 2, 2)` toffees. Imbalance `3-2=1`.

    *   **Subcase 2b: `N % 3 == 2`**
        *   `N` can be written as `3k + 2` for some integer `k`.
        *   We can distribute the toffees as `(k+1, k+1, k)`.
        *   The sum is `(k+1) + (k+1) + k = 3k + 2 = N`.
        *   Here, `mx = k+1` and `mn = k`.
        *   The imbalance is `(k+1) - k = 1`.
        *   *Example:* If `N=5` (`k=1`), we can give `(2, 2, 1)` toffees. Imbalance `2-1=1`.
        *   *Example:* If `N=8` (`k=2`), we can give `(3, 3, 2)` toffees. Imbalance `3-2=1`.

**Conclusion:**
*   If `N % 3 == 0`, the minimum imbalance is 0.
*   If `N % 3 == 1` or `N % 3 == 2`, the minimum imbalance is 1.

This logic covers all possible values of `N` (given `N >= 3` as per constraints, which ensures `k >= 0`). The solution simply involves checking `N % 3`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading a single integer `N`, performing a modulo operation (`N % 3`), and a conditional check. These operations take constant time, regardless of the value of `N`.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (e.g., `N`) to store input and perform calculations. The memory usage does not scale with the input value `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// Using namespace std; is requested by the problem statement.
using namespace std;

int main() {
    // Fast I/O is requested by the problem statement.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement's "Input Format" section specifies:
    // "The first and only line of input contains a single integer N - the number of toffees you had."
    // This indicates that there is only one test case.
    // The "Critical Instructions" mention handling multiple test cases "as requested by the problem statement",
    // but the input format itself does not request multiple test cases.
    // Therefore, we will process a single input N.

    int N;
    cin >> N; // Read the number of toffees

    // The goal is to minimize the imbalance, defined as (mx - mn),
    // where mx is the maximum toffees any friend received, and mn is the minimum.
    // We are dividing N toffees among 3 friends. Let the toffees received be a, b, c.
    // We must have a + b + c = N, and a, b, c >= 0 (or >= 1, given N >= 3).

    // To minimize the difference between the maximum and minimum, the numbers a, b, c
    // should be as close to each other as possible.

    // Case 1: N is perfectly divisible by 3 (N % 3 == 0)
    // If N is a multiple of 3, say N = 3k, we can give k toffees to each friend.
    // For example, if N=3, we give (1, 1, 1). mx=1, mn=1. Imbalance = 1-1 = 0.
    // For example, if N=6, we give (2, 2, 2). mx=2, mn=2. Imbalance = 2-2 = 0.
    // In this scenario, mx = mn = N/3, so the imbalance is 0.
    // An imbalance cannot be negative, so 0 is the minimum possible.

    // Case 2: N is not perfectly divisible by 3 (N % 3 != 0)
    // If N is not a multiple of 3, it's impossible to divide N into three equal integer parts.
    // This means that at least two friends must receive a different number of toffees.
    // Consequently, mx must be strictly greater than mn, implying that the imbalance (mx - mn)
    // must be at least 1.

    // Let's see if we can achieve an imbalance of 1:
    // If N % 3 == 1:
    // N can be written as 3k + 1 for some integer k.
    // We can distribute the toffees as (k+1, k, k).
    // For example, if N=4 (k=1), we give (2, 1, 1). mx=2, mn=1. Imbalance = 2-1 = 1.
    // For example, if N=7 (k=2), we give (3, 2, 2). mx=3, mn=2. Imbalance = 3-2 = 1.
    // In this case, mx = k+1 and mn = k, so the imbalance is (k+1) - k = 1.

    // If N % 3 == 2:
    // N can be written as 3k + 2 for some integer k.
    // We can distribute the toffees as (k+1, k+1, k).
    // For example, if N=5 (k=1), we give (2, 2, 1). mx=2, mn=1. Imbalance = 2-1 = 1.
    // For example, if N=8 (k=2), we give (3, 3, 2). mx=3, mn=2. Imbalance = 3-2 = 1.
    // In this case, mx = k+1 and mn = k, so the imbalance is (k+1) - k = 1.

    // Combining these observations:
    // If N % 3 == 0, the minimum imbalance is 0.
    // If N % 3 == 1 or N % 3 == 2, the minimum imbalance is 1.

    if (N % 3 == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }

    return 0;
}
```