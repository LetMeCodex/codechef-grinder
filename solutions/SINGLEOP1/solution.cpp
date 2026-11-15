#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <vector>   // Not strictly needed for this problem, but often useful
#include <algorithm> // Not strictly needed for this problem, but often useful

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the binary string
    std::string s;
    std::cin >> s; // Read the binary string

    // Initialize optimal_y to n. This handles the case where all bits are '1's.
    // In this scenario, Y=N (1-indexed) maximizes the value by keeping X unchanged.
    // For example, if S="11", N=2. If Y=2, X' = X XOR (X >> 2) = X XOR 0 = X = "11".
    // Any Y < N would result in a '0' bit at position Y (0-indexed) in the result.
    // E.g., for S="11", Y=1: S'[0]=S[0]=1, S'[1]=S[1]^S[0]=1^1=0. Result "10".
    // "11" (value 3) is greater than "10" (value 2).
    int optimal_y = n; 

    // Iterate through the string to find the first '0'
    // The loop variable 'i' represents the 0-indexed position of the bit.
    // The problem asks for a 1-indexed Y.
    // If S[i] is the first '0', then choosing Y = i (1-indexed) is optimal.
    // Let's verify:
    // If S[i] is the first '0' (0-indexed), then S[0...i-1] are all '1's.
    // Choosing Y=i (1-indexed):
    // S'[j] = S[j] for j < i. So S'[0...i-1] are all '1's.
    // S'[i] = S[i] XOR S[i-i] = S[i] XOR S[0] = '0' XOR '1' = '1'.
    // Thus, S'[0...i] are all '1's. This creates the longest possible prefix of '1's.
    // Any Y' < i would result in S'[Y'] = S[Y'] XOR S[0] = '1' XOR '1' = '0' (since S[Y'] would be '1').
    // Any Y'' > i would result in S'[i] = S[i] = '0' (since i < Y'').
    // Both of these cases produce a lexicographically smaller result than Y=i.
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            optimal_y = i; // 'i' is the 0-indexed position, which directly corresponds to the 1-indexed Y value.
            break; // Found the first '0', so we can stop searching.
        }
    }
    
    // Output the determined optimal Y value.
    std::cout << optimal_y << "\n";
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

    return 0; // Indicate successful execution
}