#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Total CRED coins earned = coins per bill * number of bills
        long long total_coins = x * y;

        // Each bag costs 100 CRED coins.
        // To find the maximum number of bags, we divide the total coins by 100
        // and take the integer part (floor division).
        long long max_bags = total_coins / 100;

        cout << max_bags << "\n";
    }

    return 0;
}