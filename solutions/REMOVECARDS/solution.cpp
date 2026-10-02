#include <bits/stdc++.h> 

// It's common practice in competitive programming to use the entire standard namespace
// for brevity, especially in single-file solutions.
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of cards
    
    // A_i values are constrained to be between 1 and 10.
    // We can use a fixed-size array (or std::vector) to store frequencies.
    // `counts[k]` will store the number of times `k` appears.
    // Size 11 is used to cover indices 0 through 10. We'll use indices 1-10.
    vector<int> counts(11, 0); 
    
    // `max_freq` will store the maximum frequency found among all card numbers.
    // Initialize to 0, as no cards have been processed yet.
    int max_freq = 0; 
    
    // Loop N times to read each card and update its frequency
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the number on the current card
        
        // Increment the frequency for the number A_i
        counts[A_i]++; 
        
        // After updating the count for A_i, check if it's the new maximum frequency.
        // This way, `max_freq` always holds the highest frequency encountered so far.
        if (counts[A_i] > max_freq) {
            max_freq = counts[A_i];
        }
    }
    
    // The goal is to have all remaining cards show the same number.
    // To minimize moves, we should choose the number that appears most frequently
    // and keep all cards with that number. All other cards must be removed.
    // The number of cards to keep is `max_freq`.
    // The total number of cards is `N`.
    // So, the number of cards to remove (minimum moves) is `N - max_freq`.
    cout << N - max_freq << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }
    
    return 0; // Indicate successful execution
}