#include <iostream> // Required for std::cin, std::cout, std::endl
#include <string>   // Required for std::string
#include <vector>   // Required for std::vector<bool> (or can use a simple bool array)

// Function to solve a single test case
void solve() {
    std::string J, S;
    std::cin >> J >> S; // Read the jewel string J and stone string S

    // Use a boolean array to mark jewel characters for O(1) lookup.
    // A size of 256 covers all possible values for an unsigned char (0-255),
    // which is safe for all ASCII characters, including English lower and upper case.
    std::vector<bool> is_jewel(256, false); 

    // Populate the is_jewel array: mark all characters present in J as true.
    for (char jewel_char : J) {
        // static_cast<unsigned char> is used for safe indexing,
        // as char can be signed or unsigned depending on the compiler/platform,
        // and negative char values would lead to out-of-bounds access.
        is_jewel[static_cast<unsigned char>(jewel_char)] = true;
    }

    int jewel_count = 0;
    // Iterate through each character in the stone string S.
    // The 'c' in 'for (char c : S)' declares 'c' for each character in S,
    // resolving the "not declared in this scope" error.
    for (char c : S) { 
        // Check if the current stone character 'c' is a jewel.
        if (is_jewel[static_cast<unsigned char>(c)]) {
            jewel_count++; // Increment count if it's a jewel
        }
    }

    std::cout << jewel_count << std::endl; // Output the total count of jewels
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); // Unties cin from cout

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {  // Loop T times for each test case
        solve();   // Call the solve function for each test case
    }
    return 0; // Indicate successful execution
}