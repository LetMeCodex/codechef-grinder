#include <iostream> // Required for cin, cout
#include <string>   // Required for std::string

// As requested by the problem statement.
using namespace std;

// Function to solve a single test case
void solve() {
    string s;
    cin >> s; // Read the binary string S

    long long count_x = 0; // Number of reachable x-coordinates
    long long count_y = 0; // Number of reachable y-coordinates

    // Determine reachability along the x-axis
    // S_1 (s[0]) refers to left, S_2 (s[1]) refers to right
    bool can_move_left = (s[0] == '1');
    bool can_move_right = (s[1] == '1');

    if (can_move_left && can_move_right) {
        // Can move both left and right, so all x-coordinates from -10 to 10 are reachable.
        // Number of values from -10 to 10 inclusive is 10 - (-10) + 1 = 21.
        count_x = 21;
    } else if (can_move_left) {
        // Can only move left. From (0,0), can reach x <= 0.
        // Within [-10, 10], this means x-coordinates from -10 to 0 inclusive.
        // Number of values is 0 - (-10) + 1 = 11.
        count_x = 11;
    } else if (can_move_right) {
        // Can only move right. From (0,0), can reach x >= 0.
        // Within [-10, 10], this means x-coordinates from 0 to 10 inclusive.
        // Number of values is 10 - 0 + 1 = 11.
        count_x = 11;
    } else {
        // Cannot move left or right. Only x=0 is reachable.
        count_x = 1;
    }

    // Determine reachability along the y-axis
    // S_3 (s[2]) refers to up, S_4 (s[3]) refers to down
    bool can_move_up = (s[2] == '1');
    bool can_move_down = (s[3] == '1');

    if (can_move_up && can_move_down) {
        // Can move both up and down, so all y-coordinates from -10 to 10 are reachable.
        // Number of values from -10 to 10 inclusive is 10 - (-10) + 1 = 21.
        count_y = 21;
    } else if (can_move_up) {
        // Can only move up. From (0,0), can reach y >= 0.
        // Within [-10, 10], this means y-coordinates from 0 to 10 inclusive.
        // Number of values is 10 - 0 + 1 = 11.
        count_y = 11;
    } else if (can_move_down) {
        // Can only move down. From (0,0), can reach y <= 0.
        // Within [-10, 10], this means y-coordinates from -10 to 0 inclusive.
        // Number of values is 0 - (-10) + 1 = 11.
        count_y = 11;
    } else {
        // Cannot move up or down. Only y=0 is reachable.
        count_y = 1;
    }

    // The total number of reachable cells is the product of reachable x and y coordinates,
    // because movements along x and y axes are independent.
    cout << count_x * count_y << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}