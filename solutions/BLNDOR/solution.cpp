#include <bits/stdc++.h> // Includes common C++ headers like iostream for input/output.

// Using the standard namespace to avoid repeatedly writing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of elements in the array

    int count_twos = 0; // Initialize a counter for the number of '2's

    // Loop through each element of the array
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the current element

        // If the element is 2, increment our counter
        if (A_i == 2) {
            count_twos++;
        }
    }

    // The product of all elements is 2 raised to the power of count_twos.
    // We need to check if this product (2^count_twos) can be written as k^8.
    // This implies that count_twos must be a multiple of 8.
    if (count_twos % 8 == 0) {
        cout << "YES\n"; // If count_twos is a multiple of 8, print YES
    } else {
        cout << "NO\n";  // Otherwise, print NO
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}