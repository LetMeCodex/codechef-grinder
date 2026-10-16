# [Fair Share Settlement (FAIRSHARE)](https://www.codechef.com/problems/FAIRSHARE)
- **Difficulty Rating**: 665
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate our net payment for a bill `N` that we initially paid in full. We are sharing this bill with `K` friends. The rule for settlement is that each of the `K` friends will reimburse us their "fair share," which is defined as the total bill `N` divided by the total number of people (including us), *rounded down* to the nearest integer. We need to output the final amount we are left paying after receiving these reimbursements.

## Intuition & Mathematical Observation

1.  **Total Number of People**: If there are `K` friends and "you" are also sharing the bill, then the total number of people involved in the settlement is `K + 1`.

2.  **Fair Share per Person (Rounded Down)**: The problem explicitly states that each friend pays their fair share *rounded down*. If the total bill is `N` and there are `(K + 1)` people, the fair share for each person is `N / (K + 1)`. In C++ (and many other languages), integer division `a / b` for positive integers `a` and `b` automatically performs floor division (rounds down to the nearest integer). This perfectly matches the problem's requirement.
    Let `S = N / (K + 1)` be the rounded-down share for each person.

3.  **Total Amount Reimbursed by Friends**: There are `K` friends, and each friend pays `S`. Therefore, the total amount we receive back from our friends is `K * S`.

4.  **Your Net Payment**: We initially paid the entire bill `N`. After receiving `K * S` from our friends, our net payment (the amount we ultimately bear) will be `N - (K * S)`.

The solution directly implements these steps:
*   Calculate `total_people = K + 1`.
*   Calculate `share_per_person_rounded_down = N / total_people`.
*   Calculate `total_reimbursed_by_friends = K * share_per_person_rounded_down`.
*   Calculate `net_payment = N - total_reimbursed_by_friends`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program processes `T` test cases. For each test case, it performs a fixed number of arithmetic operations (addition, division, multiplication, subtraction) and input/output operations. These operations take constant time. Therefore, the time complexity per test case is $O(1)$, leading to a total time complexity of $O(T)$ for `T` test cases.

-   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`T`, `N`, `K`, `total_people`, `share_per_person_rounded_down`, `total_reimbursed_by_friends`, `net_payment`). The amount of memory used by these variables is constant and does not depend on the input values `N` or `K`. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, K; // Declare integer variables N (total bill) and K (number of friends).
        cin >> N >> K; // Read N and K for the current test case.

        // Calculate the total number of people sharing the bill.
        // This includes 'you' and 'K' friends.
        int total_people = K + 1;

        // Calculate each person's fair share, rounded down to the nearest integer.
        // In C++, integer division (e.g., N / total_people) automatically performs
        // floor division for positive integers, which matches the problem's requirement
        // for rounding down.
        int share_per_person_rounded_down = N / total_people;

        // Calculate the total amount reimbursed by the K friends.
        // Each of the K friends pays their rounded-down share.
        int total_reimbursed_by_friends = K * share_per_person_rounded_down;

        // Calculate your net payment.
        // This is the initial total bill you paid minus the total amount
        // you received back from your friends.
        int net_payment = N - total_reimbursed_by_friends;

        // Output the calculated net payment for the current test case,
        // followed by a newline character.
        cout << net_payment << "\n";
    }

    return 0; // Indicate successful program execution.
}
```