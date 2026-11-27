# [Another Game (KARR)](https://www.codechef.com/problems/KARR)
- **Difficulty Rating**: 1363
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to find the minimum non-negative integer $K$ required to sort a given permutation $P$ of length $N$. The allowed operation is to choose two indices $i$ and $j$, and swap the values $P_i$ and $P_j$, provided that the absolute difference between their values, $|P_i - P_j|$, is less than or equal to $K$. The goal is to transform the permutation into a sorted state where $P_i = i$ for all $1 \le i \le N$.

## Intuition & Mathematical Observation

The solution code implements the following logic to determine the minimum non-negative $K$:

1.  **Base Case: Already Sorted Permutation:**
    If the given permutation $P$ is already sorted (i.e., $P_i = i$ for all $1 \le i \le N$), no operations are needed. In this scenario, the minimum non-negative $K$ required is $0$. The code efficiently checks this by maintaining an `is_sorted` flag during input reading.

2.  **Unsorted Permutation:**
    If the permutation is not sorted, it means there is at least one element $P_i$ such that $P_i \neq i$. To sort the permutation, these misplaced elements must be moved to their correct positions.
    The core idea behind this solution is to identify the "largest" value that is currently out of place and determine a $K$ that is sufficient to move it and, by extension, all other misplaced values.
    Let $M$ be the maximum value $P_i$ such that $P_i \neq i$. This $M$ represents the largest value that is currently not in its correct position.

3.  **Determining $K$ based on $M$:**
    The solution proposes that $K = M+1$ is a sufficient value to sort the permutation. The reasoning is as follows:
    If we set $K = M+1$, then for any two values $X$ and $Y$ in the permutation, if both $X$ and $Y$ are less than or equal to $M+1$, their absolute difference $|X-Y|$ will be at most $M$. Since $M \le M+1$, the condition $|X-Y| \le K$ (i.e., $|X-Y| \le M+1$) will always be satisfied.
    This implies that with $K = M+1$, any two values $X, Y$ such that $X, Y \le M+1$ can be swapped if they are at any two positions $i, j$. This effectively "connects" all values from $1$ to $M+1$, allowing them to be freely rearranged among themselves.
    Since $M$ is the maximum value that is out of place, all misplaced values $P_i$ satisfy $P_i \le M$. Consequently, all misplaced values are within the range $[1, M]$, which is a subset of $[1, M+1]$.
    Because all relevant (misplaced) values are part of this "connected component" of values, they can be moved to their correct positions, thus sorting the permutation.
    Therefore, $K = M+1$ is a sufficient value to sort the permutation. The code implicitly assumes this value is the minimum required $K$ for unsorted permutations.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The solution iterates through the permutation once to read all $N$ elements. During this single pass, it checks if the permutation is sorted and simultaneously finds the maximum value $P_i$ that is not in its correct position (`max_misplaced_val`). This process takes $O(N)$ time. Since this is done for each of the $T$ test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables like `N`, `max_misplaced_val`, `P_val`, `is_sorted`, and `T`. It does not use any data structures that scale with the input size $N$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int N;
    std::cin >> N; // Read the length of the permutation

    // We need to find the maximum value P_i such that P_i != i.
    // If all P_i == i, then max_misplaced_val will remain 0.
    int max_misplaced_val = 0; 
    bool is_sorted = true; // Flag to check if the permutation is sorted

    // Read the permutation and find max_misplaced_val
    // Using 1-based indexing for P_i == i comparison
    for (int i = 1; i <= N; ++i) {
        int P_val;
        std::cin >> P_val;
        if (P_val != i) {
            is_sorted = false;
            if (P_val > max_misplaced_val) {
                max_misplaced_val = P_val;
            }
        }
    }

    if (is_sorted) {
        // If the permutation is already sorted, no operations are needed.
        // The minimum non-negative K is 0.
        std::cout << 0 << "\n";
    } else {
        // If the permutation is not sorted, we need to connect all elements
        // that are not in their correct positions.
        // Let M be the maximum value P_i such that P_i != i.
        // To connect all such elements, we need to ensure that M can be moved.
        // The smallest value M can swap with is 1. So we need K >= M + 1.
        // If K = M + 1, then any value X (where X <= M) can swap with 1 (since X+1 <= M+1 = K).
        // This means all misplaced values are connected to 1 (which is either a misplaced value itself
        // or a fixed point available as a hub), and thus all misplaced values are connected to each other.
        // This is sufficient to sort the permutation.
        std::cout << max_misplaced_val + 1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```