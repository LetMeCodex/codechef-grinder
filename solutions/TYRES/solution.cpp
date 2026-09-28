#include <bits/stdc++.h> // Includes all standard libraries, as per instruction

// Using namespace std; as per instruction
using namespace std;

int main() {
    // Fast I/O as per instruction
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times
        int N;
        cin >> N; // Read N for each test case

        // Chef prioritizes manufacturing cars. Each car needs 4 tyres.
        // After manufacturing the maximum number of cars, the remaining tyres
        // will be N % 4.
        // Since N is guaranteed to be even, N % 4 can only be 0 or 2.
        //
        // Case 1: N % 4 == 0
        // This means N is a multiple of 4 (e.g., 4, 8, 12, ...).
        // Chef will use all N tyres to make N/4 cars.
        // Remaining tyres = 0.
        // No bikes can be manufactured. Chef's friend cannot purchase a bike.
        if (N % 4 == 0) {
            cout << "NO\n";
        }
        // Case 2: N % 4 == 2
        // This means N is an even number but not a multiple of 4 (e.g., 2, 6, 10, ...).
        // Chef will use (N - 2) tyres to make (N-2)/4 cars.
        // Remaining tyres = 2.
        // These 2 tyres can be used to make 1 bike (2 / 2 = 1).
        // Since at least one bike is manufactured, Chef's friend can purchase a bike.
        else { // N % 4 == 2
            cout << "YES\n";
        }
    }
    return 0;
}