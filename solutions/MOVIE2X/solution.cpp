#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The movie has a total duration of X minutes.
 * The first Y minutes are watched at 2x speed, meaning it takes Y/2 minutes to watch.
 * The remaining (X - Y) minutes are watched at 1x speed, meaning it takes (X - Y) minutes.
 * Total time = (Y / 2) + (X - Y).
 * 
 * Constraints:
 * 1 <= X, Y <= 1000
 * Y is even.
 * Time complexity: O(1) per test case.
 * Space complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice often involves multiple test cases.
    // Given the prompt asks to handle multiple test cases if applicable, 
    // we check if there's a test case count or just read the single line.
    // Based on the provided sample, it's a single input line.
    
    long long X, Y;
    if (cin >> X >> Y) {
        // Calculate time spent:
        // First Y minutes at 2x speed = Y / 2
        // Remaining X - Y minutes at 1x speed = X - Y
        long long total_time = (Y / 2) + (X - Y);
        
        cout << total_time << "\n";
    }

    return 0;
}