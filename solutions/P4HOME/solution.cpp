#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; is requested by the problem statement.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for problems with large number of test cases.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) {
        int x, y, z;
        cin >> x >> y >> z; // Read Chef's position (x), friend range (y), and travel limit (z)

        // The friends live at integer points in [x-y, x+y] excluding x.
        // Chef can travel to integer points in [x-z, x+z].

        // We need to find the number of friends that are in both ranges,
        // and are not at Chef's home (x).

        // The effective range of friends Chef can visit is the intersection of
        // [x-y, x+y] and [x-z, x+z].
        // This intersection simplifies to [x - min(y, z), x + min(y, z)].
        // Let k = min(y, z). The range is [x-k, x+k].

        // The number of integer points in the range [x-k, x+k] is (x+k) - (x-k) + 1 = 2k + 1.
        // Since friends do not live at Chef's home (x), and x is always included
        // in the range [x-k, x+k] (because k >= 0), we must subtract 1 from this count.
        // So, the number of friends Chef can visit is (2k + 1) - 1 = 2k.

        int k = min(y, z); // Calculate k = min(y, z)
        int num_friends = 2 * k; // Apply the formula 2k

        cout << num_friends << "\n"; // Print the result for the current test case
    }

    return 0; // Indicate successful execution
}