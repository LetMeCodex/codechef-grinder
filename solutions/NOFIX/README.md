# [Avoid Fixed Points (NOFIX)](https://www.codechef.com/problems/NOFIX)
- **Difficulty Rating**: 1250
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to make an array `A` "fixed-point free". An operation consists of inserting any positive integer at any position in the array. A fixed point is defined as an index `i` (1-based) such that the element `A[i]` at that index is equal to `i`. We need to output the minimum total number of operations.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how inserting an element affects the indices of subsequent elements. When an element is inserted at some position, all elements that were originally at or after that position effectively shift one place to the right, increasing their 1-based indices by one.

Consider processing the array elements from left to right. Let's maintain a count, `operations_count`, which represents the total number of elements we have inserted into the array *so far*.

When we are examining the `i`-th element of the *original* array (using 0-based indexing for `i`):
1.  Its original 1-based index would be `i + 1`.
2.  However, because we might have inserted `operations_count` elements *before* this `i`-th element, its *current effective 1-based index* in the modified array will be `(i + 1) + operations_count`.

Now, we check if this `i`-th element forms a fixed point. This happens if its value `A[i]` is equal to its `effective_index`.
If `A[i] == (i + 1) + operations_count`, then we have a fixed point. To break this fixed point and ensure the array remains fixed-point free, we *must* perform an operation. The most efficient way to do this is to increment our `operations_count`.

Why does incrementing `operations_count` work?
When we increment `operations_count`, it conceptually means we've inserted an element somewhere *before or at* the current position. This insertion shifts the current element `A[i]` (and all subsequent elements) one position to the right.
So, the `effective_index` of `A[i]` changes from `(i + 1) + operations_count` to `(i + 1) + (operations_count + 1)`.
Since `A[i]`'s value was `(i + 1) + operations_count`, its new index `(i + 1) + operations_count + 1` will no longer be equal to its value. Thus, `A[i]` is no longer a fixed point.

This greedy strategy works because:
1.  We only perform an operation when it's absolutely necessary (i.e., when a fixed point is detected).
2.  Each operation effectively shifts the current element and all subsequent elements, breaking the current fixed point. This shift also increases the indices of all future elements, which can only help in preventing them from becoming fixed points (as their values remain constant while their indices increase). It never makes it harder to avoid fixed points for elements further down the array.

By iterating through the array once and incrementing `operations_count` whenever a fixed point is encountered at its current effective index, we find the minimum number of operations.

**Example:** `A = [1, 2, 3]`
`operations_count = 0`

1.  `i = 0`, `current_A_val = 1`
    `effective_index = (0 + 1 + operations_count) = 1 + 0 = 1`
    `current_A_val == effective_index` (1 == 1) is true.
    Increment `operations_count`. Now `operations_count = 1`.
    (Conceptually, we inserted an element, making the array `[X, 1, 2, 3]`. The original `A[0]` (value 1) is now at index 2, so it's not a fixed point.)

2.  `i = 1`, `current_A_val = 2`
    `effective_index = (1 + 1 + operations_count) = 2 + 1 = 3`
    `current_A_val == effective_index` (2 == 3) is false.
    `operations_count` remains 1.

3.  `i = 2`, `current_A_val = 3`
    `effective_index = (2 + 1 + operations_count) = 3 + 1 = 4`
    `current_A_val == effective_index` (3 == 4) is false.
    `operations_count` remains 1.

Final `operations_count = 1`. This is the minimum number of operations.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    The solution involves a single loop that iterates `N` times, where `N` is the size of the input array. Inside the loop, all operations (reading input, arithmetic calculations, comparisons, and increments) take constant time. For `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`n`, `operations_count`, `i`, `current_A_val`, `effective_index`, `t`) to store counts and temporary values. These variables consume a constant amount of memory regardless of the input array size `N`. The input array itself is processed element by element and not stored in its entirety, thus requiring no additional space proportional to `N`.

## Solution Code

```cpp
#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    
    // 'operations_count' tracks the number of elements inserted so far.
    // Each inserted element shifts all subsequent elements' indices by 1.
    int operations_count = 0;
    
    for (int i = 0; i < n; ++i) {
        int current_A_val;
        std::cin >> current_A_val; // Read the i-th element of the original array
        
        // Calculate the 1-based index this element would currently occupy.
        // 'i' is 0-based, so (i + 1) is its original 1-based index.
        // 'operations_count' adds the cumulative shift from previous insertions.
        int effective_index = (i + 1 + operations_count);
        
        // Check if the current element's value equals its effective index.
        if (current_A_val == effective_index) {
            // If it's a fixed point, we must perform an operation.
            // This operation effectively inserts an element, shifting 'current_A_val'
            // and all subsequent elements one position to the right.
            // Incrementing 'operations_count' accounts for this shift for all future elements.
            // It also ensures that 'current_A_val' itself is no longer a fixed point,
            // as its new index would be (effective_index + 1), which is no longer equal to current_A_val.
            operations_count++;
        }
    }
    
    std::cout << operations_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    
    return 0;
}

```