#include <bits/stdc++.h> // Includes iostream, vector, algorithm, functional etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K; // Read N (total teams) and K (rank threshold)
    vector<int> S(N); // Create a vector to store team scores
    for (int i = 0; i < N; ++i) {
        cin >> S[i]; // Read each team's score
    }

    // Sort scores in descending order.
    // std::greater<int>() is used as a comparator for descending order.
    sort(S.begin(), S.end(), greater<int>());

    // The K-th placed team's score.
    // Since vectors are 0-indexed, the K-th element is at index K-1.
    // K is guaranteed to be at least 1, so K-1 is always a valid index.
    int min_qualifying_score = S[K - 1];

    // Count the number of teams that qualify.
    // A team qualifies if its score is greater than or equal to min_qualifying_score.
    int qualified_count = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] >= min_qualifying_score) {
            qualified_count++;
        } else {
            // Since the scores are sorted in descending order,
            // if the current score S[i] is less than min_qualifying_score,
            // all subsequent scores (S[i+1], S[i+2], ...) will also be less.
            // Therefore, we can stop counting and break out of the loop early.
            break;
        }
    }

    // Print the total number of qualified teams for the current test case.
    cout << qualified_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}