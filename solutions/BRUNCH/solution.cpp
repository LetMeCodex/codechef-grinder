#include <iostream> // Required for cin and cout
#include <algorithm> // Required for std::min

// It's common in competitive programming to include <bits/stdc++.h>
// which pulls in most standard library headers.
// For this specific problem, iostream and algorithm are sufficient.

// Using namespace std; is common in competitive programming to avoid
// repeatedly typing std::
using namespace std;

void solve() {
    int X, Y;
    cin >> X >> Y; // Read the number of plates Chef prepared (X) and plates each person takes (Y)

    // Calculate how many neighbours Chef can feed based on the total plates available.
    // Integer division X / Y automatically gives floor(X / Y), which is what we need
    // for "completely" feeding neighbours.
    int neighbours_fed_by_plates = X / Y;

    // Chef only has 20 neighbours. So, the maximum number of neighbours he can feed
    // cannot exceed 20, even if he has enough plates for more.
    // We take the minimum of the neighbours he can feed based on plates
    // and the actual total number of neighbours he has (20).
    int max_neighbours_completely_fed = min(neighbours_fed_by_plates, 20);

    // Output the result for the current test case, followed by a newline.
    cout << max_neighbours_completely_fed << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
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