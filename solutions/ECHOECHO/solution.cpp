#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement implies a single test case, but the template
    // suggests handling multiple test cases. Based on typical CodeChef
    // problem structures and the absence of a 't' in the sample input,
    // we'll assume a single test case for this specific problem.
    // If multiple test cases were intended, a loop like `int t; cin >> t; while(t--)`
    // would be used.

    string s;
    cin >> s;

    // An echo string of length 4 has S1 = S3 and S2 = S4.
    // In 0-based indexing, this translates to s[0] == s[2] and s[1] == s[3].
    if (s.length() == 4 && s[0] == s[2] && s[1] == s[3]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}