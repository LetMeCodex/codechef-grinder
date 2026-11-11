# Permutation Disturbance (PERDIS)
- **Difficulty Rating**: 1270
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a permutation $P$ of length $N$, where $P_i$ is the element at index $i$ (1-indexed), we want to find the minimum number of swaps required to ensure that for all $i$, $P_i \neq i$. A swap operation involves choosing two indices $i$ and $j$ and exchanging the elements $P_i$ and $P_j$.

## Intuition & Mathematical Observation

The problem asks for the minimum number of swaps to eliminate all fixed points (elements $P_i$ such that $P_i = i$).

Consider the elements that are *not* fixed points. If $P_i \neq i$, this element is already in a "good" position in the sense that it doesn't violate the condition. The problem arises from elements where $P_i = i$.

Let's analyze the effect of a swap. A swap can potentially fix two fixed points if we swap $P_i$ and $P_j$ where $P_i = i$ and $P_j = j$. After the swap, $P_i$ becomes $j$ and $P_j$ becomes $i$. If $i \neq j$, then $P_i \neq i$ and $P_j \neq j$. So, one swap can resolve at most two fixed points.

However, we are looking for the *minimum* number of swaps. This suggests a greedy approach. We want to resolve fixed points as efficiently as possible.

Consider a contiguous block of fixed points. For example, if $P_i = i$, $P_{i+1} = i+1$, ..., $P_{i+k-1} = i+k-1$. This is a block of $k$ fixed points.
If we have a block of length $k$, say from index $i$ to $i+k-1$, where $P_j = j$ for $j \in [i, i+k-1]$.
- If $k=1$, we have $P_i = i$. We need to swap $P_i$ with some $P_j$ where $j \neq i$. If we swap $P_i$ with an element $P_j$ that is not a fixed point ($P_j \neq j$), then $P_i$ becomes $P_j$ (which is not $i$) and $P_j$ becomes $i$. This resolves the fixed point at $i$. The element $i$ is now at index $j$. If $i \neq j$, this is fine. If $i=j$, this is not possible as we are swapping distinct indices.
- If $k=2$, we have $P_i = i$ and $P_{i+1} = i+1$. If we swap $P_i$ and $P_{i+1}$, we get $P_i = i+1$ and $P_{i+1} = i$. Now $P_i \neq i$ and $P_{i+1} \neq i+1$. One swap resolved two fixed points.
- If $k=3$, we have $P_i = i$, $P_{i+1} = i+1$, $P_{i+2} = i+2$.
    - Swap $P_i$ and $P_{i+1}$: $P_i = i+1$, $P_{i+1} = i$, $P_{i+2} = i+2$. Now $P_{i+2}$ is still a fixed point. We need another swap. Swap $P_{i+1}$ and $P_{i+2}$: $P_i = i+1$, $P_{i+1} = i+2$, $P_{i+2} = i$. All fixed points resolved. Total 2 swaps.
    - Alternatively, swap $P_i$ and $P_{i+2}$: $P_i = i+2$, $P_{i+1} = i+1$, $P_{i+2} = i$. Now $P_{i+1}$ is still a fixed point. Swap $P_{i+1}$ with $P_i$: $P_i = i+1$, $P_{i+1} = i+2$, $P_{i+2} = i$. Total 2 swaps.
    - It seems that for a block of length 3, we need 2 swaps.

