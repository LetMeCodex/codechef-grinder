#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int activities_count;
        string origin;
        cin >> activities_count >> origin;

        long long total_laddus = 0;
        int redemption_limit = (origin == "INDIAN") ? 200 : 400;

        for (int i = 0; i < activities_count; ++i) {
            string activity_type;
            cin >> activity_type;

            if (activity_type == "CONTEST_WON") {
                int rank;
                cin >> rank;
                long long bonus = max(0, 20 - rank);
                total_laddus += 300 + bonus;
            } else if (activity_type == "TOP_CONTRIBUTOR") {
                total_laddus += 300;
            } else if (activity_type == "BUG_FOUND") {
                int severity;
                cin >> severity;
                total_laddus += severity;
            } else if (activity_type == "CONTEST_HOSTED") {
                total_laddus += 50;
            }
        }

        cout << total_laddus / redemption_limit << "\n";
    }

    return 0;
}