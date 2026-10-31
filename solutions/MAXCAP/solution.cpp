#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        // Maximum capacity of the lift in kilograms
        const int MAX_WEIGHT_CAPACITY = 500;
        // Maximum number of people allowed in the lift
        const int MAX_PEOPLE_CAPACITY = 8;

        // Check if the number of friends exceeds the maximum people capacity
        if (x > MAX_PEOPLE_CAPACITY) {
            cout << "NO\n";
        } else {
            // Calculate the total weight of all friends
            long long total_weight = (long long)x * y;

            // Check if the total weight exceeds the maximum weight capacity
            if (total_weight > MAX_WEIGHT_CAPACITY) {
                cout << "NO\n";
            } else {
                // If both conditions are met, all friends can use the lift
                cout << "YES\n";
            }
        }
    }

    return 0;
}