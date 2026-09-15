#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice likes A if: (A % 2 == 0) AND (A % 7 == 0)
 * Bob likes A if: (A % 2 != 0) AND (A % 9 == 0)
 * Otherwise, Charlie takes it.
 * 
 * Constraints: 1 <= A <= 1000, T <= 100.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a;
        cin >> a;
        
        // Check Alice's condition: Even and multiple of 7
        if (a % 2 == 0 && a % 7 == 0) {
            cout << "Alice" << "\n";
        }
        // Check Bob's condition: Odd and multiple of 9
        else if (a % 2 != 0 && a % 9 == 0) {
            cout << "Bob" << "\n";
        }
        // Otherwise, Charlie
        else {
            cout << "Charlie" << "\n";
        }
    }
    
    return 0;
}