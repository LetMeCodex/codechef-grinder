# [Color Festival (BOP2)](https://www.codechef.com/problems/BOP2)
- **Difficulty Rating**: 588
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to process `T` test cases. In each test case, we are given an integer `N`, followed by `N` integers representing colors, `C_1, C_2, ..., C_N`. Each color `C_i` is guaranteed to be an integer between 1 and `N` (inclusive). Our task is to determine and print the total number of *distinct* colors present in the given sequence for each test case.

## Intuition & Mathematical Observation

The core of this problem is to count unique elements in a sequence. Since the colors `C_i` are constrained to be between 1 and `N`, we can leverage this property for an efficient solution.

A common approach to count distinct elements is to use a hash set (like `std::set` in C++). We would iterate through the colors, inserting each one into the set. At the end, the size of the set would give us the count of distinct colors. This approach has a time complexity of $O(N \log N)$ on average for `std::set` (due to tree-based implementation) or $O(N)$ on average for `std::unordered_set` (hash table).

However, given the constraint that `1 <= C_i <= N`, we can use a more specialized and often faster technique: a boolean array (or a frequency array). We can declare a boolean array (or `std::vector<bool>`) of size `N+1`, let's call it `seen_colors`. Initialize all its elements to `false`. When we encounter a color `C_i`:
1.  We check `seen_colors[C_i]`.
2.  If `seen_colors[C_i]` is `false`, it means we haven't seen this color before. We then mark `seen_colors[C_i] = true` and increment our `distinct_count`.
3.  If `seen_colors[C_i]` is already `true`, it means we have seen this color before, so we do nothing and move to the next color.

After iterating through all `N` colors, `distinct_count` will hold the total number of unique colors. This approach is highly efficient because array lookups and updates are $O(1)$ operations.

## Complexity Analysis

*   **Time Complexity**:
    *   For each test case:
        *   Reading `N`: $O(1)$
        *   Initializing the `seen_colors` vector of size `N+1`: $O(N)$
        *   Looping `N` times to read colors:
            *   Reading `C_i`: $O(1)$
            *   Checking and updating `seen_colors[C_i]`: $O(1)$
        *   Printing the result: $O(1)$
    *   Therefore, for a single test case, the time complexity is dominated by the initialization and the loop, resulting in $O(N)$.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N_{max})$, where $N_{max}$ is the maximum possible value of `N` across all test cases.

*   **Space Complexity**:
    *   For each test case, we use a `std::vector<bool>` named `seen_colors` of size `N+1` to keep track of seen colors.
    *   This requires $O(N)$ space.
    *   The space is reused for each test case, so the maximum space used at any point is $O(N_{max})$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, set, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Using a boolean vector to mark seen colors.
    // C_i are 1-indexed, so the vector needs to be of size N + 1.
    // Initialize all elements to false.
    vector<bool> seen_colors(N + 1, false); 
    int distinct_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int C_i;
        cin >> C_i;
        // If this color hasn't been seen before
        if (!seen_colors[C_i]) {
            seen_colors[C_i] = true; // Mark it as seen
            distinct_count++;       // Increment the count of distinct colors
        }
    }
    
    cout << distinct_count << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```