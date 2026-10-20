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

        // The ratio of orange syrup to water must be 1:2.
        // This means for every 1 unit of syrup, we need 2 units of water.
        // Let 's' be the amount of syrup used and 'w' be the amount of water used.
        // We must have w = 2 * s.
        // Also, s <= A and w <= B.
        // Substituting w = 2*s into w <= B, we get 2*s <= B, which means s <= B/2.
        // So, the amount of syrup we can use, 's', must satisfy:
        // s <= A (we have enough syrup)
        // s <= B/2 (we have enough water for the syrup)
        // To maximize the total juice (s + w = s + 2*s = 3*s), we need to maximize 's'.
        // The maximum possible integer value for 's' is min(A, B/2).

        long long max_syrup_to_use = min(a, b / 2);

        // The total juice made is syrup used + water used.
        // If we use 'max_syrup_to_use' units of syrup, we will use 2 * 'max_syrup_to_use' units of water.
        // Total juice = max_syrup_to_use + 2 * max_syrup_to_use = 3 * max_syrup_to_use.
        long long total_juice = 3 * max_syrup_to_use;

        cout << total_juice << "\n";
    }
    return 0;
}