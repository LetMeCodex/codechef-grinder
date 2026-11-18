#include <iostream> // Required for input/output operations (cin, cout)
#include <vector>   // Required for std::vector
#include <string>   // Required for std::string
// #include <cctype>   // std::tolower is replaced by custom function, so this is no longer strictly needed

// Custom tolower function for ASCII characters, which is typically faster than std::tolower
// when only 'A'-'Z' to 'a'-'z' conversion is needed.
char my_tolower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A'); // Convert uppercase to lowercase
    }
    return c; // Return as is for lowercase or other characters
}

// Function to solve a single test case
void solve() {
    int R, C; // R: number of rows, C: number of columns
    std::cin >> R >> C; // Read R and C

    // Declare a 2D vector of strings to store the matrix
    // std::vector<std::string> is efficient enough for R, C <= 100
    std::vector<std::string> matrix(R);
    for (int i = 0; i < R; ++i) {
        std::cin >> matrix[i]; // Read each row as a string
    }

    bool found_spoon = false; // Flag to track if "Spoon" is found
    std::string target_word = "spoon"; // The word to search for, in lowercase for easy comparison
    int word_length = target_word.length(); // Length of "spoon" is 5

    // --- Search horizontally (left to right) ---
    for (int i = 0; i < R; ++i) { // Iterate through each row
        // Iterate through columns, stopping early if not enough space for "spoon"
        // C - word_length is the last valid starting index for a horizontal match
        for (int j = 0; j <= C - word_length; ++j) {
            bool current_match = true; // Assume a match for the current starting position
            for (int k = 0; k < word_length; ++k) { // Check each character of "spoon"
                // Compare character from matrix (converted to lowercase using custom function)
                // with target_word character
                if (my_tolower(matrix[i][j + k]) != target_word[k]) {
                    current_match = false; // Mismatch found, break inner loop
                    break;
                }
            }
            if (current_match) {
                found_spoon = true; // "Spoon" found horizontally
                break; // No need to check further in this row
            }
        }
        if (found_spoon) {
            break; // No need to check further rows
        }
    }

    // --- If not found horizontally, search vertically (top to bottom) ---
    if (!found_spoon) {
        for (int j = 0; j < C; ++j) { // Iterate through each column
            // Iterate through rows, stopping early if not enough space for "spoon"
            // R - word_length is the last valid starting index for a vertical match
            for (int i = 0; i <= R - word_length; ++i) {
                bool current_match = true; // Assume a match for the current starting position
                for (int k = 0; k < word_length; ++k) { // Check each character of "spoon"
                    // Compare character from matrix (converted to lowercase using custom function)
                    // with target_word character
                    if (my_tolower(matrix[i + k][j]) != target_word[k]) {
                        current_match = false; // Mismatch found, break inner loop
                        break;
                    }
                }
                if (current_match) {
                    found_spoon = true; // "Spoon" found vertically
                    break; // No need to check further in this column
                }
            }
            if (found_spoon) {
                break; // No need to check further columns
            }
        }
    }

    // Output the result based on the flag
    if (found_spoon) {
        std::cout << "There is a spoon!\n"; // Changed std::endl to '\n' for faster output
    } else {
        std::cout << "There is indeed no spoon!\n"; // Changed std::endl to '\n' for faster output
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming
    // This unties cin from cout and disables synchronization with C stdio,
    // making input/output operations faster.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop T times
        solve(); // Call the solve function for each test case
    }
    return 0; // Indicate successful execution
}