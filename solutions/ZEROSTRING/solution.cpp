#include <bits/stdc++.h> // Required by problem statement

// Required by problem statement
using namespace std; 

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the length of the string
    string s;
    cin >> s; // Read the binary string

    int count_1 = 0;
    // Count the number of '1's in the string
    for (char c : s) {
        if (c == '1') {
            count_1++;
        }
    }

    // If there are no '1's, the string already consists of all '0's.
    // No operations are needed.
    if (count_1 == 0) {
        cout << 0 << "\n";
        return; // Done with this test case
    }

    // Strategy 1: Achieve the goal by only deleting '1's.
    // Each '1' must be deleted. Each deletion costs 1 operation.
    // So, the total cost for this strategy is simply the number of '1's.
    int cost_only_deletions = count_1;

    // Strategy 2: Achieve the goal by performing one flip operation,
    // and then deleting the '1's that result from the flip.
    //
    // Step 1: Perform a flip operation. This costs 1 operation.
    // After flipping, all original '0's become '1's, and all original '1's become '0's.
    //
    // Step 2: Delete the new '1's.
    // The number of original '0's is (n - count_1).
    // These original '0's are now '1's after the flip.
    // We need to delete all of them. This costs (n - count_1) operations.
    //
    // Total cost for this strategy: 1 (for flip) + (n - count_1) (for deletions).
    int count_0 = n - count_1;
    int cost_flip_then_delete = 1 + count_0;

    // The minimum number of operations is the minimum of the costs of these two strategies.
    cout << min(cost_only_deletions, cost_flip_then_delete) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large inputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}