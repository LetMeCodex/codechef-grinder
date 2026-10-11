#include <bits/stdc++.h> // Includes iostream, cmath, etc.

// According to problem instructions, use 'using namespace std;'
using namespace std;

int main() {
    // Fast I/O as per problem instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        int X, Y; // Positions of Chef and Chefina
        cin >> X >> Y; // Read X and Y for the current test case

        // The problem asks to find an integer court position Z that minimizes
        // the maximum distance travelled by either Chef or Chefina.
        // This is equivalent to minimizing max(|X-Z|, |Y-Z|).
        //
        // The optimal court Z is the integer point closest to the midpoint of X and Y.
        // The minimum value of max(|X-Z|, |Y-Z|) will be ceil(|X-Y| / 2).
        //
        // For positive integers A and B, ceil(A/B) can be calculated using
        // integer division as (A + B - 1) / B.
        // In this problem, A = |X-Y| and B = 2.
        // So, the formula becomes (|X-Y| + 2 - 1) / 2, which simplifies to (|X-Y| + 1) / 2.
        //
        // Constraints: 1 <= X, Y <= 1000 and X != Y.
        // This guarantees that |X-Y| is always at least 1, so the formula is valid.

        int diff = abs(X - Y); // Calculate the absolute difference between X and Y
        int result = (diff + 1) / 2; // Apply the formula to get ceil(diff / 2)

        cout << result << "\n"; // Output the calculated minimum maximum distance
    }

    return 0; // Indicate successful execution
}