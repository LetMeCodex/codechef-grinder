#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string a;
        std::cin >> a;

        // The allowed operation is swapping A[i] and A[i+2].
        // This means characters at even indices can only be swapped with other characters
        // at even indices. Similarly, characters at odd indices can only be swapped with
        // other characters at odd indices.
        //
        // For a string to be a palindrome, the character at index i must be equal to
        // the character at index N-1-i.
        //
        // Consider the indices:
        // 0, 1, 2, 3, ..., N-3, N-2, N-1
        //
        // If we swap A[i] and A[i+2]:
        // - If i is even, i+2 is also even. So, an even index character can move to another even index.
        // - If i is odd, i+2 is also odd. So, an odd index character can move to another odd index.
        //
        // This implies that the set of characters at even positions is independent of the
        // set of characters at odd positions.
        //
        // For the string to be a palindrome, for every i, A[i] must equal A[N-1-i].
        //
        // Let's analyze the parity of indices i and N-1-i.
        // Since N is even, N-1 is odd.
        //
        // Case 1: i is even.
        // Then N-1-i is odd - even = odd.
        // So, A[even_index] must match A[odd_index].
        //
        // Case 2: i is odd.
        // Then N-1-i is odd - odd = even.
        // So, A[odd_index] must match A[even_index].
        //
        // In both cases, a character at an even index must match a character at an odd index.
        //
        // However, the operation only allows swapping characters within the same parity group.
        // This means we can rearrange characters at even positions arbitrarily among themselves,
        // and characters at odd positions arbitrarily among themselves.
        //
        // For the string to be a palindrome, the multiset of characters at even positions
        // must be the same as the multiset of characters at odd positions.
        //
        // Let's verify this.
        // If the multisets are the same, we can arrange them such that A[i] = A[N-1-i].
        // For example, if we have 'a', 'b' at even indices and 'a', 'b' at odd indices.
        // We can form "abba".
        //
        // If the multisets are different, say 'a', 'a' at even and 'b', 'b' at odd.
        // We can form "aabb" or "bbaa". Neither is a palindrome.
        //
        // So, the condition is that the multiset of characters at even indices must be
        // identical to the multiset of characters at odd indices.

        std::map<char, int> even_counts;
        std::map<char, int> odd_counts;

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                even_counts[a[i]]++;
            } else {
                odd_counts[a[i]]++;
            }
        }

        if (even_counts == odd_counts) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}