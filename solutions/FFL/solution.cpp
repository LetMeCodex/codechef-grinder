#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;     // Uses the standard namespace for convenience

void solve() {
    int N, S;
    cin >> N >> S;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // Initialize min prices to a value greater than any possible player price (max P_i is 100).
    // This value (101) serves two purposes:
    // 1. It's an initial maximum for finding the minimum price.
    // 2. If no player of a certain type is found, its price will remain 101.
    //    The sum of prices will then be high enough to exceed the maximum possible remaining budget (100 - 13 = 87),
    //    correctly indicating that it's impossible to complete the team.
    int min_defender_price = 101; 
    int min_forward_price = 101;

    // Read player types and update minimum prices for defenders and forwards.
    // The i-th price P[i] corresponds to the i-th player type.
    for (int i = 0; i < N; ++i) {
        int player_type;
        cin >> player_type;
        if (player_type == 0) { // Defender
            min_defender_price = min(min_defender_price, P[i]);
        } else { // Forward (player_type == 1)
            min_forward_price = min(min_forward_price, P[i]);
        }
    }

    // Calculate the remaining budget Chef has for the two new players.
    int remaining_budget = 100 - S;

    // Check if the sum of the cheapest defender and cheapest forward
    // is within the remaining budget.
    // This condition implicitly handles cases where no defender or no forward was found
    // because their respective min_price would still be 101, making the sum too high.
    if (min_defender_price + min_forward_price <= remaining_budget) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}