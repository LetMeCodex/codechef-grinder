#include <bits/stdc++.h> // Include all standard libraries as requested

using namespace std; // Use the standard namespace as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer variable N to store the date.
    cin >> N; // Read the date N from standard input.

    // The Advitiya fest runs on the 16th, 17th, and 18th of February.
    // We need to check if the date N falls within this range.
    // The constraints state 1 <= N <= 18, so N will always be a valid date within February up to the 18th.
    if (N >= 16 && N <= 18) {
        // If N is 16, 17, or 18, Mehul will be able to enjoy the fest.
        cout << "ADVITIYA\n"; // Print "ADVITIYA" followed by a newline.
    } else {
        // If N is any other date (1 through 15), Mehul will have to wait.
        cout << "WAITING FOR ADVITIYA\n"; // Print "WAITING FOR ADVITIYA" followed by a newline.
    }

    return 0; // Indicate successful program execution.
}