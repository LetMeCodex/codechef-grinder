#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have G girls and B boys, where B > G.
 * Each team consists of exactly 1 girl and 1 boy.
 * To maximize the number of teams, we pair each girl with one boy.
 * Since there are G girls, we can form at most G teams.
 * Each team uses 1 boy, so G boys are used.
 * The number of boys remaining is B - G.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long g, b;
        cin >> g >> b;
        
        // The number of boys left over is simply the difference
        // between the total number of boys and the number of girls.
        long long result = b - g;
        
        cout << result << "\n";
    }
    
    return 0;
}