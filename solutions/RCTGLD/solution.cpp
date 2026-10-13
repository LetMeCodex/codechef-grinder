#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N;
        std::cin >> N; // Read the amount of ink left for the current test case

        // The perimeter of a rectangle is 2 * (length + width).
        // Chef has N units of ink, so the perimeter must be less than or equal to N.
        // 2 * (L + W) <= N
        // This implies L + W <= N / 2.
        // Since L and W must be integral (positive integers), their sum (L + W) must also be an integer.
        // So, the maximum possible sum of length and width is floor(N / 2).
        // Integer division in C++ automatically computes floor(N / 2) for positive N.
        int S_max = N / 2;

        // To maximize the area (L * W) for a fixed sum (L + W = S_max),
        // L and W should be as close to each other as possible.
        // We can achieve this by setting L to S_max / 2 (integer division)
        // and W to the remaining part, S_max - L.
        // For example, if S_max = 7, L = 7/2 = 3, W = 7 - 3 = 4. Area = 3*4 = 12.
        // If S_max = 8, L = 8/2 = 4, W = 8 - 4 = 4. Area = 4*4 = 16.

        // Also, a rectangle with integral sides must have L >= 1 and W >= 1.
        // This means L + W must be at least 2.
        // If S_max is 0 (e.g., N=0 or N=1), L=0, W=0, Area=0.
        // If S_max is 1 (e.g., N=2 or N=3), L=0, W=1, Area=0.
        // In these cases, the calculated L or W would be 0, resulting in an area of 0,
        // which correctly reflects that a valid rectangle (with positive integral sides) cannot be formed.
        
        int L = S_max / 2;
        int W = S_max - L;

        // Calculate the area.
        // The maximum N is 1000, so S_max is 500. L and W are at most 250.
        // The maximum area is 250 * 250 = 62500, which fits within an 'int'.
        // Using 'long long' for area is a safe practice in competitive programming,
        // though not strictly necessary here.
        long long area = (long long)L * W;

        std::cout << area << "\n"; // Output the maximum area followed by a newline
    }

    return 0; // Indicate successful execution
}