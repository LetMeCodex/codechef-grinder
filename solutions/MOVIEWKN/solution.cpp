#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

void solve() {
    int n;
    cin >> n; // Read the number of movies

    vector<int> L(n);
    for (int i = 0; i < n; ++i) {
        cin >> L[i]; // Read movie lengths
    }

    vector<int> R(n);
    for (int i = 0; i < n; ++i) {
        cin >> R[i]; // Read movie ratings
    }

    int max_product = 0; // Stores the maximum L*R product found so far
    int max_rating_for_max_product = 0; // Stores the rating R for the movie with max_product (used for tie-breaking)
    int best_index = -1; // Stores the 1-based index of the best movie

    for (int i = 0; i < n; ++i) {
        int current_product = L[i] * R[i]; // Calculate L*R for the current movie

        if (current_product > max_product) {
            // This movie is strictly better by the primary criterion (L*R)
            max_product = current_product;
            max_rating_for_max_product = R[i];
            best_index = i + 1; // Store 1-based index
        } else if (current_product == max_product) {
            // Tie on primary criterion, check secondary criterion (max R)
            if (R[i] > max_rating_for_max_product) {
                // This movie is better by the secondary criterion (higher R)
                max_rating_for_max_product = R[i];
                best_index = i + 1; // Store 1-based index
            }
            // If R[i] == max_rating_for_max_product, it's a tie on both primary and secondary.
            // In this case, we need the minimal index. Since we iterate from i=0 upwards,
            // 'best_index' will naturally retain the smallest index among such ties.
            // So, no action is needed here.
        }
    }

    cout << best_index << "\n"; // Output the 1-based index of the chosen movie
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}