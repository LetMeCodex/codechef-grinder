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