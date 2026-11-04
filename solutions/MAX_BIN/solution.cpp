#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
// <vector> and <algorithm> are not strictly needed for this problem,
// but are often included in competitive programming templates.

void solve() {
    int n, k;
    std::cin >> n >> k; // Read N and K
    std::string s;
    std::cin >> s; // Read the binary string S

    // Step 1: If the first character is '0' and we have operations left (K > 0),
    // change it to '1'. This makes the most significant bit '1', which is
    // the most impactful change for maximizing the decimal value.
    if (s[0] == '0' && k > 0) {
        s[0] = '1'; // Change '0' to '1'
        k--;        // One operation used
    }

    // Step 2: Use any remaining K operations to append '0's to the end of the string.
    // Appending '0's effectively multiplies the current decimal value by 2 for each '0' added.
    // This is the most efficient way to increase the value after the first bit is '1'.
    // Using s.append(count, char) is generally more efficient for appending multiple
    // characters than repeated push_back, as it can perform a single memory allocation.
    if (k > 0) { // Only append if there are operations left
        s.append(k, '0');
    }

    std::cout << s << "\n"; // Output the modified string
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}