#include <bits/stdc++.h> // Includes iostream and many other useful headers
using namespace std;     // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) {
        int P;
        cin >> P; // Read the points obtained by Chef

        // The number of times Chef serves from the right side is determined
        // by the number of even scores Chef has when he is about to serve.
        // Chef serves when his score is 0, 1, 2, ..., up to P.
        // He serves from the right side if his score at that moment is even.
        // So, we count the even numbers in the range [0, P].
        //
        // For any integer P, the count of even numbers in [0, P] is P/2 + 1
        // using integer division.
        // Example:
        // P=0: Even numbers are {0}. Count = 1. (0/2 + 1 = 1)
        // P=1: Even numbers are {0}. Count = 1. (1/2 + 1 = 1)
        // P=2: Even numbers are {0, 2}. Count = 2. (2/2 + 1 = 2)
        // P=3: Even numbers are {0, 2}. Count = 2. (3/2 + 1 = 2)
        // P=4: Even numbers are {0, 2, 4}. Count = 3. (4/2 + 1 = 3)
        int right_serves = P / 2 + 1;

        cout << right_serves << "\n"; // Output the result followed by a newline
    }

    return 0; // Indicate successful execution
}