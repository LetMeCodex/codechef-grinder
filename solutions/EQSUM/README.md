# [Equal Difference (EQSUM)](https://www.codechef.com/problems/EQSUM)
- **Difficulty Rating**: 979
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the number of pairs of indices $(i, j)$ such that $1 \le i < j \le N$ and $A_i - i = A_j - j$. We are given an array $A$ of $N$ distinct integers, $A_1, A_2, \dots, A_N$, where each $A_k$ satisfies $1 \le A_k \le N$.

## Intuition & Mathematical Observation

The core of the problem lies in the condition $A_i - i = A_j - j$. This condition suggests that if we transform each element $A_k$ into a new value, say $B_k = A_k - k$, then we are simply looking for pairs of indices $(i, j)$ where $B_i = B_j$.

Let's define a new sequence $B$ where $B_k = A_k - k$. The problem then becomes: count the number of pairs $(i, j)$ with $1 \le i < j \le N$ such that $B_i = B_j$.

This is a classic counting problem. If a certain value $X$ appears $C$ times in the sequence $B$, then any two of these $C$ occurrences can form a pair $(i, j)$ satisfying $B_i = B_j = X$. The number of ways to choose 2 distinct indices from $C$ available indices is given by the combination formula "C choose 2", which is $\frac{C \times (C - 1)}{2}$.

So, the strategy is:
1.  For each element $A_k$ (where $k$ is its 1-indexed position), calculate its transformed value. The problem uses 1-indexed $k$, but the provided C++ code uses 0-indexed loop variable `k`. If `val_Ak` is $A_{k+1}$ (the value at 1-indexed position `k+1`), the code calculates $A_{k+1} - k$. Let's call this $B'_k = A_{k+1} - k$.
    While the problem asks for $A_i - i$, and the code calculates $A_{k+1} - k$, these two values are related: $A_i - i = (A_i - (i-1)) - 1$. So, if $B'_k = A_{k+1} - k$, then $A_i - i = B'_{i-1} - 1$. This means the set of values $\{A_i - i\}$ is just a shifted version of the set of values $\{A_{k+1} - k\}$. The frequencies of values will be the same, just shifted, and thus the total count of pairs will be identical.
2.  Count the frequency of each distinct $B'_k$ value.
3.  For each value $X$ that appears $C$ times in the $B'$ sequence, add $\frac{C \times (C - 1)}{2}$ to the total count of pairs.

**Range of $B'_k$ values and Frequency Array:**
The values $A_k$ are between $1$ and $N$. The 0-indexed loop variable $k$ is between $0$ and $N-1$.
The value $B'_k = A_{k+1} - k$ can range as follows:
*   **Minimum value**: When $A_{k+1}$ is smallest (1) and $k$ is largest ($N-1$).
    $B'_{N-1} = 1 - (N-1) = 2 - N$.
*   **Maximum value**: When $A_{k+1}$ is largest ($N$) and $k$ is smallest (0).
    $B'_0 = N - 0 = N$.
So, the range of $B'_k$ values is $[2-N, N]$.

To use a frequency array (like `std::vector<int> freq`), we need non-negative indices. We can apply an `offset` to map the minimum value to index 0.
The smallest value is $2-N$. To map this to index 0, we need to add $-(2-N) = N-2$.
So, `offset = N-2`.
With this offset:
*   The smallest value $(2-N) + (N-2)$ maps to index $0$.
*   The largest value $N + (N-2)$ maps to index $2N-2$.
The indices for the frequency array will range from $0$ to $2N-2$. A vector of size $2N-1$ would be sufficient. The code uses `vector<int> freq(2 * N, 0);`, which is a safe choice as $2N-1 < 2N$.

**Preventing Overflow:**
The count of pairs $\frac{C \times (C - 1)}{2}$ can be large. If $C$ is up to $N$ (which is $4 \times 10^4$), then $C \times (C-1)$ can be approximately $(4 \times 10^4)^2 = 16 \times 10^8$. This value exceeds the maximum for a 32-bit signed integer (`~2 \times 10^9`). Therefore, the `count_pairs` variable and the intermediate product `(long long)count * (count - 1)` must use `long long` to prevent overflow. The provided code correctly handles this.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and initializing `freq` vector: $O(N)$ (the vector size is $2N$).
    *   Loop for reading $A_k$ values and updating frequencies: This loop runs $N$ times. Inside the loop, reading an integer, performing arithmetic, and accessing the `freq` vector are all $O(1)$ operations. Thus, this part takes $O(N)$ time.
    *   Loop for calculating `count_pairs`: This loop iterates through the `freq` vector, which has a size of $O(N)$. Each iteration is $O(1)$. Thus, this part takes $O(N)$ time.
    *   Overall, for each test case, the time complexity is $O(N)$.
    *   Given $T$ test cases, the total time complexity is $O(T \cdot N)$. With $T \le 10$ and $N \le 4 \times 10^4$, $T \cdot N \le 10 \cdot 4 \times 10^4 = 4 \times 10^5$, which is well within typical time limits.

*   **Space Complexity**:
    *   The `freq` vector stores $2N$ integers. This requires $O(N)$ space.
    *   All other variables (`N`, `offset`, `val_Ak`, `count_pairs`, `T`, `count`) use $O(1)$ space.
    *   Overall, the space complexity is $O(N)$. With $N \le 4 \times 10^4$, $2N$ integers (e.g., $8 \times 10^4$ integers, roughly $320$ KB) is well within typical memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std as requested
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // The values A[k] - k (where k is 0-indexed) can range as follows:
    // Smallest possible value: A[k]=1, k=N-1 (last element) => 1 - (N-1) = 2 - N
    // Largest possible value: A[k]=N, k=0 (first element)   => N - 0 = N
    // So, the range of values for A[k] - k is [2-N, N].
    // To map these values to non-negative indices for a frequency array,
    // we can add an offset.
    // If we add (N-2) to the smallest value (2-N), it becomes 0.
    // If we add (N-2) to the largest value (N), it becomes N + (N-2) = 2N-2.
    // Thus, the indices will range from 0 to 2N-2.
    // A vector of size 2N-1 would be sufficient (indices 0 to 2N-2).
    // Using 2N for the vector size is a safe choice, as 2N-2 < 2N.
    vector<int> freq(2 * N, 0); 
    int offset = N - 2; // Offset to map the minimum value (2-N) to index 0

    for (int k = 0; k < N; ++k) {
        int val_Ak;
        cin >> val_Ak; // Read A[k] (which is A_{k+1} from problem statement)
        // Calculate B_k = A[k] - k (using 0-indexed k)
        // Add offset to map B_k to a non-negative index
        freq[val_Ak - k + offset]++;
    }

    long long count_pairs = 0;
    // Iterate through the frequency counts
    for (int count : freq) {
        if (count > 1) {
            // If 'count' elements have the same B_k value,
            // they can form count * (count - 1) / 2 pairs.
            // Use long long for the product to prevent overflow,
            // as count can be up to N (4*10^4), and N*(N-1)/2 can be ~8*10^8.
            count_pairs += (long long)count * (count - 1) / 2;
        }
    }

    cout << count_pairs << "\n";
}

int main() {
    // Enable fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```