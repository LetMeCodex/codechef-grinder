#include <bits/stdc++.h> 

// Using namespace std; is requested by the problem statement.
using namespace std;

int main() {
    // Fast I/O setup as requested for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.

    while (T--) { // Loop T times for each test case.
        int X, N;
        cin >> X >> N; // Read the number of aircraft owned (X) and passengers (N).

        // Calculate the minimum number of planes required to carry N passengers.
        // Each aircraft can carry up to 100 passengers.
        // This is equivalent to ceil(N / 100.0).
        // In integer arithmetic, ceil(A / B) for positive integers A, B can be calculated as (A + B - 1) / B.
        // Here, A = N and B = 100.
        int planes_needed = (N + 99) / 100;

        // Determine the number of new planes the airline must purchase.
        // If the number of planes needed is greater than the planes already owned (X),
        // the airline must buy the difference: planes_needed - X.
        // If planes_needed is less than or equal to X, the airline already has enough planes,
        // so it needs to buy 0 new planes.
        // The std::max function handles this concisely: max(0, value).
        int planes_to_buy = max(0, planes_needed - X);

        cout << planes_to_buy << "\n"; // Output the result for the current test case.
    }

    return 0; // Indicate successful execution.
}