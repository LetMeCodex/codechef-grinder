#include <bits/stdc++.h> // Includes iostream, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read N, the number of spots

    int last_person_pos = -1; // Stores the 0-indexed position of the last person found.
                              // Initialized to -1 to indicate no person has been found yet.
    bool social_distancing_followed = true; // Flag to track if social distancing advice is followed.
                                            // Assume true initially, set to false if a violation is found.

    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the state of the current spot (0 for empty, 1 for person)

        if (A_i == 1) { // If a person is at this spot
            if (last_person_pos != -1) { // If a previous person has already been found
                // Calculate the distance between the current person and the last found person.
                // Since spots are 0-indexed, the distance is simply the difference in their indices.
                if (i - last_person_pos < 6) {
                    social_distancing_followed = false; // A violation is found (distance < 6 feet)
                    // We don't break the loop here because we still need to consume the rest of the input
                    // for the current test case to ensure correct input reading for subsequent test cases.
                    // However, further distance checks are redundant as the flag is already false.
                }
            }
            // Update last_person_pos to the current person's position for future comparisons.
            last_person_pos = i;
        }
    }

    // After iterating through all spots, print the result for the current test case.
    if (social_distancing_followed) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O setup as requested by competitive programming guidelines.
    // This unties cin/cout from C's stdio and disables synchronization, speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful execution
}