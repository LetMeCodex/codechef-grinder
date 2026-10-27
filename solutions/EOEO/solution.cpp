#include <bits/stdc++.h> // As requested by the problem statement

using namespace std; // As requested by the problem statement

void solve() {
    long long TS;
    cin >> TS;

    if (TS % 2 != 0) { // TS is odd
        // If TS is odd, Jerry wins if JS is even.
        // We need 1 <= JS <= TS.
        // The even values for JS are 2, 4, 6, ..., (TS - 1) (since TS is odd, TS-1 is even).
        // The count of these values is (TS - 1) / 2.
        cout << (TS - 1) / 2 << "\n";
    } else { // TS is even
        // If TS is even, let TS = 2^p * TS_odd, where TS_odd is an odd number.
        // Jerry wins if JS = 2^q * JS_odd, where JS_odd is an odd number, AND q > p.
        // This means JS must be a multiple of 2^(p+1).

        // Step 1: Find p, the number of factors of 2 in TS.
        long long temp_TS = TS;
        int p = 0;
        while (temp_TS % 2 == 0) { // TS >= 1, so temp_TS will be positive until it becomes odd.
            temp_TS /= 2;
            p++;
        }

        // Step 2: Calculate the target divisor, which is 2^(p+1).
        // We use 1LL to ensure the shift operation is performed on a long long,
        // preventing overflow if p+1 is large (e.g., > 30 for int).
        long long target_divisor = 1LL << (p + 1);

        // Step 3: Count the number of multiples of target_divisor that are <= TS.
        // These are 1 * target_divisor, 2 * target_divisor, ..., k * target_divisor.
        // The largest k satisfies k * target_divisor <= TS, so k <= TS / target_divisor.
        // Since k must be a positive integer, the number of possible values for k is floor(TS / target_divisor).
        // Integer division in C++ automatically performs floor for positive numbers.
        cout << TS / target_divisor << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve();
    }

    return 0;
}