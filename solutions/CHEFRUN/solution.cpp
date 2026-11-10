#include <bits/stdc++.h> // Include all standard libraries

// Using namespace std; is common in competitive programming
using namespace std;

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        // Declare variables using long long to safely handle intermediate products
        // (X_i values and V_i values fit in int, but their products might exceed int limits)
        long long X1, X2, X3, V1, V2; 
        cin >> X1 >> X2 >> X3 >> V1 >> V2;

        // Calculate distances for Chef and Kefa
        // The problem guarantees X1 < X3 < X2, so distances are always positive.
        long long dist_chef = X3 - X1;
        long long dist_kefa = X2 - X3;

        // To compare times (distance / speed) without using floating-point numbers,
        // we cross-multiply:
        // Compare (dist_chef / V1) with (dist_kefa / V2)
        // is equivalent to comparing (dist_chef * V2) with (dist_kefa * V1)
        // These products can be up to (2 * 10^5) * (10^5) = 2 * 10^10,
        // which requires 'long long' to prevent overflow.
        long long time_chef_scaled_numerator = dist_chef * V2;
        long long time_kefa_scaled_numerator = dist_kefa * V1;

        // Compare the scaled numerators to determine who reaches first
        if (time_chef_scaled_numerator < time_kefa_scaled_numerator) {
            cout << "Chef\n"; // Chef's time is less
        } else if (time_kefa_scaled_numerator < time_chef_scaled_numerator) {
            cout << "Kefa\n"; // Kefa's time is less
        } else {
            cout << "Draw\n"; // Times are equal
        }
    }
    return 0; // Indicate successful execution
}