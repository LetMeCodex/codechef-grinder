#include <bits/stdc++.h> // Includes iostream, string, algorithm etc.

// Using namespace std; as per problem instructions
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count0 = 0;
    int count1 = 0;

    // Count the occurrences of '0' and '1' in the string S
    for (char c : s) {
        if (c == '0') {
            count0++;
        } else { // c must be '1'
            count1++;
        }
    }

    // The maximum length of an alternating string can be formed by
    // pairing up as many '0's and '1's as possible.
    // Each pair (01 or 10) contributes 2 to the length.
    // The number of such pairs is min(count0, count1).
    // So, an initial alternating string of length 2 * min(count0, count1) can be formed.
    int result = 2 * min(count0, count1);

    // If the counts of '0's and '1's are not equal, it means there are
    // some characters of the majority type left over. We can append exactly
    // one of these leftover characters to the alternating string to extend
    // its length by 1, while still maintaining the alternating property.
    // For example, if we have "0101" and a '0' left, we can make "01010".
    // We cannot append more than one character without breaking the alternating property.
    if (count0 != count1) {
        result += 1;
    }
    
    cout << result << "\n";
}

int main() {
    // Fast I/O as per problem instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}