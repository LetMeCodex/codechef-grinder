#include <bits/stdc++.h> // Includes iostream, vector, algorithm, limits, etc.

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array
    
    // Initialize min_val to the largest possible integer value
    // and max_val to the smallest possible integer value.
    // This ensures that the first element read will correctly set
    // both min_val and max_val.
    // Given constraints 1 <= A_i <= 100, we could also initialize
    // min_val = 101 and max_val = 0, but using numeric_limits is more general.
    int min_val = std::numeric_limits<int>::max();
    int max_val = std::numeric_limits<int>::min();
    
    // Iterate through the array elements to find the minimum and maximum values
    for (int i = 0; i < N; ++i) {
        int A_i;
        std::cin >> A_i; // Read an element
        min_val = std::min(min_val, A_i); // Update minimum value
        max_val = std::max(max_val, A_i); // Update maximum value
    }
    
    // An integer X is "good" if there exist A_i and A_j such that A_i < X < A_j.
    // This condition is equivalent to min_val < X < max_val.
    // The integers satisfying this condition are min_val + 1, min_val + 2, ..., max_val - 1.
    // The count of such integers is (max_val - 1) - (min_val + 1) + 1,
    // which simplifies to max_val - min_val - 1.
    
    // If max_val <= min_val (e.g., all elements in the array are the same, or N=1),
    // then there are no integers X such that min_val < X < max_val.
    // In this case, the count should be 0.
    // The formula max_val - min_val - 1 would yield a non-positive number (e.g., -1 if max_val == min_val).
    // So, we take the maximum of 0 and the calculated count to handle this case correctly.
    int count = std::max(0, max_val - min_val - 1);
    
    std::cout << count << "\n"; // Output the result for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }
    
    return 0; // Indicate successful execution
}