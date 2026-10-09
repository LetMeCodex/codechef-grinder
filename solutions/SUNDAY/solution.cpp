#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; as requested by problem instructions
using namespace std;

void solve() {
    int N;
    cin >> N;

    // Use a boolean vector to mark holidays.
    // Size 31 to use 1-based indexing for days 1 to 30.
    vector<bool> is_holiday(31, false);

    // Mark all Saturdays and Sundays as holidays.
    // Day 1 is Monday.
    // The day of the week can be determined by (day - 1) % 7.
    // 0: Monday
    // 1: Tuesday
    // 2: Wednesday
    // 3: Thursday
    // 4: Friday
    // 5: Saturday
    // 6: Sunday
    for (int day = 1; day <= 30; ++day) {
        int day_of_week_idx = (day - 1) % 7;
        if (day_of_week_idx == 5 || day_of_week_idx == 6) { // 5 is Saturday, 6 is Sunday
            is_holiday[day] = true;
        }
    }

    // Mark festival days as holidays.
    for (int i = 0; i < N; ++i) {
        int festival_day;
        cin >> festival_day;
        is_holiday[festival_day] = true;
    }

    // Count total unique holidays.
    int total_holidays = 0;
    for (int day = 1; day <= 30; ++day) {
        if (is_holiday[day]) {
            total_holidays++;
        }
    }

    cout << total_holidays << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}