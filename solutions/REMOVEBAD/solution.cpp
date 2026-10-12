#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.
using namespace std;     // Use standard namespace for brevity

void solve() {
    int N;
    cin >> N; // Read the length of the array

    // Create a frequency array. Since A_i can be up to N (1 <= A_i <= N),
    // a vector of size N+1 is sufficient to store counts for values from 1 to N.
    // Initialize all counts to 0.
    vector<int> freq(N + 1, 0); 
    
    int max_freq = 0; // Variable to store the maximum frequency found so far

    // Iterate N times to read all elements of the array
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val; // Read an element A_i

        // Increment the frequency count for the current value
        freq[val]++;

        // Update max_freq if the current value's frequency is higher
        if (freq[val] > max_freq) {
            max_freq = freq[val];
        }
    }
    
    // The minimum number of operations required is N (total elements)
    // minus the count of the most frequent element (which we choose to keep).
    cout << N - max_freq << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}