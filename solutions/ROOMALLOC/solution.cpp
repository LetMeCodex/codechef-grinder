#include <bits/stdc++.h> 

// Using the standard namespace to avoid writing std:: before cin, cout, etc.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can further speed up I/O in interactive problems or problems with mixed I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N; // Variable to store the number of colleges
        cin >> N; // Read the number of colleges

        long long total_rooms = 0; // Variable to store the total minimum rooms needed.
                                   // Using long long to be safe, though 'int' would suffice
                                   // given the constraints (max 100 colleges * 50 rooms/college = 5000).

        // Loop N times to read the number of members from each college
        for (int i = 0; i < N; ++i) {
            int A_i; // Variable to store the number of members from the i-th college
            cin >> A_i; // Read A_i

            // Calculate rooms needed for the current college:
            // Each room can accommodate at most 2 people.
            // To minimize rooms, we put 2 people per room whenever possible.
            // The formula (A_i + 1) / 2 using integer division correctly calculates
            // the ceiling of A_i / 2.
            // For example:
            // A_i = 1 => (1+1)/2 = 1 room
            // A_i = 2 => (2+1)/2 = 1 room
            // A_i = 3 => (3+1)/2 = 2 rooms
            // A_i = 4 => (4+1)/2 = 2 rooms
            total_rooms += (A_i + 1) / 2;
        }

        // Output the total minimum rooms for the current test case, followed by a newline.
        cout << total_rooms << "\n";
    }

    return 0; // Indicate successful execution
}