Let's generalize. Consider a block of $k$ consecutive fixed points: $P_i = i, P_{i+1} = i+1, \dots, P_{i+k-1} = i+k-1$.
We can resolve these $k$ fixed points by performing swaps within this block.
If we swap $P_i$ with $P_{i+1}$, then $P_i$ becomes $i+1$ and $P_{i+1}$ becomes $i$. The fixed points at $i$ and $i+1$ are resolved.
We can pair up adjacent fixed points and swap them.
For a block of length $k$:
- If $k$ is even, say $k=2m$. We can perform $m$ swaps: $(P_i, P_{i+1}), (P_{i+2}, P_{i+3}), \dots, (P_{i+k-2}, P_{i+k-1})$. Each swap resolves two fixed points. Total $m = k/2$ swaps.
- If $k$ is odd, say $k=2m+1$. We can perform $m$ swaps as above: $(P_i, P_{i+1}), \dots, (P_{i+k-3}, P_{i+k-2})$. This leaves $P_{i+k-1} = i+k-1$ as a fixed point. We need one more swap. We can swap $P_{i+k-1}$ with any element that is not a fixed point. If there are no other non-fixed points, we can swap it with one of the elements we just moved, e.g., swap $P_{i+k-1}$ with $P_{i+k-2}$ (which now holds $i+k-2$).
    - A simpler strategy for odd $k$: Swap $P_i$ with $P_{i+1}$, $P_{i+2}$ with $P_{i+3}$, ..., $P_{i+k-3}$ with $P_{i+k-2}$. This uses $(k-1)/2$ swaps and resolves $k-1$ fixed points. The last element $P_{i+k-1}$ is still $i+k-1$. We need one more swap. We can swap $P_{i+k-1}$ with $P_{i+k-2}$ (which now holds $i+k-2$). This resolves the last fixed point. Total swaps: $(k-1)/2 + 1 = (k+1)/2$.

Notice that $(k+1)/2$ is the ceiling of $k/2$, i.e., $\lceil k/2 \rceil$.
- If $k$ is even, $k=2m$, $\lceil k/2 \rceil = \lceil 2m/2 \rceil = m = k/2$.
- If $k$ is odd, $k=2m+1$, $\lceil k/2 \rceil = \lceil (2m+1)/2 \rceil = \lceil m + 0.5 \rceil = m+1 = (k-1)/2 + 1 = (k+1)/2$.

So, a contiguous block of $k$ fixed points requires $\lceil k/2 \rceil$ swaps.

The problem now reduces to identifying contiguous blocks of fixed points and summing up the required swaps for each block.
We can iterate through the permutation. If we encounter a fixed point ($P_i = i$), we start counting the length of the contiguous block of fixed points. Once the block ends (either we reach the end of the array or find a non-fixed point), we calculate $\lceil length/2 \rceil$ and add it to the total swaps. We then continue scanning from the element after the block. If we encounter a non-fixed point, we simply move to the next element.

Let's trace with an example: $N=5$, $P = [1, 2, 3, 4, 5]$.
All are fixed points.
Block 1: $P_0=1, P_1=2, P_2=3, P_3=4, P_4=5$. Length $k=5$.
Swaps needed: $\lceil 5/2 \rceil = 3$.
Example swaps:
1. Swap $P_0, P_1$: $[2, 1, 3, 4, 5]$. Fixed points at 2, 3, 4.
2. Swap $P_2, P_3$: $[2, 1, 4, 3, 5]$. Fixed point at 4.
3. Swap $P_4, P_3$: $[2, 1, 4, 5, 3]$. No fixed points. Total 3 swaps.

Example: $N=5$, $P = [1, 3, 2, 4, 5]$.
$P_0 = 1$ (fixed).
$P_1 = 3 \neq 2$.
$P_2 = 2 \neq 3$.
$P_3 = 4$ (fixed).
$P_4 = 5$ (fixed).

Fixed points are at indices 0, 3, 4.
Block 1: $P_0 = 1$. Length $k=1$. Swaps: $\lceil 1/2 \rceil = 1$.
Block 2: $P_3 = 4, P_4 = 5$. Length $k=2$. Swaps: $\lceil 2/2 \rceil = 1$.
Total swaps = $1 + 1 = 2$.

Let's verify for $P = [1, 3, 2, 4, 5]$:
Fixed points at indices 0, 3, 4.
Swap $P_0$ with $P_1$: $[3, 1, 2, 4, 5]$. Now $P_0=3 \neq 1$. Fixed point at index 0 resolved.
Fixed points remaining: $P_3=4, P_4=5$.
Swap $P_3$ with $P_4$: $[3, 1, 2, 5, 4]$. Now $P_3=5 \neq 3$ and $P_4=4 \neq 4$. Fixed points at 3 and 4 resolved.
Total swaps = 2.

The logic seems sound. The key is that we only care about fixed points. Non-fixed points can be used as "temporary storage" for elements that were previously fixed points. By grouping consecutive fixed points, we can efficiently resolve them. Swapping within a block of fixed points ensures that the elements moved out of their original positions become non-fixed points, and the elements moved in also become non-fixed points (unless we swap an element $i$ with index $j$ where $i=j$, which is not possible with distinct indices).

