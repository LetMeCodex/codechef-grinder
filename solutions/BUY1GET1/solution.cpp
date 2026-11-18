#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    std::string s;
    std::cin >> s; // Read the jewel string

    // Use a vector as a frequency map for ASCII characters.
    // Size 256 covers all possible char values (0-255).
    // Initialize all counts to 0.
    std::vector<int> freq(256, 0); 
    
    // Populate the frequency map by iterating through the input string
    for (char c : s) {
        // Cast char to unsigned char to safely use it as an index.
        // This prevents issues if 'char' is signed and holds a negative value,
        // which would lead to out-of-bounds access for the 'freq' array.
        freq[static_cast<unsigned char>(c)]++;
    }

    int total_cost = 0;
    // Iterate through the frequency counts.
    // We only care about characters that actually appeared in the string (count > 0).
    // Iterating through all 256 possible counts is efficient enough given the small constant size.
    for (int count : freq) {
        if (count > 0) {
            // Calculate cost for this color:
            // For N jewels of a specific color:
            // N/2 pairs can be acquired using the Buy1-Get1 offer, costing N/2.
            // If N is odd, there will be one jewel left over, which must be bought individually, costing 1.
            // So, the cost for 'count' jewels of a single color is (count / 2) + (count % 2).
            total_cost += (count / 2) + (count % 2);
        }
    }
    std::cout << total_cost << "\n"; // Output the minimum total cost for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input,
    // which can speed up interactive programs or programs with mixed I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful program execution
}