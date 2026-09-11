#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total students = X * Y
 * Passed students = Z
 * Condition: Z > 50% of (X * Y)
 * Mathematically: Z > (X * Y) / 2
 * To avoid floating point issues, we can multiply both sides by 2:
 * 2 * Z > X * Y
 * 
 * Constraints:
 * X <= 5, Y <= 50, Z <= X*Y
 * Max value of X*Y is 250, so standard 'int' is sufficient.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        long long total_students = x * y;
        
        // We need to check if z / total_students > 0.5
        // Which is equivalent to 2 * z > total_students
        if (2 * z > total_students) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}