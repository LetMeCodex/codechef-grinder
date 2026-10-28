#include <cstdio>   // For scanf, printf
#include <algorithm> // For std::max

int main() {
    // No need for std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); with C-style I/O
    int t;
    scanf("%d", &t); // Read number of test cases
    while (t--) {
        long long x, y;
        scanf("%lld %lld", &x, &y); // Read X and Y
        char s[31]; // Character array for the string (length 30 + null terminator)
        scanf("%s", s); // Read the binary string

        long long actual_salary = 0;
        int max_streak = 0;
        int current_streak = 0;

        // Iterate through the string. The problem states string length is exactly 30.
        for (int i = 0; i < 30; ++i) {
            if (s[i] == '1') {
                actual_salary += x; // Add X for each working day
                current_streak++;   // Increment current streak
            } else {
                max_streak = std::max(max_streak, current_streak); // Update max streak if current streak is longer
                current_streak = 0; // Reset current streak on leave day
            }
        }
        // After the loop, check if the longest streak ends at the very end of the string
        max_streak = std::max(max_streak, current_streak);

        long long bonus_salary = (long long)max_streak * y; // Calculate bonus salary
        long long total_salary = actual_salary + bonus_salary; // Calculate total salary

        printf("%lld\n", total_salary); // Print the result
    }
    return 0;
}