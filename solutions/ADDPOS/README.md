# [Add to make Positive (ADDPOS)](https://www.codechef.com/problems/ADDPOS)
- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum non-negative integer `X` such that if we add `X` to every element of a given array `A` of `N` integers, the sum of the modified array becomes non-negative. We need to output this minimum `X`.

## Intuition & Mathematical Observation

Let the given array be $A = [A_1, A_2, \ldots, A_N]$.
Let $S_A = \sum_{i=1}^N A_i$ be the initial sum of all elements in the array.

If we add an integer $X$ to every element of the array, each $A_i$ becomes $A_i + X$.
The sum of the modified array, let's call it $S_{A'}$, will be:
$S_{A'} = \sum_{i=1}^N (A_i + X)$
We can split this sum:
$S_{A'} = \left(\sum_{i=1}^N A_i\right) + \left(\sum_{i=1}^N X\right)$
$S_{A'} = S_A + N \cdot X$

Our goal is to find the minimum non-negative integer $X$ such that the sum of the modified array is non-negative. That is, we need to satisfy:
$S_A + N \cdot X \ge 0$

We can consider two cases:

**Case 1: The initial sum $S_A$ is already non-negative ($S_A \ge 0$).**
If the sum is already non-negative, we don't need to add any positive value to the elements. The smallest non-negative integer $X$ that satisfies the condition is $X=0$. Adding $0$ to each element doesn't change the sum, so $S_A + N \cdot 0 = S_A \ge 0$.

**Case 2: The initial sum $S_A$ is negative ($S_A < 0$).**
In this case, we need to increase the sum to make it non-negative. This means $X$ must be a positive integer.
From the inequality $S_A + N \cdot X \ge 0$, we can rearrange it:
$N \cdot X \ge -S_A$

Since $N$ is the length of the array, it must be a positive integer ($N \ge 1$). We can divide both sides by $N$ without changing the direction of the inequality:
$X \ge \frac{-S_A}{N}$

Since $X$ must be an integer, and we are looking for the *minimum* such non-negative integer, $X$ must be the smallest integer that is greater than or equal to $\frac{-S_A}{N}$. This is precisely the definition of the ceiling function.
So, $X = \lceil \frac{-S_A}{N} \rceil$.

Let $K = -S_A$. Since $S_A < 0$, $K$ will be a positive integer.
We need to compute $X = \lceil \frac{K}{N} \rceil$.
For any two positive integers $K$ and $N$, the ceiling division $\lceil \frac{K}{N} \rceil$ can be efficiently computed using integer division as:
$X = (K + N - 1) / N$

For example, if $S_A = -10$ and $N=3$:
$K = -(-10) = 10$.
$X = \lceil \frac{10}{3} \rceil = \lceil 3.33\ldots \rceil = 4$.
Using the integer division formula: $X = (10 + 3 - 1) / 3 = 12 / 3 = 4$. This matches.

The problem constraints state that $|A_i| \le 10^9$ and $N \le 10^5$.
The sum $S_A$ can be as large as $10^5 \times 10^9 = 10^{14}$ or as small as $10^5 \times (-10^9) = -10^{14}$. An `int` type in C++ typically handles values up to $2 \times 10^9$, so `sum_A` must be stored in a `long long` to prevent overflow. Similarly, `X` can also be up to $10^{14}$ (e.g., if $S_A = -10^{14}$ and $N=1$), so `X` also needs to be `long long`. The provided solution correctly uses `long long` for `sum_A` and `X`.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    -   Reading `N` takes $O(1)$.
    -   The loop iterates `N` times to read each element of the array and add it to `sum_A`. This takes $O(N)$ time.
    -   The conditional check and calculation of `X` (if needed) are constant time operations, $O(1)$.
    -   Printing the result is $O(1)$.
    Since there are `T` test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(1)$.
    -   The solution only uses a few variables (`N`, `sum_A`, `A_i`, `required_sum_increase`, `X`) to store intermediate values. It does not store the entire array `A`. Thus, the space used is constant, regardless of the input size `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, numeric, etc.

using namespace std; // Use standard namespace

void solve() {
    int N;
    cin >> N; // Read the length of the array

    long long sum_A = 0; // Initialize sum of array A. Using long long for safety, though int is sufficient.
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read each element
        sum_A += A_i; // Add to the total sum
    }

    if (sum_A >= 0) {
        // If the initial sum is already non-negative, no X is needed.
        // The minimum non-negative X is 0.
        cout << 0 << "\n";
    } else {
        // If the initial sum is negative, we need to find X such that S_A + N*X >= 0
        // This means N*X >= -S_A
        // X >= -S_A / N
        // Since X must be an integer, X = ceil(-S_A / N)
        // For positive integers 'a' and 'b', ceil(a/b) can be computed as (a + b - 1) / b using integer division.
        // Here, 'a' is -sum_A (which is positive because sum_A is negative)
        // 'b' is N (which is positive)
        long long required_sum_increase = -sum_A;
        long long X = (required_sum_increase + N - 1) / N;
        cout << X << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
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