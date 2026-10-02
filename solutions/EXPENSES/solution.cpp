#include <bits/stdc++.h> 
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, X;
        cin >> N >> X; // Read N (number of expenses) and X (exponent for income 2^X)

        // Calculate the amount saved using the derived formula: 2^(X-N)
        // The expression (X - N) gives the exponent.
        // 1LL << (X - N) performs a left bit shift.
        // For example, 1LL << 3 results in 1 * 2^3 = 8.
        // 1LL ensures that the operation is performed using a long long integer type,
        // which prevents potential overflow if the result were larger, though for X-N <= 19,
        // a standard 'int' would suffice. It's good practice for powers of 2.
        long long savings = 1LL << (X - N); 
        
        cout << savings << "\n"; // Output the calculated savings followed by a newline
    }

    return 0; // Indicate successful program execution
}