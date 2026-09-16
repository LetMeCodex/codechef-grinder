#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;     // Uses the standard namespace

// Function to solve a single test case
void solve() {
    int N;
    cin >> N;
    
    // Initialize max1 and max2. Since A_i >= 1, 0 is a safe initial value.
    // max1 will store the largest element found so far.
    // max2 will store the second largest distinct element found so far.
    int max1 = 0; 
    int max2 = 0;
    
    for (int i = 0; i < N; ++i) {
        int current_val;
        cin >> current_val;
        
        if (current_val > max1) {
            // If current_val is strictly greater than max1, it becomes the new max1.
            // The old max1 (which was the largest) becomes the new max2.
            max2 = max1;
            max1 = current_val;
        } else if (current_val > max2 && current_val < max1) {
            // If current_val is not greater than max1, but is strictly greater than max2,
            // and also strictly less than max1 (to ensure distinctness from max1),
            // then it becomes the new max2.
            max2 = current_val;
        }
        // If current_val is equal to max1, or less than or equal to max2,
        // it does not affect max1 or max2.
    }
    
    cout << max1 + max2 << "\n";
}

int main() {
    // Fast I/O setup to speed up cin/cout operations.
    // This is crucial for competitive programming problems with large inputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }
    
    return 0;
}