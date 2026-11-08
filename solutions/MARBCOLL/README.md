# [Marble Collector (MARBCOLL)](https://www.codechef.com/problems/MARBCOLL)
- **Difficulty Rating**: 860
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine how many distinct types of marbles are *missing* from a given collection. We are provided with:
1.  `N`: The number of marbles we currently possess.
2.  `M`: The total number of possible distinct marble types, numbered from 1 to `M`.
3.  A list of `N` integers, where each integer `A_i` represents the type of a marble we own.

Our task is to count how many marble types (from 1 to `M`) are *not* present in our collection.

## Intuition & Mathematical Observation

The core idea is to keep track of which marble types we *already have*. Once we know this, we can simply iterate through all possible marble types (from 1 to `M`) and count those that we haven't marked as "collected".

Here's the step-by-step intuition:

1.  **Representing Collected Types**: We need an efficient way to mark whether a specific marble type has been collected. A boolean array (or `std::vector<bool>` in C++) is ideal for this. Let's call it `collected`.
    *   `collected[i]` will be `true` if we have at least one marble of type `i`.
    *   `collected[i]` will be `false` if we do not have any marble of type `i`.
    *   Since marble types are 1-indexed (from 1 to `M`), our `collected` array should be of size `M+1` to easily access `collected[1]` through `collected[M]`.

2.  **Initialization**: Initially, we haven't collected any marbles, so all entries in our `collected` array should be set to `false`.

3.  **Processing Our Marbles**: We read the `N` marbles we currently possess. For each marble of type `A_i` that we read:
    *   We mark `collected[A_i] = true`. This ensures that even if we have multiple marbles of the same type, that type is only marked once as "collected".

4.  **Counting Missing Types**: After processing all `N` marbles, our `collected` array accurately reflects which types we have. Now, we need to find the missing ones.
    *   We initialize a counter, say `missing_types_count`, to 0.
    *   We iterate from `i = 1` to `M` (covering all possible marble types).
    *   If `collected[i]` is `false`, it means we do not have any marble of type `i`. In this case, we increment `missing_types_count`.

5.  **Result**: The final value of `missing_types_count` is our answer.

This approach is essentially using a frequency array (or a set-like structure) to keep track of presence, then iterating through the universal set to find elements not in our collected set.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `M`: $O(1)$
    *   Initializing the `collected` vector of size `M+1`: This takes $O(M)$ time.
    *   Reading `N` marble types and marking them in the `collected` vector: This loop runs `N` times. Inside the loop, reading an integer and setting a boolean value are $O(1)$ operations. So, this part takes $O(N)$ time.
    *   Counting missing types by iterating from 1 to `M`: This loop runs `M` times. Inside the loop, checking a boolean value and incrementing a counter are $O(1)$ operations. So, this part takes $O(M)$ time.
    *   Total time complexity for one test case: $O(M) + O(N) + O(M) = O(N + M)$.
    *   Since there are `T` test cases, the overall time complexity is $O(T \cdot (N + M))$.

*   **Space Complexity**:
    *   The `collected` vector of size `M+1` is the primary data structure used. It stores `M+1` boolean values. This requires $O(M)$ space.
    *   Other variables (`N`, `M`, `type`, `missing_types_count`, `T`) use $O(1)$ space.
    *   Therefore, the total space complexity is $O(M)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, etc.

// Use the standard namespace as requested
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    
    // Use a boolean vector to keep track of collected marble types.
    // Size M+1 because types are 1-indexed, up to M.
    // Initialize all elements to false (meaning no type has been collected yet).
    vector<bool> collected(M + 1, false);
    
    // Read the N marbles we currently have.
    // For each marble, mark its type as collected in our boolean vector.
    for (int i = 0; i < N; ++i) {
        int type;
        cin >> type;
        // According to constraints, 1 <= A_i <= M, so 'type' will always be a valid index.
        collected[type] = true;
    }
    
    // Now, count the number of types that have not been collected.
    // Iterate through all possible marble types from 1 to M.
    int missing_types_count = 0;
    for (int i = 1; i <= M; ++i) {
        // If collected[i] is false, it means we don't have a marble of type 'i'.
        if (!collected[i]) {
            missing_types_count++;
        }
    }
    
    // Output the total count of missing marble types.
    cout << missing_types_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Variable to store the number of test cases.
    cin >> T; // Read the number of test cases.
    
    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }
    
    return 0; // Indicate successful execution.
}

```