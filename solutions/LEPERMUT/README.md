# Little Elephant and Permutations (LEPERMUT)

- **Difficulty Rating**: 1261
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given permutation of numbers from 1 to $N$ is "good". A permutation is defined as "good" if the total number of inversions is equal to the number of local inversions.

An **inversion** in a permutation $A$ is a pair of indices $(i, j)$ such that $i < j$ and $A[i] > A[j]$.
A **local inversion** is an index $i$ such that $A[i] > A[i+1]$.

## Intuition & Mathematical Observation

Let's analyze the relationship between inversions and local inversions.

1.  **Local Inversions:** A local inversion occurs at index $i$ if $A[i] > A[i+1]$. This directly corresponds to an inversion pair $(i, i+1)$.

2.  **Inversions:** An inversion is a pair $(i, j)$ where $i < j$ and $A[i] > A[j]$.

The problem states that a permutation is "good" if the total number of inversions equals the number of local inversions.

Consider an inversion $(i, j)$ where $i < j$ and $A[i] > A[j]$.
*   If $j = i+1$, then this inversion $(i, i+1)$ is also a local inversion at index $i$.
*   If $j > i+1$, then this inversion $(i, j)$ is *not* a local inversion.

For the total number of inversions to be equal to the number of local inversions, every inversion must be a local inversion. This means that there cannot be any inversions $(i, j)$ where $j > i+1$.

In other words, for any pair of indices $(i, j)$ such that $i < j$ and $A[i] > A[j]$, it must be the case that $j = i+1$.

This condition can be rephrased: if $A[i] > A[j]$ for some $i < j$, then it must be that $j = i+1$.
This implies that if $A[i] > A[j]$ for some $i < j$, then $A[i]$ must be greater than $A[i+1], A[i+2], \dots, A[j]$.

The crucial observation is that if there exists an inversion $(i, j)$ where $j > i+1$, then the total number of inversions will be strictly greater than the number of local inversions. Therefore, for a permutation to be "good", there must be **no inversions $(i, j)$ where $j > i+1$**.

This condition is equivalent to stating that for every index $i$, the element $A[i]$ must be less than or equal to all elements $A[j]$ where $j \ge i+2$.
If $A[i] > A[j]$ for any $j \ge i+2$, then we have found an inversion $(i, j)$ that is not a local inversion, and the permutation is not good.

So, the algorithm is to iterate through all possible pairs $(i, j)$ where $j \ge i+2$ and check if $A[i] > A[j]$. If such a pair is found, the permutation is not good. If no such pair is found after checking all possibilities, the permutation is good.

Let's consider the constraints. $N$ can be up to $10^5$. A naive $O(N^2)$ check for all pairs $(i, j)$ where $j \ge i+2$ would be too slow. However, the problem statement implies that the input is a permutation of numbers from 1 to $N$. The constraints on $N$ for the actual test cases might be smaller, or there's a more efficient way to check this condition.

Looking at the provided solution code, it implements the $O(N^2)$ check:
```cpp
        bool is_good = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 2; j < n; ++j) {
                if (a[i] > a[j]) {
                    is_good = false;
                    break;
                }
            }
            if (!is_good) {
                break;
            }
        }
```
This code directly checks the condition: for every $i$, is $A[i]$ greater than any $A[j]$ where $j \ge i+2$? If yes, it's not good.

Given the difficulty rating (1261) and the fact that it was solved in 1 attempt, it's likely that the test cases for this problem have a smaller constraint on $N$ (e.g., $N \le 1000$ or $N \le 2000$) where an $O(N^2)$ solution passes within the time limits. If $N$ were truly up to $10^5$, a more optimized approach would be necessary.

Let's confirm the logic with an example:
Permutation: `[1, 2, 3, 4]` ($N=4$)
- Local inversions: None.
- Inversions: None.
- Total inversions = Local inversions. Good.
  - Check:
    - $i=0, A[0]=1$: $j=2, A[2]=3$ ($1 \ngtr 3$), $j=3, A[3]=4$ ($1 \ngtr 4$). OK.
    - $i=1, A[1]=2$: $j=3, A[3]=4$ ($2 \ngtr 4$). OK.
    - $i=2, A[2]=3$: No $j \ge i+2$. OK.
    - $i=3, A[3]=4$: No $j \ge i+2$. OK.
  - Result: YES.

