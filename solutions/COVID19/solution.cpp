#include <bits/stdc++.h> // Includes iostream, vector, algorithm, limits, etc.

// Using namespace std as requested by problem instructions
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of people
    vector<int> X(N); // Create a vector to store their positions
    for (int i = 0; i < N; ++i) {
        cin >> X[i]; // Read positions
    }

    // Initialize min_infected and max_infected.
    // Constraints state N >= 2, so there will always be at least one person
    // and thus at least one segment of size >= 1.
    // Using numeric_limits for robust initialization.
    int min_infected = numeric_limits<int>::max();
    int max_infected = numeric_limits<int>::min();
    
    // current_segment_size tracks the number of people in the current connected group.
    // Start with 1 for the first person in any segment.
    int current_segment_size = 1;

    // Iterate from the second person (index 1) to compare with the previous one.
    for (int i = 1; i < N; ++i) {
        // If the distance between current person and previous person is at most 2,
        // they are part of the same connected segment.
        if (X[i] - X[i-1] <= 2) {
            current_segment_size++;
        } else {
            // If the distance is greater than 2, the current segment ends here.
            // Update min_infected and max_infected with the size of the completed segment.
            min_infected = min(min_infected, current_segment_size);
            max_infected = max(max_infected, current_segment_size);
            
            // Start a new segment with the current person.
            current_segment_size = 1;
        }
    }

    // After the loop, the last segment's size needs to be processed.
    // This is crucial because the loop finishes without processing the segment
    // that extends to the end of the array.
    min_infected = min(min_infected, current_segment_size);
    max_infected = max(max_infected, current_segment_size);

    // Print the results for the current test case.
    cout << min_infected << " " << max_infected << "\n";
}

int main() {
    // Enable fast I/O as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}