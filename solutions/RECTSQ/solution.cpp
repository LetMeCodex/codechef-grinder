#include <bits/stdc++.h> // Includes iostream, numeric, etc. for convenience
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, M;
        cin >> N >> M; // Read the length N and breadth M of the land

        // Calculate the greatest common divisor (GCD) of N and M.
        // This GCD will be the side length of the largest possible square plots
        // that can perfectly tile the rectangle.
        int common_side_length = std::gcd(N, M);

        // The number of squares along the length N will be N / common_side_length.
        // The number of squares along the breadth M will be M / common_side_length.
        // The total minimum number of square plots is the product of these two quantities.
        // Using long long for num_plots to prevent potential overflow, though int would suffice for given constraints.
        long long num_plots = (long long)(N / common_side_length) * (M / common_side_length);
        
        // Print the calculated minimum number of plots, followed by a newline.
        cout << num_plots << "\n";
    }

    return 0; // Indicate successful execution
}