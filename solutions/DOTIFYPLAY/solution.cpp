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