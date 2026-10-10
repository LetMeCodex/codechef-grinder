#include <bits/stdc++.h> // Includes iostream, string, set, etc.

void solve() {
    int N;
    int X; // X can be up to 1,000,000 and N up to 100.
           // The maximum coordinate reached would be X + N (1,000,000 + 100 = 1,000,100)
           // The minimum coordinate reached would be X - N (-1,000,000 - 100 = -1,000,100)
           // Both these values fit comfortably within a standard 32-bit signed integer.
    std::cin >> N >> X;
    std::string S;
    std::cin >> S;

    // A std::set is used to store all unique coordinates visited by the robot.
    // It automatically handles duplicates, ensuring only distinct points are counted.
    std::set<int> visited_points;
    
    // The robot's initial position X is always considered visited.
    visited_points.insert(X);
    
    // current_position tracks the robot's current coordinate.
    int current_position = X;

    // Iterate through each command in the string S.
    for (char command : S) {
        if (command == 'L') {
            // Move one step to the left (decrease x by 1).
            current_position--;
        } else { // command == 'R'
            // Move one step to the right (increase x by 1).
            current_position++;
        }
        // After each command, the new position is visited. Add it to the set.
        visited_points.insert(current_position);
    }

    // The total number of distinct points visited is the size of the set.
    std::cout << visited_points.size() << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // T denotes the number of test cases.
    std::cin >> T;
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}