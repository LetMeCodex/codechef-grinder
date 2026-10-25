#include <bits/stdc++.h> // Includes most standard libraries, including iostream
using namespace std;     // Brings all names from std namespace into the global scope

// Function to solve a single test case
void solve() {
    int X, Y, A, B, K;
    // Read the five space-separated integers for the current test case
    cin >> X >> Y >> A >> B >> K;

    // Calculate the final price of petrol after K months
    // Initial price X + (monthly increase A * number of months K)
    // Using long long for calculation to be safe, though int would suffice for given constraints.
    long long final_petrol_price = (long long)X + (long long)A * K;

    // Calculate the final price of diesel after K months
    // Initial price Y + (monthly increase B * number of months K)
    long long final_diesel_price = (long long)Y + (long long)B * K;

    // Compare the final prices and print the appropriate result
    if (final_petrol_price < final_diesel_price) {
        cout << "PETROL\n"; // Petrol is cheaper
    } else if (final_diesel_price < final_petrol_price) {
        cout << "DIESEL\n"; // Diesel is cheaper
    } else {
        cout << "SAME PRICE\n"; // Both have the same price
    }
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
    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution
}