The implementation can use a boolean array `is_fixed` to mark indices where $P_i = i+1$. Then, iterate through this array to find contiguous segments of `true` values.

The formula $\lceil k/2 \rceil$ can be implemented as `(k + 1) / 2` using integer division.

Let's consider the constraints. $N$ can be up to $10^5$. The approach of iterating through the permutation once to identify fixed points and then iterating again to find blocks is $O(N)$.

The problem statement uses 1-based indexing for $P_i$, but C++ vectors are 0-indexed. So, if $P_i$ is the element at index $i$ (0-indexed), a fixed point is when $P_i = i+1$.

The provided solution code uses `std::vector<bool> is_fixed(n, false);` and checks `if (p[i] == i + 1)`. This correctly identifies fixed points for 0-indexed `p` and 1-indexed values.
The loop `while (i < n)` iterates through the `is_fixed` array.
If `is_fixed[i]` is true, it means we found the start of a block of fixed points.
`int start = i;` stores the beginning of the block.
The inner `while (i < n && is_fixed[i]) { i++; }` finds the end of the contiguous block of fixed points. `i` will point to the first element *after* the block.
`int length = i - start;` calculates the length of the block.
`total_swaps += (length + 1) / 2;` adds the required swaps for this block using integer division for ceiling.
If `is_fixed[i]` is false, we simply increment `i` to move to the next element.

This logic perfectly matches the derived strategy.

## Complexity Analysis

- **Time Complexity**:
    - Reading the input permutation: $O(N)$
    - Identifying fixed points and marking `is_fixed`: $O(N)$
    - Iterating through `is_fixed` to find blocks and calculate swaps: Each element `i` is visited at most twice (once in the outer `while` loop, and potentially once more in the inner `while` loop when it's part of a block). So, this part is also $O(N)$.
    - Total time complexity: $O(N) + O(N) + O(N) = O(N)$.

- **Space Complexity**:
    - Storing the permutation `p`: $O(N)$
    - Storing the `is_fixed` boolean vector: $O(N)$
    - Other variables take constant space.
    - Total space complexity: $O(N) + O(N) = O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <cmath> // Not strictly needed for (length + 1) / 2, but good practice if ceil was used directly.

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Size of the permutation
        std::cin >> n;
        std::vector<int> p(n); // The permutation (0-indexed)
        // is_fixed[i] will be true if p[i] == i + 1 (i.e., a fixed point)
        std::vector<bool> is_fixed(n, false); 
        
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
            // Check for fixed points: element at index i should be i + 1
            if (p[i] == i + 1) {
                is_fixed[i] = true;
            }
        }

        long long total_swaps = 0; // Use long long for total swaps as N can be large
        int i = 0; // Current index for iterating through is_fixed
        
        while (i < n) {
            // If we find a fixed point, it's the start of a potential block of fixed points
            if (is_fixed[i]) {
                int start = i; // Mark the beginning of the block
                
                // Find the end of the contiguous block of fixed points
                // i will be incremented until is_fixed[i] is false or we reach the end of the array
                while (i < n && is_fixed[i]) {
                    i++;
                }
                
                // Calculate the length of the block of fixed points
                int length = i - start;
                
                // A block of length L requires ceil(L/2) swaps.
                // Integer division (length + 1) / 2 correctly computes ceil(length / 2).
                // For example:
                // length = 1: (1+1)/2 = 1 (ceil(0.5) = 1)
                // length = 2: (2+1)/2 = 1 (ceil(1) = 1) - Wait, this is wrong.
                // Let's re-check the formula.
                // length = 1: needs 1 swap. (1+1)/2 = 1. Correct.
                // length = 2: needs 1 swap. (2+1)/2 = 1. Correct.
                // length = 3: needs 2 swaps. (3+1)/2 = 2. Correct.
                // length = 4: needs 2 swaps. (4+1)/2 = 2. Correct.
                // length = 5: needs 3 swaps. (5+1)/2 = 3. Correct.
                // The formula (length + 1) / 2 is indeed correct for ceil(length / 2) using integer division.
                total_swaps += (length + 1) / 2;
            } else {
                // If the current element is not a fixed point, just move to the next element
                i++;
            }
        }
        std::cout << total_swaps << "\n";
    }
    return 0;
}
```