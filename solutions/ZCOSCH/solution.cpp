#include <bits/stdc++.h>

using namespace std;

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R; // Declare an integer variable to store the rank
    cin >> R; // Read the rank from standard input

    // Apply the scholarship rules based on the rank R
    if (R >= 1 && R <= 50) {
        // Ranks from 1 to 50 get 100% scholarship
        cout << 100 << "\n";
    } else if (R >= 51 && R <= 100) {
        // Ranks from 51 to 100 get 50% scholarship
        cout << 50 << "\n";
    } else {
        // Ranks greater than 100 get 0% scholarship
        cout << 0 << "\n";
    }

    return 0; // Indicate successful program termination
}