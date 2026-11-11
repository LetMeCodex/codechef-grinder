# Retrieve the Array (ARRAYRET)
- **Difficulty Rating**: 1193
- **Solved in**: 1 attempt(s)

## Problem Summary

Given an array $B$ of size $N$, where each element $B_i$ is defined as the sum of a prefix of an unknown array $A$ and a suffix of the same array $A$. Specifically, $B_i = (A_1 + A_2 + \dots + A_i) + (A_i + A_{i+1} + \dots + A_N)$. We need to reconstruct the original array $A$.

## Intuition & Mathematical Observation

Let $S$ be the sum of all elements in array $A$, i.e., $S = A_1 + A_2 + \dots + A_N$.

The definition of $B_i$ can be rewritten as:
$B_i = (A_1 + A_2 + \dots + A_i) + (A_i + A_{i+1} + \dots + A_N)$

Notice that the element $A_i$ is included in both the prefix sum and the suffix sum. We can rearrange the terms to see a pattern:
$B_i = (A_1 + A_2 + \dots + A_N) + A_i$
$B_i = S + A_i$

This is a crucial observation. It tells us that each element $B_i$ is simply the total sum of array $A$ plus the corresponding element $A_i$.

Now, let's consider the sum of all elements in array $B$:
$\sum_{i=1}^{N} B_i = \sum_{i=1}^{N} (S + A_i)$

We can split this sum:
$\sum_{i=1}^{N} B_i = \sum_{i=1}^{N} S + \sum_{i=1}^{N} A_i$

Since $S$ is a constant for all $i$, $\sum_{i=1}^{N} S = N \times S$.
And we know that $\sum_{i=1}^{N} A_i = S$.

Substituting these back into the equation:
$\sum_{i=1}^{N} B_i = N \times S + S$
$\sum_{i=1}^{N} B_i = (N + 1) \times S$

From this, we can derive the total sum of array $A$:
$S = \frac{\sum_{i=1}^{N} B_i}{N + 1}$

The problem guarantees that a valid array $A$ exists, which implies that $\sum_{i=1}^{N} B_i$ will always be divisible by $(N+1)$.

Once we have the total sum $S$, we can easily find each element $A_i$ using our earlier observation:
$A_i = B_i - S$

So, the strategy is:
1. Read the input array $B$ and calculate its sum, `sum_b`.
2. Calculate the total sum of array $A$, $S = \text{sum\_b} / (N + 1)$.
3. For each element $B_i$, calculate $A_i = B_i - S$ and print it.

## Complexity Analysis

- **Time Complexity**: $O(N)$
    - Reading the input array $B$ and calculating its sum takes $O(N)$ time.
    - Calculating $S$ takes $O(1)$ time.
    - Reconstructing and printing array $A$ takes $O(N)$ time.
    - Therefore, the total time complexity is dominated by the linear scans, resulting in $O(N)$.

- **Space Complexity**: $O(N)$
    - We need to store the input array $B$, which takes $O(N)$ space.
    - The variables for $N$, `sum_b`, and $S$ take $O(1)$ space.
    - Thus, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, numeric, etc.

// Use the standard namespace as requested
using namespace std;

void solve() {
    int n;
    cin >> n; // Read N

    // Use long long for B_i values and their sum, as B_i can be up to 2 * 10^10
    // and sum_b can be up to N * max(B_i) = 10^5 * 2 * 10^10 = 2 * 10^15.
    vector<long long> b(n);
    long long sum_b = 0;

    // Read array B and calculate its sum
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum_b += b[i];
    }

    // Derivation:
    // Let S = A_1 + A_2 + ... + A_N be the total sum of array A.
    // For any i (1 <= i <= N):
    // f(i) = A_1 + ... + A_i
    // g(i) = A_i + ... + A_N
    // B_i = f(i) + g(i) = (A_1 + ... + A_i) + (A_i + ... + A_N)
    // Notice that A_i is included in both f(i) and g(i).
    // So, B_i = (A_1 + ... + A_N) + A_i = S + A_i.
    //
    // Now, sum B_i over all i from 1 to N:
    // sum(B_i) = sum(S + A_i) for i=1 to N
    // sum(B_i) = (S + A_1) + (S + A_2) + ... + (S + A_N)
    // sum(B_i) = N * S + (A_1 + A_2 + ... + A_N)
    // sum(B_i) = N * S + S
    // sum(B_i) = (N + 1) * S
    //
    // Therefore, S = sum(B_i) / (N + 1).
    // The problem guarantees that a valid array A exists, so sum(B_i) will be divisible by (N+1).
    long long S = sum_b / (n + 1);

    // Recover A_i using A_i = B_i - S
    for (int i = 0; i < n; ++i) {
        cout << b[i] - S << (i == n - 1 ? "" : " "); // Print A_i, space-separated
    }
    cout << "\n"; // Newline after each test case's output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```