#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int H, L, W; // Declare integer variables for Height, Length, and Width of the gift box.
        std::cin >> H >> L >> W; // Read the dimensions for the current test case.

        // Calculate the surface area of one gift box.
        // A rectangular box has 6 faces:
        // - Two faces with dimensions L x W (top and bottom). Area: 2 * L * W
        // - Two faces with dimensions L x H (front and back). Area: 2 * L * H
        // - Two faces with dimensions W x H (left and right). Area: 2 * W * H
        // Total Surface Area = 2 * (L*W + L*H + W*H)
        // All dimensions (H, L, W) are small (1 to 10), so intermediate products
        // and the final surface area will easily fit within an 'int' type.
        int surface_area_one_gift = 2 * (L * W + L * H + W * H);

        // The total available wrapping paper area is a constant 1000 square centimeters.
        const int total_paper_area = 1000;

        // Calculate the maximum number of complete gifts Chef can wrap.
        // This is found by dividing the total available paper area by the surface area
        // required for one gift. Integer division automatically truncates any fractional
        // part, giving us the number of *complete* gifts.
        int max_gifts = total_paper_area / surface_area_one_gift;

        // Output the result for the current test case, followed by a newline character.
        std::cout << max_gifts << "\n";
    }

    return 0; // Indicate successful program execution.
}