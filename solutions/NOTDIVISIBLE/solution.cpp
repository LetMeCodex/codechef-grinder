#include <iostream> // Required for std::cin, std::cout, std::ios_base, std::endl
#include <string>   // Required for std::string

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read N for the current test case
    
    // Use a std::string to build the output for the current test case.
    // This reduces the number of I/O operations to a single std::cout call per test case,
    // which can be significantly faster than multiple small std::cout calls.
    std::string result_buffer = "";
    // Pre-allocate memory for the string to avoid reallocations during concatenation.
    // Each number is '1' or '2' (1 char), plus a space (1 char), for N-1 spaces.
    // Max length is N * 2 (e.g., "1 2 1 2 ...").
    result_buffer.reserve(N * 2); 
    
    // Construct the array A using the pattern:
    // A_k = 1 if k (1-based index) is odd
    // A_k = 2 if k (1-based index) is even
    // For a 0-based loop index `i`:
    // If `(i + 1)` is odd (meaning `i` is even), A[i] = 1.
    // If `(i + 1)` is even (meaning `i` is odd), A[i] = 2.
    
    for (int i = 0; i < N; ++i) {
        if ((i + 1) % 2 != 0) { // Check if the 1-based index (i+1) is odd
            result_buffer += "1";
        } else { // The 1-based index (i+1) is even
            result_buffer += "2";
        }
        
        // Append a space after each number, except for the last one
        if (i < N - 1) {
            result_buffer += " ";
        }
    }
    
    // Print the entire constructed string followed by a newline character
    std::cout << result_buffer << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); // Untie cin from cout
    
    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases
    
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }
    
    return 0; // Indicate successful program execution
}