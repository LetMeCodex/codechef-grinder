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