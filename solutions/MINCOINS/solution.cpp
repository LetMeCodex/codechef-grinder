#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        // If x is not divisible by 5, it's impossible to form it using denominations 5 and 10.
        if (x % 5 != 0) {
            cout << -1 << "\n";
        } else {
            // To minimize the number of coins, we should prioritize using coins of denomination 10.
            // Let num_10 be the number of 10 rupee coins and num_5 be the number of 5 rupee coins.
            // We want to minimize num_10 + num_5 such that 10 * num_10 + 5 * num_5 = x.

            // We can express num_5 in terms of num_10:
            // 5 * num_5 = x - 10 * num_10
            // num_5 = (x - 10 * num_10) / 5

            // For num_5 to be a non-negative integer, (x - 10 * num_10) must be non-negative and divisible by 5.
            // Since x is already divisible by 5, and 10 * num_10 is always divisible by 5,
            // (x - 10 * num_10) will always be divisible by 5.
            // We only need to ensure x - 10 * num_10 >= 0, which means 10 * num_10 <= x.
            // So, num_10 <= x / 10.

            // To minimize num_10 + num_5, we want to maximize num_10.
            // The maximum possible value for num_10 is x / 10 (integer division).
            int num_10 = x / 10;
            int remaining_amount = x - (num_10 * 10);

            // The remaining amount must be paid using 5 rupee coins.
            // Since x is divisible by 5 and we used as many 10s as possible,
            // the remaining_amount will be either 0 or 5.
            // If remaining_amount is 0, we need 0 coins of 5.
            // If remaining_amount is 5, we need 1 coin of 5.
            int num_5 = remaining_amount / 5;

            cout << num_10 + num_5 << "\n";
        }
    }
    return 0;
}