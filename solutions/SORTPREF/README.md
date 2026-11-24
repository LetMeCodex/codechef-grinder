# Sorting Prefixes (SORTPREF)
- **Difficulty Rating**: 1291
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ distinct integers from $1$ to $N$, we can perform an operation: choose an index $i$ ($1 \le i \le N$) and sort the prefix $A[1 \dots i]$ in ascending order. The cost of this operation is $A[i]$ (the value at index $i$ *before* sorting). The goal is to find the minimum total cost to sort the entire array $A$ into ascending order, i.e., $A[i] = i$ for all $1 \le i \le N$.

## Intuition & Mathematical Observation

The problem asks for the minimum cost to sort the array. We have a specific operation that sorts a prefix. The cost of sorting a prefix $A[1 \dots i]$ is the value $A[i]$ at the end of that prefix.

Let's consider the target sorted array: $[1, 2, 3, \dots, N]$.
We are given an array $A$ which is a permutation of $[1, 2, \dots, N]$.

Consider the elements from the right end of the array. If the last element $A[N]$ is already $N$, then this element is in its correct sorted position. If $A[N-1]$ is $N-1$ and $A[N]$ is $N$, then the suffix of length 2 is sorted. We can generalize this: we are looking for the longest suffix of the array that is already sorted and contains the correct elements in their correct positions.

Let's say the longest sorted suffix is $A[k \dots N]$, where $A[i] = i$ for all $i$ from $k$ to $N$. This means the elements $k, k+1, \dots, N$ are already in their correct positions at indices $k, k+1, \dots, N$ respectively.
If such a suffix exists, then the prefix $A[1 \dots k-1]$ is the part of the array that is *not* in its final sorted position. To sort the entire array, we must sort this prefix $A[1 \dots k-1]$.

The available operation allows us to sort a prefix $A[1 \dots i]$ with cost $A[i]$. To sort the prefix $A[1 \dots k-1]$, we can apply the operation at index $i = k-1$. The cost of this operation would be the value of $A[k-1]$ *before* the sorting operation is applied. After this single operation, the prefix $A[1 \dots k-1]$ will be sorted, and since the suffix $A[k \dots N]$ was already sorted, the entire array $A[1 \dots N]$ will be sorted.

Therefore, the strategy is to find the largest index $k$ such that the suffix $A[k \dots N]$ is already sorted (i.e., $A[i] = i$ for $i$ from $k$ to $N$). If such a $k$ is found, the prefix $A[1 \dots k-1]$ needs to be sorted. The minimum cost to achieve this is by performing the sort operation on $A[1 \dots k-1]$, which costs $A[k-1]$ (the value at index $k-1$ before sorting).

If the entire array is already sorted (i.e., $A[i] = i$ for all $i$ from $1$ to $N$), then $k=1$, and the prefix to sort is empty. The cost is $0$.

Let's use 0-based indexing for implementation convenience. The array is $A[0 \dots N-1]$. The target sorted array is $[1, 2, \dots, N]$.
We are looking for the largest index $k$ such that $A[i] = i+1$ for all $i$ from $k$ to $N-1$.
This means the suffix $A[k \dots N-1]$ is sorted and contains the elements $k+1, k+2, \dots, N$.
The prefix that needs sorting is $A[0 \dots k-1]$.
The operation to sort $A[0 \dots i]$ costs $A[i]$. To sort the prefix $A[0 \dots k-1]$, we apply the operation at index $i = k-1$. The cost is $A[k-1]$ (the value at index $k-1$ before sorting).

We can find the first index from the right that is *not* in its sorted position. Let this index be `first_unsorted_idx`.
We iterate from $i = N-1$ down to $0$.
If $A[i] == i+1$, this element is in its correct sorted place. We continue checking to the left.
If $A[i] \neq i+1$, then this is the first element from the right that is out of place. The prefix $A[0 \dots i]$ needs to be sorted. The cost of sorting this prefix using the operation at index $i$ is $A[i]$.
If the loop completes without finding any element out of place (i.e., `first_unsorted_idx` remains $N$), it means the array is already sorted, and the cost is $0$.

Example: $A = [2, 3, 1, 4, 5]$, $N=5$.
Target: $[1, 2, 3, 4, 5]$.

Iterate from right to left (0-indexed):
- $i=4$: $A[4] = 5$. Expected $4+1=5$. Match.
- $i=3$: $A[3] = 4$. Expected $3+1=4$. Match.
- $i=2$: $A[2] = 1$. Expected $2+1=3$. Mismatch.
  `first_unsorted_idx` becomes $2$. The prefix $A[0 \dots 2]$ needs to be sorted.
  The cost is $A[2]$ (the value before sorting), which is $1$.
  The operation is to sort $A[0 \dots 2]$. Cost is $A[2] = 1$.
  Array becomes $[1, 2, 3, 4, 5]$. Total cost = $1$.

