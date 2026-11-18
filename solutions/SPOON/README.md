# [Spoon in Matrix (SPOON)](https://www.codechef.com/problems/SPOON)
- **Difficulty Rating**: 1303
- **Solved in**: 3 attempt(s)

## Problem Summary
The problem asks us to determine if the word "spoon" (case-insensitive) exists within a given character matrix. The word can appear either horizontally (left-to-right) or vertically (top-to-bottom). We are provided with the dimensions of the matrix, `R` rows and `C` columns, and the matrix itself. For each test case, we need to output "There is a spoon!" if the word is found, and "There is indeed no spoon!" otherwise. The constraints are relatively small: `R, C <= 100` and `T <= 100` test cases.

## Intuition & Mathematical Observation
1.  **Brute-Force Search**: Given the small constraints (`R, C <= 100`), a straightforward brute-force search is an efficient and acceptable approach. We need to check every possible starting position for the word "spoon" in both horizontal and vertical directions.
2.  **Case-Insensitivity**: The problem explicitly states that the search should be case-insensitive. To handle this, we can convert all characters from the matrix to lowercase before comparing them with the lowercase target word "spoon". The provided solution uses a custom `my_tolower` function for this purpose. This custom function is often slightly faster than `std::tolower` for basic ASCII character conversion, as it avoids locale-specific overhead.
3.  **Word Length**: The target word "spoon" has a fixed length of 5 characters. This constant length simplifies boundary checks.
4.  **Horizontal Search Strategy**:
    *   We iterate through each row `i` from `0` to `R-1`.
    *   For each row, we iterate through possible starting columns `j`. Since "spoon" has 5 characters, if a row has `C` columns, the last valid starting column `j` is `C - 5`. Any `j` greater than `C - 5` would not leave enough space for the entire word. So, `j` goes from `0` to `C - 5`.
    *   At each `(i, j)` starting point, we compare `my_tolower(matrix[i][j])` with 's', `my_tolower(matrix[i][j+1])` with 'p', and so on, for all 5 characters.
5.  **Vertical Search Strategy**:
    *   If "spoon" is not found horizontally after checking all rows, we then proceed to search vertically.
    *   We iterate through each column `j` from `0` to `C-1`.
    *   For each column, we iterate through possible starting rows `i`. Similar to the horizontal search, the last valid starting row `i` is `R - 5`. So, `i` goes from `0` to `R - 5`.
    *   At each `(i, j)` starting point, we compare `my_tolower(matrix[i][j])` with 's', `my_tolower(matrix[i+1][j])` with 'p', and so on, for all 5 characters.
6.  **Early Exit**: An important optimization is to stop searching as soon as "spoon" is found (either horizontally or vertically). A boolean flag (`found_spoon`) is used to track this, and `break` statements are employed to exit loops prematurely, improving average-case performance.
7.  **Input/Output Optimization**: Standard competitive programming practice includes using `std::ios_base::sync_with_stdio(false);` and `std::cin.tie(NULL);` in `main` to speed up C++ I/O operations. Additionally, using `'\n'` instead of `std::endl` for newlines avoids unnecessary buffer flushes, further contributing to faster output.

## Complexity Analysis
Let `R` be the number of rows and `C` be the number of columns in the matrix.
Let `L` be the length of the target word "spoon", which is a constant `5`.

-   **Time Complexity**:
    *   **Reading Input**: Reading `R` strings, each of length `C`, takes `O(R * C)` time.
    *   **Horizontal Search**:
        *   The outermost loop iterates `R` times (for each row).
        *   The middle loop iterates `C - L + 1` times (for each possible starting column).
        *   The innermost loop iterates `L` times (for comparing characters of "spoon").
        *   Total for horizontal search: `O(R * (C - L + 1) * L)`. Since `L` is a constant (5), this simplifies to `O(R * C)`.
    *   **Vertical Search**:
        *   The outermost loop iterates `C` times (for each column).
        *   The middle loop iterates `R - L + 1` times (for each possible starting row).
        *   The innermost loop iterates `L` times (for comparing characters of "spoon").
        *   Total for vertical search: `O(C * (R - L + 1) * L)`. Since `L` is a constant (5), this simplifies to `O(C * R)`.
    *   In the worst case, we perform both horizontal and vertical searches. The dominant factor is `O(R * C)`.
    *   Considering `T` test cases, the total time complexity is `O(T * R * C)`.
    *   Given the constraints `T <= 100`, `R <= 100`, `C <= 100`, the maximum number of operations would be approximately `100 * 100 * 100 = 10^6`. This is well within typical time limits for competitive programming (usually `10^8` operations per second).

-   **Space Complexity**:
    *   The `std::vector<std::string> matrix` stores `R` strings, each of length `C`. This requires `O(R * C)` space to store the entire matrix.
    *   Other variables like `R`, `C`, `found_spoon`, `target_word`, `word_length`, and loop counters consume a constant amount of space, `O(1)`.
    *   Therefore, the overall space complexity is `O(R * C)`.
    *   For `R=100`, `C=100`, this amounts to `100 * 100 = 10,000` characters, which is approximately 10KB. This is well within typical memory limits.

## Solution Code
```cpp
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
```