Permutation: `[1, 3, 2, 4]` ($N=4$)
- Local inversions: $A[1]=3 > A[2]=2$. Index 1 is a local inversion. Count = 1.
- Inversions:
  - $(1, 2): A[1]=3 > A[2]=2$. This is a local inversion.
  - $(0, 2): A[0]=1 \ngtr A[2]=2$.
  - $(0, 1): A[0]=1 \ngtr A[1]=3$.
  - $(0, 3): A[0]=1 \ngtr A[3]=4$.
  - $(1, 3): A[1]=3 \ngtr A[3]=4$.
  - $(2, 3): A[2]=2 \ngtr A[3]=4$.
  Wait, let's list all inversions properly:
  - $(1, 2): A[1]=3 > A[2]=2$.
  Total inversions = 1.
- Total inversions = Local inversions. Good.
  - Check:
    - $i=0, A[0]=1$: $j=2, A[2]=2$ ($1 \ngtr 2$), $j=3, A[3]=4$ ($1 \ngtr 4$). OK.
    - $i=1, A[1]=3$: $j=3, A[3]=4$ ($3 \ngtr 4$). OK.
    - $i=2, A[2]=2$: No $j \ge i+2$. OK.
    - $i=3, A[3]=4$: No $j \ge i+2$. OK.
  - Result: YES.

Permutation: `[3, 1, 2, 4]` ($N=4$)
- Local inversions: $A[0]=3 > A[1]=1$. Index 0 is a local inversion. Count = 1.
- Inversions:
  - $(0, 1): A[0]=3 > A[1]=1$. (Local)
  - $(0, 2): A[0]=3 > A[2]=2$. (Not local, $j=2, i=0$, $j > i+1$)
  - $(0, 3): A[0]=3 \ngtr A[3]=4$.
  - $(1, 2): A[1]=1 \ngtr A[2]=2$.
  - $(1, 3): A[1]=1 \ngtr A[3]=4$.
  - $(2, 3): A[2]=2 \ngtr A[3]=4$.
  Total inversions = 2.
- Total inversions (2) $\neq$ Local inversions (1). Not good.
  - Check:
    - $i=0, A[0]=3$: $j=2, A[2]=2$ ($3 > 2$). Found an inversion $(0, 2)$ where $j > i+1$. Not good.
  - Result: NO.

The logic holds. The $O(N^2)$ approach is correct for the problem's definition.

## Complexity Analysis

-   **Time Complexity**: $O(T \cdot N^2)$, where $T$ is the number of test cases and $N$ is the size of the permutation. The nested loops iterate up to $N$ times each. For each test case, the dominant part is the nested loop.
-   **Space Complexity**: $O(N)$ for storing the input permutation in a `std::vector`.

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
        int n; // Size of the permutation
        std::cin >> n;
        std::vector<int> a(n); // Vector to store the permutation
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read the permutation elements
        }

        // A permutation is "good" if the number of inversions equals the number of local inversions.
        // An inversion is a pair (i, j) such that i < j and A[i] > A[j].
        // A local inversion is an index i such that A[i] > A[i+1].
        //
        // For the number of inversions to equal the number of local inversions,
        // every inversion must be a local inversion.
        // This means that for any pair (i, j) with i < j and A[i] > A[j],
        // it must be the case that j = i + 1.
        //
        // Therefore, a permutation is NOT good if there exists any inversion (i, j)
        // where j > i + 1.
        //
        // This condition is equivalent to checking if for any index i,
        // A[i] is greater than any element A[j] where j >= i + 2.
        // If such a pair (i, j) exists, the permutation is not good.

        bool is_good = true; // Assume the permutation is good initially
        // Iterate through each element A[i]
        for (int i = 0; i < n; ++i) {
            // Check against elements A[j] where j is at least two positions ahead of i
            for (int j = i + 2; j < n; ++j) {
                // If A[i] is greater than A[j] where j >= i + 2,
                // we have found an inversion (i, j) that is not a local inversion.
                if (a[i] > a[j]) {
                    is_good = false; // The permutation is not good
                    break; // No need to check further for this 'i'
                }
            }
            // If we found that the permutation is not good, we can stop checking altogether
            if (!is_good) {
                break;
            }
        }

        // Output the result
        if (is_good) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```