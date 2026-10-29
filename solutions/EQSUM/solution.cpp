#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std as requested
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // The values A[k] - k (where k is 0-indexed) can range as follows:
    // Smallest possible value: A[k]=1, k=N-1 (last element) => 1 - (N-1) = 2 - N
    // Largest possible value: A[k]=N, k=0 (first element)   => N - 0 = N
    // So, the range of values for A[k] - k is [2-N, N].
    // To map these values to non-negative indices for a frequency array,
    // we can add an offset.
    // If we add (N-2) to the smallest value (2-N), it becomes 0.
    // If we add (N-2) to the largest value (N), it becomes N + (N-2) = 2N-2.
    // Thus, the indices will range from 0 to 2N-2.
    // A vector of size 2N-1 would be sufficient (indices 0 to 2N-2).
    // Using 2N for the vector size is a safe choice, as 2N-2 < 2N.
    vector<int> freq(2 * N, 0); 
    int offset = N - 2; // Offset to map the minimum value (2-N) to index 0

    for (int k = 0; k < N; ++k) {
        int val_Ak;
        cin >> val_Ak; // Read A[k] (which is A_{k+1} from problem statement)
        // Calculate B_k = A[k] - k (using 0-indexed k)
        // Add offset to map B_k to a non-negative index
        freq[val_Ak - k + offset]++;
    }

    long long count_pairs = 0;
    // Iterate through the frequency counts
    for (int count : freq) {
        if (count > 1) {
            // If 'count' elements have the same B_k value,
            // they can form count * (count - 1) / 2 pairs.
            // Use long long for the product to prevent overflow,
            // as count can be up to N (4*10^4), and N*(N-1)/2 can be ~8*10^8.
            count_pairs += (long long)count * (count - 1) / 2;
        }
    }

    cout << count_pairs << "\n";
}

int main() {
    // Enable fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}