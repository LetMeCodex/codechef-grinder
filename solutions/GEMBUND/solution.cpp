#include <bits/stdc++.h> // Includes iostream, algorithm, etc. as per instructions
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int R, B, G; // Variables to store the counts of red, blue, and green gems
        cin >> R >> B >> G; // Read the gem counts for the current test case

        // Calculate the maximum number of bundles that can be formed.
        // A bundle requires 1 red, 1 blue, and 1 green gem.
        // The number of bundles is limited by the gem type with the minimum count.
        // std::min({R, B, G}) uses an initializer list (C++11 feature) to find the minimum of three values.
        int num_bundles = min({R, B, G});

        // Calculate coins earned from selling bundles.
        // Each bundle sells for 10 coins.
        // Using long long for coins to be safe, though int would suffice given the constraints.
        long long coins_from_bundles = (long long)num_bundles * 10;

        // Calculate the number of remaining gems of each type after forming bundles.
        int remaining_R = R - num_bundles;
        int remaining_B = B - num_bundles;
        int remaining_G = G - num_bundles;

        // Calculate coins earned from selling individual gems.
        // These remaining gems cannot form another bundle (because at least one type is now 0).
        // Each individual gem sells for 3 coins.
        long long coins_from_individuals = (long long)(remaining_R + remaining_B + remaining_G) * 3;

        // The total maximum coins earned is the sum of coins from bundles and individual gems.
        long long total_coins = coins_from_bundles + coins_from_individuals;

        // Output the result for the current test case, followed by a newline.
        cout << total_coins << "\n";
    }

    return 0; // Indicate successful execution
}