#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the length of the DNA strand
    string S;
    cin >> S; // Read the sequence of nucleotides of one strand of DNA

    string complementary_S = ""; // Initialize an empty string to store the complementary strand
    // Optional optimization: reserve memory for the string to avoid reallocations.
    // For N <= 100, this is a minor optimization but good practice.
    complementary_S.reserve(N); 

    // Iterate through each nucleotide in the input string S
    for (char nucleotide : S) {
        // Determine the complementary nucleotide based on the given rules
        if (nucleotide == 'A') {
            complementary_S += 'T'; // A is complementary to T
        } else if (nucleotide == 'T') {
            complementary_S += 'A'; // T is complementary to A
        } else if (nucleotide == 'C') {
            complementary_S += 'G'; // C is complementary to G
        } else if (nucleotide == 'G') {
            complementary_S += 'C'; // G is complementary to C
        }
        // The problem constraints guarantee that S contains only 'A', 'T', 'C', and 'G',
        // so no 'else' case for invalid characters is necessary.
    }

    // Output the resulting complementary strand followed by a newline character
    cout << complementary_S << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, once for each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}