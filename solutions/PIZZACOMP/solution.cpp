#include <bits/stdc++.h> // Required include for competitive programming

// Required using directive
using namespace std;

void solve() {
    int A, B;
    cin >> A >> B; // Read costs A and B

    // Small pizza: length 10 inches, area = 10*10 = 100
    // Large pizza: length 15 inches, area = 15*15 = 225

    // We want to maximize Area / Cost.
    // For small pizza: 100 / A
    // For large pizza: 225 / B

    // To compare these fractions (100/A vs 225/B) without using floating-point numbers,
    // we can cross-multiply:
    // Compare (100 * B) with (225 * A)

    // Further simplification: Both 100 and 225 are divisible by 25.
    // 100 / 25 = 4
    // 225 / 25 = 9
    // So, the comparison simplifies to:
    // Compare (4 * B) with (9 * A)

    // Use long long for the products to prevent potential overflow,
    // although for the given constraints (A, B <= 400), int would suffice.
    long long small_pizza_metric = 4LL * B;
    long long large_pizza_metric = 9LL * A;

    if (small_pizza_metric > large_pizza_metric) {
        cout << "Small\n"; // Small pizza offers more area per rupee
    } else if (large_pizza_metric > small_pizza_metric) {
        cout << "Large\n"; // Large pizza offers more area per rupee
    } else {
        cout << "Equal\n"; // Both offer the same area per rupee
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}