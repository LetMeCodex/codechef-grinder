#include <bits/stdc++.h>
using namespace std;

const int MAX_SUM = 2005; // Maximum possible sum of x, y, and potatoes from third field (1000 + 1000 + ~1000)
vector<bool> is_prime(MAX_SUM, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX_SUM; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX_SUM; i += p)
                is_prime[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int current_sum = x + y;
        int potatoes_needed = 1;
        while (true) {
            if (is_prime[current_sum + potatoes_needed]) {
                cout << potatoes_needed << "\n";
                break;
            }
            potatoes_needed++;
        }
    }

    return 0;
}