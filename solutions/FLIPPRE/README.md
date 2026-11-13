# [Flip Prefix (FLIPPRE)](https://www.codechef.com/problems/FLIPPRE)
- **Difficulty Rating**: 1148
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the total number of distinct strings that can be formed from an initial binary string $S$ of length $N$. We are allowed to perform an operation any number of times: choose a prefix of $S$ that has an equal number of '0's and '1's, and flip all characters within that prefix (i.e., '0' becomes '1' and '1' becomes '0').

## Intuition & Mathematical Observation

Let's denote the original string as $S = S_1S_2\dots S_N$.
An operation involves choosing a prefix $P_k = S_1S_2\dots S_k$ such that $P_k$ contains an equal number of '0's and '1's, and then flipping all characters $S_1, \dots, S_k$. This operation can be applied any number of times.

The key insight lies in understanding the effect of these operations.
Let's define the "balance" of a prefix $P_j$ as (count of '0's in $P_j$) - (count of '1's in $P_j$). A prefix has an equal number of '0's and '1's if its balance is 0.

Consider what happens when we flip a zero-balance prefix $P_k$:
1.  **For any prefix $P_j$ where $j \le k$**: All characters $S_1, \dots, S_j$ are part of $P_k$ and thus get flipped. If $P_j$ originally had $Z_j$ zeros and $O_j$ ones, after flipping $P_k$, $P_j$ will have $O_j$ zeros and $Z_j$ ones. Its new balance will be $O_j - Z_j = -(Z_j - O_j)$, which is the negative of its original balance. Crucially, if $P_j$ was a zero-balance prefix (balance 0), it remains a zero-balance prefix (balance 0).
2.  **For any prefix $P_j$ where $j > k$**: The characters $S_1, \dots, S_k$ are flipped, but $S_{k+1}, \dots, S_j$ are not. The change in balance for $P_j$ is due to the change in balance of $P_k$. Since $P_k$ is a zero-balance prefix, its balance is 0. Flipping $P_k$ changes its characters, but its *balance* remains 0 (it still has an equal number of 0s and 1s, just swapped). Therefore, the balance of $P_j$ (which is balance($P_k$) + balance($S_{k+1}\dots S_j$)) does not change. This means if $P_j$ was a zero-balance prefix, it remains a zero-balance prefix.

This observation is critical: **Flipping a zero-balance prefix $P_k$ does not change whether any other prefix $P_j$ (for $j \ne k$) is a zero-balance prefix.**

Let $P_{k_1}, P_{k_2}, \dots, P_{k_M}$ be all the distinct prefixes of $S$ that have an equal number of '0's and '1's, sorted by length ($k_1 < k_2 < \dots < k_M$).
For each such prefix $P_{k_j}$, we can choose to effectively "flip" it or not.
Let $x_j \in \{0, 1\}$ be a binary variable for each $P_{k_j}$, where $x_j=1$ means we apply the operation on $P_{k_j}$ an odd number of times, and $x_j=0$ means we apply it an even number of times (which is equivalent to not applying it at all).

The final state of each character $S_i$ depends on the parity of the number of times it has been flipped. $S_i$ is flipped if it is part of an odd number of chosen effective flips. Specifically, $S_i$ is flipped if $\bigoplus_{j \text{ s.t. } k_j \ge i} x_j = 1$ (where $\oplus$ is XOR).

Consider two different choices of $(x_1, \dots, x_M)$ and $(y_1, \dots, y_M)$. Suppose these two choices result in the same final string. Let $j_{max}$ be the largest index where $x_{j_{max}} \ne y_{j_{max}}$.
Now consider the character $S_{k_{j_{max}}}$. Its final state is determined by:
- For $(x_1, \dots, x_M)$: $S_{k_{j_{max}}} \text{ (initial)} \oplus x_{j_{max}} \oplus \bigoplus_{p > j_{max}} x_p$
- For $(y_1, \dots, y_M)$: $S_{k_{j_{max}}} \text{ (initial)} \oplus y_{j_{max}} \oplus \bigoplus_{p > j_{max}} y_p$
Since $p > j_{max}$ implies $x_p = y_p$, the terms $\bigoplus_{p > j_{max}} x_p$ and $\bigoplus_{p > j_{max}} y_p$ are equal.
For the final states of $S_{k_{j_{max}}}$ to be the same, we must have $x_{j_{max}} = y_{j_{max}}$. This contradicts our assumption that $j_{max}$ is the largest index where they differ.
Therefore, each distinct choice of $(x_1, \dots, x_M)$ leads to a distinct final string.

Since there are $M$ such zero-balance prefixes, and for each we can independently choose to effectively flip it or not, there are $2^M$ distinct combinations of operations, each leading to a distinct string.

The problem then reduces to simply counting the number of prefixes that have an equal number of '0's and '1's.
We can do this by iterating through the string, maintaining a `balance` variable. Increment `balance` for '0' and decrement for '1'. Each time `balance` becomes 0, we increment a counter for zero-balance prefixes.

For example, if $S = "0101"$:
- $P_1 = "0"$: balance = 1
- $P_2 = "01"$: balance = 0. Count = 1.
- $P_3 = "010"$: balance = 1
- $P_4 = "0101"$: balance = 0. Count = 2.
Total zero-balance prefixes = 2. Result = $2^2 = 4$.

The maximum value of $N$ is 60. The maximum number of zero-balance prefixes can be $N/2 = 30$ (e.g., for "0101..."). $2^{30}$ is approximately $10^9$, which fits within a `long long` data type.

## Complexity Analysis

-   **Time Complexity**: The solution iterates through the input string $S$ once to calculate the `balance` for each prefix and count the zero-balance prefixes. This takes $O(N)$ time. The power calculation (`1LL << zero_balance_prefix_count`) is a constant time bit shift operation. This process is repeated for $T$ test cases. Therefore, the total time complexity is $O(T \cdot N)$.
    Given $N \le 60$ and $T \le 10^5$, $T \cdot N \le 10^5 \cdot 60 = 6 \cdot 10^6$, which is well within typical time limits.
-   **Space Complexity**: The solution stores the input string $S$, which requires $O(N)$ space. A few integer variables are used for `balance`, `zero_balance_prefix_count`, and `result`, which take $O(1)$ auxiliary space. Thus, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but common for competitive programming

void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    int balance = 0;
    int zero_balance_prefix_count = 0;

    // Iterate through the string to calculate prefix balances
    // S[i] corresponds to S_{i+1} in 1-based indexing for prefixes
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            balance++;
        } else { // S[i] == '1'
            balance--;
        }
        
        // If the balance is zero, it means the prefix S[0...i] (length i+1)
        // has an equal number of 0s and 1s.
        if (balance == 0) {
            zero_balance_prefix_count++;
        }
    }

    // The number of distinct strings is 2 raised to the power of 
    // the number of prefixes with equal 0s and 1s.
    // Use long long for the result because N can be up to 60,
    // so zero_balance_prefix_count can be up to 30 (e.g., for "0101...").
    // 2^30 is 1,073,741,824, which fits in a long long.
    long long result = 1LL << zero_balance_prefix_count;
    
    std::cout << result << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```