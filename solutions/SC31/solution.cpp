#include <bits/stdc++.h> // Includes common standard libraries like iostream, string, etc.

// Using namespace std; is common in competitive programming to avoid typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of participants

    // Initialize a bitmask to represent the final weapon set.
    // Each bit (0 to 9) corresponds to a weapon type (1 to 10).
    // A bit is '1' if the weapon type is present, '0' otherwise.
    // We use XOR to combine weapon sets, as explained in the problem analysis.
    int final_weapon_mask = 0;

    // Iterate through each participant
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S; // Read the weapon string for the current participant

        // Convert the current participant's weapon string into a bitmask.
        int current_participant_mask = 0;
        for (int j = 0; j < 10; ++j) {
            if (S[j] == '1') {
                // If the j-th character is '1', it means the participant has
                // weapon type (j+1). Set the j-th bit in their mask.
                current_participant_mask |= (1 << j);
            }
        }

        // XOR the current participant's weapon mask with the running total.
        // This effectively combines their weapons into the final set according
        // to the symmetric difference rule.
        final_weapon_mask ^= current_participant_mask;
    }

    // After processing all participants, final_weapon_mask holds the
    // combined weapon set of the tournament winner.
    // We need to count the number of set bits (1s) in this mask.
    // __builtin_popcount is a GCC extension that efficiently counts set bits in an integer.
    int max_weapons = __builtin_popcount(final_weapon_mask);
    
    // Print the result for the current test case, followed by a newline.
    cout << max_weapons << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}