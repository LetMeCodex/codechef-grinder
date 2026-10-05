#include <bits/stdc++.h> // Required include as per instructions

// Required using namespace std; as per instructions
using namespace std;

int main() {
    // Fast I/O as per instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, M;
        cin >> N >> M; // Read online cost N and restaurant cost M

        // Calculate the final online cost after 10% discount.
        // The discount is 10% of N, so the final cost is N - (N * 10 / 100) = N - N/10.
        // This simplifies to (10N - N) / 10 = 9N / 10.
        //
        // To avoid potential floating-point arithmetic issues and ensure exact comparison,
        // we compare the costs by multiplying both sides of the inequality by 10.
        //
        // Original comparison: (9 * N) / 10 vs M
        // Equivalent integer comparison: 9 * N vs 10 * M
        //
        // Constraints: 1 <= N, M <= 1000.
        // Maximum value for 9 * N is 9 * 1000 = 9000.
        // Maximum value for 10 * M is 10 * 1000 = 10000.
        // Both these values fit comfortably within a standard 'int' type,
        // so 'long long' is not strictly necessary for this problem.

        int online_cost_after_discount_multiplied_by_10 = 9 * N;
        int restaurant_cost_multiplied_by_10 = 10 * M;

        if (online_cost_after_discount_multiplied_by_10 < restaurant_cost_multiplied_by_10) {
            cout << "ONLINE\n"; // Online option is cheaper
        } else if (online_cost_after_discount_multiplied_by_10 > restaurant_cost_multiplied_by_10) {
            cout << "DINING\n"; // Restaurant option is cheaper
        } else { // online_cost_after_discount_multiplied_by_10 == restaurant_cost_multiplied_by_10
            cout << "EITHER\n"; // Both options cost the same
        }
    }

    return 0;
}