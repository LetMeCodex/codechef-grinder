#include <iostream> // For std::ios_base, std::cin, std::cout (though not used directly after change)
#include <vector>
#include <algorithm> // For std::max (not strictly needed for this solution, but often useful)
#include <cstdio>    // For scanf/printf

void solve() {
    int N, K;
    // Use scanf for faster input of N and K
    scanf("%d %d", &N, &K);

    // counts[val] stores the frequency of 'val' in the original array A.
    // Max A_i is 1000, so array size 1001 (for indices 0 to 1000).
    std::vector<int> counts(1001, 0);
    for (int i = 0; i < N; ++i) {
        int val;
        // Use scanf for faster input of array elements
        scanf("%d", &val);
        counts[val]++;
    }

    // prefix_counts[v] stores the total number of elements in A that are <= v.
    std::vector<int> prefix_counts(1001, 0);
    // Initialize prefix_counts[0] with counts[0].
    // The loop for i=1 to 1000 will correctly sum up counts even if N=0 (all counts are 0).
    prefix_counts[0] = counts[0];
    for (int i = 1; i <= 1000; ++i) {
        prefix_counts[i] = prefix_counts[i-1] + counts[i];
    }

    int total_elements = N + K;
    // The median is at index (total_elements - 1) / 2 (0-indexed).
    // To be the median, an element 'val' must satisfy:
    // 1. At least (total_elements - 1) / 2 + 1 elements are <= val.
    // 2. At least total_elements - (total_elements - 1) / 2 elements are >= val.
    // Both conditions simplify to needing at least (total_elements + 1) / 2 elements.
    int required_count_for_median = (total_elements + 1) / 2;

    // Iterate from the largest possible median value (1000) down to 0.
    // The first 'val' that satisfies the conditions will be the greatest median.
    for (int val = 1000; val >= 0; --val) {
        // num_le_val_A: Number of elements in original array A that are <= val.
        int num_le_val_A = prefix_counts[val];
        
        // num_lt_val_A: Number of elements in original array A that are < val.
        // If val is 0, there are no elements < 0, so this is 0.
        int num_lt_val_A = (val == 0) ? 0 : prefix_counts[val-1];
        
        // num_ge_val_A: Number of elements in original array A that are >= val.
        // This is N - (count of elements < val).
        int num_ge_val_A = N - num_lt_val_A;

        // Check if 'val' can be the median.
        // We can insert K elements. To maximize the median, we assume we insert K elements
        // that are equal to 'val'. These K elements contribute to both counts.
        bool condition_le_met = (num_le_val_A + K >= required_count_for_median);
        bool condition_ge_met = (num_ge_val_A + K >= required_count_for_median);

        if (condition_le_met && condition_ge_met) {
            // Use printf for faster output
            printf("%d\n", val);
            return; // Found the greatest possible median, so we can stop.
        }
    }
}

int main() {
    // When using scanf/printf, std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    // are not needed and can sometimes cause minor issues if mixed with C-style I/O.
    // So, they are removed.
    
    int t;
    scanf("%d", &t); // Read the number of test cases.
    while (t--) {
        solve(); // Solve each test case.
    }
    return 0;
}