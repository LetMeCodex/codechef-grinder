#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use the standard namespace

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count0 = 0;
    int count1 = 0;
    for (char c : s) {
        if (c == '0') {
            count0++;
        } else {
            count1++;
        }
    }

    // We want to form a palindrome consisting of only '0's or only '1's.
    // This is always possible within the given deletion constraints.
    // The strategy is to keep the character type that appears more frequently (or equally frequently).

    if (count0 >= count1) {
        // If there are more or an equal number of '0's than '1's,
        // we can form a palindrome consisting only of '0's.
        // The number of '0's to keep is `count0`.
        // The number of '1's to delete is `count1`.
        // The constraint is that we can delete at most floor(N/2) characters.
        // Since `count0 + count1 = N` and `count0 >= count1`,
        // it implies `2 * count1 <= N`, so `count1 <= N/2`.
        // Thus, `count1 <= floor(N/2)` is always true, meaning this is a valid operation.
        for (int i = 0; i < count0; ++i) {
            cout << '0';
        }
        cout << "\n";
    } else {
        // If there are more '1's than '0's,
        // we can form a palindrome consisting only of '1's.
        // The number of '1's to keep is `count1`.
        // The number of '0's to delete is `count0`.
        // The constraint is that we can delete at most floor(N/2) characters.
        // Since `count0 + count1 = N` and `count1 > count0`,
        // it implies `2 * count0 < N`, so `count0 < N/2`.
        // Thus, `count0 <= floor(N/2)` is always true, meaning this is a valid operation.
        for (int i = 0; i < count1; ++i) {
            cout << '1';
        }
        cout << "\n";
    }
}

int main() {
    // Fast I/O setup as per problem instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();
    }

    return 0;
}