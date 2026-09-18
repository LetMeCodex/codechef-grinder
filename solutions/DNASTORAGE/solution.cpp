#include <bits/stdc++.h> // Includes iostream, string, etc., as required by problem statement

// Use the standard namespace, as required by problem statement
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the binary string
    string S;
    cin >> S; // Read the binary string

    string encoded_S = "";
    // Pre-allocate memory for the encoded string to improve performance
    // The encoded string will have N/2 characters.
    encoded_S.reserve(N / 2);

    // Lookup table for the encoding rules:
    // Index 0 corresponds to "00" -> 'A'
    // Index 1 corresponds to "01" -> 'T'
    // Index 2 corresponds to "10" -> 'C'
    // Index 3 corresponds to "11" -> 'G'
    char lookup_table[] = {'A', 'T', 'C', 'G'};

    // Iterate through the binary string, taking two characters at a time
    for (int i = 0; i < N; i += 2) {
        // Convert the character '0' or '1' to its integer equivalent (0 or 1)
        int val1 = S[i] - '0';
        int val2 = S[i+1] - '0';
        
        // Calculate the index for the lookup table based on the two binary digits:
        // '00' -> (0 * 2) + 0 = 0
        // '01' -> (0 * 2) + 1 = 1
        // '10' -> (1 * 2) + 0 = 2
        // '11' -> (1 * 2) + 1 = 3
        int index = val1 * 2 + val2;
        
        // Append the corresponding encoded character from the lookup table
        encoded_S += lookup_table[index];
    }
    
    // Output the final encoded sequence followed by a newline
    cout << encoded_S << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output, as required
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}