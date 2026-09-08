#include <iostream> // Required for cin, cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::sort

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N; // Declare N to store the number of triples
    std::cin >> N; // Read the number of triples

    // Loop N times, once for each triple
    while (N--) {
        // Declare a vector of 3 integers to store the current triple
        std::vector<int> nums(3);
        
        // Read the three integers into the vector
        std::cin >> nums[0] >> nums[1] >> nums[2];

        // Sort the vector in ascending order.
        // After sorting, nums[0] will be the minimum,
        // nums[1] will be the second minimum (which is the second maximum for 3 distinct numbers),
        // and nums[2] will be the maximum.
        std::sort(nums.begin(), nums.end());

        // Output the second element (index 1) which is the second maximum
        std::cout << nums[1] << "\n";
    }

    return 0; // Indicate successful execution
}