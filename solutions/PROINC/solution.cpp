#include <bits/stdc++.h> // Includes common standard libraries like iostream

using namespace std; // Allows using cin, cout, etc. without std:: prefix

void solve() {
    int X, Y;
    // Read the initial selling price X and initial profit Y
    cin >> X >> Y;
    
    // Calculate the new profit.
    // The buying price remains constant: BP = X - Y.
    // The new selling price is X + 10% of X.
    // Since X is a multiple of 100, 10% of X is simply X / 10.
    // New selling price = X + (X / 10).
    // New profit = (New selling price) - (Buying price)
    // New profit = (X + X / 10) - (X - Y)
    // Simplifying the expression:
    // New profit = X + X / 10 - X + Y
    // New profit = X / 10 + Y
    
    int new_profit = (X / 10) + Y;
    
    // Output the calculated new profit, followed by a newline
    cout << new_profit << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful execution
}