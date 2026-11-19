#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    int current_sum = 0; // Sum of scores from the first N assignments
    for (int i = 0; i < N; ++i) {
        int score;
        cin >> score;
        current_sum += score;
    }
    
    // Calculate the total score required to pass (50% of maximum possible total marks)
    // Total assignments = N + 1
    // Max marks per assignment = 100
    // Max total marks = (N + 1) * 100
    // Required score to pass = (N + 1) * 100 * 0.5 = (N + 1) * 50
    int required_total_score = (N + 1) * 50;
    
    // Calculate the minimum score X needed on the last assignment mathematically
    // current_sum + X >= required_total_score
    // X >= required_total_score - current_sum
    int min_X_needed_mathematically = required_total_score - current_sum;
    
    // The score X cannot be negative. So, take the maximum of 0 and the mathematically needed score.
    int final_min_X = max(0, min_X_needed_mathematically);
    
    // Check if it's possible to achieve final_min_X.
    // The maximum score Chef can get on the last assignment is 100.
    if (final_min_X > 100) {
        // If even with a perfect 100, Chef cannot reach the passing threshold, it's impossible.
        cout << -1 << "\n";
    } else {
        // Otherwise, Chef needs final_min_X score to pass.
        cout << final_min_X << "\n";
    }
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }
    
    return 0;
}