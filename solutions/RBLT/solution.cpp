#include <bits/stdc++.h> // Includes iostream, etc.

// Using namespace std; is common in competitive programming
// as requested by the problem instructions.
using namespace std; 

void solve() {
    int N;
    cin >> N; // Read N, the number of lights
    
    int red_count = 0;
    int blue_count = 0;
    
    // Iterate through the lights to count existing red and blue lights
    for (int i = 0; i < N; ++i) {
        int C_i;
        cin >> C_i; // Read the color of the i-th light
        if (C_i == 1) { // If it's red
            red_count++;
        } else if (C_i == 2) { // If it's blue
            blue_count++;
        }
        // If C_i == 0, it's undecided, we don't count it here.
        // Its role is implicitly handled by the logic.
    }
    
    // Condition 1: If N is odd, it's impossible to have an equal number of red and blue lights.
    if (N % 2 != 0) {
        cout << "No\n";
        return;
    }
    
    // If N is even, we need N/2 red lights and N/2 blue lights for a balanced configuration.
    int target_count = N / 2;
    
    // Condition 2: Check if we already have more red lights than the target.
    // If red_count > target_count, we cannot remove red lights, so it's impossible.
    if (red_count > target_count) {
        cout << "No\n";
        return;
    }
    
    // Condition 3: Check if we already have more blue lights than the target.
    // If blue_count > target_count, we cannot remove blue lights, so it's impossible.
    if (blue_count > target_count) {
        cout << "No\n";
        return;
    }
    
    // If N is even, and both red_count and blue_count are less than or equal to N/2,
    // then we have enough undecided lights to fill the gaps and achieve a balanced configuration.
    // The number of undecided lights is exactly N - (red_count + blue_count).
    // The number of red lights needed from undecided is (target_count - red_count).
    // The number of blue lights needed from undecided is (target_count - blue_count).
    // The sum of needed lights is (N/2 - red_count) + (N/2 - blue_count) = N - (red_count + blue_count),
    // which is exactly the total number of undecided lights. Since both needed counts are non-negative,
    // we can always make the assignment.
    cout << "Yes\n";
}

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }
    
    return 0;
}