#include <iostream> // Required for cin, cout
#include <string>   // Required for std::string
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the string
    std::string s;
    std::cin >> s; // Read the string

    // Use a vector to store frequency counts of characters.
    // Since S contains only lowercase English letters, we can use an array/vector of size 26.
    // 'a' will map to index 0, 'b' to index 1, ..., 'z' to index 25.
    std::vector<int> counts(26, 0);

    // Iterate through the string to populate character counts
    for (char c : s) {
        counts[c - 'a']++; // Increment count for the corresponding character
    }

    // Check if all character counts are even
    bool possible = true;
    for (int count : counts) {
        if (count % 2 != 0) { // If any character has an odd count
            possible = false; // It's not possible to erase the whole string
            break;            // No need to check further
        }
    }

    // Print the result
    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();   // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}