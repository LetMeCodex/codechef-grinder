#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype> // For islower, tolower

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        // Step 1: Calculate initial counts after converting all uppercase to lowercase.
        std::map<char, int> initial_counts;
        for (char c : s) {
            if (std::islower(c)) {
                initial_counts[c]++;
            } else {
                initial_counts[std::tolower(c)]++;
            }
        }

        int max_score = 0;

        // Step 2: Consider the case where Operation 2 is not used effectively.
        // The maximum score is the maximum count of any single character.
        for (char c = 'a'; c <= 'z'; ++c) {
            max_score = std::max(max_score, initial_counts[c]);
        }

        // Step 3: Consider all possible uses of Operation 2.
        // Iterate through all possible source characters to be converted.
        for (char source_char = 'a'; source_char <= 'z'; ++source_char) {
            // Iterate through all possible target characters to convert to.
            for (char target_char = 'a'; target_char <= 'z'; ++target_char) {
                // If source and target are the same, Operation 2 has no effect.
                if (source_char == target_char) {
                    continue;
                }

                // Create a temporary map to simulate the operation.
                std::map<char, int> current_counts = initial_counts;

                // Perform the conversion: all occurrences of source_char become target_char.
                current_counts[target_char] += current_counts[source_char];
                current_counts[source_char] = 0;

                // Find the maximum count in the modified string.
                int current_max_for_this_op = 0;
                for (char c = 'a'; c <= 'z'; ++c) {
                    current_max_for_this_op = std::max(current_max_for_this_op, current_counts[c]);
                }

                // Update the overall maximum score.
                max_score = std::max(max_score, current_max_for_this_op);
            }
        }

        std::cout << max_score << "\n";
    }
    return 0;
}