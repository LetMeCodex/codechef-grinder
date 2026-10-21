#include <bits/stdc++.h> // Includes iostream and many other useful headers
using namespace std;     // Allows direct use of cin, cout, etc.

// Function to calculate the minimum number of digits required for a given power P
int calculate_min_digits(int P) {
    // To minimize digits, each digit should be as large as possible (9).
    // The minimum number of digits is ceil(P / 9).
    // Using integer division, ceil(A / B) for positive A, B is (A + B - 1) / B.
    // Here, A = P, B = 9. So, (P + 9 - 1) / 9 = (P + 8) / 9.
    return (P + 8) / 9;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases

    while (T--) { // Loop through each test case
        int P_C, P_R; // Final powers for Chef and Rick
        cin >> P_C >> P_R; // Read Chef's and Rick's final powers

        // Calculate the minimum digits required for Chef and Rick
        int digits_C = calculate_min_digits(P_C);
        int digits_R = calculate_min_digits(P_R);

        // Determine the winner based on the number of digits
        if (digits_C < digits_R) {
            // Chef needs fewer digits, so Chef wins.
            // Output 0 (for Chef) and Chef's digit count.
            cout << 0 << " " << digits_C << "\n";
        } else if (digits_R < digits_C) {
            // Rick needs fewer digits, so Rick wins.
            // Output 1 (for Rick) and Rick's digit count.
            cout << 1 << " " << digits_R << "\n";
        } else {
            // Both need the same number of digits. Rick cheats and wins.
            // Output 1 (for Rick) and the common digit count.
            cout << 1 << " " << digits_R << "\n";
        }
    }

    return 0; // Indicate successful execution
}