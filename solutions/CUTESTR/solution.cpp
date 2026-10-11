#include <bits/stdc++.h> // Includes common headers like iostream, string, etc.

// It's common in competitive programming to use the entire std namespace.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is generally good practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare a string variable to store the input.
    // The problem guarantees the string will be of length 3.
    string s;

    // Read the 3-character string from standard input.
    cin >> s;

    // Check the two conditions for a string to be "cute":
    // 1. The first character (s[0]) must be equal to the third character (s[2]).
    // 2. The second character (s[1]) must be 'w'.
    if (s[0] == s[2] && s[1] == 'w') {
        // If both conditions are true, the string is cute.
        cout << "Cute\n";
    } else {
        // Otherwise, the string is not cute.
        cout << "No\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}