#include <bits/stdc++.h> // Includes most standard libraries, as per problem instructions.
using namespace std; // As per problem instructions.

// Function to solve a single test case
void solve() {
    // Declare a vector to store the prices of the 26 letters ('a' through 'z').
    // prices[0] will store the price of 'a', prices[1] for 'b', and so on.
    vector<int> prices(26);
    for (int i = 0; i < 26; ++i) {
        cin >> prices[i]; // Read each price
    }

    // Declare a string to store Mathison's initial text.
    string s;
    cin >> s; // Read the text

    // Declare a boolean vector to keep track of which letters are already present in the text.
    // isPresent[0] will be true if 'a' is in the text, false otherwise.
    // Similarly for other letters up to 'z'.
    vector<bool> isPresent(26, false); // Initialize all to false (no letters present yet)

    // Iterate through each character in the input string 's'.
    for (char c : s) {
        // For each character 'c', calculate its corresponding index (0 for 'a', 1 for 'b', etc.).
        // Mark that letter as present.
        isPresent[c - 'a'] = true;
    }

    // Initialize total cost to 0.
    // Use long long to prevent potential integer overflow.
    // Max cost: 26 letters * 1,000,000 (max price) = 26,000,000.
    // This fits in a 32-bit signed int, but long long is safer and good practice.
    long long totalCost = 0;

    // Iterate through all 26 possible letters (from 'a' to 'z').
    for (int i = 0; i < 26; ++i) {
        // If the letter corresponding to index 'i' is NOT present in the initial text,
        // then Mathison needs to buy it. Add its price to the total cost.
        if (!isPresent[i]) {
            totalCost += prices[i];
        }
    }

    // Print the calculated total cost for the current test case, followed by a newline.
    cout << totalCost << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false); // Untie C++ streams from C standard streams.
    cin.tie(NULL); // Untie cin from cout.

    int t;
    cin >> t; // Read the number of test cases.
    while (t--) { // Loop 't' times, solving each test case.
        solve();
    }

    return 0; // Indicate successful execution.
}