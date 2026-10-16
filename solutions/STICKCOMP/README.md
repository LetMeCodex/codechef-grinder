# [Brick Comparisions (STICKCOMP)](https://www.codechef.com/problems/STICKCOMP)
- **Difficulty Rating**: 625
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef starts with a collection of $N$ bricks, each with a specific size. He begins by picking up brick number 1. Then, he proceeds to examine bricks from number 2 up to number $N$. For each subsequent brick, if its size is *strictly greater* than the size of the brick Chef is currently holding, he drops his current brick and picks up the new, larger one. If the new brick is not strictly larger (i.e., it's smaller than or equal to the current brick), Chef keeps the brick he is currently holding. The task is to determine and output the 1-based index of the brick Chef is holding after he has examined all $N$ bricks.

## Intuition & Mathematical Observation

The problem describes a straightforward process of finding the "maximum so far" with a specific tie-breaking rule.

1.  **Initial State**: Chef starts with brick #1. This means our initial "maximum size found" is the size of brick #1, and the "brick number" is 1.

2.  **Iterative Comparison**: Chef then goes through the remaining bricks one by one, from brick #2 to brick #N.
    *   For each new brick, he compares its size to the size of the brick he currently holds.
    *   The crucial rule is "strictly greater". If the new brick's size is `new_size > current_held_size`, Chef updates his held brick.
    *   If `new_size <= current_held_size`, Chef does *not* change his brick. This is the tie-breaking rule: if two bricks have the same maximum size, Chef keeps the *earlier* one he picked up.

3.  **Core Logic**: This process is essentially finding the maximum element in the array of brick sizes, but with a twist: if multiple bricks share the same maximum size, we want the one with the smallest index among them. Since Chef starts with brick #1 and only updates if a brick is *strictly larger*, he will naturally retain the first brick he encounters that reaches the maximum size.

    For example, if bricks are `[5, 2, 8, 8, 3, 10]`:
    *   Start: Chef holds brick #1 (size 5). `current_max_size = 5`, `final_brick_number = 1`.
    *   Brick #2 (size 2): `2 <= 5`. Chef keeps brick #1.
    *   Brick #3 (size 8): `8 > 5`. Chef drops brick #1, picks up brick #3. `current_max_size = 8`, `final_brick_number = 3`.
    *   Brick #4 (size 8): `8 <= 8`. Chef keeps brick #3. (This demonstrates the tie-breaking: brick #4 is not strictly larger than brick #3, so Chef keeps #3).
    *   Brick #5 (size 3): `3 <= 8`. Chef keeps brick #3.
    *   Brick #6 (size 10): `10 > 8`. Chef drops brick #3, picks up brick #6. `current_max_size = 10`, `final_brick_number = 6`.
    *   Final: Chef holds brick #6.

The algorithm directly simulates this process:
*   Initialize `current_max_size` with `A[0]` (size of brick 1).
*   Initialize `final_brick_number` with `1`.
*   Iterate from `i = 1` to `N-1` (representing bricks 2 to N).
*   If `A[i]` (size of current brick) is greater than `current_max_size`, update `current_max_size = A[i]` and `final_brick_number = i + 1`.
*   After the loop, `final_brick_number` will hold the answer.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` brick sizes into a vector takes $O(N)$ time.
    *   The main loop iterates from `i = 1` to `N-1`, performing a constant number of operations (comparison, assignment) in each iteration. This loop runs $N-1$ times, contributing $O(N)$ time.
    *   All other operations (reading `N`, initializing variables, printing output) take $O(1)$ time.
    *   Therefore, for a single test case, the total time complexity is $O(N)$.
    *   Given $T$ test cases, the overall time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   A `vector<int> A` is used to store the sizes of $N$ bricks. This requires $O(N)$ space.
    *   A few integer variables (`N`, `current_max_size`, `final_brick_number`, `i`, `T`) are used, which take $O(1)$ space.
    *   Thus, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use standard namespace as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read N - the number of bricks

    // Create a vector to store the sizes of the bricks
    // A[i] corresponds to the size of brick (i+1)
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read brick sizes
    }

    // Initialize with the first brick
    // Chef first picks up brick numbered 1.
    // current_max_size stores the size of the brick Chef currently holds.
    // final_brick_number stores the 1-based index of the brick Chef currently holds.
    int current_max_size = A[0];
    int final_brick_number = 1; 

    // Iterate through the rest of the bricks, from brick 2 to N
    // In a 0-indexed array, this means from index 1 to N-1
    for (int i = 1; i < N; ++i) {
        // If the current brick (A[i]) has a strictly larger size
        // than the brick currently in Chef's hand (current_max_size)
        if (A[i] > current_max_size) {
            // Chef drops his current brick and picks this one up
            current_max_size = A[i];
            // Update the brick number (0-indexed i to 1-indexed brick number i+1)
            final_brick_number = i + 1; 
        }
        // If A[i] is not strictly larger (i.e., A[i] <= current_max_size),
        // Chef keeps his current brick. No action is needed in this case.
    }

    // Output the number of the brick which is finally with Chef
    cout << final_brick_number << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```