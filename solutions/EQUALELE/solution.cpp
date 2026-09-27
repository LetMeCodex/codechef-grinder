#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace as requested
using namespace std;

// Using a global frequency array to avoid reallocating large memory for each test case.
// MAX_VAL is chosen based on the maximum possible value of N (2 * 10^5)
// since A_i can be up to N. So, indices up to 200000 are needed.
const int MAX_VAL = 200005; 
int freq[MAX_VAL]; // Stores frequencies of elements. Global arrays are initialized to 0 by default.

void solve() {
    int N;
    cin >> N;

    int max_freq = 0;
    // We need to store the elements encountered in the current test case
    // to efficiently reset their frequencies for the next test case.
    vector<int> elements_in_current_test_case;
    elements_in_current_test_case.reserve(N); // Pre-allocate memory for efficiency

    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;
        freq[A_i]++; // Increment frequency for A_i
        max_freq = max(max_freq, freq[A_i]); // Update max_freq with the current maximum frequency
        elements_in_current_test_case.push_back(A_i); // Store A_i to clear its freq later
    }

    // The minimum operations needed is N - (maximum frequency).
    // This is because we want to make all N elements equal to the most frequent element.
    // If 'max_freq' elements are already equal to that value, we need to change N - max_freq elements.
    cout << N - max_freq << "\n";

    // Reset frequencies for the elements encountered in this test case.
    // This is crucial for correctness in subsequent test cases and maintains O(sum of N) complexity.
    for (int val : elements_in_current_test_case) {
        freq[val] = 0;
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}