#include <bits/stdc++.h> // Includes all standard C++ libraries

using namespace std; // Uses the standard namespace to avoid prefixing std::

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O.
    // cin.tie(NULL) prevents cout from being flushed before each cin operation,
    // further improving performance.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable X to store the page number.
    cin >> X; // Read the single integer X from standard input.

    // The problem states that the newspaper has 10 pages, numbered 1 to 10.
    // The last 3 pages are dedicated to the sports section.
    // These pages are:
    // 10 (the last page)
    // 9 (the second to last page)
    // 8 (the third to last page)
    // So, any page number X that is 8, 9, or 10 is part of the sports section.
    // This condition can be simply checked by verifying if X is greater than or equal to 8.
    if (X >= 8) {
        // If X is 8, 9, or 10, it's a sports page.
        cout << "YES\n"; // Output "YES" followed by a newline.
    } else {
        // If X is any page from 1 to 7, it's not a sports page.
        cout << "NO\n"; // Output "NO" followed by a newline.
    }

    return 0; // Indicate successful program execution.
}