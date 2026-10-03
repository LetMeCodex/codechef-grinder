#include <bits/stdc++.h> // Includes common headers like iostream and algorithm

// Use the standard namespace to avoid repeatedly writing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from C's stdio and prevents synchronization,
    // which is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the input values:
    // A: cost per item for Chef
    // B: cost per item for Chefina
    // C: number of items sold by both
    int A, B, C;

    // Read the three space-separated integers from standard input.
    cin >> A >> B >> C;

    // Calculate Chef's total sales: cost per item * number of items.
    int chef_total_sales = A * C;

    // Calculate Chefina's total sales: cost per item * number of items.
    int chefina_total_sales = B * C;

    // Find the maximum of the two total sales values.
    // std::max is part of the <algorithm> header, which is included by <bits/stdc++.h>.
    int maximum_sales = max(chef_total_sales, chefina_total_sales);

    // Print the calculated maximum sales value to standard output,
    // followed by a newline character as required.
    cout << maximum_sales << "\n";

    // Indicate successful execution of the program.
    return 0;
}