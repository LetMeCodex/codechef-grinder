#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Use the standard namespace
using namespace std;

void solve() {
    int p;
    cin >> p; // Read the price p for the current test case
    
    int count = 0; // Initialize count of menus
    
    // Menu prices are 2^0 to 2^11.
    // For a greedy approach, it's best to iterate from largest to smallest price.
    // The prices are: 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1
    int prices[] = {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    
    // Iterate through the prices in descending order
    for (int price : prices) {
        // Add as many items of the current price as possible
        count += p / price;
        // Update p with the remaining amount
        p %= price;
        
        // If p becomes 0, we have found the exact sum, so we can stop early.
        // This is an optimization, not strictly necessary given the small constraints.
        if (p == 0) {
            break;
        }
    }
    
    cout << count << "\n"; // Print the minimum number of menus
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}