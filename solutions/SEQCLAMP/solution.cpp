#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

using namespace std; // Use the standard namespace as requested

void solve() {
    int N;
    cin >> N; // Read the number of pairs

    // Initialize current_max_Y to a value that effectively represents positive infinity
    // for the given constraints. The maximum B_i is 100.
    // Any value >= 100 will work for the first step's min(current_max_Y, B) operation
    // as it will always be greater than or equal to B.
    // A safe choice is 101, or even INT_MAX from <limits> for general cases.
    // Given the constraints (B_i <= 100), 101 is perfectly fine and clear.
    int current_max_Y = 101; 

    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B; // Read the i-th pair (A_i, B_i)

        // Apply the clamping rule: Y = max(A_i, min(Y, B_i))
        // This updates current_max_Y to reflect the maximum possible value
        // after processing the current pair, assuming Y started at infinity.
        current_max_Y = max(A, min(current_max_Y, B));
    }

    // After processing all N pairs, current_max_Y holds the maximum possible
    // value of f(X) across all possible input integers X.
    cout << current_max_Y << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}