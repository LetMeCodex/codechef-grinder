#include <iostream> // Required for input/output operations (cin, cout)
#include <vector>   // Not strictly needed for this solution, but often useful
#include <map>      // Used for frequency counting (std::map)

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the number of cities

    // Use a map to store the frequency of each candy price
    // Key: candy price (int), Value: count of occurrences (int)
    std::map<int, int> counts; 

    // Read 2N candy prices and update their frequencies
    for (int i = 0; i < 2 * n; ++i) {
        int price;
        std::cin >> price;
        counts[price]++; // Increment the count for the current price
    }

    // Flag to track if a valid split is possible
    bool possible = true;

    // Iterate through the frequency map
    // For each unique price and its count:
    for (auto const& pair : counts) { // C++11 range-based for loop (C++17 structured binding could be used for clarity)
        int count = pair.second; // Get the count of the current price
        
        // If any price appears more than twice, it's impossible to split
        // into two arrays where each has distinct elements.
        if (count > 2) {
            possible = false; // Set flag to false
            break;            // No need to check further, we found a violation
        }
    }

    // Output the result based on the 'possible' flag
    if (possible) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();   // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}