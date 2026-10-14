# [Card Swipe (CARDSWIPE)](https://www.codechef.com/problems/CARDSWIPE)
- **Difficulty Rating**: 1172
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a sequence of card swipes. Each swipe represents either a person entering or leaving a room. A person enters when their card is swiped for the first time, third time, fifth time, and so on (odd-numbered swipes). A person leaves when their card is swiped for the second time, fourth time, sixth time, and so on (even-numbered swipes). We need to find the maximum number of people present in the room at any point in time.

## Intuition & Mathematical Observation

The core idea is to track the number of people currently inside the room as we process the swipes.

When a card is swiped, we need to know if this is an "entry" swipe or an "exit" swipe for that particular person. This depends on how many times that specific card has been swiped *before* the current swipe.

Let's consider a single person with card ID `X`.
- If `X` is swiped for the 1st time: This is an entry. The number of people inside increases by 1.
- If `X` is swiped for the 2nd time: This is an exit. The number of people inside decreases by 1.
- If `X` is swiped for the 3rd time: This is an entry. The number of people inside increases by 1.
- If `X` is swiped for the 4th time: This is an exit. The number of people inside decreases by 1.

We can observe a pattern:
- If the total number of times a card `X` has been swiped *up to and including the current swipe* is **odd**, it signifies an **entry**.
- If the total number of times a card `X` has been swiped *up to and including the current swipe* is **even**, it signifies an **exit**.

To implement this, we can use a data structure to keep track of the swipe count for each unique card ID. An `unordered_map` (or a hash map) is suitable for this, where the key is the card ID and the value is its current swipe count.

As we iterate through the sequence of swipes:
1. For each swipe of card `a[i]`:
2. Increment the swipe count for `a[i]` in our map.
3. Check if the new swipe count for `a[i]` is odd or even.
4. If it's odd, it means a person entered, so we increment `current_people`.
5. If it's even, it means a person left, so we decrement `current_people`.
6. After updating `current_people`, we compare it with `max_people` and update `max_people` if `current_people` is greater.

The `max_people` variable will store the maximum number of people observed in the room at any point.

## Complexity Analysis

- **Time Complexity**: $O(N)$
  - We iterate through the input array `a` of size `N` once.
  - For each element, we perform an `unordered_map` operation (insertion/lookup and increment). On average, `unordered_map` operations take $O(1)$ time.
  - The `std::max` operation is $O(1)$.
  - Therefore, the total time complexity is dominated by the loop, resulting in $O(N)$.

- **Space Complexity**: $O(U)$ where $U$ is the number of unique card IDs.
  - We use an `unordered_map` to store the swipe counts for each unique card ID.
  - In the worst case, all `N` card swipes could be for distinct card IDs, leading to $O(N)$ space. However, if the number of unique card IDs is significantly less than `N`, the space complexity will be $O(U)$. Since $U \le N$, we can say the space complexity is $O(N)$ in the worst case.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of swipes
        std::cin >> n;
        std::vector<int> a(n); // Array to store the card swipe sequence
        
        // Map to store the count of swipes for each card ID.
        // Key: card ID, Value: number of times this card has been swiped.
        std::unordered_map<int, int> swipe_counts;
        
        int current_people = 0; // Tracks the number of people currently in the room
        int max_people = 0;     // Tracks the maximum number of people observed so far

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read the current card swipe

            // Increment the swipe count for the current card ID.
            // If the card ID is not in the map, it's inserted with a count of 1.
            swipe_counts[a[i]]++;

            // Check if the current swipe count for this card is odd or even.
            if (swipe_counts[a[i]] % 2 == 1) {
                // Odd swipe count means this is an entry for this person.
                current_people++;
            } else {
                // Even swipe count means this is an exit for this person.
                current_people--;
            }

            // Update the maximum number of people seen so far.
            max_people = std::max(max_people, current_people);
        }
        
        // Output the maximum number of people that were in the room at any point.
        std::cout << max_people << "\n";
    }
    return 0;
}
```