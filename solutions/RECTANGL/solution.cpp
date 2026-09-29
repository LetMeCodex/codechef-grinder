#include <bits/stdc++.h> // Includes common standard libraries like iostream, vector, algorithm

using namespace std; // Allows using standard library components without the std:: prefix

void solve() {
    int a, b, c, d;
    // Read the four side lengths for the current test case
    cin >> a >> b >> c >> d;

    // Store the four side lengths in a vector for easy sorting
    vector<int> sides = {a, b, c, d};

    // Sort the side lengths in non-decreasing order.
    // For a rectangle, there must be two pairs of equal sides.
    // If we sort the four side lengths (s1, s2, s3, s4),
    // they must satisfy s1 = s2 and s3 = s4.
    // This condition covers all cases, including squares (where s1=s2=s3=s4).
    sort(sides.begin(), sides.end());

    // Check if the sorted sides form a rectangle
    if (sides[0] == sides[1] && sides[2] == sides[3]) {
        cout << "YES\n"; // If the condition is met, it's a rectangle
    } else {
        cout << "NO\n";  // Otherwise, it's not
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false); // Disables synchronization with C's stdio library
    cin.tie(NULL); // Unties cin from cout, meaning cin will not flush cout before reading input

    int t;
    // Read the number of test cases
    cin >> t;
    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful execution
}