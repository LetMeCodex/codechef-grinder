# [Chef and Recipe (CHEFRECP)](https://www.codechef.com/problems/CHEFRECP)
- **Difficulty Rating**: 1398
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine if a given recipe, represented as a sequence of ingredient types, is "valid" according to two specific rules:

1.  **Contiguous Usage**: Each ingredient type must be used in a single, contiguous block. Once a jar of an ingredient is put away, it cannot be used again. For example, `[1, 1, 2, 2, 1]` is invalid because ingredient `1` is used, then `2`, then `1` again. `[1, 1, 2, 2]` is valid for this rule.
2.  **Unique Quantities**: All ingredient types used in the recipe must have unique quantities. For example, if ingredient type `5` is used `3` times, no other ingredient type can be used `3` times. If ingredient `1` is used `2` times and ingredient `2` is also used `2` times, this rule is violated.

We need to output "YES" if the recipe is valid according to both rules, and "NO" otherwise.

## Intuition & Mathematical Observation

Let's break down how to efficiently check each rule.

**Rule 1: Contiguous Usage**

This rule implies that if we encounter an ingredient type `X` at some point in the recipe, and then later encounter `X` again, all ingredients between these two occurrences of `X` must also be `X`. If we see `X`, then `Y` (where `Y != X`), and then `X` again, it's a violation.

To check this, we can iterate through the recipe and identify contiguous blocks of identical ingredients.
1.  We can maintain a boolean array, say `finished_types_arr`, of size `1001` (since ingredient types are from 1 to 1000). `finished_types_arr[k]` will be `true` if ingredient type `k` has already had its contiguous block processed and "put away".
2.  As we iterate through the recipe, when we encounter an ingredient `A[i]`:
    *   If `finished_types_arr[A[i]]` is already `true`, it means we are using an ingredient type that was previously "put away". This violates Rule 1, so we can immediately output "NO" and terminate.
    *   If it's `false`, we identify the entire contiguous block of `A[i]`. For example, if `A[i...j-1]` is this block.
    *   After processing this block, we mark `finished_types_arr[A[i]] = true`.
    *   We then continue our iteration from index `j` (the start of the next block).

**Rule 2: Unique Quantities**

This rule requires that the count of each *distinct* ingredient type used in the recipe must be unique.
1.  While we are iterating through the recipe to check Rule 1 and identify contiguous blocks, we can also simultaneously count the occurrences of each ingredient type. A simple integer array, `counts_arr`, of size `1001` can store `counts_arr[k] = total_count_of_ingredient_k`.
2.  After the first pass (where Rule 1 is checked and counts are collected), we will have the total count for every ingredient type.
3.  Now, we need to check if these counts are unique. We can use another boolean array, `seen_counts`, of size `N+1` (since the maximum possible count for any ingredient type is `N`). `seen_counts[c]` will be `true` if we have already encountered an ingredient type with count `c`.
4.  We iterate through `counts_arr` from `k = 1` to `1000`. For each `k`:
    *   If `counts_arr[k] > 0` (meaning ingredient `k` was actually used in the recipe):
        *   Let `current_count = counts_arr[k]`.
        *   If `seen_counts[current_count]` is `true`, it means another ingredient type already had this same quantity. This violates Rule 2, so we output "NO" and terminate.
        *   Otherwise, we set `seen_counts[current_count] = true`.

If both passes complete without any violations, the recipe is valid, and we output "YES".

**Example Walkthrough:**
Recipe: `[1, 2, 1]`
*   `N = 3`. `counts_arr` = `[0...0]`, `finished_types_arr` = `[F...F]`, `seen_counts` = `[F...F]`
*   **Pass 1 (Rule 1 & Count Collection):**
    *   `i = 0`, `A[0] = 1`. `finished_types_arr[1]` is `F`.
        *   Block is `[1]`. `current_count = 1`.
        *   `finished_types_arr[1] = T`. `counts_arr[1] = 1`.
        *   `i` becomes `1`.
    *   `i = 1`, `A[1] = 2`. `finished_types_arr[2]` is `F`.
        *   Block is `[2]`. `current_count = 1`.
        *   `finished_types_arr[2] = T`. `counts_arr[2] = 1`.
        *   `i` becomes `2`.
    *   `i = 2`, `A[2] = 1`. `finished_types_arr[1]` is `T`. **Violation of Rule 1!** Output "NO".

Recipe: `[1, 1, 2, 3, 3]`
*   `N = 5`. `counts_arr` = `[0...0]`, `finished_types_arr` = `[F...F]`, `seen_counts` = `[F...F]`
*   **Pass 1 (Rule 1 & Count Collection):**
    *   `i = 0`, `A[0] = 1`. `finished_types_arr[1]` is `F`.
        *   Block is `[1, 1]`. `current_count = 2`.
        *   `finished_types_arr[1] = T`. `counts_arr[1] = 2`.
        *   `i` becomes `2`.
    *   `i = 2`, `A[2] = 2`. `finished_types_arr[2]` is `F`.
        *   Block is `[2]`. `current_count = 1`.
        *   `finished_types_arr[2] = T`. `counts_arr[2] = 1`.
        *   `i` becomes `3`.
    *   `i = 3`, `A[3] = 3`. `finished_types_arr[3]` is `F`.
        *   Block is `[3, 3]`. `current_count = 2`.
        *   `finished_types_arr[3] = T`. `counts_arr[3] = 2`.
        *   `i` becomes `5`.
    *   Loop ends. Rule 1 satisfied.
