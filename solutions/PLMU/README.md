# [Plus Multiply (PLMU)](https://www.codechef.com/problems/PLMU)
- **Difficulty Rating**: 1277
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the number of pairs of indices `(i, j)` such that `i < j` and the elements `A[i]` and `A[j]` from a given sequence `A` satisfy the equation `A[i] + A[j] = A[i] * A[j]`. The sequence `A` consists of `N` non-negative integers.

## Intuition & Mathematical Observation

The core of this problem lies in analyzing the given equation: `A[i] + A[j] = A[i] * A[j]`.
Let's denote `x = A[i]` and `y = A[j]`. The equation becomes `x + y = x * y`.

We can rearrange this equation to find its integer solutions:
`x * y - x - y = 0`

To make it factorable, we can add 1 to both sides:
`x * y - x - y + 1 = 1`

Now, we can factor the left side by grouping:
`x(y - 1) - 1(y - 1) = 1`
`(x - 1)(y - 1) = 1`

Since `x` and `y` are non-negative integers (as `A[i]` and `A[j]` are non-negative integers), `(x - 1)` and `(y - 1)` must be integers.
For the product of two integers to be 1, there are only two possibilities:

1.  Both factors are 1:
    `x - 1 = 1`  => `x = 2`
    `y - 1 = 1`  => `y = 2`
    This means `A[i] = 2` and `A[j] = 2`.

2.  Both factors are -1:
    `x - 1 = -1` => `x = 0`
    `y - 1 = -1` => `y = 0`
    This means `A[i] = 0` and `A[j] = 0`.

Therefore, the only pairs of values `(A[i], A[j])` that satisfy the given condition are `(0, 0)` and `(2, 2)`. Any other combination of values (e.g., `(0, 2)`, `(1, 1)`, `(1, 2)`, etc.) will not satisfy the equation.

The problem asks for the number of pairs of *indices* `(i, j)` such that `i < j`. This means we need to count:
1.  The number of pairs of distinct indices `(i, j)` where both `A[i]` and `A[j]` are `0`.
2.  The number of pairs of distinct indices `(i, j)` where both `A[i]` and `A[j]` are `2`.

Let `count0` be the total number of times `0` appears in the sequence `A`.
Let `count2` be the total number of times `2` appears in the sequence `A`.

The number of ways to choose 2 distinct indices from `count0` occurrences of `0` is given by the combination formula "n choose k" for k=2, which is `C(count0, 2) = count0 * (count0 - 1) / 2`.
Similarly, the number of ways to choose 2 distinct indices from `count2` occurrences of `2` is `C(count2, 2) = count2 * (count2 - 1) / 2`.

The total number of valid pairs `(i, j)` with `i < j` is the sum of these two quantities:
`Total Pairs = (count0 * (count0 - 1) / 2) + (count2 * (count2 - 1) / 2)`

The solution involves iterating through the input array once to count the occurrences of `0` and `2`, and then applying this formula. It's important to use `long long` for the counts and the final answer, as `N` can be up to $2 \cdot 10^5$, making the number of pairs potentially large (up to approximately $2 \cdot 10^{10}$).

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The solution involves a single pass through the input array `A` of size `N` to count the occurrences of `0` and `2`. This takes $O(N)$ time. The subsequent arithmetic operations to calculate the total pairs take constant time, $O(1)$. Thus, for each test case, the time complexity is $O(N)$. Given `T` test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(1)$
    The solution uses a few variables (`count0`, `count2`, `ans`, `A_i`) to store counts and the current element. The amount of memory used by these variables is constant and does not depend on the input size `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace, as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of elements in the sequence

    long long count0 = 0; // Counter for occurrences of 0. Using long long to be safe.
    long long count2 = 0; // Counter for occurrences of 2. Using long long to be safe.

    // Iterate through the sequence to count 0s and 2s
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read each element
        if (A_i == 0) {
            count0++; // Increment count for 0
        } else if (A_i == 2) {
            count2++; // Increment count for 2
        }
    }

    // Calculate the total number of valid pairs.
    // The formula k * (k - 1) / 2 correctly handles cases where k < 2 (resulting in 0 pairs).
    long long ans = count0 * (count0 - 1) / 2 + count2 * (count2 - 1) / 2;

    cout << ans << "\n"; // Print the total number of valid pairs
}

int main() {
    // Enable fast I/O, as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```