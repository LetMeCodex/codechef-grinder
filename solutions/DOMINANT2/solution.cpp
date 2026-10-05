#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the size of the array

    // Create a frequency array (vector) of size N+1, initialized to zeros.
    // This allows us to store frequencies for elements from 1 to N,
    // as per the problem constraints (1 <= A_i <= N).
    vector<int> freq(N + 1, 0); 
    int max_freq = 0; // Variable to store the maximum frequency found so far

    // Loop through the input array to count frequencies and find the maximum frequency
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read an element of the array
        freq[A_i]++; // Increment its frequency
        
        // Update max_freq if the current element's frequency is higher
        // This updates max_freq on the fly, avoiding a second pass just for max_freq.
        if (freq[A_i] > max_freq) {
            max_freq = freq[A_i];
        }
    }

    // Now, we need to count how many distinct elements have this maximum frequency.
    // If only one element has the maximum frequency, it's dominant.
    // Otherwise, if multiple elements share the maximum frequency, no element is dominant.
    int count_of_max_freq_elements = 0;
    for (int i = 1; i <= N; ++i) { // Iterate through possible element values (from 1 to N)
        if (freq[i] == max_freq) {
            count_of_max_freq_elements++;
        }
    }

    // Check the condition for dominance
    if (count_of_max_freq_elements == 1) {
        cout << "YES\n"; // Only one element has the maximum frequency, so it's dominant
    } else {
        cout << "NO\n"; // Multiple elements share the maximum frequency, or no elements exist (N>=1 so at least one element exists)
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded).
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}