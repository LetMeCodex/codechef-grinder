#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

void solve() {
    int x; // Declare an integer variable x for the bill amount
    cin >> x; // Read the bill amount x for the current test case

    // Calculate the discount from the first coupon: 10 percent off on the bill amount.
    // Since X is guaranteed to be a multiple of 100, X/10 will always be an integer.
    int discount1 = x / 10;

    // The discount from the second coupon is a flat Rs. 100.
    int discount2 = 100;

    // To find the maximum discount Chef can avail, we compare the two discounts
    // and output the larger one.
    cout << max(discount1, discount2) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming, as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable t for the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function to handle the logic for each test case
    }

    return 0; // Indicate successful execution
}