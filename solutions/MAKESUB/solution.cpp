#include <iostream> // Required for input/output operations (cin, cout)
#include <string>   // Required for std::string and its methods (find, rfind)
#include <algorithm> // Not strictly necessary for this solution, but often useful

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of cells
    std::string S;
    std::cin >> S; // Read the binary string representing the canvas state

    // Find the index of the first occurrence of '1'
    // std::string::npos is a special value indicating "not found"
    size_t first_one = S.find('1');

    // If no '1's are found in the string, it means there are no black cells.
    // An empty set of black cells satisfies the contiguous subarray condition.
    // Therefore, 0 changes are needed.
    if (first_one == std::string::npos) {
        std::cout << 0 << "\n";
        return; // Move to the next test case
    }

    // Find the index of the last occurrence of '1'
    size_t last_one = S.rfind('1');

    // If '1's are present, the final contiguous subarray of black cells
    // must span at least from 'first_one' to 'last_one'.
    // This is because we cannot change '1's to '0's, so all existing '1's
    // must remain black and be part of the final contiguous segment.
    // To minimize changes, we only fill '0's within this minimal required range.

    int changes = 0; // Counter for the number of '0's to change to '1's
    // Iterate through the cells from the first '1' to the last '1'
    for (size_t i = first_one; i <= last_one; ++i) {
        // If a cell within this range is '0' (white), it must be changed to '1' (black)
        if (S[i] == '0') {
            changes++; // Increment the count of changes needed
        }
    }

    // Output the minimum number of changes for this test case
    std::cout << changes << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {  // Loop T times, once for each test case
        solve();   // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}