# Chef and Apple Trees (CAPPLE)

- **Difficulty Rating**: 1301
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has $N$ apple trees. Each tree initially has a certain number of apples. In one minute, Chef can perform the following operation:
1. Choose a subset of trees that all have the same number of apples.
2. For each tree in the chosen subset, Chef can pluck any number of apples, as long as the number of apples remaining on the tree is equal to the number of apples on at least one tree *not* in the chosen subset.

The goal is to find the minimum number of minutes required to make all trees have 0 apples.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the operation and how it affects the apple counts across the trees. The operation allows us to take a group of trees with `X` apples and reduce them to `Y` apples, provided there exists at least one tree (that was not part of the chosen subset) which currently has `Y` apples. This means we can effectively "merge" a group of trees with `X` apples into a group of trees with `Y` apples.

Let's consider the set of distinct apple counts present across all trees at any given moment. Initially, this set is formed by the unique values of apples on the $N$ trees.

Suppose the distinct initial apple counts are $c_1 < c_2 < \dots < c_k$.

Consider the highest distinct count, $c_k$. We can select all trees that initially have $c_k$ apples. According to the operation, we can reduce their apple count to $c_i$ for any $i < k$, because $c_i$ is present on other trees (those that initially had $c_i$ apples). The most efficient strategy to reduce the number of distinct counts is to merge the highest count into the next highest.

**Minute 1:**
Select all trees with $c_k$ apples. Reduce their apple count to $c_{k-1}$.
Now, the trees that originally had $c_k$ apples now have $c_{k-1}$ apples. The set of distinct apple counts becomes $\{c_1, c_2, \dots, c_{k-2}, c_{k-1}\}$. The number of distinct counts has decreased by one.

**Minute 2:**
Select all trees that *currently* have $c_{k-1}$ apples. This set includes the original trees with $c_{k-1}$ apples and those that were reduced from $c_k$ apples. Reduce their apple count to $c_{k-2}$.
The set of distinct apple counts becomes $\{c_1, c_2, \dots, c_{k-2}\}$. Again, the number of distinct counts has decreased by one.

We can continue this process. In minute $m$, we select all trees with the current highest distinct apple count and reduce them to the next highest distinct apple count. Each such operation effectively eliminates the highest distinct count.

After $k-1$ minutes, we will have reduced all trees to have $c_1$ apples. The set of distinct apple counts will be $\{c_1\}$.

**Minute $k$:**
Select all trees that currently have $c_1$ apples. Reduce their apple count to 0.
Now all trees have 0 apples.

This strategy takes exactly $k$ minutes, where $k$ is the number of distinct initial apple counts.

Can we do better? Each distinct initial apple count represents a "level" that needs to be processed. To eliminate a distinct count $c_i$, we must perform an operation that reduces trees with $c_i$ apples to some other count. If we have $k$ distinct initial counts, we essentially need to perform $k$ "levels" of reduction to reach 0. The operation allows us to effectively merge one level into another. The most efficient way to reduce the number of distinct levels is to merge the highest into the next highest, which takes one minute per distinct level. Therefore, the minimum number of minutes required is equal to the number of distinct initial apple counts.

For example, if the initial apple counts are 1, 2, 3, 3:
The distinct initial counts are {1, 2, 3}. So, $k=3$.

*   **Minute 1:** Trees with 3 apples can be reduced to 1 or 2. Let's reduce them to 2.
    Trees become: 1, 2, 2, 2. Distinct counts: {1, 2}.
*   **Minute 2:** Trees with 2 apples can be reduced to 1.
    Trees become: 1, 1, 1, 1. Distinct counts: {1}.
*   **Minute 3:** Trees with 1 apple can be reduced to 0.
    Trees become: 0, 0, 0, 0. Distinct counts: {0}.

This takes 3 minutes, which is the number of distinct initial apple counts.

## Complexity Analysis

-   **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the map implementation.
    -   Reading $N$ apple counts: $O(N)$.
    -   Inserting into a `std::map`: Each insertion takes $O(\log D)$ where $D$ is the number of distinct elements currently in the map. In the worst case, $D$ can be up to $N$. So, populating the map takes $O(N \log N)$.
    -   Getting the size of the map: $O(1)$.
    -   The dominant factor is populating the map. If `std::unordered_map` was used, the average time complexity would be $O(N)$, but worst-case $O(N^2)$. Given the constraints and typical competitive programming scenarios, `std::map` is safer for guaranteed performance.

-   **Space Complexity**: $O(D)$, where $D$ is the number of distinct apple counts. In the worst case, $D$ can be up to $N$. So, the space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of apple trees
        std::cin >> n;

        // Use a map to store the frequency of each distinct apple count.
        // The key is the number of apples, and the value is its frequency.
        // The size of this map will directly give us the number of distinct apple counts.
        std::map<int, int> counts;

        for (int i = 0; i < n; ++i) {
            int apples;
            std::cin >> apples;
            counts[apples]++; // Increment the count for this number of apples
        }

        // The minimum number of minutes required is equal to the number of distinct
        // initial apple counts. This is because each distinct count represents a
        // "level" that needs to be reduced. The operation allows us to merge
        // the highest current level into the next highest, effectively reducing
        // the number of distinct levels by one per minute.
        // To reach 0 apples from k distinct initial counts, it takes k minutes.
        std::cout << counts.size() << "\n";
    }
    return 0;
}
```