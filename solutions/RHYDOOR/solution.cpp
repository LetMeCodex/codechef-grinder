#include <bits/stdc++.h> // Includes iostream, string, vector, algorithm, etc.

// As per problem instructions, using namespace std; is allowed.
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of button presses
    string S;
    cin >> S; // Read the sequence of button presses

    int door_open_count = 0;
    char current_button = ' '; // Stores the button character of the current streak.
                               // Initialized to a character not 'A' or 'B' to ensure the first
                               // press correctly starts a new streak.
    int current_streak_length = 0; // Stores the length of the current consecutive streak.

    // Iterate through each button press in the sequence
    for (int i = 0; i < N; ++i) {
        char press = S[i]; // Get the current button press

        // Check if the current press continues the existing streak
        if (press == current_button) {
            current_streak_length++; // Increment streak length
        } else {
            // If the button changed, or this is the very first press (current_button was ' ')
            // a new streak begins with the current button.
            current_button = press;
            current_streak_length = 1; // Start a new streak of length 1
        }

        // Check if the streak has reached 3 consecutive presses
        if (current_streak_length == 3) {
            door_open_count++; // Increment the count of times the door opened
            
            // The lock immediately resets its counter to zero.
            // This means the current streak is "consumed" to open the door.
            // Any subsequent presses, even if they are the same button,
            // will start a fresh count. Setting current_streak_length to 0
            // achieves this: the next iteration, if 'press' is still 'current_button',
            // will increment it from 0 to 1, effectively starting a new streak.
            current_streak_length = 0; 
        }
    }

    // Print the total number of times the door opened for this test case
    cout << door_open_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}