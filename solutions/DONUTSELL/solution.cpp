#include <bits/stdc++.h> // Includes all standard libraries, as requested by the problem statement.

using namespace std; // Uses the standard namespace, as requested.

void solve() {
    int N, M;
    cin >> N >> M;

    // donut_counts stores the number of available donuts for each type.
    // We use a vector of size N+1 to easily handle 1-based indexing for donut types (1 to N).
    vector<int> donut_counts(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> donut_counts[i];
    }

    int sad_customers = 0; // Counter for customers who become sad.

    // Process each of the M customers sequentially.
    for (int i = 0; i < M; ++i) {
        int B_i; // The type of donut the current customer wants.
        cin >> B_i;

        // Check if there are any donuts of the desired type available.
        if (donut_counts[B_i] > 0) {
            // If available, the customer buys one, so decrement the count for that type.
            donut_counts[B_i]--;
        } else {
            // If not available, the customer becomes sad. Increment the sad_customers counter.
            sad_customers++;
        }
    }

    // Output the total number of sad customers for the current test case.
    cout << sad_customers << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases.
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop T times, once for each test case.
        solve(); // Call the solve function to handle each test case.
    }

    return 0; // Indicate successful execution.
}