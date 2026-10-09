#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare four integer variables to store the input values:
    // a: number of pens
    // b: number of pencils
    // x: cost per pen
    // y: cost per pencil
    int a, b, x, y;

    // Read the four space-separated integers from the first line of input.
    cin >> a >> b >> x >> y;

    // Calculate the total cost.
    // The cost of 'a' pens is 'a * x'.
    // The cost of 'b' pencils is 'b * y'.
    // The total amount spent is the sum of these two costs.
    // Given constraints (1 <= a, b, x, y <= 10^3), the maximum possible
    // value for (a * x) is 10^3 * 10^3 = 10^6.
    // Similarly, (b * y) is at most 10^6.
    // The total cost will be at most 10^6 + 10^6 = 2 * 10^6.
    // A standard 'int' type in C++ is sufficient to store this value
    // (typically up to 2 * 10^9), so no 'long long' is needed here.
    int total_cost = (a * x) + (b * y);

    // Print the calculated total cost to standard output, followed by a newline character.
    cout << total_cost << "\n";

    return 0; // Indicate successful execution of the program.
}