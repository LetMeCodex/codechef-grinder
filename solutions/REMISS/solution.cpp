#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        // Minimum entries:
        // At least one guard is always awake.
        // If Chef entered X times, guard 1 counted A times and guard 2 counted B times.
        // The total number of entries must be at least the maximum of the two counts,
        // because the guard who counted more must have seen all those entries.
        long long min_entries = max(a, b);

        // Maximum entries:
        // The guards never fall asleep at the same time.
        // This means that for any entry, at least one guard counted it.
        // The total number of entries is the sum of entries counted by guard 1 and guard 2.
        // However, if an entry was counted by both guards, it's counted twice in the sum.
        // The problem states "At least one of them remains awake and counts who enters".
        // This implies that if Chef enters, at least one guard sees it.
        // The maximum number of entries occurs when there is no overlap in the entries
        // counted by the two guards. In this scenario, the total number of entries
        // is simply the sum of the counts from both guards.
        long long max_entries = a + b;

        cout << min_entries << " " << max_entries << "\n";
    }
    return 0;
}