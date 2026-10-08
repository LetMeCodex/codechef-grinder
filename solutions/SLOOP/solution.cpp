#include <bits/stdc++.h> 

// The problem statement asks to use `using namespace std;`
using namespace std;

int main() {
    // Fast I/O setup as requested by the problem statement.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        int M, S; // M: duration of the trip, S: duration of the song.
        cin >> M >> S; // Read M and S for the current test case.

        // To find out how many times the song can be played completely,
        // we need to divide the total trip duration (M) by the song duration (S).
        // Integer division in C++ (M / S) automatically gives the floor value,
        // which is exactly what we need for "how many times completely".
        // For example:
        // If M=10, S=5, then 10/5 = 2. (Song plays 2 times)
        // If M=10, S=6, then 10/6 = 1. (Song plays 1 time completely, 4 minutes remaining)
        // If M=9, S=10, then 9/10 = 0. (Song cannot be completed even once)
        cout << M / S << "\n"; // Output the result followed by a newline.
    }

    return 0; // Indicate successful execution.
}