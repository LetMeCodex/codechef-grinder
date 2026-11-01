#include <bits/stdc++.h> 
using namespace std;

void solve() {
    int N;
    cin >> N;
    int count_odd = 0;
    int count_even = 0;
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;
        if (A_i % 2 == 0) {
            count_even++;
        } else {
            count_odd++;
        }
    }

    if (count_odd == 0) {
        // If there are no odd numbers, all elements are even.
        // Any sum of even numbers is even. So all prefix sums will be even.
        // Thus, 0 odd prefix sums.
        cout << 0 << "\n";
    } else {
        // If there is at least one odd number:
        // Optimal strategy:
        // 1. Place one odd number first (P_1 will be odd).
        // 2. Place all 'count_even' even numbers next (P_i remains odd).
        // 3. Place the remaining (count_odd - 1) odd numbers.
        //    Each remaining odd number flips the parity. Since the sum
        //    was odd before these, the sequence of parities will be
        //    Even, Odd, Even, Odd, ...
        //    The number of odd sums in this sequence of (count_odd - 1) elements
        //    is floor((count_odd - 1) / 2).
        // Total maximum odd prefix sums = (1 + count_even) + floor((count_odd - 1) / 2).
        cout << (1 + count_even + (count_odd - 1) / 2) << "\n";
    }
}

int main() {
    // Fast I/O to speed up competitive programming solutions.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}