*   **Pass 2 (Rule 2 - Unique Quantities):**
    *   `counts_arr` is now: `[0, 2, 1, 2, 0...]` (index 0 unused, index 1 has count 2, index 2 has count 1, index 3 has count 2).
    *   `k = 1`: `counts_arr[1] = 2`. `seen_counts[2]` is `F`. Set `seen_counts[2] = T`.
    *   `k = 2`: `counts_arr[2] = 1`. `seen_counts[1]` is `F`. Set `seen_counts[1] = T`.
    *   `k = 3`: `counts_arr[3] = 2`. `seen_counts[2]` is `T`. **Violation of Rule 2!** Output "NO".

This approach correctly handles both rules with efficient array lookups.

## Complexity Analysis

Let $N$ be the number of ingredients in the recipe ($1 \le N \le 1000$).
Let $M$ be the maximum possible ingredient type ($1 \le A_i \le 1000$, so $M=1000$).

-   **Time Complexity**:
    *   The first loop iterates through the recipe array `A`. The outer loop variable `i` is advanced by `j` (the end of the current contiguous block). In total, `j` (and effectively `i`) traverses the array `A` exactly once. This part takes $O(N)$ time.
    *   The second loop iterates from `k = 1` to `M` (1000). Inside the loop, array accesses are $O(1)$. This part takes $O(M)$ time.
    *   Therefore, the total time complexity per test case is $O(N + M)$.
    *   Given $N \le 1000$ and $M = 1000$, this is $O(1000 + 1000) = O(2000)$ operations per test case, which is very efficient and well within typical time limits for competitive programming (e.g., $10^8$ operations per second).

-   **Space Complexity**:
    *   `std::vector<int> A(N)`: $O(N)$ space.
    *   `std::vector<int> counts_arr(1001)`: $O(M)$ space.
    *   `std::vector<bool> finished_types_arr(1001)`: $O(M)$ space.
    *   `std::vector<bool> seen_counts(N + 1)`: $O(N)$ space.
    *   Therefore, the total space complexity per test case is $O(N + M)$.
    *   Given $N \le 1000$ and $M = 1000$, this is $O(1000 + 1000) = O(2000)$ units of memory, which is also very efficient.

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout
#include <vector>   // For std::vector
// Removed <bits/stdc++.h> and <set> as they are no longer strictly necessary.

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Max ingredient type is 1000. Use vectors for O(1) access.
    // counts_arr[ingredient_type] stores its count.
    // finished_types_arr[ingredient_type] is true if its block has already been processed.
    // Size 1001 to handle ingredient types from 1 to 1000 (inclusive).
    std::vector<int> counts_arr(1001, 0);
    std::vector<bool> finished_types_arr(1001, false);

    // Iterate through the recipe to check Rule 1 and collect counts for Rule 2.
    // The loop variable 'i' is updated inside the loop to jump to the next block.
    for (int i = 0; i < N; ) {
        int current_ingredient = A[i];

        // Rule 1 check: If this ingredient type has already finished its block,
        // it means Chef is using the jar again, which is not allowed.
        if (finished_types_arr[current_ingredient]) {
            std::cout << "NO\n";
            return;
        }

        // Count occurrences of current_ingredient in its contiguous block.
        int current_count = 0;
        int j = i;
        while (j < N && A[j] == current_ingredient) {
            current_count++;
            j++;
        }

        // Mark this ingredient type as finished.
        finished_types_arr[current_ingredient] = true;
        // Store its count.
        // Note: If an ingredient type appears multiple times (violating Rule 1),
        // its count might be updated multiple times here. However, the 'return'
        // statement for Rule 1 violation ensures we never reach Rule 2 check
        // with an invalid counts_arr if Rule 1 is violated.
        counts_arr[current_ingredient] = current_count;

        // Move 'i' to the start of the next block.
        i = j;
    }

    // If we reached here, Rule 1 (contiguous subsequences) is satisfied.
    // Now, check Rule 2: unique quantities for all ingredient types.
    // Use a boolean vector instead of a set for O(1) average time insertion/check.
    // Max possible count is N (if all ingredients are the same type).
    // Vector size N+1 to handle counts from 1 to N.
    std::vector<bool> seen_counts(N + 1, false); 
    
    // Iterate through all possible ingredient types (1 to 1000).
    for (int k = 1; k <= 1000; ++k) {
        if (counts_arr[k] > 0) { // If ingredient type k was present in the recipe.
            int count_val = counts_arr[k];
            // Check if this count has already been seen for another ingredient type.
            if (seen_counts[count_val]) {
                std::cout << "NO\n"; // Quantity is not unique.
                return;
            }
            seen_counts[count_val] = true; // Mark this count as seen.
        }
    }

    // If we reached here, both rules are satisfied.
    std::cout << "YES\n";
}

int main() {
    // Fast I/O for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}
```