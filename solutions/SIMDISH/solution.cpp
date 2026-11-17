#include <bits/stdc++.h> // Includes all standard libraries like iostream, string, vector, set

// Using namespace std; as requested by the problem statement.
using namespace std;

// Function to solve a single test case
void solve() {
    // Create a set to store ingredients of the first dish.
    // A set provides efficient O(log N) average time complexity for insertion and lookup,
    // where N is the number of elements. For N=4, this is very fast.
    set<string> dish1_ingredients;
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s; // Read each ingredient string
        dish1_ingredients.insert(s); // Add it to the set
    }

    // Create a vector to store ingredients of the second dish.
    // We will iterate through this vector to check for common ingredients.
    vector<string> dish2_ingredients(4);
    for (int i = 0; i < 4; ++i) {
        cin >> dish2_ingredients[i]; // Read each ingredient string
    }

    int common_count = 0; // Counter for common ingredients

    // Iterate through each ingredient of the second dish
    for (const string& ing : dish2_ingredients) {
        // Check if the current ingredient from dish2 is present in dish1_ingredients set.
        // set::count(element) returns 1 if the element is found, 0 otherwise.
        if (dish1_ingredients.count(ing)) {
            common_count++; // Increment count if ingredient is common
        }
    }

    // Determine if the dishes are similar based on the common_count.
    // "Similar" means at least half (2 out of 4) ingredients are the same.
    if (common_count >= 2) {
        cout << "similar\n";
    } else {
        cout << "dissimilar\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}