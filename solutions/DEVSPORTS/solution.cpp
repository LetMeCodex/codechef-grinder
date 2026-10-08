#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace

// Function to solve a single test case
void solve() {
    // Declare five integer variables to store the input values
    int Z, Y, A, B, C;
    
    // Read the initial money (Z), money already spent (Y),
    // and prices of the three water sports (A, B, C)
    cin >> Z >> Y >> A >> B >> C;

    // Calculate the money Devendra has remaining after his initial spending
    int remaining_money = Z - Y;

    // Calculate the total cost required to try each of the three water sports once
    int total_sport_cost = A + B + C;

    // Check if Devendra's remaining money is sufficient to cover the total cost
    if (remaining_money >= total_sport_cost) {
        // If he has enough money, print "YES"
        cout << "YES\n";
    } else {
        // Otherwise, print "NO"
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable to store the number of test cases
    int t;
    
    // Read the number of test cases
    cin >> t;

    // Loop through each test case
    while (t--) {
        // Call the solve function for the current test case
        solve();
    }

    // Indicate successful program execution
    return 0;
}