#include <bits/stdc++.h> // Includes most standard libraries for competitive programming

// Using namespace std; is common in competitive programming to avoid
// repeatedly typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the encoded string
    string S;
    cin >> S; // Read the encoded string

    string decoded_message = ""; // Initialize an empty string to store the decoded message

    // Iterate through the encoded string in chunks of 4 bits
    // Each 4-bit chunk represents one character
    for (int i = 0; i < N; i += 4) {
        int decimal_value = 0; // This will store the decimal equivalent of the 4-bit chunk

        // Process each of the 4 bits in the current chunk
        for (int j = 0; j < 4; ++j) {
            // Get the character at the current bit position (S[i+j])
            // Convert '0' to integer 0, and '1' to integer 1
            int bit_val = S[i + j] - '0';

            // Build the decimal value from the bits.
            // This is equivalent to shifting the current decimal_value left by 1 bit
            // (multiplying by 2) and then adding the new bit.
            // For example, if decimal_value is 0 and bit_val is 1, it becomes 1.
            // If decimal_value is 1 (binary 0001) and bit_val is 0, it becomes 2 (binary 0010).
            // If decimal_value is 2 (binary 0010) and bit_val is 0, it becomes 4 (binary 0100).
            // If decimal_value is 4 (binary 0100) and bit_val is 1, it becomes 9 (binary 1001).
            decimal_value = (decimal_value << 1) | bit_val;
        }

        // The problem states that the first 16 lowercase English letters ('a' through 'p')
        // are encoded. 'a' corresponds to decimal 0, 'b' to 1, ..., 'p' to 15.
        // So, we can simply add the calculated decimal_value to the ASCII value of 'a'
        // to get the decoded character.
        char decoded_char = 'a' + decimal_value;
        
        // Append the decoded character to our result string
        decoded_message += decoded_char;
    }

    // Print the complete decoded message followed by a newline
    cout << decoded_message << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}