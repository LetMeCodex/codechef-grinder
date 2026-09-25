#include <bits/stdc++.h> // Includes most standard libraries, as requested

// Using namespace std; is common in competitive programming
// and explicitly requested by the problem instructions.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a standard practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T each iteration
        int N, K, M;
        cin >> N >> K >> M; // Read N, K, M for the current test case

        // Calculate the total capacity of candies a single bag can hold.
        // A bag has K pockets, and each pocket can hold M candies.
        // So, one bag can hold K * M candies.
        int capacity_per_bag = K * M;

        // To find the minimum number of bags, we need to divide the total
        // number of candies (N) by the capacity of one bag (capacity_per_bag).
        // Since we must put *every* candy, if there are any remaining candies
        // after filling whole bags, we need an additional bag for them.
        // This is equivalent to performing a ceiling division.
        // The formula for ceiling division (ceil(A/B)) using integer arithmetic
        // for positive A and B is (A + B - 1) / B.
        int min_bags = (N + capacity_per_bag - 1) / capacity_per_bag;

        // Print the calculated minimum number of bags, followed by a newline.
        cout << min_bags << "\n";
    }

    return 0; // Indicate successful execution
}