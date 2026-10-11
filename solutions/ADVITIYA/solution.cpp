#include <bits/stdc++.h> // Includes most standard library headers

// Use the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    string s;
    cin >> s; // Read the input string S

    // The target string is fixed as "ADVITIYA"
    string target_str = "ADVITIYA";

    int total_steps = 0; // Initialize total steps for this test case

    // Iterate through each of the 8 characters of the string
    for (int i = 0; i < 8; ++i) {
        // Convert characters to 0-indexed integer values (A=0, B=1, ..., Z=25)
        int val_s = s[i] - 'A';
        int val_target = target_str[i] - 'A';

        // Calculate the minimum steps to transform s[i] to target_str[i]
        // The formula (val_target - val_s + 26) % 26 correctly handles cyclic increments.
        // For example:
        //   'A' (0) to 'B' (1): (1 - 0 + 26) % 26 = 1
        //   'Z' (25) to 'A' (0): (0 - 25 + 26) % 26 = 1
        //   'A' (0) to 'Z' (25): (25 - 0 + 26) % 26 = 25
        int steps_for_char = (val_target - val_s + 26) % 26;

        // Add the steps for the current character to the total
        total_steps += steps_for_char;
    }

    // Output the total minimum steps for the current test case
    cout << total_steps << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve();   // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}