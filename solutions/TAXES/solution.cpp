#include <bits/stdc++.h>

using namespace std;

void solve() {
    int X; // Declare X to store the total income
    cin >> X; // Read the total income X for the current test case

    // Check if the total income is strictly greater than 100.
    // If it is, a tax of 10 rupees is deducted.
    if (X > 100) {
        cout << X - 10 << "\n"; // Output the income after deducting 10 rupees tax
    } else {
        // If the total income is 100 or less, no tax is deducted.
        cout << X << "\n"; // Output the original income as no tax is applied
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare t to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}