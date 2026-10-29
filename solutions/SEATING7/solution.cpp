#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; as requested
using namespace std;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;

    // Using a boolean vector to represent seats.
    // occupied[i] is true if seat i is taken, false otherwise.
    // Size N+1 because seats are 1-indexed (seats 1 to N).
    vector<bool> occupied(N + 1, false);

    // Read the M initially occupied seats and mark them
    for (int i = 0; i < M; ++i) {
        int seat_num;
        cin >> seat_num;
        occupied[seat_num] = true;
    }

    // next_available_seat keeps track of the lowest seat number
    // from which to start searching for an empty seat.
    // This is an optimization: since people always take the lowest
    // available seat, and seats are only ever taken, we don't need
    // to search from seat 1 every time.
    int next_available_seat = 1;

    // For each of the K new people
    for (int i = 0; i < K; ++i) {
        // Find the lowest numbered available seat
        // Start search from next_available_seat, as seats below it
        // must already be occupied.
        for (int seat_num = next_available_seat; seat_num <= N; ++seat_num) {
            if (!occupied[seat_num]) {
                // Found an available seat
                // Print the seat number. Add a space after it unless it's the last number for this test case.
                cout << seat_num << (i == K - 1 ? "" : " "); 
                
                occupied[seat_num] = true; // Mark this seat as occupied
                
                // Update next_available_seat for the next person.
                // The next person will search from the seat immediately after this one.
                next_available_seat = seat_num + 1; 
                
                break; // Move to the next person
            }
        }
    }
    cout << "\n"; // Newline after all K seats for the current test case
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}