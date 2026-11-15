#include <iostream> // Required for cin, cout
#include <vector>   // Required for std::vector
#include <numeric>  // Not strictly needed, but often useful

void solve() {
    int n;
    std::cin >> n; // Read N

    // Use a frequency array for negative numbers.
    // neg_counts[i] will store the count of the number -i.
    // Since A_i is between -100 and 100, negative numbers are -1 to -100.
    // Size 101 to cover indices 1 to 100.
    std::vector<int> neg_counts(101, 0); 
    
    long long current_sum = 0; // To keep track of the sum of selected elements
    int current_count = 0;     // To keep track of the count of selected elements

    // First pass: include all non-negative numbers and count negative numbers
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val; // Read each element
        if (val >= 0) {
            current_sum += val;
            current_count++;
        } else {
            // Store count of negative numbers.
            // For val = -5, neg_counts[5]++.
            neg_counts[-val]++; 
        }
    }

    // Second pass: try to add negative numbers, starting from the least negative (-1)
    // Iterate from i = 1 (representing -1) up to 100 (representing -100).
    for (int i = 1; i <= 100; ++i) {
        int num_val = -i; // The actual negative number, e.g., -1, -2, ...
        int count_of_this_num = neg_counts[i];

        // Try to add all occurrences of this specific negative number (e.g., all -1s).
        for (int k = 0; k < count_of_this_num; ++k) {
            // If adding the current negative number keeps the sum non-negative
            if (current_sum + num_val >= 0) {
                current_sum += num_val;
                current_count++;
            } else {
                // If adding this negative number makes the sum negative,
                // then we cannot add any more numbers. This is because:
                // 1. Any remaining occurrences of the current num_val would also make the sum negative.
                // 2. Any subsequent num_val (e.g., -2 after -1) would be even smaller/more negative,
                //    and thus would also make the sum negative.
                // So, we output the current count and stop processing for this test case.
                std::cout << current_count << "\n";
                return; // Exit the solve function
            }
        }
    }

    // If we processed all negative numbers and the sum is still non-negative,
    // output the final maximum count.
    std::cout << current_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}