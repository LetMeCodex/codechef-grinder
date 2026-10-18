#include <bits/stdc++.h> // Includes iostream, vector, algorithm etc.

using namespace std; // Required by problem statement

void solve() {
    int N;
    cin >> N;
    
    // Use a vector as a frequency array.
    // A_i values are between 1 and 100, so an array of size 101 (indices 0-100) is suitable.
    // Initialize all counts to 0.
    vector<int> counts(101, 0); 
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        counts[val]++; // Increment frequency for the current value
    }
    
    int max_freq = 0;
    // Iterate through possible values (1 to 100) to find the maximum frequency.
    // Since N >= 1, there will always be at least one element, so max_freq will be at least 1.
    for (int i = 1; i <= 100; ++i) {
        if (counts[i] > max_freq) {
            max_freq = counts[i];
        }
    }
    
    // The minimum number of moves is N - (maximum frequency of any element).
    // This is because N - max_freq elements are not equal to the most frequent value,
    // and each of them needs at least one move.
    cout << N - max_freq << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }
    
    return 0;
}