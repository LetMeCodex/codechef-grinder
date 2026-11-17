#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <vector>   // Not strictly needed for this problem, but often useful
#include <algorithm> // Not strictly needed for this problem, but often useful (e.g. std::min, std::max)

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the string
    std::string s;
    std::cin >> s; // Read the binary string

    // Find the index of the first '1' in the string
    int first_one_idx = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            first_one_idx = i;
            break; // Found the first '1', no need to search further
        }
    }

    // Find the index of the last '0' in the string
    int last_zero_idx = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            last_zero_idx = i;
            break; // Found the last '0', no need to search further
        }
    }

    // Case 1: The string is already sorted.
    // This occurs if:
    // a) There are no '1's (string is "00...0"). `first_one_idx` will be -1.
    // b) There are no '0's (string is "11...1"). `last_zero_idx` will be -1.
    // c) All '0's appear before all '1's. This means the first '1' appears after the last '0'.
    //    So, `first_one_idx > last_zero_idx`.
    // In any of these scenarios, 0 operations are needed.
    if (first_one_idx == -1 || last_zero_idx == -1 || first_one_idx > last_zero_idx) {
        std::cout << 0 << "\n";
        return; // Move to the next test case
    }

    // Case 2: The string is unsorted. We need at least 1 operation.
    // At this point, we know `first_one_idx < last_zero_idx`.
    // This means there is at least one '1' that appears before at least one '0'.
    // The "problematic" segment of the string is `S[first_one_idx ... last_zero_idx]`.
    // This segment starts with a '1' and ends with a '0'.

    // We need to count the number of '01' patterns within the problematic segment.
    // Each '01' pattern signifies an additional "inversion" that needs to be resolved.
    // The first operation resolves the outermost '1...0' inversion.
    // Each subsequent '01' pattern requires an additional operation.
    int count_01_patterns = 0;
    // Iterate through the problematic segment S[first_one_idx ... last_zero_idx-1]
    // to check for any '01' substring.
    // The loop goes up to `last_zero_idx - 1` because we are checking `s[i]` and `s[i+1]`.
    for (int i = first_one_idx; i < last_zero_idx; ++i) {
        if (s[i] == '0' && s[i+1] == '1') {
            count_01_patterns++;
        }
    }

    // The minimum number of operations is 1 (for the initial '1...0' inversion)
    // plus the number of '01' patterns found within that '1...0' segment.
    std::cout << 1 + count_01_patterns << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}