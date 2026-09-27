#include <bits/stdc++.h> 
using namespace std;

void solve() {
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;

    if (A == B) {
        // If the initial temperature is already the desired temperature,
        // Chef doesn't need to add any water.
        cout << "YES\n";
    } else if (B > A) {
        // If the desired temperature is higher than the initial temperature,
        // Chef needs to increase the temperature by adding hot water.
        // The required temperature increase is B - A degrees.
        // Each litre of hot water increases temperature by 1 degree.
        int hot_water_needed = B - A;
        
        // Check if Chef has enough hot water.
        if (hot_water_needed <= X) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else { // B < A
        // If the desired temperature is lower than the initial temperature,
        // Chef needs to decrease the temperature by adding cold water.
        // The required temperature decrease is A - B degrees.
        // Each litre of cold water decreases temperature by 1 degree.
        int cold_water_needed = A - B;
        
        // Check if Chef has enough cold water.
        if (cold_water_needed <= Y) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before cin, speeding up I/O operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}