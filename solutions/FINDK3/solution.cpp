#include <bits/stdc++.h> // Includes common headers like iostream, etc.

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    long long X, Y, Z; // Using long long for X, Y, Z and products to be safe,
                       // though int would suffice given constraints (max product 10^8).
    cin >> X >> Y >> Z;

    // Possibility 1: B = X, A = Y * Z
    if ((Y * Z) % X == 0) {
        cout << (Y * Z) << " " << X << "\n";
        return; // Found a solution, print and return
    }

    // Possibility 2: B = Y, A = X * Z
    if ((X * Z) % Y == 0) {
        cout << (X * Z) << " " << Y << "\n";
        return; // Found a solution, print and return
    }

    // Possibility 3: B = Z, A = X * Y
    if ((X * Y) % Z == 0) {
        cout << (X * Y) << " " << Z << "\n";
        return; // Found a solution, print and return
    }

    // If no solution is found after checking all possibilities
    cout << -1 << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}