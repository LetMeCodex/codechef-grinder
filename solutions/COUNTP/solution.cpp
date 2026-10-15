#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace for convenience, as is common in competitive programming
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the size of the array

    int count_odd = 0; // Initialize a counter for odd numbers
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read each element of the array
        if (A_i % 2 != 0) { // Check if the element is odd
            count_odd++;    // Increment the counter if it's odd
        }
    }

    // The product of two integers sum(S1) * sum(S2) is odd if and only if
    // both sum(S1) and sum(S2) are odd.

    // A sum of integers is odd if and only if it contains an odd number of odd integers.
    // So, for sum(S1) to be odd, S1 must contain an odd number of odd elements.
    // And for sum(S2) to be odd, S2 must contain an odd number of odd elements.

    // Let odd_S1 be the count of odd numbers in S1, and odd_S2 be the count of odd numbers in S2.
    // We need odd_S1 to be odd and odd_S2 to be odd.
    // The total count of odd numbers in A is count_odd = odd_S1 + odd_S2.
    // If odd_S1 is odd and odd_S2 is odd, then their sum (odd + odd) must be even.
    // Therefore, count_odd must be an even number.

    // Additionally, for odd_S1 and odd_S2 to both be odd, they must each be at least 1.
    // This implies count_odd = odd_S1 + odd_S2 >= 1 + 1 = 2.
    // So, count_odd must be an even number and must be at least 2.

    // Combining these conditions:
    // We need count_odd to be even AND count_odd to be greater than 0.
    // If count_odd is 0, all elements are even, sums will be even, product even. NO.
    // If count_odd is odd, impossible to split into two odd counts. NO.
    // If count_odd is even and > 0 (i.e., >= 2), then YES.
    // We can put one odd number in S1, and the remaining (count_odd - 1) odd numbers in S2.
    // Both S1 and S2 will be non-empty and have odd sums.
    // Even numbers can be distributed arbitrarily (e.g., all to S1).
    if (count_odd % 2 == 0 && count_odd > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}