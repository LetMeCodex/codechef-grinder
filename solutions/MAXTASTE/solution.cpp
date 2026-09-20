#include <bits/stdc++.h> // Includes most standard libraries, as requested.

using namespace std; // Uses the standard namespace, as requested.

void solve() {
    int a, b, c, d;
    // Read the tastiness values for ingredients A, B, C, and D.
    cin >> a >> b >> c >> d;

    // To maximize the total tastiness of the dish, Chef should make the optimal choice
    // for each ingredient slot independently.

    // For the first ingredient, Chef can choose either A or B.
    // To maximize tastiness, Chef should pick the one with higher tastiness.
    int max_tastiness_from_first_pair = max(a, b);

    // For the second ingredient, Chef can choose either C or D.
    // To maximize tastiness, Chef should pick the one with higher tastiness.
    int max_tastiness_from_second_pair = max(c, d);
    
    // The maximum possible tastiness of the dish is the sum of the maximums
    // from each ingredient slot.
    int total_max_tastiness = max_tastiness_from_first_pair + max_tastiness_from_second_pair;
    
    // Output the result for the current test case, followed by a newline.
    cout << total_max_tastiness << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases.
    cin >> t;
    // Loop through each test case.
    while (t--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}