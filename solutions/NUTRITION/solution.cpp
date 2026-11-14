#include <bits/stdc++.h> // Includes all standard libraries, as per problem instructions.

// Use the standard namespace as per problem instructions.
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of fruits.

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read fruit types.
    }

    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i]; // Read nutrition values.
    }

    // max_nutrition_per_type[type_id] will store the maximum nutrition value
    // found for a fruit of that specific type.
    // Fruit types A_i are between 1 and N. Since N <= 100, types are 1 to 100.
    // We need an array of size 101 to cover indices 0 to 100.
    // Initialize all values to -101, which is less than or equal to the minimum
    // possible nutrition value B_i (-100). This ensures that the first B_i
    // encountered for any type will correctly update its max_nutrition_per_type entry.
    vector<int> max_nutrition_per_type(101, -101); 

    // Iterate through all fruits to find the maximum nutrition for each type.
    for (int i = 0; i < N; ++i) {
        // For fruit A[i] with nutrition B[i], update the maximum for its type.
        max_nutrition_per_type[A[i]] = max(max_nutrition_per_type[A[i]], B[i]);
    }

    // Calculate the total maximum nutrition.
    // Initialize with 0, as eating no fruits gives 0 nutrition.
    // Using long long for total_max_nutrition is a good practice for sums,
    // though for given constraints (max sum 100*100 = 10000), int would suffice.
    long long total_max_nutrition = 0; 

    // Iterate through all possible fruit types (from 1 to 100).
    // For each type, if its maximum nutrition value is positive, add it to the total.
    // If it's zero or negative, we choose not to eat any fruit of that type,
    // as it would not increase (or would decrease) the total nutrition.
    for (int i = 1; i <= 100; ++i) { 
        if (max_nutrition_per_type[i] > 0) {
            total_max_nutrition += max_nutrition_per_type[i];
        }
    }

    // Output the result for the current test case.
    cout << total_max_nutrition << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}