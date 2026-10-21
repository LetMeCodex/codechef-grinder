#include <bits/stdc++.h> // Includes common libraries like iostream and algorithm
using namespace std; // Use standard namespace for convenience

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int X, Y, Z;
        cin >> X >> Y >> Z; // Read X, Y, Z for the current test case

        // Calculate the maximum number of income sources Chef can keep
        // without exceeding the account limit Z.
        // If Chef keeps 'k' sources, his total income is k * Y.
        // This must satisfy k * Y <= Z, which implies k <= Z / Y.
        // Since 'k' must be an integer, the maximum 'k' is floor(Z / Y).
        // Integer division in C++ (for positive numbers) automatically computes floor.
        int max_sources_by_limit = Z / Y;

        // Chef initially has X income sources. He cannot keep more than X sources.
        // So, the actual number of sources Chef will keep is the minimum of:
        // 1. The initial number of sources he has (X).
        // 2. The maximum number of sources allowed by the account limit (max_sources_by_limit).
        int sources_to_keep = min(X, max_sources_by_limit);

        // The number of sources Chef needs to reduce is the difference between
        // his initial number of sources and the number of sources he decides to keep.
        int sources_to_reduce = X - sources_to_keep;

        cout << sources_to_reduce << "\n"; // Output the result for the current test case
    }

    return 0; // Indicate successful execution
}