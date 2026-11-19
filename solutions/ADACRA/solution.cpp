#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.
using namespace std; // As requested by critical instructions

void solve() {
    string s;
    cin >> s;
    
    int n = s.length();
    
    // num_D_blocks counts contiguous segments of 'D's.
    // To make all crayons 'U', we need to flip each 'D' segment once.
    // So, num_D_blocks is the minimum flips needed to make all 'U'.
    int num_D_blocks = 0; 

    // num_U_blocks counts contiguous segments of 'U's.
    // To make all crayons 'D', we need to flip each 'U' segment once.
    // So, num_U_blocks is the minimum flips needed to make all 'D'.
    int num_U_blocks = 0; 
    
    // N >= 1 due to constraints.
    // Initialize counts based on the first character.
    // The first character always starts a block.
    if (s[0] == 'D') {
        num_D_blocks = 1;
    } else { // s[0] == 'U'
        num_U_blocks = 1;
    }
    
    // Iterate from the second character to count subsequent blocks.
    // A new block starts whenever the current character is different from the previous one.
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) { // A change in character means a new block starts
            if (s[i] == 'D') {
                num_D_blocks++;
            } else { // s[i] == 'U'
                num_U_blocks++;
            }
        }
    }
    
    // The minimum flips is the smaller of the two counts.
    cout << min(num_D_blocks, num_U_blocks) << "\n";
}

int main() {
    // Fast I/O setup as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; // Read the number of test cases.
    while (t--) { // Loop through each test case.
        solve();
    }
    
    return 0;
}