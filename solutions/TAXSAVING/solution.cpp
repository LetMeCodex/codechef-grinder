#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int X, Y;
        cin >> X >> Y; // Read the amount earned (X) and the tax threshold (Y)

        // Problem Analysis:
        // You earn X rupees.
        // You have to pay tax if you earn *strictly more* than Y rupees.
        // Currently, X > Y, so you are paying taxes.
        // You want to invest a minimum amount of money, let's call it 'I',
        // such that your effective income after investment (X - I)
        // is no longer strictly more than Y.
        // This means we need to satisfy the condition: X - I <= Y.

        // To find the minimum 'I' that satisfies this inequality, we can rearrange it:
        // X - Y <= I

        // The smallest integer value for 'I' that satisfies X - Y <= I is exactly X - Y.
        // If you invest I = X - Y, your effective income becomes X - (X - Y) = Y.
        // Since Y is not strictly greater than Y, you will not have to pay taxes.
        // Any investment less than X - Y would result in an effective income
        // that is still strictly greater than Y, meaning you would still pay taxes.
        // Therefore, X - Y is the minimum required investment.

        int investment_needed = X - Y;

        // Output the calculated minimum investment for the current test case,
        // followed by a newline character.
        cout << investment_needed << "\n";
    }

    return 0; // Indicate successful execution
}