#include <bits/stdc++.h> // As requested by the problem statement

// Using namespace std; as requested by the problem statement
using namespace std;

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of testcases
    while (T--) { // Loop through each testcase
        long long X, Y; // Use long long for X and Y to handle values up to 10^9
        cin >> X >> Y; // Read the number of chocolates Meliodas and Ban have

        if (X == 0 || Y == 0) {
            // According to the problem statement, the war stops if "atleast one of them is left with no chocolates".
            // If X or Y is initially 0, this condition is met immediately.
            // The total chocolates remaining is simply the sum of their current chocolates.
            cout << X + Y << "\n";
        } else {
            // If both X and Y are positive, the war continues.
            // The process described: "Whoever has lesser number of chocolates eats as many chocolates as he has from the other's collection"
            // This operation (if X > Y, new state is (X-Y, Y); if Y > X, new state is (X, Y-X))
            // is precisely the subtractive form of the Euclidean algorithm for finding the Greatest Common Divisor (GCD).
            //
            // The war continues until "they have the same number of chocolates".
            // The Euclidean algorithm, when applied subtractively, converges to a state where both numbers are equal to their initial GCD.
            // For example: (5, 3) -> (2, 3) -> (2, 1) -> (1, 1). Here GCD(5,3) = 1.
            // (4, 8) -> (4, 4). Here GCD(4,8) = 4.
            //
            // So, if initial X_0, Y_0, they stop when both have GCD(X_0, Y_0) chocolates.
            // The total chocolates remaining will be GCD(X_0, Y_0) + GCD(X_0, Y_0) = 2 * GCD(X_0, Y_0).
            
            long long common_chocolates = std::gcd(X, Y); // Calculate GCD using C++17's std::gcd
            cout << 2 * common_chocolates << "\n"; // Output 2 times the GCD
        }
    }

    return 0; // Indicate successful execution
}