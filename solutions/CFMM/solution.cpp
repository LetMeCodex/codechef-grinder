#include <iostream>  // Required for standard input/output operations (std::cin, std::cout)
#include <string>    // Required for using std::string to handle ingredient names
#include <algorithm> // Required for std::min function

// The 'solve' function encapsulates the logic for processing a single test case.
void solve() {
    int N; // Declare an integer N to store the number of ingredients
    std::cin >> N; // Read the value of N from standard input
    
    // Declare a C-style array to store the counts of each lowercase English letter.
    // 'a' corresponds to index 0, 'b' to index 1, ..., 'z' to index 25.
    // Initialize all elements to 0. This is efficient for fixed-size arrays.
    int char_counts[26] = {0}; 
    
    // Loop N times to read each ingredient string
    for (int i = 0; i < N; ++i) {
        std::string s; // Declare a string variable to store the current ingredient
        std::cin >> s; // Read the ingredient string from standard input
        
        // Iterate over each character in the string 's'
        for (char ch : s) {
            // Increment the count for the corresponding character.
            // 'ch - 'a'' converts a character ('a' through 'z') into an integer index (0 through 25).
            char_counts[ch - 'a']++;
        }
    }
    
    // Define the character requirements for one "codechef" meal:
    // 'c': 2 times
    // 'o': 1 time
    // 'd': 1 time
    // 'e': 2 times
    // 'h': 1 time
    // 'f': 1 time
    
    // Calculate how many "codechef" meals can be made based on the availability
    // of each required character. Integer division automatically handles flooring.
    // For characters required once, division by 1 is technically redundant but makes the logic explicit.
    int meals_c = char_counts['c' - 'a'] / 2;
    int meals_o = char_counts['o' - 'a'] / 1;
    int meals_d = char_counts['d' - 'a'] / 1;
    int meals_e = char_counts['e' - 'a'] / 2;
    int meals_h = char_counts['h' - 'a'] / 1;
    int meals_f = char_counts['f' - 'a'] / 1;
    
    // The maximum number of complete meals is limited by the character that is
    // most scarce relative to its requirement. We find this by taking the minimum
    // of the potential meals calculated for each character.
    // Using nested std::min calls is a robust way to find the minimum of multiple values,
    // especially for environments that might not fully optimize initializer_list usage.
    int max_meals = std::min(meals_c, 
                      std::min(meals_o, 
                        std::min(meals_d, 
                          std::min(meals_e, 
                            std::min(meals_h, meals_f)))));
    
    // Print the final result for the current test case, followed by a newline character.
    std::cout << max_meals << "\n";
}

// The main function is the entry point of the program.
int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard I/O.
    // std::cin.tie(NULL) prevents std::cin from flushing std::cout before each input operation.
    // These two lines are crucial for performance in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T; // Declare an integer T to store the number of test cases
    std::cin >> T; // Read the number of test cases
    
    // Loop T times, processing one test case in each iteration.
    // The T-- decrements T after each check, effectively looping T times.
    while (T--) { 
        solve(); // Call the 'solve' function to handle the current test case
    }
    
    return 0; // Indicate successful program execution
}