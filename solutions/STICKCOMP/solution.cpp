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