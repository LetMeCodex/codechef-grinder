#include <bits/stdc++.h> // Includes most standard libraries like iostream

// Using namespace std; is common in competitive programming to avoid typing std::
using namespace std; 

int main() {
    // Enable fast I/O operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int X, Y;
        cin >> X >> Y; // Read the cost of disposable (X) and cloth (Y) masks

        // Calculate the total cost for disposable masks for 100 days.
        // Each disposable mask lasts 1 day, so 100 masks are needed.
        int cost_disposable = 100 * X;

        // Calculate the total cost for cloth masks for 100 days.
        // Each cloth mask lasts 10 days, so 100 / 10 = 10 masks are needed.
        int cost_cloth = 10 * Y;

        // Apply Chef's decision logic:
        // Chef chooses the masks which cost him the least.
        // In case of a tie, Chef chooses cloth masks (eco-friendly).
        // This means Chef chooses CLOTH if its cost is less than or equal to DISPOSABLE's cost.
        if (cost_cloth <= cost_disposable) {
            cout << "CLOTH\n"; // Print "CLOTH" if cloth masks are cheaper or equal in cost
        } else {
            cout << "DISPOSABLE\n"; // Otherwise, print "DISPOSABLE"
        }
    }

    return 0; // Indicate successful execution
}