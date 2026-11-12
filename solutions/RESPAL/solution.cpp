#include <iostream>
#include <string>
#include <vector> // Not strictly necessary for this problem, but common in competitive programming

void solve() {
    int n;
    std::cin >> n; // Read the length N

    std::string s = ""; // Initialize an empty string
    for (int i = 0; i < n; ++i) {
        // Append characters 'a', 'b', 'c' in a repeating pattern
        // 'a' + (i % 3) will give:
        // 'a' for i=0, 3, 6, ...
        // 'b' for i=1, 4, 7, ...
        // 'c' for i=2, 5, 8, ...
        s += (char)('a' + (i % 3));
    }
    std::cout << s << "\n"; // Print the constructed string followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}