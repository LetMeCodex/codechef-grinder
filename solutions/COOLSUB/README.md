# [Cool Subsequences (COOLSUB)](https://www.codechef.com/problems/COOLSUB)
- **Difficulty Rating**: 1239
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find a "cool subsequence" $S$ of length $K$, where $1 \le K < N$. A subsequence $S$ is considered "cool" if for every non-empty subsequence $S'$ of $S$, the average of the elements in $S'$ is present in the complement subsequence $S^c$. The complement subsequence $S^c$ contains all elements of the original array $A$ that are not in $S$. If no such cool subsequence exists, we should output -1.

## Intuition & Mathematical Observation

The core of the problem lies in the definition of a "cool subsequence". Let $S$ be a subsequence of $A$ with length $K$, where $1 \le K < N$. The complement $S^c$ consists of the remaining $N-K$ elements of $A$.

The condition is: for every non-empty subsequence $S'$ of $S$, the average of elements in $S'$ must be present in $S^c$.

Let's consider the simplest possible non-empty subsequence of $S$, which is a subsequence of length 1. If $S = [s_1, s_2, \dots, s_K]$, then any single element $s_i$ from $S$ forms a subsequence $S' = [s_i]$. The average of this subsequence is simply $s_i$.

According to the problem statement, for $S$ to be cool, this average ($s_i$) must be present in $S^c$. This means that for every element $s_i$ that we pick to be in our subsequence $S$, that same element $s_i$ must *also* be present in the complement subsequence $S^c$.

This implies a crucial constraint: if an element $X$ is chosen to be part of the subsequence $S$, then $X$ must also be available in the original array $A$ to be part of $S^c$. If $X$ appears only once in the original array $A$, and we pick it for $S$, it cannot be in $S^c$. Therefore, for any element $X$ to be part of a cool subsequence $S$, it must appear at least twice in the original array $A$.

Now, let's consider the simplest possible cool subsequence: a subsequence of length $K=1$. Let $S = [X]$. For this to be a cool subsequence, its only non-empty subsequence is $S' = [X]$. The average of $S'$ is $X$. This average must be present in $S^c$.
If $S = [X]$, then $S^c$ contains all elements of $A$ except for one instance of $X$. For $X$ to be present in $S^c$, the original array $A$ must have contained at least two occurrences of $X$. If $A$ has at least two occurrences of $X$, we can form $S = [X]$ and $S^c$ will contain at least one $X$. The average of $S'=[X]$ is $X$, which is in $S^c$. The length of $S$ is 1, and since $N \ge 2$ (as $K < N$ and $K \ge 1$), $1 \le K < N$ is satisfied.

Therefore, if there exists any element $X$ in the array $A$ that appears at least twice, we can form a cool subsequence $S = [X]$ of length 1. This is the simplest possible cool subsequence.

What if no element appears at least twice? This means all elements in the array $A$ are distinct. If all elements are distinct, and we pick any element $X$ to be in $S$, then $X$ appears only once in $A$. If $X$ is in $S$, it cannot be in $S^c$. But for $S=[X]$ to be cool, $X$ must be in $S^c$. This is a contradiction.
If all elements are distinct, then for any subsequence $S$, if an element $s_i \in S$, it cannot be in $S^c$ because it only appears once in $A$. This violates the condition that the average of any single-element subsequence of $S$ (which is the element itself) must be in $S^c$.
Thus, if all elements in $A$ are distinct, no cool subsequence can exist.

The problem statement also has a constraint: $1 \le K < N$.
If $N=1$, it's impossible to satisfy $K < N$ because $K \ge 1$. So, if $N=1$, no cool subsequence exists.

Combining these observations:
1. If $N=1$, output -1.
2. If there is any element that appears at least twice in $A$, we can form a cool subsequence of length 1. Output 1 and one such element.
3. If all elements in $A$ are distinct (and $N \ge 2$), no cool subsequence exists. Output -1.

This logic covers all cases and leads to a simple solution.

## Complexity Analysis

- **Time Complexity**: $O(N)$
    - Reading the input array and counting frequencies using an `unordered_map` takes $O(N)$ on average.
    - Iterating through the `unordered_map` to find an element with a count of at least 2 takes $O(U)$ in the worst case, where $U$ is the number of unique elements. Since $U \le N$, this is at most $O(N)$.
    - The overall time complexity is dominated by reading input and counting frequencies, resulting in $O(N)$ per test case.

- **Space Complexity**: $O(U)$ or $O(N)$
    - The `unordered_map` stores the counts of unique elements. In the worst case, all elements are distinct, so the space complexity is $O(N)$. If the number of unique elements is significantly less than $N$, it would be $O(U)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map> // Changed to unordered_map for better average time complexity

void solve() {
    int N;
    std::cin >> N;
    std::unordered_map<int, int> counts; // Using unordered_map for O(1) average time complexity
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        counts[val]++;
    }

    // Constraint: 1 <= K < N.
    // If N=1, it's impossible to satisfy K < N.
    if (N == 1) {
        std::cout << -1 << "\n";
        return;
    }

    // We look for the simplest cool subsequence: S = [X] (length K=1).
    // For S=[X] to be cool, its only non-empty subsequence [X] must have its average (which is X)
    // present in the complement subsequence S^c.
    // This means that if we pick one X for S, there must be at least one other X remaining in the array A
    // to be part of S^c.
    // In other words, X must appear at least twice in the original array A.

    int cool_element = -1;
    for (auto const& [val, count] : counts) {
        if (count >= 2) {
            cool_element = val; // Found a number that appears at least twice
            break;             // We only need one such number
        }
    }

    if (cool_element != -1) {
        // If we found such an X, then S=[X] is a cool subsequence.
        // Its length is 1, which satisfies 1 <= K < N (since N >= 2).
        std::cout << 1 << "\n";
        std::cout << cool_element << "\n";
    } else {
        // If no number appears at least twice, it means all elements in A are distinct.
        // As reasoned above, for any element s_i chosen for S, s_i must also be present in S^c.
        // If all elements in A are distinct, then each s_i appears only once in A.
        // If s_i is chosen for S, it cannot be in S^c.
        // Therefore, if all elements are distinct, no cool subsequence can exist.
        std::cout << -1 << "\n";
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