# [Easy Permutation (EASYPERM)](https://www.codechef.com/problems/EASYPERM)
- **Difficulty Rating**: 1057
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct a permutation $A = [A_1, A_2, \dots, A_N]$ of numbers from $1$ to $N$ such that the Least Common Multiple (LCM) of the sequence $B = [1+A_1, 2+A_2, \dots, N+A_N]$ is minimized. We need to output any such permutation $A$.

## Intuition & Mathematical Observation

The goal is to minimize $\text{LCM}(1+A_1, 2+A_2, \dots, N+A_N)$. To minimize the LCM of a set of numbers, we generally want the numbers in the set to be as small as possible and to share as many common factors as possible.

Let's consider the sums $S_i = i + A_i$. We want to minimize $\text{LCM}(S_1, S_2, \dots, S_N)$.

A powerful strategy to minimize LCM is to make all the numbers in the set equal. If $S_1 = S_2 = \dots = S_N = C$ for some constant $C$, then $\text{LCM}(S_1, \dots, S_N) = C$.

Let's explore if we can achieve $i + A_i = C$ for all $i$ from $1$ to $N$.
If $i + A_i = C$, then $A_i = C - i$.
Since $A$ must be a permutation of numbers from $1$ to $N$, each $A_i$ must satisfy $1 \le A_i \le N$.
Substituting $A_i = C - i$:
$1 \le C - i \le N$ for all $i \in \{1, 2, \dots, N\}$.

Let's analyze the bounds for $C$:
For $i=1$: $1 \le C - 1 \le N \implies 2 \le C \le N+1$.
For $i=N$: $1 \le C - N \le N \implies N+1 \le C \le 2N$.

For $C$ to satisfy these conditions for all $i$, it must be within the intersection of these ranges.
The intersection of $[2, N+1]$ and $[N+1, 2N]$ is simply $\{N+1\}$ (assuming $N \ge 2$, which is given by the constraints).
So, the only possible value for $C$ that allows $A_i = C - i$ to be a permutation of $1$ to $N$ is $C = N+1$.

If $C = N+1$, then $A_i = (N+1) - i$.
Let's check if this $A_i$ forms a valid permutation:
- For $i=1$, $A_1 = (N+1) - 1 = N$.
- For $i=2$, $A_2 = (N+1) - 2 = N-1$.
- ...
- For $i=N$, $A_N = (N+1) - N = 1$.

The sequence $A = [N, N-1, N-2, \dots, 1]$ is indeed a permutation of numbers from $1$ to $N$. This is the reversed permutation.

With this permutation, the sums are $i + A_i = i + ((N+1) - i) = N+1$ for all $i=1, \dots, N$.
The set of sums is $\{N+1, N+1, \dots, N+1\}$.
The LCM of this set is $\text{LCM}(N+1, N+1, \dots, N+1) = N+1$.

This strategy yields an LCM of $N+1$. It is difficult to achieve a smaller LCM because the LCM must be at least the maximum value in the set of sums. The maximum possible sum is $N+N=2N$, and the minimum possible sum is $1+1=2$. The value $N+1$ is relatively small within this range.

For example, if $N=2$, the reversed permutation is $[2, 1]$. The sums are $1+2=3$ and $2+1=3$. $\text{LCM}(3, 3) = 3$. This matches $N+1 = 2+1=3$.
If $N=3$, the reversed permutation is $[3, 2, 1]$. The sums are $1+3=4$, $2+2=4$, $3+1=4$. $\text{LCM}(4, 4, 4) = 4$. This matches $N+1 = 3+1=4$.
If $N=4$, the reversed permutation is $[4, 3, 2, 1]$. The sums are $1+4=5$, $2+3=5$, $3+2=5$, $4+1=5$. $\text{LCM}(5, 5, 5, 5) = 5$. This matches $N+1 = 4+1=5$.

The problem asks for *any* permutation that minimizes the LCM. The reversed permutation strategy is simple to implement and mathematically sound for achieving the minimum LCM.

## Complexity Analysis

- **Time Complexity**: For each test case, we need to generate and print the reversed permutation of length $N$. This involves a loop that runs $N$ times. Therefore, the time complexity per test case is $O(N)$. With $T$ test cases, the total time complexity is $O(T \cdot N)$. Given $T \le 1000$ and $N \le 1000$, the maximum operations would be around $1000 \times 1000 = 10^6$, which is well within typical time limits.

- **Space Complexity**: We can print the permutation elements directly without storing the entire permutation in an array. The loop variable and other temporary variables take constant space. Thus, the space complexity is $O(1)$ per test case.

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
        int n; // The size of the permutation
        std::cin >> n;

        // The strategy is to construct the reversed permutation: [N, N-1, ..., 1].
        // For this permutation, A_i = N - i + 1.
        // The sum i + A_i becomes i + (N - i + 1) = N + 1 for all i from 1 to N.
        // The LCM of N+1 repeated N times is N+1.
        // This strategy minimizes the LCM.

        // Print the reversed permutation: N, N-1, ..., 1
        for (int i = n; i >= 1; --i) {
            std::cout << i << (i == 1 ? "" : " "); // Print space unless it's the last element
        }
        std::cout << "\n"; // Newline after each test case output
    }
    return 0;
}

```