#include <bits/stdc++.h> // Required header

// Required namespace
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the string
    string S;
    cin >> S; // Read the string S

    int count_a = 0; // Initialize count for 'a'
    int count_b = 0; // Initialize count for 'b'

    // Iterate through each character in the string S
    for (char c : S) {
        if (c == 'a') {
            count_a++; // Increment count_a if the character is 'a'
        } else {
            // Since the problem states S consists only of 'a' and 'b',
            // if it's not 'a', it must be 'b'.
            count_b++; // Increment count_b if the character is 'b'
        }
    }

    // Print the counts of 'a' and 'b' separated by a space, followed by a newline
    cout << count_a << " " << count_b << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}