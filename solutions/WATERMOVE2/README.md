# Water Moving (Max) (WATERMOVE2)
- **Difficulty Rating**: 934
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum possible amount of water in any single cup after performing exactly $K$ operations. In each operation, we can choose two distinct cups, say cup $i$ and cup $j$, and move any positive amount of water from cup $i$ to cup $j$. We are given $N$ cups with initial amounts of water.

## Intuition & Mathematical Observation

The goal is to maximize the amount of water in *any* single cup. To achieve this, the most effective strategy is to consolidate water into the cup that *initially* holds the largest amount of water. This is because any water moved into a cup that already has a large amount will contribute more significantly to the maximum than water moved into a cup with a small initial amount.

Let the initial amounts of water in the $N$ cups be $a_1, a_2, \ldots, a_N$.
Suppose we identify the cup with the maximum initial amount, say $M = \max(a_1, a_2, \ldots, a_N)$.
We have exactly $K$ operations to perform. Each operation allows us to move water from one cup to another. To maximize the amount in our chosen target cup (the one that initially had $M$), we should use our $K$ operations to move water from other cups into it.

Consider the $N-1$ other cups. We can pick at most $N-1$ distinct cups to move water from.
If $K \ge N-1$, we have enough operations to potentially move water from all other $N-1$ cups into the target cup. In this scenario, the maximum amount of water in a single cup would be the sum of water from all cups. However, the problem states we must perform *exactly* $K$ operations. If $K > N-1$, after moving water from all $N-1$ other cups into the target cup (using $N-1$ operations), we still have $K - (N-1)$ operations left. These remaining operations can be used to move water between cups, but since all water is already consolidated into one cup (or distributed among a few, if we didn't consolidate perfectly), these extra operations won't increase the maximum amount further if we've already consolidated into the largest initial cup. The key is that we *must* perform $K$ operations. The most sensible way to use these extra operations without decreasing the maximum is to move water from the target cup to another cup and then immediately back, or move water between two other cups. This doesn't change the maximum. Therefore, if $K \ge N-1$, the maximum achievable amount is the sum of all initial water amounts.

If $K < N-1$, we can only perform $K$ operations. To maximize the water in our target cup (the one with the largest initial amount), we should pick the $K$ cups with the largest amounts among the remaining $N-1$ cups and move their entire contents into the target cup. This will require $K$ operations.

Therefore, the strategy is:
1. Find the cup with the maximum initial amount of water.
2. Sort the initial amounts in descending order. Let the sorted amounts be $a'_1 \ge a'_2 \ge \ldots \ge a'_N$. The maximum initial amount is $a'_1$.
3. We can perform $K$ operations. Each operation can take water from one of the other $N-1$ cups and add it to the cup that initially had $a'_1$.
4. The number of other cups we can take water from is limited by $K$ and also by the total number of other cups, which is $N-1$. So, we can take water from at most $\min(K, N-1)$ other cups.
5. To maximize the sum, we should pick the $\min(K, N-1)$ largest amounts from the remaining $N-1$ cups (which are $a'_2, a'_3, \ldots, a'_{N-1}$) and add them to $a'_1$.

The final maximum amount will be $a'_1 + a'_2 + \ldots + a'_{\min(K, N-1) + 1}$.

Let's re-evaluate the $K \ge N-1$ case. If $K \ge N-1$, we can indeed move water from all $N-1$ other cups into the largest cup. This uses $N-1$ operations. The total amount in that cup becomes the sum of all initial amounts. We still have $K - (N-1)$ operations remaining. The problem states we must perform *exactly* $K$ operations. If we have already consolidated all water into one cup, any further operations would involve moving water from this cup to another and back, or moving water between other cups. These operations do not increase the maximum amount. So, if $K \ge N-1$, the maximum is the sum of all elements.

However, the code implements a slightly different logic: it adds the top `min(K, N-1)` elements to the largest. Let's trace this.
If $K=1, N=3$, amounts are $[10, 5, 2]$. Sorted: $[10, 5, 2]$.
`max_val = 10`. `operations_to_perform = min(1, 3-1) = min(1, 2) = 1`.
Loop adds `a[1]` (which is 5) to `max_val`. Result: $10+5=15$. This is correct. We move 5 from the second cup to the first.

If $K=3, N=3$, amounts are $[10, 5, 2]$. Sorted: $[10, 5, 2]$.
`max_val = 10`. `operations_to_perform = min(3, 3-1) = min(3, 2) = 2`.
Loop adds `a[1]` (5) and `a[2]` (2) to `max_val`. Result: $10+5+2=17$. This is the sum of all elements. This is also correct. We move 5 from the second cup to the first (1 op), then move 2 from the third cup to the first (1 op). Total 2 ops. We still need 1 more operation. We can move 2 from the first cup to the third and then back to the first. The maximum remains 17.

The logic `operations_to_perform = std::min((long long)n - 1, k);` correctly captures that we can take water from at most $N-1$ other cups, and we have $K$ operations available. If $K \ge N-1$, we effectively take water from all $N-1$ other cups, and the loop runs $N-1$ times, summing up all elements. If $K < N-1$, we take water from the $K$ largest of the other cups, and the loop runs $K$ times. This logic seems sound and covers both cases implicitly.

## Complexity Analysis

- **Time Complexity**:
    - Reading input: $O(N)$ for each test case.
    - Sorting the array: $O(N \log N)$ for each test case.
    - Iterating to sum up the top elements: $O(\min(K, N-1))$, which is at most $O(N)$.
    - Total time complexity per test case: $O(N \log N)$.
    - With $T$ test cases, the total time complexity is $O(T \cdot N \log N)$.

- **Space Complexity**:
    - Storing the amounts in a vector: $O(N)$ for each test case.
    - The sorting is done in-place or with auxiliary space depending on the implementation, but typically $O(\log N)$ or $O(N)$ in worst-case scenarios for some sorting algorithms. For `std::sort` in C++, it's typically $O(\log N)$ on average.
    - Total space complexity per test case: $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of cups
        long long k; // Number of operations
        std::cin >> n >> k;

        std::vector<long long> a(n); // Vector to store water amounts in cups
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        // To maximize the amount of water in any single cup, we should consolidate
        // water into the cup that initially has the most water.
        // We have exactly K operations. Each operation allows us to move water
        // from one cup to another.

        // Sort the amounts in descending order. The largest initial amount will be a[0].
        std::sort(a.rbegin(), a.rend());

        long long max_val = a[0]; // Initialize max_val with the largest initial amount

        // We can perform K operations. Each operation can take water from one of the
        // other N-1 cups and add it to the cup that initially had the most water (a[0]).
        // The number of other cups we can take water from is limited by K and also by N-1.
        // So, we can take water from at most min(K, N-1) other cups.
        // To maximize the sum, we should pick the largest amounts from the remaining N-1 cups.
        // Since the array `a` is sorted in descending order, the largest amounts
        // among the remaining N-1 cups are a[1], a[2], ..., a[min(K, N-1)].

        long long operations_to_perform = std::min((long long)n - 1, k);

        // Add the water from the 'operations_to_perform' largest cups (excluding the absolute largest)
        // to the cup that initially had the most water.
        for (int i = 0; i < operations_to_perform; ++i) {
            max_val += a[i + 1];
        }

        // Output the maximum possible amount of water in a single cup.
        std::cout << max_val << "\n";
    }
    return 0;
}
```