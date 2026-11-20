#include <bits/stdc++.h> 
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.

    while (T--) { // Loop T times, processing each test case.
        int P, M, V;
        cin >> P >> M >> V; // Read P (people), M (base fuel economy), V (fuel volume).

        // Calculate the number of extra passengers.
        // P includes the driver, so P-1 are the additional passengers.
        int extra_passengers = P - 1;

        // Calculate the effective fuel economy.
        // The base fuel economy M is decreased by 1 km/litre for each extra passenger.
        int effective_fuel_economy = M - extra_passengers;

        // Calculate the maximum distance the car can travel.
        // Distance = Effective Fuel Economy * Volume of Fuel.
        // The maximum possible distance is 56 * 100 = 5600, which fits in an int.
        // However, using long long for the result is a good general practice in competitive programming
        // to prevent potential overflow issues, even if not strictly necessary here.
        long long max_distance = (long long)effective_fuel_economy * V;

        // Output the calculated maximum distance, followed by a newline.
        cout << max_distance << "\n";
    }

    return 0; // Indicate successful execution.
}