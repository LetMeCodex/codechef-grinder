#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We want to maximize N % A.
 * If we pick A = N/2 + 1, the remainder is N - (N/2 + 1) = (N-1)/2.
 * This is the largest possible remainder we can get for any N.
 * For N=2, N/2 + 1 = 2, 2 % 2 = 0 (Correct).
 * For N=5, 5/2 + 1 = 3, 5 % 3 = 2 (Correct).
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int N;
        cin >> N;
        
        // The optimal package size to maximize leftovers is N/2 + 1
        cout << (N / 2) + 1 << "\n";
    }

    return 0;
}