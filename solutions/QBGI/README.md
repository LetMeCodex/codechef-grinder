# [Bar Queue (QBGI)](https://www.codechef.com/problems/QBGI)
- **Difficulty Rating**: 821
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem describes a queue of `N` people, where each person is either a 'B' (boy) or a 'G' (girl). People enter a bar one by one from the front of the queue. There's a security rule: if at any point the number of boys who have entered the bar becomes strictly greater than twice the number of girls who have entered, the security closes the entrance. We need to determine the maximum number of people who can enter the bar before this security condition is met. If all `N` people can enter without the condition being met, the answer is `N`.

## Intuition & Mathematical Observation

The problem asks for the maximum number of people who can enter, given a dynamic condition that depends on the cumulative count of boys and girls. Since people enter one by one from the front of the queue, this suggests a direct simulation approach.

Here's the intuition:
1.  **Iterate sequentially**: We must process the people in the order they appear in the queue, from front to back (index 0 to `N-1` in the input string).
2.  **Maintain counts**: As each person enters, we need to keep track of:
    *   `boys_count`: The total number of boys who have entered so far.
    *   `girls_count`: The total number of girls who have entered so far.
    *   `people_entered`: The total number of people who have entered so far.
3.  **Check condition immediately**: After *each* person enters, we must check the security condition: `boys_count > 2 * girls_count`.
4.  **Stop and report**: If the condition is met, it means the current person just caused the security to close the entrance. The `people_entered` count at this exact moment is our answer. We can stop processing and print this value.
5.  **All clear**: If we iterate through all `N` people in the queue and the security condition is never met, it means all `N` people can enter the bar. In this scenario, the answer is `N`.

There isn't a complex mathematical observation beyond directly implementing the given rule. The key is the sequential processing and immediate condition check.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   The solution involves a single loop that iterates through the input string `S` from index `0` to `N-1`.
    *   Inside the loop, operations like character comparison, incrementing counters, and checking the security condition are all constant time operations.
    *   In the worst case, the loop runs `N` times (if the security condition is never met, or met at the very last person).
    *   Therefore, the time complexity is directly proportional to the length of the queue, `N`. Given `N` is up to 10, this is extremely efficient.

*   **Space Complexity**: $O(N)$
    *   We use a `char` array `S` of size `N+1` to store the input string representing the queue. This consumes $O(N)$ space.
    *   A few integer variables (`N`, `boys_count`, `girls_count`, `people_entered`, `i`, `T`) are used to store counts and loop indices. These variables take up a constant amount of space, $O(1)$, regardless of `N`.
    *   Thus, the dominant factor for space complexity is the storage of the input string, leading to $O(N)$ space complexity.

## Solution Code

```cpp
#include <cstdio>   // For scanf, printf
#include <string>   // For std::string (though we'll use char array for S)

// Function to solve a single test case
void solve() {
    int N;
    scanf("%d", &N); // Read the length of the queue

    // Using a char array for S to potentially reduce overhead compared to std::string
    // N can be up to 10, so N+1 for the null terminator is sufficient.
    char S[11]; 
    scanf("%s", S); // Read the queue string

    int boys_count = 0;      // Counter for boys who have entered
    int girls_count = 0;     // Counter for girls who have entered
    int people_entered = 0;  // Total people who have entered

    // Iterate through the queue from the front (index 0) to the back
    for (int i = 0; i < N; ++i) {
        // A person enters the bar
        if (S[i] == 'B') {
            boys_count++;
        } else { // S[i] == 'G'
            girls_count++;
        }
        people_entered++; // Increment the total count of people who entered

        // Check the security condition immediately after this person enters
        // The condition is: number of boys > twice the number of girls
        if (boys_count > 2 * girls_count) {
            // If the condition is met, the security closes the entrance.
            // The current 'people_entered' count is the answer for this test case.
            printf("%d\n", people_entered);
            return; // Exit the function for this test case
        }
    }

    // If the loop completes, it means all N people in the queue were allowed to enter
    // without the security condition ever being met.
    // In this case, 'people_entered' would have naturally reached N.
    printf("%d\n", N);
}

int main() {
    // No need for ios_base::sync_with_stdio(false); cin.tie(NULL); with scanf/printf

    int T;
    scanf("%d", &T); // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```