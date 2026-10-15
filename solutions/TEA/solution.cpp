#include <bits/stdc++.h> // Includes most standard libraries for competitive programming

// Using the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y, Z; // X: total tea Chef needs, Y: jar capacity, Z: cost per refill
        cin >> X >> Y >> Z; // Read X, Y, and Z for the current test case

        // Calculate the minimum number of refills needed.
        // Chef needs X liters of tea. Each refill provides Y liters.
        // The number of refills must be sufficient to cover X liters.
        // This is a classic ceiling division problem: ceil(X / Y).
        // In integer arithmetic, for positive integers A and B, ceil(A / B) can be
        // calculated as (A + B - 1) / B.
        int num_refills = (X + Y - 1) / Y;

        // The total cost is the number of refills multiplied by the cost per refill (Z).
        // X, Y, Z are up to 100.
        // Maximum num_refills would be (100 + 1 - 1) / 1 = 100 (if X=100, Y=1).
        // Maximum total_cost would be 100 * 100 = 10000.
        // An 'int' type is sufficient for this range, but using 'long long'
        // is a good practice in competitive programming to prevent potential
        // integer overflow in similar problems with larger constraints,
        // as advised by the critical instructions.
        long long total_cost = (long long)num_refills * Z;

        // Output the calculated minimum total cost for the current test case,
        // followed by a newline character.
        cout << total_cost << "\n";
    }

    return 0; // Indicate successful program execution
}