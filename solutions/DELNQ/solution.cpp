#include <iostream>
#include <string>
#include <algorithm> // Not strictly necessary for this problem, but often useful.

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        std::cin >> n; // Read the length of the string
        std::string s;
        std::cin >> s; // Read the binary string

        int count0 = 0;
        int count1 = 0;
        // Count occurrences of '0' and '1'
        for (char c : s) {
            if (c == '0') {
                count0++;
            } else {
                count1++;
            }
        }

        // Apply the revised logic
        if (count0 == 0 || count1 == 0) {
            // If the string is monochromatic (all '0's or all '1's),
            // no operations can be performed. The length remains N.
            std::cout << n << "\n";
        } else {
            // If the string contains both '0's and '1's,
            // it's always possible to reduce it to a single character.
            std::cout << 1 << "\n";
        }
    }
    return 0;
}