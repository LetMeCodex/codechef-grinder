#include <iostream> // Required for cin
#include <cstdio>   // Required for printf

// Use the standard namespace to avoid writing std::repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    // These lines primarily affect cin/cout. While we're switching to printf for output,
    // cin is still used for input, so these are beneficial for input speed.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, R; // Declare two integer variables L and R
    cin >> L >> R; // Read the values of L and R from standard input

    // Determine the first odd number to start printing from.
    // If L is odd, start from L.
    // If L is even, the next number (L+1) will be odd, so start from L+1.
    int current_num;
    if (L % 2 != 0) { // L is odd
        current_num = L;
    } else { // L is even
        current_num = L + 1;
    }

    bool first_odd_printed = false; // Flag to manage space printing

    // Iterate from the first odd number up to R (inclusive), incrementing by 2 each time.
    // This ensures we only process odd numbers and do so efficiently.
    while (current_num <= R) {
        if (first_odd_printed) {
            // If an odd number has already been printed, print a space before the current one.
            printf(" "); // Using printf for faster output
        }
        printf("%d", current_num); // Using printf for faster output
        first_odd_printed = true; // Set flag to true as an odd number has now been printed
        current_num += 2; // Move to the next odd number
    }

    printf("\n"); // Print a newline character at the end of the output line using printf

    return 0; // Indicate successful execution
}