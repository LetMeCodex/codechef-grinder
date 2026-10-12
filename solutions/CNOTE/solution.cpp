#include <bits/stdc++.h> // Includes common C++ headers, as requested by the problem statement

// Using namespace std; is common in competitive programming and requested by the problem statement
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop through each test case
        int X, Y, K, N;
        cin >> X >> Y >> K >> N; // Read poetry length, current pages, budget, and number of notebooks

        // Calculate the minimum number of additional pages Chef needs from a new notebook.
        // If Chef already has enough pages (Y >= X), he needs 0 additional pages.
        // Otherwise, he needs X - Y pages.
        int pages_needed = max(0, X - Y);

        bool found_suitable_notebook = false; // Flag to track if a suitable notebook is found

        // Iterate through all N notebooks available in the shop
        for (int i = 0; i < N; ++i) {
            int Pi, Ci;
            cin >> Pi >> Ci; // Read pages (Pi) and price (Ci) of the current notebook

            // Check if the current notebook meets both criteria:
            // 1. Its price (Ci) does not exceed Chef's budget (K).
            // 2. It provides enough pages (Pi) to cover the 'pages_needed'.
            if (Ci <= K && Pi >= pages_needed) {
                found_suitable_notebook = true; // Mark that a suitable notebook has been found
                // We don't break here because we still need to consume the remaining input
                // for this test case to ensure correct parsing for subsequent test cases.
                // The loop will continue, but 'found_suitable_notebook' will remain true.
            }
        }

        // After checking all notebooks, print the result based on the flag
        if (found_suitable_notebook) {
            cout << "LuckyChef\n";
        } else {
            cout << "UnluckyChef\n";
        }
    }

    return 0; // Indicate successful execution
}