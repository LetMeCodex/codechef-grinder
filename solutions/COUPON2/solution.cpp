#include <bits/stdc++.h> // Includes all standard libraries, as per problem instructions

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int D, C; // Delivery charge and coupon price
    cin >> D >> C;

    int A1, A2, A3; // Item prices for Day 1
    cin >> A1 >> A2 >> A3;
    int S1 = A1 + A2 + A3; // Sum of item prices for Day 1

    int B1, B2, B3; // Item prices for Day 2
    cin >> B1 >> B2 >> B3;
    int S2 = B1 + B2 + B3; // Sum of item prices for Day 2

    // Calculate total cost without buying the coupon
    // Chef pays for items on Day 1, delivery for Day 1, items on Day 2, delivery for Day 2
    int cost_without_coupon = S1 + S2 + (2 * D);

    // Calculate total cost if Chef buys the coupon
    // Start with item costs and the coupon price
    int cost_with_coupon = S1 + S2 + C;

    // Check delivery charge for Day 1 with coupon
    // If sum of items is less than 150, delivery charge applies
    if (S1 < 150) {
        cost_with_coupon += D;
    }

    // Check delivery charge for Day 2 with coupon
    // If sum of items is less than 150, delivery charge applies
    if (S2 < 150) {
        cost_with_coupon += D;
    }

    // Compare the two costs and print the result
    // Chef buys the coupon only if it costs strictly less
    if (cost_with_coupon < cost_without_coupon) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}