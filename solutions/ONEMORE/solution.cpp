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
        // An episode is 24 minutes long.
        // Chef finishes strictly before the exam starts if the available time X
        // is strictly greater than the episode duration (24 minutes).
        if (x > 24) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}