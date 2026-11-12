#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <vector>   // Not strictly needed for this problem, but often useful
#include <algorithm> // Not strictly needed for this problem, but often useful

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of string U
    std::string u;
    std::cin >> u; // Read the string U

    std::string s_res = ""; // Initialize an empty string to build S
    int i = 0; // Pointer to iterate through string U

    // Iterate through U, processing it block by block of identical characters
    while (i < n) {
        char current_char = u[i]; // Get the character of the current block
        int count = 0; // Count of consecutive occurrences of current_char

        // Count how many times current_char appears consecutively
        int j = i;
        while (j < n && u[j] == current_char) {
            count++;
            j++;
        }

        // Logic to determine how many characters to add to S_res based on block length:
        // A single character 'c' in S can be expanded to any block of 'c's of odd length (1, 3, 5, ...).
        // This is because each operation 'X -> XXX' increases the length of the string by 2.
        // Starting from length 1 (no operations), all reachable lengths are 1 + 2k.
        //
        // If the current block length 'count' is odd:
        // It can be generated from a single 'current_char' in S.
        // To minimize S, we add only one 'current_char'.
        if (count % 2 == 1) {
            s_res.push_back(current_char);
        } 
        // If the current block length 'count' is even:
        // It cannot be generated from a single 'current_char' in S (as single chars only produce odd lengths).
        // It must be generated from at least two 'current_char's in S.
        // For example, if S has "cc", the first 'c' can become 'c' (length 1) and the second 'c' can become 'ccc' (length 3).
        // This results in "cccc" (length 4).
        // In general, two characters in S, say S_k and S_{k+1}, both being 'c', can generate a block of 'c's of total length L_k + L_{k+1},
        // where L_k and L_{k+1} are odd. The sum of two odd numbers is always even.
        // Thus, any even length block can be formed from two characters in S.
        // To minimize S, we add exactly two 'current_char's.
        else { // count % 2 == 0
            s_res.push_back(current_char);
            s_res.push_back(current_char);
        }
        
        // Move the pointer 'i' to the start of the next block
        i = j; 
    }
    std::cout << s_res << "\n"; // Output the constructed string S
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
        solve(); // Solve each test case
    }
    return 0;
}