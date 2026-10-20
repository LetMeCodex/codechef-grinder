#include <iostream> // Required for std::cin, std::cout
#include <map>      // Required for std::map

// Function to solve a single test case
void solve() {
    // Use a map to store the frequency of each difficulty level.
    // Key: difficulty level, Value: count of problems with that difficulty.
    std::map<int, int> counts;

    // Read the four difficulty levels and update their counts.
    for (int i = 0; i < 4; ++i) {
        int a;
        std::cin >> a;
        counts[a]++; // Increment count for difficulty 'a'
    }

    // The number of distinct difficulty levels is simply the size of the map.
    int distinct_difficulty_count = counts.size();

    // Apply the logic based on the number of distinct difficulty levels:
    if (distinct_difficulty_count == 4) {
        // Case 1: All four problems have distinct difficulties (e.g., 1 2 3 4).
        // Can form two sets: [1,2] and [3,4].
        std::cout << 2 << "\n";
    } else if (distinct_difficulty_count == 3) {
        // Case 2: Three distinct difficulties (e.g., 1 1 2 3).
        // One difficulty appears twice, others once. Can form two sets: [1,2] and [1,3].
        std::cout << 2 << "\n";
    } else if (distinct_difficulty_count == 2) {
        // Case 3: Two distinct difficulties.
        // Sub-case A: Counts are (3, 1) (e.g., 1 1 1 2). Only one set [1,2] can be formed.
        // Sub-case B: Counts are (2, 2) (e.g., 1 1 2 2). Can form two sets: [1,2] and [1,2].

        // Check if any difficulty has a count of 3 to distinguish sub-cases.
        bool has_three_count = false;
        for (auto const& pair : counts) { // Iterate through the map's key-value pairs
            if (pair.second == 3) { // If any difficulty has a count of 3
                has_three_count = true;
                break;
            }
        }

        if (has_three_count) {
            std::cout << 1 << "\n"; // Sub-case A: (3,1) counts
        } else {
            std::cout << 2 << "\n"; // Sub-case B: (2,2) counts (since it's not (3,1) and distinct_count is 2)
        }
    } else { // distinct_difficulty_count == 1
        // Case 4: All four problems have the same difficulty (e.g., 1 1 1 1).
        // Cannot form any set as problems must have distinct difficulties.
        std::cout << 0 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}