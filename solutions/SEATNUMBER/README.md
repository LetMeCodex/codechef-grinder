# Bus Seat Numbering (SEATNUMBER)
- **Difficulty Rating**: 613
- **Solved in**: 3 attempt(s)

## Problem Summary
The problem asks us to determine the deck (Lower or Upper) and the type of seat (Single or Double) for a given bus seat number `N`. The seat numbering scheme is provided visually in the problem statement.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the provided seat numbering pattern. By carefully observing the image, we can deduce the ranges for each deck and seat type:

**Lower Deck:**
- Seats 1 through 10 are on the Lower Deck and are "Double" seats.
- Seats 11 through 15 are on the Lower Deck and are "Single" seats.

**Upper Deck:**
- Seats 16 through 25 are on the Upper Deck and are "Double" seats.
- Seats 26 through 30 are on the Upper Deck and are "Single" seats.

We can translate these observations into simple conditional logic.

1.  **Determine the Deck:**
    *   If `N` is between 1 and 15 (inclusive), it's on the "Lower" deck.
    *   If `N` is between 16 and 30 (inclusive), it's on the "Upper" deck.

2.  **Determine the Seat Type (within the identified deck):**
    *   **For the Lower Deck:**
        *   If `N` is between 1 and 10 (inclusive), it's a "Double" seat.
        *   If `N` is between 11 and 15 (inclusive), it's a "Single" seat.
    *   **For the Upper Deck:**
        *   If `N` is between 16 and 25 (inclusive), it's a "Double" seat.
        *   If `N` is between 26 and 30 (inclusive), it's a "Single" seat.

These observations directly translate into a series of `if-else if-else` statements.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of comparisons and conditional checks, regardless of the input value `N`. Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a few variables to store the input `N`, the deck type, and the seat type. The amount of memory used does not grow with the input size, making the space complexity constant.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

void solve() {
    int N;
    std::cin >> N;

    std::string deck_type;
    std::string seat_type;

    // Determine the deck
    if (N >= 1 && N <= 15) { // Lower deck
        deck_type = "Lower";
        // Determine seat type for Lower deck based on image
        if (N >= 1 && N <= 10) {
            seat_type = "Double";
        } else { // N >= 11 && N <= 15
            seat_type = "Single";
        }
    } else { // N >= 16 && N <= 30 (Upper deck)
        deck_type = "Upper";
        // Determine seat type for Upper deck based on image
        if (N >= 16 && N <= 25) {
            seat_type = "Double";
        } else { // N >= 26 && N <= 30
            seat_type = "Single";
        }
    }

    std::cout << deck_type << " " << seat_type << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```