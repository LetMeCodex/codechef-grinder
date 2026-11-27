#include <iostream> // For std::cin, std::cout
#include <vector>   // For std::vector
// Removed <bits/stdc++.h> and <set> as they are no longer strictly necessary.

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Max ingredient type is 1000. Use vectors for O(1) access.
    // counts_arr[ingredient_type] stores its count.
    // finished_types_arr[ingredient_type] is true if its block has already been processed.
    // Size 1001 to handle ingredient types from 1 to 1000 (inclusive).
    std::vector<int> counts_arr(1001, 0);
    std::vector<bool> finished_types_arr(1001, false);

    // Iterate through the recipe to check Rule 1 and collect counts for Rule 2.
    // The loop variable 'i' is updated inside the loop to jump to the next block.
    for (int i = 0; i < N; ) {
        int current_ingredient = A[i];

        // Rule 1 check: If this ingredient type has already finished its block,
        // it means Chef is using the jar again, which is not allowed.
        if (finished_types_arr[current_ingredient]) {
            std::cout << "NO\n";
            return;
        }

        // Count occurrences of current_ingredient in its contiguous block.
        int current_count = 0;
        int j = i;
        while (j < N && A[j] == current_ingredient) {
            current_count++;
            j++;
        }

        // Mark this ingredient type as finished.
        finished_types_arr[current_ingredient] = true;
        // Store its count.
        counts_arr[current_ingredient] = current_count;

        // Move 'i' to the start of the next block.
        i = j;
    }

    // If we reached here, Rule 1 (contiguous subsequences) is satisfied.
    // Now, check Rule 2: unique quantities for all ingredient types.
    // Use a boolean vector instead of a set for O(1) average time insertion/check.
    // Max possible count is N (if all ingredients are the same type).
    // Vector size N+1 to handle counts from 1 to N.
    std::vector<bool> seen_counts(N + 1, false); 
    
    // Iterate through all possible ingredient types (1 to 1000).
    for (int k = 1; k <= 1000; ++k) {
        if (counts_arr[k] > 0) { // If ingredient type k was present in the recipe.
            int count_val = counts_arr[k];
            // Check if this count has already been seen for another ingredient type.
            if (seen_counts[count_val]) {
                std::cout << "NO\n"; // Quantity is not unique.
                return;
            }
            seen_counts[count_val] = true; // Mark this count as seen.
        }
    }

    // If we reached here, both rules are satisfied.
    std::cout << "YES\n";
}

int main() {
    // Fast I/O for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}