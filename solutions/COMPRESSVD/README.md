# Compress the Video (COMPRESSVD)
- **Difficulty Rating**: 940
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of frames required to represent a video, given an initial sequence of $N$ frames. The compression rule states that if a frame $A_i$ has the same value as its immediate predecessor ($A_{i-1}$) or its immediate successor ($A_{i+1}$), then $A_i$ can be removed. This process can be repeated until no more frames can be removed. We need to find the minimum number of frames remaining after applying this compression.

## Intuition & Mathematical Observation

The core idea behind the compression is that consecutive frames with the same value can be reduced to a single frame. Consider a sequence of identical frames: $[X, X, X, X]$.

- If we have $[X, X]$, we can remove the first $X$ because it's equal to its successor, leaving $[X]$. Or, we can remove the second $X$ because it's equal to its predecessor, leaving $[X]$. In either case, we end up with one frame.

- If we have $[X, X, X]$, we can apply the rule iteratively. For example, in $[X_1, X_2, X_3]$ where $X_1=X_2=X_3=X$:
    - $X_1$ can be removed because $X_1 = X_2$. We are left with $[X_2, X_3]$.
    - Now, $X_2$ can be removed because $X_2 = X_3$. We are left with $[X_3]$, which is just $[X]$.
    - Alternatively, we could have removed $X_2$ first because $X_2 = X_1$. We are left with $[X_1, X_3]$. Then $X_3$ can be removed because $X_3 = X_1$. We are left with $[X_1]$, which is $[X]$.

This observation leads to a crucial insight: **any contiguous block of identical frames can be reduced to a single frame.**

The problem then simplifies to counting the number of distinct "runs" of consecutive identical frame values. For example, if the frames are $[1, 1, 2, 3, 3, 3, 1]$, the runs are:
- $[1, 1]$ (a run of value 1)
- $[2]$ (a run of value 2)
- $[3, 3, 3]$ (a run of value 3)
- $[1]$ (a run of value 1)

Each of these runs can be compressed to a single frame. So, $[1, 1, 2, 3, 3, 3, 1]$ can be compressed to $[1, 2, 3, 1]$. The minimum number of frames is the count of these distinct runs.

Therefore, the algorithm is to iterate through the frames and count how many times the current frame's value is different from the previous frame's value. The first frame always starts a new run, so we initialize our count to 1.

**Edge Case:** If there is only one frame ($N=1$), no compression is possible, and the minimum number of frames is 1.

## Complexity Analysis

- **Time Complexity**: $O(N)$
    The solution iterates through the $N$ frames exactly once to count the distinct runs. Reading the input for each test case takes $O(N)$ time. Since there are $T$ test cases, the total time complexity is $O(T \cdot N)$. However, for a single test case, it's $O(N)$.

- **Space Complexity**: $O(1)$
    The solution only uses a few variables to store the current frame value, the previous frame value, and the count. This is constant extra space, independent of the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; is common in competitive programming for brevity.
using namespace std; 

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of frames
    
    // Handle the base case where N=1.
    // If there's only one frame, it has no neighbors, so it cannot be removed.
    // The minimum number of frames is 1.
    if (N == 1) {
        int val;
        cin >> val; // Read the single frame value (not used for calculation, just to consume input)
        cout << 1 << "\n";
        return;
    }
    
    // For N > 1, we can apply the compression logic.
    // The goal is to count the number of "runs" of distinct values.
    // For example, [1, 1, 2, 3, 3, 3, 1] becomes [1, 2, 3, 1], which has 4 frames.
    // This is because any sequence of identical frames (e.g., [X, X, X]) can be reduced to a single frame [X].
    // The operation allows removing A_i if A_i == A_{i-1} or A_i == A_{i+1}.
    // This means if we have A_i == A_{i+1}, we can remove A_i (keeping A_{i+1}) or remove A_{i+1} (keeping A_i).
    // In essence, one of the duplicate adjacent frames can always be removed, reducing the length of the identical block by one.
    // This can be repeated until only one frame from the block remains.
    
    int count = 1; // Initialize count with 1 for the first frame, which always starts a "run".
    int prev_val;
    cin >> prev_val; // Read the value of the first frame
    
    // Iterate from the second frame to the last frame
    for (int i = 1; i < N; ++i) {
        int current_val;
        cin >> current_val; // Read the current frame's value
        
        // If the current frame's value is different from the previous frame's value,
        // it means we've encountered a new "run" of values.
        // So, this frame (or rather, this new distinct value) must be kept.
        if (current_val != prev_val) {
            count++; // Increment the count of frames that must be kept
        }
        
        // Update prev_val for the next iteration
        prev_val = current_val;
    }
    
    cout << count << "\n"; // Output the minimum number of frames
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false); // Untie C++ streams from C standard streams
    cin.tie(NULL); // Untie cin from cout
    
    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }
    
    return 0; // Indicate successful execution
}
```