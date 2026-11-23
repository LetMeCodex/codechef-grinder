#include <iostream> // Required for standard input/output operations (cin, cout)
#include <algorithm> // Required for std::abs and std::min
#include <climits>  // Required for INT_MAX

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the number of elements in the array

    long long total_abs_sum = 0; // Stores the sum of absolute values of all elements. Use long long to prevent overflow.
    int neg_count = 0;           // Counts the number of negative elements
    int min_abs_val = INT_MAX;   // Stores the minimum absolute value found in the array. Initialize with a very large value.

    // Iterate through the array elements
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val; // Read an element directly

        if (val < 0) {
            neg_count++; // Increment negative count if the element is negative
        }
        
        // Add the absolute value of the current element to total_abs_sum
        total_abs_sum += std::abs(val);
        
        // Update min_abs_val if the absolute value of the current element is smaller
        min_abs_val = std::min(min_abs_val, std::abs(val));
    }

    // Based on the parity of negative_count, determine the maximum sum
    if (neg_count % 2 == 0) {
        // If the count of negative numbers is even, we can make all elements positive.
        // The maximum sum is simply the sum of all absolute values.
        std::cout << total_abs_sum << "\n";
    } else {
        // If the count of negative numbers is odd, we must end up with an odd number of negative elements.
        // To maximize the sum, we want exactly one element to be negative, and it should be the one
        // with the smallest absolute value.
        // The sum will be (sum of all absolute values) - 2 * (smallest absolute value).
        // This is because if we made all positive (sum = total_abs_sum), and then had to flip one
        // element 'x' back to negative, its contribution changes from |x| to -|x|, a net change of -2|x|.
        std::cout << total_abs_sum - 2 * min_abs_val << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}