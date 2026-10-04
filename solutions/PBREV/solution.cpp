#include <bits/stdc++.h> // Includes most standard library headers, as requested
using namespace std;     // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, once for each test case
        int N;
        cin >> N; // Read the number of judges for the current test case

        // Initialize a flag to assume the problem is good.
        // We will set it to false if we find any score that violates the condition.
        bool is_good_problem = true; 

        for (int i = 0; i < N; ++i) { // Loop N times to read each judge's score
            int score;
            cin >> score; // Read the current judge's score

            // The problem is "good" if *every* judge gives a score *strictly greater than* 4.
            // This means if we find *any* score that is 4 or less, the problem is NOT good.
            if (score <= 4) {
                is_good_problem = false; // Mark the problem as not good
                // We don't need to break the loop here. Even if we've determined
                // the problem is not good, we must continue reading the remaining
                // scores for this test case to correctly advance the input stream
                // for the next test case. The 'is_good_problem' flag will correctly
                // retain its 'false' value.
            }
        }
        
        // After processing all N scores for the current test case, print the result.
        if (is_good_problem) {
            cout << "YES\n"; // If the flag is still true, all scores were > 4
        } else {
            cout << "NO\n";  // Otherwise, at least one score was <= 4
        }
    }

    return 0; // Indicate successful program execution
}