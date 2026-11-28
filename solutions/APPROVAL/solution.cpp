#include <bits/stdc++.h> // Includes iostream, vector, numeric, algorithm, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    vector<int> A(5);
    int current_sum = 0; // int is sufficient for sum (max 5*10=50)
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
        current_sum += A[i];
    }

    // If initial sum is already 35 or more, no bribes needed.
    if (current_sum >= 35) {
        cout << 0 << "\n";
        return;
    }

    // Sort scores in ascending order.
    // To minimize bribes, we should always bribe the judge with the lowest current score first.
    sort(A.begin(), A.end());

    int bribes_count = 0;
    // Iterate through the sorted scores, simulating bribing judges one by one
    // starting from the lowest score.
    for (int i = 0; i < 5; ++i) {
        // If current_sum is already 35 or more, we have achieved the target.
        // No more bribes are needed.
        if (current_sum >= 35) {
            break;
        }
        
        // Bribe the judge with the current lowest score (A[i]).
        // Their score changes from A[i] to 10.
        // The total sum increases by (10 - A[i]).
        current_sum = current_sum - A[i] + 10;
        bribes_count++;
    }

    // Output the total gold coins needed. Each bribe costs 100 gold coins.
    cout << bribes_count * 100 << "\n";
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