Example: $A = [1, 2, 3, 4, 5]$, $N=5$.
Target: $[1, 2, 3, 4, 5]$.

Iterate from right to left:
- $i=4$: $A[4] = 5$. Expected $5$. Match.
- $i=3$: $A[3] = 4$. Expected $4$. Match.
- $i=2$: $A[2] = 3$. Expected $3$. Match.
- $i=1$: $A[1] = 2$. Expected $2$. Match.
- $i=0$: $A[0] = 1$. Expected $1$. Match.
The loop finishes. `first_unsorted_idx` remains $N$ (which is 5).
Total cost = $0$.

Example: $A = [5, 4, 3, 2, 1]$, $N=5$.
Target: $[1, 2, 3, 4, 5]$.

Iterate from right to left:
- $i=4$: $A[4] = 1$. Expected $5$. Mismatch.
  `first_unsorted_idx` becomes $4$. The prefix $A[0 \dots 4]$ needs to be sorted.
  The cost is $A[4]$ (the value before sorting), which is $1$.
  The operation is to sort $A[0 \dots 4]$. Cost is $A[4] = 1$.
  Array becomes $[1, 2, 3, 4, 5]$. Total cost = $1$.

The logic seems sound. The key is that sorting a prefix $A[1 \dots i]$ with cost $A[i]$ is the only way to fix elements up to index $i$. If the suffix $A[k \dots N]$ is already sorted, we only need to fix the prefix $A[1 \dots k-1]$. The most "efficient" way to fix this prefix is to sort it using the operation at index $k-1$, costing $A[k-1]$. This single operation will place all elements $1, \dots, k-1$ in their correct positions.

## Complexity Analysis

- **Time Complexity**: $O(N)$
  The code iterates through the input array once from right to left to find the `first_unsorted_idx`. This takes $O(N)$ time. The rest of the operations are constant time. Thus, the total time complexity is $O(N)$ per test case.

- **Space Complexity**: $O(N)$
  We use a `std::vector<int> a` to store the input array, which takes $O(N)$ space. Other variables use constant space. Thus, the total space complexity is $O(N)$ per test case.

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
        int n; // Size of the array
        std::cin >> n;
        std::vector<int> a(n); // The input array
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        long long total_cost = 0;
        
        // We want to find the longest suffix that is already sorted and contains the correct elements.
        // The target sorted array is [1, 2, ..., n].
        // We iterate from the right end of the array (index n-1) towards the left.
        // We are looking for the first index `i` from the right such that `a[i]` is NOT equal to `i+1`.
        // If `a[i] == i+1`, it means the element at index `i` is in its correct sorted position.
        // If we find such an `i`, it implies that the prefix `a[0...i]` needs to be sorted.
        // The operation to sort prefix `a[0...k]` costs `a[k]`.
        // To sort the prefix `a[0...i]`, we should perform the operation at index `i`.
        // The cost of this operation is the value of `a[i]` *before* sorting.

        int first_unsorted_idx = n; // Initialize to n, indicating the array might be fully sorted.
                                    // If the loop completes and this remains n, it means all elements were in place.

        for (int i = n - 1; i >= 0; --i) {
            // Check if the element at index `i` is in its correct sorted position.
            // In a 0-indexed array sorted to [1, 2, ..., n], the element at index `i` should be `i+1`.
            if (a[i] != i + 1) {
                // Found the first element from the right that is out of place.
                // This means the prefix `a[0...i]` needs to be sorted.
                // The operation to sort `a[0...i]` is performed at index `i`.
                // The cost of this operation is the value `a[i]` at this point.
                first_unsorted_idx = i;
                break; // We found the boundary, no need to check further left.
            }
        }

        // If `first_unsorted_idx` is still `n`, it means the loop completed without finding any
        // element out of place. The array was already sorted.
        if (first_unsorted_idx == n) {
            total_cost = 0; // No operations needed, cost is 0.
        } else {
            // The prefix `a[0...first_unsorted_idx]` needs to be sorted.
            // The operation to sort this prefix is applied at index `first_unsorted_idx`.
            // The cost is the value of `a[first_unsorted_idx]` before sorting.
            total_cost = a[first_unsorted_idx];
        }

        std::cout << total_cost << "\n";
    }
    return 0;
}
```