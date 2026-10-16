#include <bits/stdc++.h> // Includes all standard libraries for competitive programming
using namespace std;     // Allows using standard library elements without the std:: prefix

void solve() {
    int D, d, A, B, C;
    // Read the five integers for the current test case
    cin >> D >> d >> A >> B >> C;

    // Calculate the total distance Chef can cover
    int chef_total_dist = D * d;

    int max_prize = 0; // Initialize max_prize to 0 (in case no prize is won)

    // Check categories from highest prize to lowest prize
    // Category 3: 42 km, Prize C
    if (chef_total_dist >= 42) {
        max_prize = C;
    } 
    // Category 2: 21 km, Prize B
    else if (chef_total_dist >= 21) {
        max_prize = B;
    } 
    // Category 1: 10 km, Prize A
    else if (chef_total_dist >= 10) {
        max_prize = A;
    } 
    // If none of the above conditions are met, chef_total_dist is less than 10 km,
    // so Chef cannot win any prize. max_prize remains 0.

    // Output the maximum prize Chef can win, followed by a newline
    cout << max_prize << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}