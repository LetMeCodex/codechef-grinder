#include <iostream> // Required for standard input/output operations (cin, cout)

// Define the modulo constant. It's a prime number commonly used in competitive programming.
const long long MOD = 998244353;

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array C

    long long total_sum = 0; // Initialize a long long variable to store the sum of elements.
                             // Using long long is crucial because C_i can be up to 10^9 and N up to 2*10^5,
                             // so total_sum can be up to 2*10^5 * 10^9 = 2*10^14, which exceeds int's capacity.

    // Loop through N elements to read them and calculate their sum
    for (int i = 0; i < N; ++i) {
        long long C_i; // Each element C_i can be up to 10^9, so use long long for safety.
        std::cin >> C_i;
        total_sum += C_i; // Add the current element to the total sum
    }

    // The maximum value of f(C) is obtained when all elements in the array are 1s.
    // The sum of elements (total_sum) remains invariant under the given operations.
    // If the final array consists of only 1s, its size will be equal to the initial total_sum.
    // Let S_final be the total_sum. The final array will be [1, 1, ..., 1] (S_final times).
    // For this array:
    // - The sum of elements is S_final.
    // - The sum of squares of elements is S_final * 1^2 = S_final.
    // The function f(A) is defined as (sum of elements)^2 - (sum of squares of elements).
    // So, the maximum value of f(C) is S_final^2 - S_final.

    // Now, calculate (total_sum^2 - total_sum) modulo MOD.
    // First, take total_sum modulo MOD to keep intermediate values within manageable range.
    long long S_mod = total_sum % MOD;

    // Calculate S_mod * S_mod, then take modulo.
    long long S_squared_mod = (S_mod * S_mod) % MOD;

    // Calculate (S_squared_mod - S_mod) modulo MOD.
    // We add MOD before subtracting S_mod to ensure the result of the subtraction is non-negative
    // before applying the final modulo operation. This handles cases where S_squared_mod < S_mod.
    long long result = (S_squared_mod - S_mod + MOD) % MOD;

    std::cout << result << "\n"; // Output the final result
}

int main() {
    // Optimize C++ standard streams for faster input/output.
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