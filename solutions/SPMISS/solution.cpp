#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    long long C; // Using long long for C and sums to be safe, though int is sufficient given constraints.
    cin >> N >> C;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    string S;
    cin >> S;

    long long sum_non_special = 0;
    long long sum_all_missions = 0;

    // Calculate sum of all mission rewards and sum of non-special mission rewards
    for (int i = 0; i < N; ++i) {
        sum_all_missions += A[i];
        if (S[i] == '0') { // If it's a non-special mission
            sum_non_special += A[i];
        }
    }

    // Scenario 1: Do not pay the wizard fee.
    // In this case, we can only complete non-special missions.
    // The maximum coins obtained is the sum of rewards from all non-special missions.
    long long max_coins = sum_non_special;

    // Scenario 2: Consider paying the wizard fee.
    // To pay the fee, we must have at least C coins.
    // The best way to accumulate coins before paying the fee is by completing all non-special missions.
    if (sum_non_special >= C) {
        // If we have enough coins from non-special missions, we can pay the fee.
        // After paying, we can complete all missions (both non-special and special).
        // The total coins would be (sum of all A_i) - C.
        // We take the maximum between this and not paying the fee.
        max_coins = max(max_coins, sum_all_missions - C);
    }
    
    // Output the maximum coins obtainable for the current test case.
    cout << max_coins << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}