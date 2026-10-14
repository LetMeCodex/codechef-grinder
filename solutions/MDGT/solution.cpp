#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::max

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of students
    std::vector<int> H(N); // Create a vector to store heights
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i]; // Read heights
    }

    // If there's only one student, Bhoomi is at the front and can always see.
    // No movement needed.
    if (N == 1) {
        std::cout << 0 << "\n";
        return;
    }

    // Bhoomi's height is the last student's height (H_N in 1-indexed, H[N-1] in 0-indexed)
    int bhoomi_h = H[N - 1];

    // Create a prefix_max array.
    // prefix_max[i] will store the maximum height among H[0], H[1], ..., H[i].
    // We only need to consider students *before* Bhoomi's potential positions.
    // The maximum possible index for a student in front of Bhoomi is N-2 (if Bhoomi is at 1-indexed position N-1).
    // So prefix_max needs to go up to index N-2.
    // Its size will be N-1 (indices 0 to N-2).
    std::vector<int> prefix_max(N - 1); 
    
    // Initialize the first element
    prefix_max[0] = H[0];
    
    // Compute prefix maximums for the rest of the students in front
    for (int i = 1; i < N - 1; ++i) {
        prefix_max[i] = std::max(prefix_max[i - 1], H[i]);
    }

    int seconds_taken = 0;
    // Iterate Bhoomi's potential positions (1-indexed) from N down to 1.
    // We want to find the *first* position (largest k) where she can see.
    for (int k = N; k >= 1; --k) {
        int max_val_in_front_of_k = 0; // Default max height in front is 0 (for k=1, no one in front)

        // If k-1 >= 1, it means there are students in front of Bhoomi at position k.
        // The students in front are H_1, ..., H_{k-1} (1-indexed).
        // In 0-indexed, these are H[0], ..., H[k-2].
        // The maximum of these heights is stored in prefix_max[k-2].
        if (k - 1 >= 1) { 
            max_val_in_front_of_k = prefix_max[k - 2];
        }
        
        // Check if Bhoomi's height is strictly greater than everyone in front.
        if (bhoomi_h > max_val_in_front_of_k) {
            // If she can see, this is the earliest position (largest k) where she can.
            // The number of seconds taken is N - k (initial position N, current position k).
            seconds_taken = N - k;
            break; // Found the answer, no need to check further positions.
        }
    }
    std::cout << seconds_taken << "\n"; // Output the result
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }
    return 0;
}