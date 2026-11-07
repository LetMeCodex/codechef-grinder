# [How Many Maximums (HOWMANYMAX)](https://www.codechef.com/problems/HOWMANYMAX)
- **Difficulty Rating**: 1202
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to count the number of indices `i` (from 1 to `N`) such that `A_i` *could* be the maximum element in an array `A` of length `N`. We are not given the array `A` directly. Instead, we are given a binary string `S` of length `N-1`. The characters in `S` define the relative order of adjacent elements in `A`:
*   `S_j = '0'` means `A_j < A_{j+1}`.
*   `S_j = '1'` means `A_j > A_{j+1}`.

We need to find how many positions `i` (1-indexed) can potentially hold the maximum value, given these constraints.

## Intuition & Mathematical Observation

The core idea is to determine, for each possible position `i` in the array `A`, if it's *possible* to construct an array `A` that satisfies all `N-1` given constraints from `S` such that `A_i` is the maximum element.

An element `A_i` can be the maximum if it's greater than all other elements. More specifically, for `A_i` to be the maximum, it must be greater than its immediate neighbors `A_{i-1}` (if `i > 1`) and `A_{i+1}` (if `i < N`). If these local conditions are met, and the remaining elements can be arranged to satisfy the `S` constraints without exceeding `A_i`, then `A_i` is a possible maximum.

Let's analyze the conditions for `A_i` to be a possible maximum based on its position:

We use 1-indexed `A` (from `A_1` to `A_N`) and 0-indexed `S` (from `S[0]` to `S[N-2]`).
The relation `A_j` vs `A_{j+1}` is given by `S_j` (which is `S[j-1]` in 0-indexed string).

1.  **`A_1` can be the maximum:**
    For `A_1` to be the maximum, it must be greater than `A_2`.
    This condition is `A_1 > A_2`, which corresponds to `S_1 = '1'`. In 0-indexed string `S`, this is `S[0] == '1'`.
    If `S[0] == '1'`, we can construct an array where `A_1` is the maximum (e.g., `A_1 = 10`, `A_2 = 5`, and subsequent elements follow `S` without exceeding `A_1`).

2.  **`A_N` can be the maximum:**
    For `A_N` to be the maximum, it must be greater than `A_{N-1}`.
    This condition is `A_{N-1} < A_N`, which corresponds to `S_{N-1} = '0'`. In 0-indexed string `S`, this is `S[N-2] == '0'`.
    If `S[N-2] == '0'`, we can construct an array where `A_N` is the maximum (e.g., `A_N = 10`, `A_{N-1} = 5`, and preceding elements follow `S` without exceeding `A_N`).

3.  **`A_i` can be the maximum for `1 < i < N` (i.e., `i` is an intermediate element):**
    For `A_i` to be the maximum, it must be greater than its left neighbor `A_{i-1}` AND greater than its right neighbor `A_{i+1}`.
    *   `A_{i-1} < A_i` corresponds to `S_{i-1} = '0'`. In 0-indexed string `S`, this is `S[i-2] == '0'`.
    *   `A_i > A_{i+1}` corresponds to `S_i = '1'`. In 0-indexed string `S`, this is `S[i-1] == '1'`.
    So, if `S[i-2] == '0'` AND `S[i-1] == '1'`, then `A_i` is a possible maximum.
    The loop for `i` (1-indexed array position) should iterate from `2` to `N-1`.
    For `i=2`, we check `S[0]` and `S[1]`.
    For `i=N-1`, we check `S[N-3]` and `S[N-2]`.
    All these string indices are valid since `S` has length `N-1` (indices `0` to `N-2`).

By summing up the counts from these three cases, we get the total number of positions that can potentially hold the maximum value. The cases are mutually exclusive in terms of the conditions they check on `S` (e.g., `A_1` only checks `S[0]`, `A_N` only checks `S[N-2]`, and intermediate `A_i` check `S[i-2]` and `S[i-1]`).

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and the string `S` takes `O(N)` time, as `S` has length `N-1`.
    *   Checking the conditions for `A_1` and `A_N` each takes `O(1)` time.
    *   The loop for intermediate elements `A_i` runs `N-2` times (from `i=2` to `N-1`). Inside the loop, operations are `O(1)`. Thus, this part takes `O(N)` time.
    *   Therefore, the total time complexity for a single test case is `O(N)`.
    *   Given that the sum of `N` over all test cases is at most `10^5`, the total time complexity across all test cases is `O(sum of N)`, which is efficient enough.

*   **Space Complexity**:
    *   Storing `N` and `possible_max_count` requires `O(1)` space.
    *   Storing the input string `S` requires `O(N)` space.
    *   Thus, the total space complexity for a single test case is `O(N)`.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector> // Not strictly needed for this problem, but common in competitive programming

void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    int possible_max_count = 0;

    // Case 1: A_1 can be the maximum
    // This is possible if A_1 > A_2, which means S_1 = '1'.
    // In 0-indexed string S, S_1 corresponds to S[0].
    if (S[0] == '1') {
        possible_max_count++;
    }

    // Case 2: A_N can be the maximum
    // This is possible if A_{N-1} < A_N, which means S_{N-1} = '0'.
    // In 0-indexed string S, S_{N-1} corresponds to S[N-2].
    // Note: N-2 is a valid index because N >= 2, so N-1 >= 1, and string length is N-1.
    if (S[N - 2] == '0') {
        possible_max_count++;
    }

    // Case 3: A_i can be the maximum for 1 < i < N (i.e., i from 2 to N-1)
    // This is possible if A_{i-1} < A_i AND A_i > A_{i+1}.
    // In terms of S, this means S_{i-1} = '0' AND S_i = '1'.
    // In 0-indexed string S:
    // S_{i-1} corresponds to S[i-2]
    // S_i corresponds to S[i-1]
    // The loop for array index 'i' goes from 2 up to N-1.
    // The corresponding string indices S[i-2] and S[i-1] will be valid.
    // For i=2, we check S[0] and S[1].
    // For i=N-1, we check S[N-3] and S[N-2].
    // This loop runs for N >= 3. If N=2, the loop range (2 to 1) is empty, which is correct.
    for (int i = 2; i < N; ++i) {
        if (S[i - 2] == '0' && S[i - 1] == '1') {
            possible_max_count++;
        }
    }

    std::cout << possible_max_count << "\n";
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