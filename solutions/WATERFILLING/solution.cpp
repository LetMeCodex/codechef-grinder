#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three integers B1, B2, B3 representing the state of three bottles.
 * 0 = empty, 1 = full.
 * Condition for "Water filling time": At least two bottles are empty.
 * This means the count of zeros must be >= 2.
 * Equivalently, the sum of B1, B2, and B3 must be <= 1 (since 0+0+1 = 1, 0+0+0 = 0).
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few integer variables.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int b1, b2, b3;
        cin >> b1 >> b2 >> b3;
        
        // Count how many bottles are empty (value is 0)
        int empty_count = 0;
        if (b1 == 0) empty_count++;
        if (b2 == 0) empty_count++;
        if (b3 == 0) empty_count++;
        
        // If at least two are empty, it's water filling time
        if (empty_count >= 2) {
            cout << "Water filling time" << "\n";
        } else {
            cout << "Not now" << "\n";
        }
    }
    
    return 0;
}