#include <iostream> // Required for standard input/output operations (cin, cout)
#include <vector>   // Required for std::vector, a dynamic array
#include <numeric>  // Not strictly needed for this problem, but often useful (e.g., std::iota)
#include <algorithm> // Not strictly needed for this problem, but often useful (e.g., std::max)

// Using namespace std; is common in competitive programming to avoid
// repeatedly typing std:: before standard library elements.
using namespace std;

// Function to solve a single test case
void solve() {
    int N; // Number of friends
    cin >> N;

    // Create a vector to store the count of recommendations for each laptop.
    // Since laptop IDs are from 1 to 10, a vector of size 11 is used
    // to allow 1-based indexing (counts[1] for laptop 1, counts[10] for laptop 10).
    // All counts are initialized to 0.
    vector<int> counts(11, 0); 

    // Read N recommendations and update their counts
    for (int i = 0; i < N; ++i) {
        int laptop_id;
        cin >> laptop_id;
        counts[laptop_id]++; // Increment the count for the recommended laptop
    }

    int max_recommendations = 0; // Stores the highest number of recommendations found so far
    int recommended_laptop_id = -1; // Stores the ID of the laptop with max_recommendations
    int num_laptops_with_max_recs = 0; // Counts how many laptops have max_recommendations

    // Iterate through laptop IDs from 1 to 10 to find the maximum recommendations
    // and determine if there's a unique laptop with that maximum.
    for (int i = 1; i <= 10; ++i) {
        if (counts[i] > max_recommendations) {
            // Found a new maximum number of recommendations
            max_recommendations = counts[i];
            recommended_laptop_id = i; // This laptop is currently the sole winner
            num_laptops_with_max_recs = 1; // Reset count of laptops with max recommendations
        } else if (counts[i] == max_recommendations) {
            // Found another laptop with the same maximum number of recommendations
            num_laptops_with_max_recs++;
        }
    }

    // Output the result based on the number of laptops with maximum recommendations
    if (num_laptops_with_max_recs == 1) {
        // If exactly one laptop has the maximum recommendations, print its ID
        cout << recommended_laptop_id << "\n";
    } else {
        // If multiple laptops have the maximum recommendations, Chef is CONFUSED
        cout << "CONFUSED" << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}