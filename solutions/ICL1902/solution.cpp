#include <bits/stdc++.h> // Required header for competitive programming

// Required namespace
using namespace std;

void solve() {
    int n;
    cin >> n; // Read the number of circles for the current test case
    
    int squares_count = 0; // Initialize count of squares formed
    
    // Continue forming squares as long as there are circles remaining
    while (n > 0) {
        // Find the largest integer S such that S*S <= n.
        // std::sqrt returns a double. Casting to int truncates the decimal part,
        // which is equivalent to floor() for positive numbers.
        int s = static_cast<int>(sqrt(static_cast<double>(n)));
        
        // Subtract the circles used to form this square (S*S circles)
        n -= s * s;
        
        // Increment the count of squares formed
        squares_count++;
    }
    
    // Output the total number of squares for this test case
    cout << squares_count << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    
    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}