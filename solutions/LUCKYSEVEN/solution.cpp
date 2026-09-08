#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LUCKYSEVEN
 * The problem asks for the 7th character of a string S of length 10.
 * In C++, strings are 0-indexed, so the 7th character is at index 6.
 * Time Complexity: O(1) per test case (string length is fixed at 10).
 * Space Complexity: O(1) to store the string.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single string input per execution 
    // based on the sample cases, but we structure it to handle the input string.
    string s;
    if (cin >> s) {
        // The 7th character is at index 6 (0-indexed)
        cout << s[6] << "\n";
    }

    return 0;
}