#include <iostream> // Required for std::cin, std::cout, std::ios_base, std::endl
#include <cstddef>  // Required for NULL (or use nullptr directly)

// Function to encapsulate the problem logic for a single test case
void solve() {
    int A, B;
    // Read the number of invited boys (A) and girls (B)
    std::cin >> A >> B;

    // Chef is a boy, so add 1 to the count of boys.
    int total_boys = A + 1;
    int total_girls = B;

    // Calculate the total number of slices needed.
    // A boy eats 4 slices, a girl eats 3 slices.
    // Using long long for slices_needed to be safe, though int is sufficient for given constraints.
    long long slices_needed = (long long)total_boys * 4 + (long long)total_girls * 3;

    // A single pizza has 8 slices.
    // To find the minimum number of pizzas, we perform ceiling division.
    // For positive integers x and y, ceil(x/y) can be calculated as (x + y - 1) / y.
    long long pizzas_needed = (slices_needed + 8 - 1) / 8;

    // Output the result
    std::cout << pizzas_needed << std::endl;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); // Or std::cin.tie(nullptr); for modern C++

    // The problem statement indicates only one test case,
    // so we call the solve function once.
    solve();

    return 0;
}