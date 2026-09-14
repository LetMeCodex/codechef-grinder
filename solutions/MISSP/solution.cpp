#include <iostream>
#include <vector>

/**
 * Problem Analysis:
 * We are given N dolls, where every type of doll appears in pairs except for one.
 * We need to find the type of the doll that does not have a pair.
 * 
 * Mathematical Property:
 * The XOR operation (^) has the following properties:
 * 1. a ^ a = 0
 * 2. a ^ 0 = a
 * 3. XOR is commutative and associative.
 * 
 * If we XOR all the doll types together, all pairs will cancel each other out (x ^ x = 0),
 * leaving only the doll type that appears an odd number of times.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) as we only need to store the running XOR sum.
 */

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        if (!(cin >> n)) break;
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int doll_type;
            cin >> doll_type;
            // XORing all inputs will leave the single element
            result ^= doll_type;
        }
        
        cout << result << "\n";
    }
    
    return 0;
}