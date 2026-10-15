#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

// It's common practice in competitive programming to use the entire std namespace.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the input values:
    // B for bread pieces, H for ham pieces, C for cheese pieces.
    int B, H, C;

    // Read the three integers from standard input.
    cin >> B >> H >> C;

    // Calculate the maximum number of sandwiches that can be made based on the
    // available bread. Each sandwich requires 2 pieces of bread.
    // Integer division (B / 2) correctly handles cases where B is odd,
    // as any leftover single piece of bread cannot form a sandwich.
    int max_sandwiches_from_bread = B / 2;

    // Calculate the maximum number of sandwiches that can be made based on the
    // available fillings (ham or cheese). Each sandwich requires 1 piece of
    // either ham or cheese. The total available fillings are H + C.
    int max_sandwiches_from_fillings = H + C;

    // The total number of sandwiches Chef can make is limited by whichever
    // resource (bread or fillings) runs out first. Therefore, the maximum
    // number of sandwiches is the minimum of the two limits calculated above.
    int result = min(max_sandwiches_from_bread, max_sandwiches_from_fillings);

    // Print the calculated maximum number of sandwiches to standard output,
    // followed by a newline character.
    cout << result << "\n";

    // Return 0 to indicate successful execution.
    return 0;
}