#include <bits/stdc++.h> 

// It's common practice in competitive programming to use the entire std namespace.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a standard competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        int X, Y; // Variables to store the costs for 2 packets (X) and 4 packets (Y).
        cin >> X >> Y; // Read X and Y for the current test case.

        // Chef needs to buy a total of 10 packets.
        // There are two ways to buy packets:
        // 1. 2 packets for X rupees.
        // 2. 4 packets for Y rupees.

        // Let n2 be the number of 2-packet bundles and n4 be the number of 4-packet bundles.
        // The total number of packets must be 10:
        // 2 * n2 + 4 * n4 = 10

        // We need to find non-negative integer solutions for (n2, n4) and calculate the cost:
        // Cost = n2 * X + n4 * Y

        // Let's list the possible combinations for (n2, n4):
        // Case 1: n4 = 0
        //   2 * n2 + 4 * 0 = 10  =>  2 * n2 = 10  =>  n2 = 5
        //   Cost1 = 5 * X

        // Case 2: n4 = 1
        //   2 * n2 + 4 * 1 = 10  =>  2 * n2 = 6   =>  n2 = 3
        //   Cost2 = 3 * X + 1 * Y

        // Case 3: n4 = 2
        //   2 * n2 + 4 * 2 = 10  =>  2 * n2 = 2   =>  n2 = 1
        //   Cost3 = 1 * X + 2 * Y

        // Case 4: n4 = 3
        //   2 * n2 + 4 * 3 = 10  =>  2 * n2 = -2  =>  n2 = -1 (not possible, n2 must be non-negative)

        // So, there are only three valid ways to buy 10 packets:
        // 1. Five 2-packet bundles: Cost = 5X
        // 2. Three 2-packet bundles and one 4-packet bundle: Cost = 3X + Y
        // 3. One 2-packet bundle and two 4-packet bundles: Cost = X + 2Y

        // We are given the constraint: X < Y <= 2 * X.
        // This constraint is crucial for determining the minimum cost.
        // It implies that buying a 4-packet bundle for Y rupees is always at least as cost-effective
        // as buying two 2-packet bundles for 2X rupees (since Y <= 2X).

        // Let's compare the three costs using this constraint:
        // Comparison 1: 5X vs (3X + Y)
        //   Difference = 5X - (3X + Y) = 2X - Y
        //   Since Y <= 2X, it means 2X - Y >= 0.
        //   Therefore, 5X >= 3X + Y. This means (3X + Y) is always less than or equal to 5X.

        // Comparison 2: (3X + Y) vs (X + 2Y)
        //   Difference = (3X + Y) - (X + 2Y) = 2X - Y
        //   Again, since Y <= 2X, it means 2X - Y >= 0.
        //   Therefore, 3X + Y >= X + 2Y. This means (X + 2Y) is always less than or equal to (3X + Y).

        // Combining these comparisons, we get:
        // X + 2Y <= 3X + Y <= 5X

        // This shows that the minimum cost is always X + 2Y.

        int min_cost = X + 2 * Y;

        // Output the minimum cost for the current test case, followed by a newline.
        cout << min_cost << "\n";
    }

    return 0; // Indicate successful execution.
}