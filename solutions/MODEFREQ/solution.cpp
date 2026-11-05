#include <iostream>
#include <vector>
#include <algorithm> // Not strictly needed for this approach, but good to include for general competitive programming.

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N;

    // Step 1: Calculate frequency of each number in A.
    // A_i are between 1 and 10. So we need an array of size 11 (indices 0-10).
    // counts_A[v] will store the frequency of number 'v' in the input array A.
    std::vector<int> counts_A(11, 0); 
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        counts_A[val]++;
    }

    // Step 2: Calculate frequency of these frequencies.
    // Frequencies (let's call them 'w') can range from 1 (if a number appears once)
    // up to N (if all numbers in A are identical).
    // counts_freq[w] will store how many distinct numbers 'v' had a frequency of 'w'.
    std::vector<int> counts_freq(N + 1, 0); 
    // Iterate through possible values of A_i (from 1 to 10).
    for (int v = 1; v <= 10; ++v) { 
        if (counts_A[v] > 0) { // If number 'v' actually appeared in the input array A
            int freq_v = counts_A[v]; // This is the frequency 'w' for number 'v'
            counts_freq[freq_v]++;    // Increment the count for this frequency 'w'
        }
    }

    // Step 3: Find the mode of frequencies (smallest one in case of tie).
    // max_freq_of_freq stores the highest count found for any frequency 'w'.
    // mode_freq stores the 'w' that corresponds to max_freq_of_freq.
    int max_freq_of_freq = -1; 
    int mode_freq = -1;        

    // Iterate 'w' from 1 to N.
    // Iterating in increasing order of 'w' automatically handles the "report the smallest one"
    // tie-breaking rule, because if a tie occurs, the first 'w' encountered will be the smallest.
    for (int w = 1; w <= N; ++w) {
        if (counts_freq[w] > 0) { // Only consider frequencies 'w' that actually occurred
            if (counts_freq[w] > max_freq_of_freq) {
                max_freq_of_freq = counts_freq[w];
                mode_freq = w;
            }
            // If counts_freq[w] == max_freq_of_freq, we do nothing.
            // This is because 'w' is greater than the current 'mode_freq' (due to increasing iteration),
            // and we need to report the smallest 'w' in case of a tie.
        }
    }
    
    std::cout << mode_freq << "\n";
}

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {  // Loop through each test case
        solve();
    }

    return 0;
}