#include <bits/stdc++.h> 

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of players
    
    long long total_sum = 0; // Initialize total sum of A_i. Use long long to prevent overflow.
    // A_i values are between 0 and 10^4. Initialize min_A to a value greater than max possible A_i.
    int min_A = 10001; 
    
    // Iterate N times to read all A_i values
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the current A_i value
        total_sum += A_i; // Add it to the total sum
        
        // Update min_A if the current A_i is smaller
        if (A_i < min_A) {
            min_A = A_i;
        }
    }
    
    // The maximum prize is achieved when the winner is the player
    // whose elimination would add the minimum amount (min_A) to the prize pool.
    // This means we subtract min_A from the total sum of all A_i.
    cout << total_sum - min_A << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }
    
    return 0; // Indicate successful execution
}