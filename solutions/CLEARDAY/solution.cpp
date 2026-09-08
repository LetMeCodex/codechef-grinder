#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    // A week has 7 days.
    // The total number of days in a week is 7.
    // The number of rainy days is X.
    // The number of cloudy days is Y.
    // The number of clear days is the total days minus rainy days and cloudy days.
    // clear_days = 7 - X - Y

    int clear_days = 7 - x - y;
    cout << clear_days << "\n";

    return 0;
}