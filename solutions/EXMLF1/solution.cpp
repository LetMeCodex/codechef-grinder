#include <bits/stdc++.h> // Includes most standard libraries, common in competitive programming

// Function to solve a single test case
void solve() {
    int N; // Number of AI-driven cars
    std::cin >> N;

    int max_speed = 0;      // Stores the maximum speed found so far. Speeds are positive, so 0 is a safe initial minimum.
    int winner_label = 0;   // Stores the label of the car with max_speed. Car labels are 1-indexed.

    // Iterate through each car from 1 to N
    for (int i = 1; i <= N; ++i) {
        int d, t; // Distance traveled and time taken for the current car
        std::cin >> d >> t;

        // Calculate the speed of the current car.
        // d_i is guaranteed to be a multiple of t_i, so integer division is exact.
        int current_speed = d / t;

        // Check if the current car is faster than the fastest car found so far
        if (current_speed > max_speed) {
            max_speed = current_speed; // Update max_speed
            winner_label = i;          // Update winner_label to the current car's label
        }
        // If current_speed == max_speed, we do nothing.
        // This is because we are looking for the minimum label among fastest cars.
        // Since we iterate 'i' from 1 to N, if a car 'j' (where j < i) already
        // achieved 'max_speed', then 'winner_label' would be 'j'.
        // If car 'i' also achieves 'max_speed', its label 'i' will be greater than 'j'.
        // Thus, 'winner_label' already holds the minimum label for 'max_speed'.
    }

    // Output the label of the fastest car (with minimum label in case of ties)
    std::cout << winner_label << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}