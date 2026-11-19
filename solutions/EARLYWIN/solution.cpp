#include <bits/stdc++.h> // Includes all standard libraries like iostream, string, algorithm

// Use the standard namespace for convenience as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N, M;
    cin >> N >> M; // Read the lengths of the two strings
    string A, B;
    cin >> A >> B; // Read the two strings

    string result = ""; // Initialize an empty string to store the longest common prefix
    
    // The longest possible common prefix cannot be longer than the shorter of the two strings.
    // We iterate up to this limit.
    int limit = min(N, M); 

    // Loop through characters from the beginning of both strings
    for (int i = 0; i < limit; ++i) {
        // Compare characters at the current index 'i'
        if (A[i] == B[i]) {
            // If characters match, append this character to our result string
            result += A[i];
        } else {
            // If characters do not match, the common prefix ends here.
            // We break out of the loop as no further characters will be common.
            break;
        }
    }
    
    // Output the determined longest common prefix, followed by a newline
    cout << result << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard I/O.
    // `cin.tie(NULL)` prevents `cout` from being flushed before `cin` reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop 'T' times, once for each test case
        solve(); // Call the solve function to process the current test case
    }

    return 0; // Indicate successful program execution
}