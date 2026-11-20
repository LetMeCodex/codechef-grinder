#include <iostream> // Required for standard input/output operations (cin, cout)
#include <string>   // Required for using std::string to read dish names
// #include <bits/stdc++.h> // A common competitive programming header that includes many standard libraries

// The solve function encapsulates the logic for a single test case.
void solve() {
    int N; // Declare an integer variable N to store the number of dishes
    std::cin >> N; // Read the value of N from standard input

    // Initialize common_mask. This bitmask will keep track of ingredients
    // that are present in ALL dishes processed so far.
    // Initially, we assume all 26 lowercase English letters ('a' through 'z')
    // are potentially special ingredients.
    // (1 << 26) creates an integer with the 26th bit set (0-indexed, so bit 25 is 'z').
    // Subtracting 1 makes all bits from 0 to 25 set.
    // For example, if we only had 3 letters, (1 << 3) - 1 would be 7 (binary 111).
    int common_mask = (1 << 26) - 1; 

    // Loop N times, once for each dish
    for (int i = 0; i < N; ++i) {
        std::string S; // Declare a string variable S to store the current dish's ingredients
        std::cin >> S; // Read the dish string from standard input

        // current_dish_mask will store the unique ingredients present in the current dish S.
        // It's initialized to 0, meaning no ingredients are present yet.
        int current_dish_mask = 0;
        
        // Iterate through each character (ingredient) in the current dish string S
        for (char c : S) {
            // Set the bit corresponding to the character 'c'.
            // 'a' corresponds to bit 0, 'b' to bit 1, ..., 'z' to bit 25.
            // The bitwise OR operator (`|=`) ensures that if a character appears
            // multiple times in the string, its corresponding bit is set only once.
            current_dish_mask |= (1 << (c - 'a'));
        }

        // Update common_mask by performing a bitwise AND with current_dish_mask.
        // This operation finds the intersection of ingredients.
        // Only bits that are set in *both* common_mask (ingredients common to previous dishes)
        // AND current_dish_mask (ingredients in the current dish) will remain set.
        // If an ingredient was common to previous dishes but is NOT in the current dish,
        // its corresponding bit will be cleared in common_mask.
        common_mask &= current_dish_mask;
    }

    // After processing all N dishes, common_mask will contain bits set only for
    // ingredients that were present in ALL N dishes.
    // We need to count these set bits to find the number of special ingredients.
    // __builtin_popcount is a GCC extension that efficiently counts the number of set bits
    // (population count) in an integer.
    int special_ingredients_count = __builtin_popcount(common_mask);
    
    // Print the result for the current test case, followed by a newline character.
    std::cout << special_ingredients_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // std::cin.tie(NULL) prevents std::cout from flushing before each std::cin operation,
    // which can further speed up I/O in interactive problems or problems with mixed I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases
    std::cin >> T; // Read the number of test cases from standard input
    
    // Loop T times, calling the solve() function for each test case.
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}