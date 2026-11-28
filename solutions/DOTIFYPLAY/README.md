# Dotify Playlist (DOTIFYPLAY)
- **Difficulty Rating**: 1178
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum total length of a playlist of $K$ songs, given that all songs in the playlist must be of a specific target language $L_{target}$. We are given $N$ songs, each with a duration $M_i$ and a language $L_i$.

## Intuition & Mathematical Observation
The core of the problem is to select $K$ songs that satisfy two conditions:
1. They must all be of the target language $L_{target}$.
2. Their combined duration should be maximized.

To maximize the total duration, we should always pick the songs with the longest durations. Therefore, the strategy is to:
1. Filter out all songs that are *not* of the target language $L_{target}$.
2. From the remaining eligible songs, select the $K$ songs with the largest durations.
3. Sum up the durations of these $K$ selected songs.

If there are fewer than $K$ songs available in the target language, it's impossible to form the playlist, and we should output -1.

The mathematical observation is straightforward: to maximize a sum of $K$ elements from a set, we must choose the $K$ largest elements.

## Complexity Analysis
- **Time Complexity**:
    - Reading input: $O(N)$ for each test case.
    - Filtering eligible songs: $O(N)$ for each test case.
    - Sorting eligible songs: If there are $E$ eligible songs, sorting takes $O(E \log E)$. In the worst case, all $N$ songs are eligible, so this is $O(N \log N)$.
    - Summing the top $K$ songs: $O(K)$ for each test case.
    - The dominant factor is sorting. Thus, the overall time complexity per test case is $O(N \log N)$.
    - With $T$ test cases, the total time complexity is $O(T \cdot N \log N)$.

- **Space Complexity**:
    - We store the lengths of eligible songs in a `std::vector`. In the worst case, all $N$ songs are eligible, so the vector can store up to $N$ integers.
    - Thus, the space complexity is $O(N)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Using namespace std; is requested by the problem description.
using namespace std;

void solve() {
    int N, K, L_target;
    cin >> N >> K >> L_target;

    vector<int> eligible_song_lengths;
    for (int i = 0; i < N; ++i) {
        int M_i, L_i;
        cin >> M_i >> L_i;
        // If the song's language matches the target language, add its length
        if (L_i == L_target) {
            eligible_song_lengths.push_back(M_i);
        }
    }

    // Check if enough songs are available to form a playlist of K songs
    if (eligible_song_lengths.size() < K) {
        cout << -1 << "\n"; // Not enough songs, output -1
        return;
    }

    // Sort the eligible songs in descending order of length.
    // This allows us to easily pick the K longest songs.
    // rbegin() and rend() provide reverse iterators for descending sort.
    sort(eligible_song_lengths.rbegin(), eligible_song_lengths.rend());

    long long total_length = 0; // Use long long for sum to be safe, though int would suffice here.
    // Sum the lengths of the K longest eligible songs
    for (int i = 0; i < K; ++i) {
        total_length += eligible_song_lengths[i];
    }

    cout << total_length << "\n";
}

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```