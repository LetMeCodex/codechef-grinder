# [Codechef Airlines (AIRLINES)](https://www.codechef.com/problems/AIRLINES)
- **Difficulty Rating**: 475
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef owns 10 airplanes. Each airplane has a capacity of `X` passengers. There are `Y` people who are willing to book tickets. Each ticket costs `Z` rupees. The task is to calculate the maximum amount of money Chef can earn.

## Intuition & Mathematical Observation

The core idea is to determine how many tickets Chef can actually sell, and then multiply that number by the price per ticket.

1.  **Total Available Seats**: Chef has 10 airplanes, and each airplane can hold `X` passengers. So, the total number of seats available across all airplanes is `10 * X`.

2.  **Number of Tickets Sold**:
    *   Chef cannot sell more tickets than the total number of seats available (`10 * X`).
    *   Chef cannot sell more tickets than the number of people willing to book (`Y`).
    *   Therefore, the actual number of tickets Chef can sell is limited by the minimum of these two quantities. That is, `tickets_sold = min(Y, 10 * X)`.

3.  **Maximum Earnings**: Once we have the number of tickets sold, the maximum earnings are simply the `tickets_sold` multiplied by the cost per ticket `Z`.
    `max_earnings = tickets_sold * Z`.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution involves a few constant-time arithmetic operations (multiplication, `min`, multiplication) and input/output operations. These operations do not depend on the magnitude of the input values (within integer limits). If there are $T$ test cases, the total time complexity will be $O(T)$.

-   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of variables (`X`, `Y`, `Z`, `total_available_seats`, `tickets_sold`, `max_earnings`, `T`) to store input and intermediate results. The memory usage does not grow with the input values, making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

// Use the standard namespace to avoid writing std:: before every standard library function
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y, Z;
    // Read the capacity of each airplane (X),
    // the number of people willing to book (Y),
    // and the cost per ticket (Z).
    cin >> X >> Y >> Z;

    // Calculate the total number of seats available across all 10 airplanes.
    // Chef has 10 airplanes, each with capacity X.
    int total_available_seats = 10 * X;

    // Determine the actual number of tickets Chef can sell.
    // Chef can sell tickets to at most Y people (if Y is less than or equal to available seats).
    // Chef can sell at most total_available_seats tickets (if Y is greater than available seats).
    // So, the number of tickets sold is the minimum of Y and total_available_seats.
    int tickets_sold = min(Y, total_available_seats);

    // Calculate the maximum amount Chef can earn.
    // This is the number of tickets sold multiplied by the price per ticket (Z).
    // We use long long for max_earnings to safely store the product,
    // although for the given constraints (max 100*100 = 10000), int would also be sufficient.
    long long max_earnings = (long long)tickets_sold * Z;

    // Output the maximum earnings for the current test case, followed by a newline.
    cout << max_earnings << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases.
    cin >> T;
    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}
```