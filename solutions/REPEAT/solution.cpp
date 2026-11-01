#include <bits/stdc++.h> // Includes iostream, etc. for standard I/O and other utilities

// Using namespace std; is common in competitive programming to avoid typing std::
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, K, S;
        cin >> N >> K >> S; // Read N, K, S for the current test case

        // The sum of the first N positive odd numbers is N*N.
        // Let X be the number that appears K times.
        // All other N-1 distinct odd numbers appear once.
        // The total sum S can be expressed as:
        // S = (sum of all N distinct odd numbers) - X (because it's counted once in N*N) + K*X (its actual contribution)
        // S = N*N - X + K*X

        // Rearranging the equation to solve for X:
        // S - N*N = (K-1)*X
        // X = (S - N*N) / (K-1)

        // N, K, S are within int limits (N, K <= 10^4, S <= 10^9).
        // N*N can be up to 10^4 * 10^4 = 10^8, which fits in an int.
        // S - N*N can be up to 10^9 - 10^8 (approx 9*10^8), which fits in an int.
        // K-1 can be up to 10^4 - 1, which fits in an int.
        // X will be one of the first N odd numbers, so max 2*10^4 - 1, which fits in an int.
        // Therefore, 'int' type is sufficient for all calculations.
        // However, using 'long long' for intermediate sums is a good practice for robustness,
        // especially if constraints were slightly larger.

        long long sum_of_first_N_odds = (long long)N * N; // Cast N to long long to ensure the product is long long
                                                          // (even though N*N fits in int for these constraints)
        
        long long numerator = S - sum_of_first_N_odds;
        long long denominator = K - 1;

        long long X = numerator / denominator; // Calculate X

        cout << X << "\n"; // Print the result followed by a newline
    }

    return 0; // Indicate successful execution
}