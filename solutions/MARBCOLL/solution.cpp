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