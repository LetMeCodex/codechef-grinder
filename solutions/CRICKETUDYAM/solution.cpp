#include <bits/stdc++.h> // Includes most standard libraries, common in competitive programming.

// Using the standard namespace to avoid prefixing std:: to every standard library element.
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, M; // Declare integers N and M for the number of teams and minimum matches.
        cin >> N >> M; // Read N and M for the current test case.

        // In a knockout tournament with N teams, exactly N-1 matches are played
        // to determine a single winner. Each match eliminates one team, and N-1
        // teams must be eliminated to leave one winner.
        int actual_matches_played = N - 1;

        // The tournament is "interesting" if at least M matches are played.
        // Since exactly (N-1) matches are always played, we check if (N-1) is
        // greater than or equal to M.
        if (actual_matches_played >= M) {
            cout << "YES\n"; // If N-1 >= M, it's possible, so print "YES".
        } else {
            cout << "NO\n"; // Otherwise, it's not possible, so print "NO".
        }
    }

    return 0; // Indicate successful program execution.
}