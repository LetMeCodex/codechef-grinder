#include <bits/stdc++.h> 
using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int chef_votes = 0;
    int antichef_votes = 0;
    int winning_ways = 0;

    // Iterate through each possible stopping point, from 1 vote up to N votes.
    // The loop variable 'i' corresponds to the 0-based index of the current vote.
    // So, after processing S[i], we have counted i+1 votes.
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            chef_votes++;
        } else { // S[i] == '0'
            antichef_votes++;
        }

        // Check if Chef wins after counting the current set of votes.
        // A tie is not a win, so strictly greater is required.
        if (chef_votes > antichef_votes) {
            winning_ways++;
        }
    }

    cout << winning_ways << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop through each test case.
        solve(); // Call the function to solve the current test case.
    }

    return 0;
}