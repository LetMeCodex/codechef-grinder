#include <bits/stdc++.h> // Includes iostream, iomanip, etc.

// Using namespace std; as requested by the problem instructions.
using namespace std;

int main() {
    // Include fast I/O inside main() as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the total number of test cases.

    // Loop through each test case.
    while (T--) {
        long long quantity; // Use long long for quantity to handle values up to 100000.
        long long price;    // Use long long for price to handle values up to 100000.
        cin >> quantity >> price; // Read quantity and price for the current test case.

        // Calculate the total cost before any discount.
        // The product (quantity * price) can be up to 100000 * 100000 = 10^10.
        // This value exceeds the maximum capacity of a 32-bit integer (approx 2*10^9),
        // so `long long` is necessary to prevent integer overflow.
        long long total_cost_before_discount_ll = quantity * price;
        
        double final_expenses; // Variable to store the final calculated expenses, which can be a decimal.

        // Check if the quantity purchased is more than 1000 to apply the discount.
        if (quantity > 1000) {
            // If quantity is more than 1000, a 10% discount is offered.
            // This means the customer pays 90% of the original price.
            // We cast `total_cost_before_discount_ll` to `double` before multiplying by 0.90
            // to ensure floating-point arithmetic for the discount calculation.
            final_expenses = static_cast<double>(total_cost_before_discount_ll) * 0.90;
        } else {
            // If quantity is 1000 or less, no discount is applied.
            // The final expenses are simply the total cost before discount.
            final_expenses = static_cast<double>(total_cost_before_discount_ll);
        }

        // Output the total expenses.
        // `fixed` ensures that the output is in fixed-point notation (not scientific).
        // `setprecision(6)` sets the number of digits to be displayed after the decimal point to 6,
        // as required by the sample output format.
        cout << fixed << setprecision(6) << final_expenses << "\n";
    }

    return 0; // Indicate successful execution.
}