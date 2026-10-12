#include <bits/stdc++.h> // Includes all standard libraries as requested

using namespace std; // Allows using standard library elements without std:: prefix

void solve() {
    int P, L;
    cin >> P >> L; // Read total population P and literate people L

    // The literacy rate is (L/P) * 100.
    // We need to check if (L/P) * 100 >= 75.
    // To avoid floating-point arithmetic and potential precision errors,
    // we transform the inequality into an integer-only comparison:
    // L * 100 >= 75 * P
    // Both 100 and 75 are divisible by 25. Dividing both sides by 25:
    // L * (100 / 25) >= P * (75 / 25)
    // L * 4 >= P * 3
    // This is equivalent to 4 * L >= 3 * P.

    // Constraints: 1 <= L <= P <= 100.
    // Maximum value for 4 * L is 4 * 100 = 400.
    // Maximum value for 3 * P is 3 * 100 = 300.
    // These values fit comfortably within an 'int' type, so no overflow issues.

    if (4 * L >= 3 * P) {
        cout << "YES\n"; // If the condition is met, print YES
    } else {
        cout << "NO\n";  // Otherwise, print NO
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}