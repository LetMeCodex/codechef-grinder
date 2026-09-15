#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Lapindromes
 * Approach:
 * 1. Calculate the length of the string.
 * 2. Identify the two halves. If the length is odd, skip the middle character.
 * 3. Use frequency arrays (size 26 for lowercase English letters) to count 
 *    the occurrences of each character in both halves.
 * 4. Compare the two frequency arrays. If they are identical, it's a lapindrome.
 * 
 * Time Complexity: O(T * |S|), where |S| is the length of the string.
 * Space Complexity: O(1) as the frequency array size is constant (26).
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
    
    // First half
    for (int i = 0; i < n / 2; ++i) {
        freq1[s[i] - 'a']++;
    }
    
    // Second half
    // If n is odd, start from n/2 + 1, else start from n/2
    int start = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);
    for (int i = start; i < n; ++i) {
        freq2[s[i] - 'a']++;
    }
    
    bool isLapindrome = true;
    for (int i = 0; i < 26; ++i) {
        if (freq1[i] != freq2[i]) {
            isLapindrome = false;
            break;
        }
    }
    
    if (isLapindrome) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}