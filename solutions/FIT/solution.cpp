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
        // Chef walks X km to the office and X km back home.
        // So, daily travel is 2 * X km.
        // The office is open 5 days a week.
        // Total weekly travel = (2 * X) * 5
        long long total_distance = (long long)2 * x * 5;
        cout << total_distance << "\n";
    }
    return 0;
}