#include <bits/stdc++.h> // Includes iostream and many other useful headers

// Using the standard namespace as requested
using namespace std;

void solve() {
    int X;
    cin >> X; // Read the total runs X for the current test case
    
    int total_cost = 0;
    
    // Check if all runs can be scored within Phase 1
    if (X <= 20) {
        // In Phase 1: 1 run per ball, 10 rupees per ball.
        // To score X runs, Chef plays X balls.
        total_cost = X * 10;
    } else {
        // If X > 20, Chef completes Phase 1 and then proceeds to Phase 2.
        
        // Cost for Phase 1:
        // Chef plays all 20 balls of Phase 1.
        // Runs scored in Phase 1 = 20 runs (1 run/ball * 20 balls).
        // Cost for Phase 1 = 20 balls * 10 rupees/ball = 200 rupees.
        total_cost = 20 * 10; 
        
        // Remaining runs to be scored in Phase 2:
        int remaining_runs = X - 20;
        
        // In Phase 2: 2 runs per ball, 5 rupees per ball.
        // Number of balls needed in Phase 2 = remaining_runs / 2.
        // (X is guaranteed even, so X-20 is even, ensuring integer division).
        int balls_in_phase2 = remaining_runs / 2;
        
        // Cost for Phase 2 = balls_in_phase2 * 5 rupees.
        total_cost += balls_in_phase2 * 5;
    }
    
    // Output the total calculated cost for the current test case
    cout << total_cost << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful execution
}