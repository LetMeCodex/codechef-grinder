#include <iostream> // Required for standard input/output operations (cin, cout)
#include <vector>   // Required for using std::vector to store the array elements

// As per competitive programming common practice and problem instructions,
// using the entire std namespace to avoid prefixing std:: everywhere.
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the size of the array

    // Declare a vector of long long to store array elements.
    // long long is used because elements can be up to 10^9,
    // and sums can exceed 2*10^9 (max for 32-bit int).
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Read array elements
    }

    long long count = 0; // Initialize counter for subarrays satisfying the condition

    // Iterate through all possible starting indices 'i' for subarrays
    for (int i = 0; i < n; ++i) {
        long long current_sum = 0;     // Initialize sum for the current subarray
        long long current_product = 1; // Initialize product for the current subarray (product starts at 1)

        // Iterate through all possible ending indices 'j' for subarrays, starting from 'i'
        for (int j = i; j < n; ++j) {
            // Add the current element A[j] to the running sum
            current_sum += a[j];

            // Multiply the current element A[j] to the running product
            // The problem states A[i] are positive (1 <= A[i] <= 10^9),
            // so no division by zero or product becoming zero unexpectedly.
            // The constraint A1 * A2 * ... * An <= 10^9 ensures that
            // any subarray product will also not exceed 10^9.
            // long long is used for current_product for consistency and safety,
            // as current_sum can reach 50 * 10^9.
            current_product *= a[j];

            // Check if the current sum equals the current product
            if (current_sum == current_product) {
                count++; // If they are equal, increment the counter
            }
        }
    }

    // Output the total count for the current test case, followed by a newline
    cout << count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}