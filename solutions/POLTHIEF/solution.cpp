#include <bits/stdc++.h> // Includes iostream, cmath (for abs), etc.

// Using namespace std; is common in competitive programming for brevity.
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop T times for each test case.
        int X, Y;
        cin >> X >> Y; // Read the initial locations of the policeman (X) and thief (Y).
        
        // The problem states the policeman's speed is 2 units/sec and the thief's speed is 1 unit/sec.
        // The thief tries to evade for as long as possible.
        //
        // If the policeman is at X and the thief is at Y:
        // 1. If X < Y (policeman is to the left of the thief):
        //    The policeman will move right (towards Y).
        //    - If the thief also moves right (evading):
        //      Policeman's position: X + 2t
        //      Thief's position: Y + t
        //      They meet when X + 2t = Y + t => t = Y - X
        //    - If the thief moves left (towards policeman):
        //      Policeman's position: X + 2t
        //      Thief's position: Y - t
        //      They meet when X + 2t = Y - t => 3t = Y - X => t = (Y - X) / 3
        //    To maximize evasion time, the thief chooses to move right, so time = Y - X.
        //
        // 2. If X > Y (policeman is to the right of the thief):
        //    The policeman will move left (towards Y).
        //    - If the thief also moves left (evading):
        //      Policeman's position: X - 2t
        //      Thief's position: Y - t
        //      They meet when X - 2t = Y - t => t = X - Y
        //    - If the thief moves right (towards policeman):
        //      Policeman's position: X - 2t
        //      Thief's position: Y + t
        //      They meet when X - 2t = Y + t => 3t = X - Y => t = (X - Y) / 3
        //    To maximize evasion time, the thief chooses to move left, so time = X - Y.
        //
        // In both cases, the minimum time for the policeman to catch the thief, considering the thief's optimal evasion,
        // is simply the absolute difference between their initial positions.
        // If X == Y, the time is 0, which is correctly given by abs(X - Y).
        
        int time_taken = abs(X - Y); // Calculate the absolute difference.
        cout << time_taken << "\n"; // Output the result followed by a newline.
    }
    return 0; // Indicate successful execution.
}