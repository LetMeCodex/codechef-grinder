#include <bits/stdc++.h> // Include all standard libraries

// Use the standard namespace to avoid writing std:: before every standard library function
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y, Z;
    // Read the capacity of each airplane (X),
    // the number of people willing to book (Y),
    // and the cost per ticket (Z).
    cin >> X >> Y >> Z;

    // Calculate the total number of seats available across all 10 airplanes.
    // Chef has 10 airplanes, each with capacity X.
    int total_available_seats = 10 * X;

    // Determine the actual number of tickets Chef can sell.
    // Chef can sell tickets to at most Y people (if Y is less than or equal to available seats).
    // Chef can sell at most total_available_seats tickets (if Y is greater than available seats).
    // So, the number of tickets sold is the minimum of Y and total_available_seats.
    int tickets_sold = min(Y, total_available_seats);

    // Calculate the maximum amount Chef can earn.
    // This is the number of tickets sold multiplied by the price per ticket (Z).
    // We use long long for max_earnings to safely store the product,
    // although for the given constraints (max 100*100 = 10000), int would also be sufficient.
    long long max_earnings = (long long)tickets_sold * Z;

    // Output the maximum earnings for the current test case, followed by a newline.
    cout << max_earnings << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases.
    cin >> T;
    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}