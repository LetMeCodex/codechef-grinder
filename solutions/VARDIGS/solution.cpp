#include <bits/stdc++.h> // Includes iostream for cin/cout

// Using namespace std; is requested by the problem.
using namespace std;

int main() {
    // Fast I/O is requested by the problem.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement specifies: "The only line of input will contain a single 2-digit integer, X."
    // This indicates that there is only one test case per execution, so no explicit loop for 't' test cases is needed.

    int X;
    cin >> X; // Read the 2-digit integer X

    // To determine if the digits are different, we need to extract them.
    // For a 2-digit number X:
    // The units digit can be obtained using the modulo operator: X % 10
    // The tens digit can be obtained using integer division: X / 10

    int units_digit = X % 10;
    int tens_digit = X / 10;

    // Compare the two extracted digits.
    // If they are different, the number is "varied".
    // Otherwise, it is not "varied".
    if (units_digit != tens_digit) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}