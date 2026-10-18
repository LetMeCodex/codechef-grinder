#include <bits/stdc++.h> 

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can also speed up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables L and R to store the input range.
    int L, R;
    
    // Read the two integers L and R from standard input.
    cin >> L >> R;

    // The problem asks if there is any even integer in the range [L, R].
    // An integer X is even if X % 2 == 0.
    //
    // An even number exists in the range if:
    // 1. L itself is even (L % 2 == 0).
    //    OR
    // 2. L is odd, but the range includes at least one number after L (i.e., L < R).
    //    In this case, L+1 would be in the range. Since L is odd, L+1 is always even.
    //
    // The only scenario where no even number exists is if L is odd AND L == R.
    // This means the range contains only L, which is odd.
    if (L % 2 == 0 || L < R) {
        // If the condition is true, print "Yes" followed by a newline.
        cout << "Yes\n";
    } else {
        // Otherwise (L is odd AND L == R), print "No" followed by a newline.
        cout << "No\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}