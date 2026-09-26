#include <bits/stdc++.h> // Includes iostream, string, etc.

using namespace std; // As requested

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        string s1, s2;
        cin >> s1 >> s2; // Read the two strings for the current test case

        int min_diff = 0; // Initialize minimal difference
        int max_diff = 0; // Initialize maximal difference
        int n = s1.length(); // Get the length of the strings (S1 and S2 have equal length)

        // Iterate through each character position in the strings
        for (int i = 0; i < n; ++i) {
            // Check if either character at the current position is a question mark
            if (s1[i] == '?' || s2[i] == '?') {
                // If at least one character is '?', we have flexibility:
                // For minimal difference: We can always replace '?' to make s1[i] and s2[i] equal.
                // For example, if s1[i] is 'a' and s2[i] is '?', replace s2[i] with 'a'.
                // If both are '?', replace both with 'a'. In these cases, the difference is 0.
                // So, min_diff does not increase.

                // For maximal difference: We can always replace '?' to make s1[i] and s2[i] different.
                // For example, if s1[i] is 'a' and s2[i] is '?', replace s2[i] with 'b'.
                // If both are '?', replace s1[i] with 'a' and s2[i] with 'b'. In these cases, the difference is 1.
                // So, max_diff increases by 1.
                max_diff++;
            } else {
                // Both characters are fixed lowercase Latin letters (not '?')
                // If the characters are different, this position contributes 1 to the difference.
                if (s1[i] != s2[i]) {
                    // Since they are fixed and different, they contribute 1 to both
                    // the minimal and maximal possible differences.
                    min_diff++;
                    max_diff++;
                }
                // If s1[i] == s2[i], they are fixed and equal. They contribute 0 to both
                // minimal and maximal differences. No change to min_diff or max_diff.
            }
        }
        // Output the calculated minimal and maximal differences, separated by a space,
        // followed by a newline for the next test case.
        cout << min_diff << " " << max_diff << "\n";
    }
    return 0; // Indicate successful execution
}