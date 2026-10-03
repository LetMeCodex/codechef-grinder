#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

using namespace std; // Use standard namespace for convenience

void solve() {
    int N;
    cin >> N; // Read the number of players
    
    // Read goals scored by each player
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Read fouls committed by each player
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    
    int max_overall_points = 0; // Initialize max points to 0, as points cannot be negative
    
    // Iterate through each player to calculate their points and find the maximum
    for (int i = 0; i < N; ++i) {
        int goals = A[i];
        int fouls = B[i];
        
        // Calculate raw points: 20 for each goal, -10 for each foul
        int raw_points = (goals * 20) - (fouls * 10);
        
        // Apply the rule: if points are negative, they become 0
        int current_player_points = max(0, raw_points);
        
        // Update the maximum overall points found so far
        max_overall_points = max(max_overall_points, current_player_points);
    }
    
    // Print the maximum points for the current test case
    cout << max_overall_points << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times
        solve(); // Call the function to solve each test case
    }
    
    return 0; // Indicate successful execution
}