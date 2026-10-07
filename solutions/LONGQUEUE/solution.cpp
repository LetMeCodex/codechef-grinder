#include <bits/stdc++.h> // Required header for competitive programming

// Required namespace usage
using namespace std;

void solve() {
    int n;
    cin >> n; // Read the number of people in the queue
    vector<int> a(n); // Create a vector to store wealths
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Read wealths into the vector
    }

    // Sushil is the N-th person, so his wealth is at index N-1 (0-indexed)
    int sushil_wealth = a[n - 1];
    // Sushil's initial position is N (1-indexed)
    int sushil_position = n;

    // Iterate from the person directly in front of Sushil backwards.
    // The person directly in front is at index n-2 (0-indexed).
    // We go down to index 0 (the first person in the original queue).
    for (int i = n - 2; i >= 0; --i) {
        int person_in_front_wealth = a[i];
        
        // Check if Sushil can bully this person.
        // Condition: person_in_front_wealth <= sushil_wealth / 2.
        // Using person_in_front_wealth * 2 <= sushil_wealth for robust integer arithmetic.
        if (person_in_front_wealth * 2 <= sushil_wealth) {
            // Sushil bullies this person, so his position moves forward by 1.
            sushil_position--;
        } else {
            // Sushil cannot bully this person, so the process stops.
            break;
        }
    }

    // Output Sushil's final position.
    cout << sushil_position << "\n";
}

int main() {
    // Enable fast I/O for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases.
    while (t--) {
        solve(); // Solve each test case.
    }

    return 0;
}