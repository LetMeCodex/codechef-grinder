#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement implies a single test case,
    // but the template mentions handling multiple test cases.
    // Based on typical competitive programming platforms and the problem's simplicity,
    // it's likely a single test case. If multiple were intended,
    // the input format would usually specify the number of test cases.
    // For this problem, we'll assume a single test case as per the input format.

    string s;
    cin >> s;

    if (s == "WECNITK") {
        cout << "Welcome to Web Club!\n";
    } else {
        cout << "Access denied\n";
    }

    return 0;
}