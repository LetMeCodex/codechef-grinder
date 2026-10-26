#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Using namespace std as requested
using namespace std;

void solve() {
    int N;
    long long M; // M can be up to 10^18, so use long long
    cin >> N >> M;

    vector<long long> P(N); // P_i can be up to 10^18, so use long long
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // Sort plates in descending order.
    // std::sort with reverse iterators (rbegin(), rend()) sorts in descending order.
    sort(P.rbegin(), P.rend());

    long long current_sum = 0; // Sum of meatballs collected so far
    int plates_count = 0;      // Number of plates taken

    // Iterate through the sorted plates, picking the largest ones first
    for (int i = 0; i < N; ++i) {
        current_sum += P[i];
        plates_count++;
        if (current_sum >= M) {
            // We have collected enough meatballs, so this is the minimum number of plates
            break; 
        }
    }

    // Check if we successfully reached M meatballs
    if (current_sum >= M) {
        cout << plates_count << "\n";
    } else {
        // Even after taking all N plates, we couldn't reach M
        cout << -1 << "\n";
    }
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}