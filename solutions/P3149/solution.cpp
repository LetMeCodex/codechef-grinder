#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the array

    std::vector<int> a(n); // Declare a vector to store array elements
    int first_pos = -1;    // Initialize index of the first positive element (0-indexed)
    int last_pos = -1;     // Initialize index of the last positive element (0-indexed)

    // Read array elements and find first_pos and last_pos
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] > 0) {
            if (first_pos == -1) {
                first_pos = i; // Found the first positive element
            }
            last_pos = i; // Update last_pos with the current positive element's index
        }
    }

    // Case 1: No positive numbers in the array
    // If all elements are non-positive, the maximum subarray sum is 0 (achieved by an empty subarray).
    // No operations are needed to achieve this.
    if (first_pos == -1) {
        std::cout << 0 << "\n";
    } else {
        // Case 2: There is at least one positive number
        // The maximum possible subarray sum is the sum of all positive numbers in the original array.
        // To achieve this sum, we must form a subarray that includes all original positive numbers.
        // This subarray must span from the first positive number to the last positive number.
        // Any negative numbers within this range must be changed to 0 to contribute neutrally to the sum.
        // Numbers outside this range (before first_pos or after last_pos) that are negative
        // do not need to be changed, as including them would reduce the sum, and excluding them
        // (by making the subarray start at first_pos and end at last_pos) is optimal.
        
        int operations = 0;
        // Iterate through the subarray from first_pos to last_pos (inclusive)
        for (int i = first_pos; i <= last_pos; ++i) {
            if (a[i] < 0) {
                // If an element is strictly negative, it must be changed to 0
                // to ensure the sum of the subarray containing all positive elements
                // equals the maximum possible sum.
                operations++;
            }
        }
        std::cout << operations << "\n";
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
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}