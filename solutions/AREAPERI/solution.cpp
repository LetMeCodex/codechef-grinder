#include <bits/stdc++.h> // Includes common libraries like iostream, algorithm, etc.

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    cin.tie(NULL);

    // Declare variables for length (L) and breadth (B) of the rectangle.
    // 'int' is sufficient for L and B, as their maximum values are 1000.
    // The calculated area (L*B) and perimeter (2*(L+B)) will also fit within
    // the typical range of an 'int' (up to 2*10^9).
    int L, B;

    // Read the length L from the first line of input.
    cin >> L;
    // Read the breadth B from the second line of input.
    cin >> B;

    // Calculate the area of the rectangle.
    // Formula: Area = Length * Breadth
    int area = L * B;

    // Calculate the perimeter of the rectangle.
    // Formula: Perimeter = 2 * (Length + Breadth)
    int perimeter = 2 * (L + B);

    // Compare the calculated area and perimeter to determine which is greater,
    // or if they are equal.
    if (area > perimeter) {
        // If the area is strictly greater than the perimeter:
        // Print "Area" on the first line.
        cout << "Area\n";
        // Print the calculated area on the second line.
        cout << area << "\n";
    } else if (perimeter > area) {
        // If the perimeter is strictly greater than the area:
        // Print "Peri" on the first line.
        cout << "Peri\n";
        // Print the calculated perimeter on the second line.
        cout << perimeter << "\n";
    } else { // This condition is met if area == perimeter
        // If the area and perimeter are equal:
        // Print "Eq" on the first line.
        cout << "Eq\n";
        // Print the value (either area or perimeter, as they are the same) on the second line.
        cout << area << "\n";
    }

    // The main function returns 0 to indicate successful execution of the program.
    return 0;
}