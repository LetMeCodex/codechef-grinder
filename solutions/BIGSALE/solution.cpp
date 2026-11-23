#include <bits/stdc++.h> // Includes all standard libraries, as requested
using namespace std; // Uses the standard namespace, as requested

void solve() {
    int N;
    cin >> N; // Read the number of recipe types

    double total_loss = 0.0; // Initialize total loss to 0.0

    // Loop through each recipe type
    for (int i = 0; i < N; ++i) {
        int price, quantity, discount;
        cin >> price >> quantity >> discount; // Read price, quantity, and discount for current recipe type

        // Calculate loss per unit using the derived formula:
        // loss_per_unit = original_price * (discount / 100.0)^2
        // This is equivalent to original_price * (discount * discount / 10000.0)
        double loss_per_unit = (double)price * ((double)discount * (double)discount / 10000.0);
        
        // Add the total loss for this recipe type (loss_per_unit * quantity) to the overall total_loss
        total_loss += loss_per_unit * quantity;
    }

    // Print the total loss.
    // std::fixed ensures that the number is printed in fixed-point notation.
    // std::setprecision(9) sets the number of digits after the decimal point to 9,
    // which is sufficient for the required precision (10^-2).
    cout << fixed << setprecision(9) << total_loss << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}