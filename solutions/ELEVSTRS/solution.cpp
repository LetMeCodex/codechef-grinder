#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        double n;
        double v1, v2;
        std::cin >> n >> v1 >> v2;

        // Time taken by stairs
        // Distance = N * sqrt(2)
        // Velocity = V1
        // Time_stairs = Distance / Velocity
        double time_stairs = (n * std::sqrt(2.0)) / v1;

        // Time taken by elevator
        // Elevator goes from ground to N (distance N, time N/V2)
        // Then from N to ground with Chef (distance N, time N/V2)
        // Total time for elevator operation = N/V2 + N/V2 = 2*N/V2
        double time_elevator = (2.0 * n) / v2;

        // Compare times
        // Using a small epsilon for floating point comparisons is good practice,
        // but for this problem, direct comparison should be fine given constraints.
        // If time_elevator is strictly less than time_stairs, choose Elevator.
        // Otherwise, choose Stairs.
        if (time_elevator < time_stairs) {
            std::cout << "Elevator\n";
        } else {
            std::cout << "Stairs\n";
        }
    }
    return 0;
}