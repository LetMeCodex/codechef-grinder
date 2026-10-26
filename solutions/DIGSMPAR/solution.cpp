#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to calculate the sum of digits of a number
// It takes a long long to handle numbers up to 10^9 and beyond safely.
long long getDigitSum(long long num) {
    long long sum = 0;
    // Loop until the number becomes 0
    while (num > 0) {
        // Add the last digit (num % 10) to the sum
        sum += num % 10;
        // Remove the last digit by integer division (num / 10)
        num /= 10;
    }
    return sum;
}

// Function to solve a single test case
void solve() {
    long long n;
    cin >> n; // Read the input integer N

    // Calculate the digit sum of N and its parity
    long long digitSumN = getDigitSum(n);
    int parityN = digitSumN % 2; // 0 for even, 1 for odd

    // Start checking integers strictly greater than N, beginning with N+1
    long long x = n + 1;
    while (true) { // This loop will run at most twice
        // Calculate the digit sum of X and its parity
        long long digitSumX = getDigitSum(x);
        int parityX = digitSumX % 2;

        // Check if the parities are different
        if (parityX != parityN) {
            // If they are different, X is the smallest such integer
            cout << x << "\n"; // Print X followed by a newline
            return; // Exit the function for this test case
        }
        // If parities are the same, increment X and check the next number
        x++;
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}