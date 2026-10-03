#include <bits/stdc++.h> // Includes all standard libraries

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Use the standard namespace as requested.
    using namespace std;

    int X, Y;
    // Read the two space-separated integers X and Y.
    // X: kilometers Chef can run before needing a rest.
    // Y: total distance of the race in kilometers.
    cin >> X >> Y;

    // Calculate the number of times Chef will stop to rest before reaching the finish line.
    // Chef rests after every X kilometers. A rest counts if the distance covered
    // at the rest point is strictly less than the total race distance Y.
    // We are looking for the count of positive integers 'k' such that 'k * X < Y'.
    // This inequality is equivalent to 'k < Y / X'.
    // Since 'k' must be an integer, the largest possible 'k' is floor((Y - 1) / X).
    // The number of such positive integers 'k' is precisely floor((Y - 1) / X).
    // In C++, integer division for positive numbers automatically performs the floor operation.
    int rests = (Y - 1) / X;

    // Print the calculated number of rests, followed by a newline character.
    cout << rests << "\n";

    return 0; // Indicate successful execution.
}