#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Use the standard namespace as requested by the problem statement.
using namespace std;

// Function to calculate and print factorial of n
void factorial(int n) {
    // A vector to store the digits of the factorial.
    // res[0] will store the least significant digit, res[1] the next, and so on.
    vector<int> res;
    res.push_back(1); // Initialize result with 1 (representing 1!)

    // Multiply res by numbers from 2 to n
    // This loop calculates (x-1)! * x to get x!
    for (int x = 2; x <= n; x++) {
        int carry = 0; // Initialize carry for the current multiplication

        // Iterate through the digits of the current result (which holds (x-1)!)
        // and multiply each digit by x, adding the carry from the previous digit.
        for (size_t i = 0; i < res.size(); i++) {
            // Calculate product of digit and x, plus carry.
            // The maximum value for res[i] is 9, for x is 100, and for carry is 9.
            // So, prod can be at most 9 * 100 + 9 = 909, which fits comfortably in an int.
            // Using long long for prod is a minor safety measure, though not strictly necessary here.
            long long prod = (long long)res[i] * x + carry; 
            
            res[i] = prod % 10; // Store the last digit of prod in the current position
            carry = prod / 10;  // Update carry for the next digit
        }

        // After multiplying all existing digits, if there's still a carry,
        // append its digits to the end of the result vector.
        while (carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Print the result. Since digits are stored from least significant to most significant,
    // we need to print them in reverse order to get the correct number.
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << "\n"; // Newline after each factorial
}

int main() {
    // Fast I/O setup to speed up input and output operations.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) { // Loop through each test case
        int n; // Input integer for which factorial is to be calculated
        cin >> n;
        factorial(n); // Call the factorial function
    }

    return 0;
}