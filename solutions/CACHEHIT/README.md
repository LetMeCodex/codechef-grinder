# [Cache Hits (CACHEHIT)](https://www.codechef.com/problems/CACHEHIT)
- **Difficulty Rating**: 1320
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a memory system with `N` elements, indexed from `A_0` to `A_{N-1}`. These elements are organized into blocks, where each block contains `B` consecutive elements. Specifically:
*   Block 0 contains elements `A_0, A_1, ..., A_{B-1}`.
*   Block 1 contains elements `A_B, A_{B+1}, ..., A_{2B-1}`.
*   And so on.

A cache is available that can hold exactly one block at a time. When an element `A_x` is accessed:
1.  If the block containing `A_x` is *not* currently in the cache, the entire block is loaded into the cache. This replaces any block that might have been there previously. This counts as one "block load".
2.  If the block containing `A_x` *is* already in the cache, no new block load occurs.

Given `M` sequential accesses to elements `A_x`, the task is to determine the total number of times a block is loaded into the cache.

## Intuition & Mathematical Observation

The core of this problem is to efficiently determine which block an element `A_x` belongs to and then track the state of the cache.

1.  **Determining Block ID**:
    Given that blocks are of size `B` and elements are indexed from `0`:
    *   Elements `A_0, ..., A_{B-1}` are in Block 0.
    *   Elements `A_B, ..., A_{2B-1}` are in Block 1.
    *   Elements `A_{2B}, ..., A_{3B-1}` are in Block 2.
    *   In general, elements `A_{kB}, ..., A_{(k+1)B-1}` are in Block `k`.

    From this pattern, it's clear that for any element `A_x`, its corresponding block ID can be calculated using integer division: `block_id = x / B`. For example, if `B=3`:
    *   `A_0`: `0 / 3 = 0` (Block 0)
    *   `A_1`: `1 / 3 = 0` (Block 0)
    *   `A_2`: `2 / 3 = 0` (Block 0)
    *   `A_3`: `3 / 3 = 1` (Block 1)
    *   `A_4`: `4 / 3 = 1` (Block 1)

2.  **Tracking Cache State**:
    We need a variable to keep track of which block is currently loaded in the cache. Let's call it `current_block_in_cache`.
    *   Initially, the cache is empty. We can represent this state with a special value, like `-1`, since valid block IDs are non-negative (`0, 1, 2, ...`).
    *   For each access `A_x`:
        *   Calculate `target_block_id = x / B`.
        *   Compare `target_block_id` with `current_block_in_cache`.
        *   If `target_block_id` is *different* from `current_block_in_cache` (which will always be true for the very first access when `current_block_in_cache` is `-1`), then a block load occurs. We increment our `load_count` and update `current_block_in_cache` to `target_block_id`.
        *   If `target_block_id` is the *same* as `current_block_in_cache`, the block is already present, so no load occurs, and the `load_count` remains unchanged.

By iterating through all `M` accesses and applying this logic, we can accurately count the total number of block loads.

## Complexity Analysis

*   **Time Complexity**: The solution involves a single loop that iterates `M` times, once for each access. Inside the loop, we perform a constant number of operations: reading an integer (`x`), integer division (`x / B`), a comparison, and potentially an increment and an assignment. These operations take constant time. Therefore, for a single test case, the time complexity is $O(M)$. Since there are `T` test cases, the total time complexity is $O(T \cdot M)$.

*   **Space Complexity**: The solution uses a fixed number of integer variables (`N`, `B`, `M`, `current_block_in_cache`, `load_count`, `x`, `target_block_id`). These variables consume a constant amount of memory regardless of the input size (`N` or `M`). Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as per problem instructions

// Using the standard namespace as requested by problem instructions
using namespace std;

void solve() {
    int N, B, M;
    cin >> N >> B >> M;

    // current_block_in_cache stores the ID of the block currently loaded in the cache.
    // Initialize with -1 to signify that the cache is empty initially.
    // Valid block IDs are non-negative (0, 1, 2, ...).
    int current_block_in_cache = -1; 
    
    // load_count keeps track of how many times a block has been loaded into the cache.
    int load_count = 0;

    // Iterate through each of the M accesses Chef wants to make.
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x; // Read the index of the element A_x to be accessed.

        // Calculate the block ID for the current element A_x.
        // Integer division `x / B` correctly determines which block A_x belongs to.
        // For example, if B=3:
        // Indices 0, 1, 2 are in block 0 (0/3=0, 1/3=0, 2/3=0)
        // Indices 3, 4, 5 are in block 1 (3/3=1, 4/3=1, 5/3=1)
        int target_block_id = x / B;

        // If the target block is different from the one currently loaded in the cache,
        // a new block load is required. This also covers the initial state where
        // current_block_in_cache is -1 (empty cache).
        if (target_block_id != current_block_in_cache) {
            load_count++; // Increment the count of block loads.
            current_block_in_cache = target_block_id; // Update the cache to hold the new block.
        }
        // If target_block_id == current_block_in_cache,
        // the element A_x is in the block already present in the cache,
        // so no new load occurs.
    }

    // Print the total number of block loads for this test case, followed by a newline.
    cout << load_count << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded).
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop through each test case.
        solve(); // Call the function to solve the current test case.
    }

    return 0; // Indicate successful program execution.
}
```