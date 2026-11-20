#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store the total number of seats (N)
    // and the number of seats Chef's party has won (K).
    int N, K;

    // Read N and K from standard input.
    cin >> N >> K;

    // Calculate the minimum number of seats required to form the government.
    // A strict majority is defined as floor(N / 2) + 1 seats.
    // In C++, integer division `N / 2` automatically computes `floor(N / 2)`
    // for positive integer N.
    int required_seats = N / 2 + 1;

    // Calculate the number of additional seats Chef's party needs.
    // If Chef's party already has K seats, and K is less than required_seats,
    // they need `required_seats - K` more seats.
    // If K is already greater than or equal to required_seats, they need 0 additional seats.
    // The `max(0, ...)` function handles this condition concisely.
    int additional_seats_needed = max(0, required_seats - K);

    // Output the minimum number of additional seats required, followed by a newline.
    cout << additional_seats_needed << "\n";

    return 0;
}