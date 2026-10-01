#include <bits/stdc++.h> // Required header for competitive programming

using namespace std; // Required namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, processing each test case
        int N, K;
        cin >> N >> K; // Read the side length of the chart paper (N) and the cutout squares (K)

        // Calculate how many K-length segments can fit along one side of length N.
        // Integer division automatically truncates, giving floor(N/K).
        int num_squares_per_side = N / K;

        // The total number of KxK squares is the product of the number of squares
        // that can fit along the width and the number that can fit along the height.
        int total_squares = num_squares_per_side * num_squares_per_side;

        cout << total_squares << "\n"; // Output the result for the current test case, followed by a newline
    }

    return 0; // Indicate successful execution
}