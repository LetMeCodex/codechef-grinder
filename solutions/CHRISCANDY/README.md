# [Christmas Candy (CHRISCANDY)](https://www.codechef.com/problems/CHRISCANDY)
- **Difficulty Rating**: 1214
- **Solved in**: 1 attempt(s)

## Problem Summary

We are given `N` friends seated in a row, indexed from `0` to `N-1`. Each friend `i` has a unique ID `A[i]`, where `A` is a permutation of numbers from `1` to `N`.

A friend `A[i]` receives a candy if there exists at least one friend `A[k]` such that:
1. `k < i` (friend `A[k]` is seated to the left of friend `A[i]`).
2. `A[k] > A[i]` (friend `A[k]` has a larger ID than friend `A[i]`).

The task is to find the total number of *distinct* friends (by their ID) who receive at least one candy.

## Intuition & Mathematical Observation

The core condition for a friend `A[i]` to receive a candy is the existence of an `A[k]` to their left (`k < i`) with a larger ID (`A[k] > A[i]`). This is a classic pattern that can be efficiently solved using a data structure that tracks counts of elements seen so far.

Let's process the friends from left to right, i.e., iterate `i` from `0` to `N-1`.
For each friend `A[i]`:
1. We need to determine if there's any friend `A[k]` (where `k < i`) that has an ID greater than `A[i]`.
2. If such an `A[k]` exists, then `A[i]` receives a candy. We should mark `A[i]`'s ID as a recipient.
3. After processing `A[i]` as a potential recipient, `A[i]` itself becomes a "seen" friend. It can now act as `A[k]` for any subsequent friend `A[j]` (where `j > i`). Therefore, we must add `A[i]` to our collection of "seen" friends.

A Fenwick Tree (also known as a Binary Indexed Tree or BIT) is an ideal data structure for this. Since the friend IDs are unique and range from `1` to `N`, we can use a Fenwick Tree of size `N` to store counts.

Here's how the Fenwick Tree helps:
- **`update(value, delta)`**: Adds `delta` to the count associated with `value`. In our case, `delta` will be `1` to mark that `value` has been seen.
- **`query(idx)`**: Returns the sum of counts for all values from `1` to `idx`.

To find the count of friends `A[k]` (with `k < i`) such that `A[k] > A[i]`:
- First, query the total count of friends seen so far: `total_seen = ft.query(N)`.
- Then, query the count of friends seen so far whose IDs are less than or equal to `A[i]`: `seen_le_current = ft.query(A[i])`.
- The difference `total_seen - seen_le_current` gives us the count of friends seen so far whose IDs are strictly greater than `A[i]`.

If this count is greater than `0`, it means `A[i]` receives a candy. We use a boolean array `received_candy` (indexed by friend ID from `1` to `N`) to keep track of which distinct friends have received candy. After iterating through all friends, we simply count the number of `true` values in `received_candy`.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading input: $O(N)$ for the array `A` per test case.
    -   Fenwick Tree initialization: $O(N)$.
    -   Main loop iterating `N` times (for `i` from `0` to `N-1`):
        -   Inside the loop, `ft.query(N)`, `ft.query(current_friend_num)`, and `ft.update(current_friend_num, 1)` each take $O(\log N)$ time.
        -   Total for the loop: $N \times O(\log N) = O(N \log N)$.
    -   Counting distinct recipients: $O(N)$.
    -   Overall time complexity per test case: $O(N \log N)$.
    -   For `T` test cases: $O(T \cdot N \log N)$.

-   **Space Complexity**:
    -   `std::vector<int> A(N)`: $O(N)$ to store friend IDs.
    -   `FenwickTree ft(N)`: The internal `bit` vector is of size `N+1`, so $O(N)$.
    -   `std::vector<bool> received_candy(N + 1)`: $O(N)$ to track recipients.
    -   Overall space complexity per test case: $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for this solution, but often useful.

// Fenwick Tree (BIT) implementation
// This class is designed to handle 1-indexed values from 1 to N.
class FenwickTree {
private:
    std::vector<int> bit;
    int size;

public:
    // Constructor: initializes a Fenwick tree for numbers up to 'n'.
    // All counts are initially zero.
    FenwickTree(int n) : size(n), bit(n + 1, 0) {}

    // Add value 'delta' to the element at index 'idx'.
    // 'idx' must be 1-indexed (1 <= idx <= size).
    void update(int idx, int delta) {
        for (; idx <= size; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    // Get the sum of elements from index 1 to 'idx'.
    // 'idx' must be 1-indexed (1 <= idx <= size).
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }
};

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Fenwick tree to keep track of numbers encountered so far.
    // Values in A are 1 to N, so BIT size N is appropriate for 1-based indexing.
    FenwickTree ft(N); 
    
    // Boolean array to mark friends who have received at least one candy.
    // Index i corresponds to friend number i.
    // Size N+1 to use 1-based indexing for friend numbers (1 to N).
    std::vector<bool> received_candy(N + 1, false);

    // Iterate through the friends from left to right (seat i = 0 to N-1).
    for (int i = 0; i < N; ++i) {
        int current_friend_num = A[i];
        
        // To check if current_friend_num (A[i]) receives a candy,
        // we need to see if there's any friend A[k] with k < i such that A[k] > A[i].
        // This is equivalent to querying the Fenwick tree for the count of numbers
        // greater than current_friend_num that have been added to the BIT so far.
        
        // ft.query(N) gives the total count of numbers added to the BIT so far.
        // ft.query(current_friend_num) gives the count of numbers <= current_friend_num added to the BIT so far.
        // Their difference gives the count of numbers > current_friend_num added to the BIT so far.
        int count_greater_elements_to_left = ft.query(N) - ft.query(current_friend_num);

        if (count_greater_elements_to_left > 0) {
            // If there's at least one A[k] (k < i) such that A[k] > A[i],
            // then current_friend_num (A[i]) receives a candy.
            received_candy[current_friend_num] = true;
        }

        // After processing A[i] as a potential recipient, add it to the Fenwick tree.
        // This makes A[i] available as a potential giver for subsequent friends A[j] (j > i).
        ft.update(current_friend_num, 1);
    }

    // Count the number of distinct friends who received candy.
    int total_recipients = 0;
    for (int i = 1; i <= N; ++i) {
        if (received_candy[i]) {
            total_recipients++;
        }
    }
    std::cout << total_recipients << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
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