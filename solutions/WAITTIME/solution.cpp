#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int k, x;
        cin >> k >> x;
        // Total days to wait is k weeks, which is k * 7 days.
        // Chef has already waited x days.
        // Remaining days = Total days - Days already waited.
        int total_days = k * 7;
        int remaining_days = total_days - x;
        cout << remaining_days << "\n";
    }
    return 0;
}