#include <bits/stdc++.h> 

// Using namespace std; as per instructions
using namespace std;

int main() {
    // Fast I/O as per instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC; // Number of test cases
    cin >> TC;
    while (TC--) {
        int N; // Number of usage periods
        int K; // Free minutes
        cin >> N >> K;

        int total_cost = 0; // Total amount Chef has to pay.
                            // Max cost: N * Ti * Di = 10 * 10 * 10 = 1000. Fits comfortably in an int.

        for (int i = 0; i < N; ++i) {
            int Ti, Di; // Minutes and MBs per minute for current period
            cin >> Ti >> Di;

            if (K > 0) {
                // If there are still free minutes left
                if (Ti <= K) {
                    // Current period is entirely covered by free minutes
                    K -= Ti;
                    // No cost for this period, total_cost remains unchanged
                } else {
                    // Current period is partially covered by free minutes
                    // The first 'K' minutes are free.
                    // The remaining 'Ti - K' minutes are paid.
                    total_cost += (Ti - K) * Di;
                    K = 0; // All free minutes are now used up
                }
            } else {
                // No free minutes left, all minutes are paid
                total_cost += Ti * Di;
            }
        }
        cout << total_cost << "\n"; // Output total cost for the test case
    }

    return 0;
}