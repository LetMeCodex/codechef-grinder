# Jumping in the hills (HILLS)
- **Difficulty Rating**: 1216
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a sequence of $N$ hills with their respective heights. You start at the first hill (index 0). You can move from hill $i$ to hill $i+1$.
- If the next hill is at the same height or lower than the current hill ($H[i+1] \le H[i]$), you can always move to it.
- If the next hill is taller than the current hill ($H[i+1] > H[i]$), you can move to it only if the height difference ($H[i+1] - H[i]$) is less than or equal to your upward jump capacity $U$.
- You have a parachute that can be used once. If you encounter a downhill jump ($H[i+1] < H[i]$) where the height difference ($H[i] - H[i+1]$) is greater than your downward jump capacity $D$, you can use the parachute to make this jump. Once the parachute is used, it cannot be used again.

The goal is to find the index of the rightmost hill you can reach.

## Intuition & Mathematical Observation

The problem asks for the maximum reachable index. This suggests a greedy approach. We start at the first hill and try to move to the next hill as long as the conditions are met. We maintain a flag to track if the parachute has been used.

Let's analyze the conditions for moving from hill $i$ to hill $i+1$:

1.  **Same height or downhill**: If $H[i+1] \le H[i]$, we can always move to hill $i+1$. This is because the problem statement implies that any downhill or level movement is free.

2.  **Uphill**: If $H[i+1] > H[i]$, we can move to hill $i+1$ only if $H[i+1] - H[i] \le U$. If this condition is not met, we cannot proceed further uphill, and thus we stop at hill $i$.

3.  **Steep downhill (requiring parachute)**: If $H[i+1] < H[i]$ and $H[i] - H[i+1] > D$, we need to use the parachute.
    *   If the parachute has not been used yet, we can use it to make this jump. We mark the parachute as used and proceed to hill $i+1$.
    *   If the parachute has already been used, we cannot make this steep downhill jump and must stop at hill $i$.

We can iterate through the hills from the start, checking the conditions for moving to the next hill. We keep track of the current reachable hill index. If at any point we cannot move to the next hill, the current reachable index is our answer.

The logic can be implemented by iterating from $i = 0$ to $N-2$. For each $i$, we consider the transition from $H[i]$ to $H[i+1]$.

- If $H[i+1] == H[i]$: We can reach hill $i+1$.
- If $H[i+1] > H[i]$:
    - If $H[i+1] - H[i] \le U$: We can reach hill $i+1$.
    - If $H[i+1] - H[i] > U$: We cannot reach hill $i+1$. We stop at hill $i$.
- If $H[i+1] < H[i]$:
    - If $H[i] - H[i+1] \le D$: We can reach hill $i+1$ without using the parachute.
    - If $H[i] - H[i+1] > D$:
        - If parachute is not used: Use parachute, mark it as used, and we can reach hill $i+1$.
        - If parachute is used: We cannot reach hill $i+1$. We stop at hill $i$.

The rightmost reachable hill will be $i+1$ if we successfully make the jump from hill $i$ to hill $i+1$. If we fail to make a jump from hill $i$ to $i+1$, the rightmost reachable hill is $i$. Since we start at index 0, the initial rightmost reachable hill is 1 (meaning we can reach at least the second hill if $N>1$).

The loop should continue as long as we can make the jump. The index of the hill we are currently at is $i$, and the next hill is $i+1$. If we successfully make the jump to $i+1$, the new rightmost reachable hill becomes $i+2$ (since indices are 0-based, and we want to report the 1-based index of the hill).

Let's refine the loop and tracking:
We start at hill 0. We want to find the largest `k` such that we can reach hill `k-1`.
We iterate from `i = 0` to `N-2`.
`rightmost_reachable_hill` will store the 1-based index of the furthest hill we can reach. Initially, it's 1 (representing hill 0).

For `i` from 0 to `N-2`:
  `h_current = H[i]`
  `h_next = H[i+1]`

  If `h_next == h_current`:
    We can reach `i+1`. Update `rightmost_reachable_hill = i + 2`.
  Else if `h_next > h_current`: // Uphill
    If `h_next - h_current <= U`:
      We can reach `i+1`. Update `rightmost_reachable_hill = i + 2`.
    Else:
      We cannot reach `i+1`. Break the loop. The current `rightmost_reachable_hill` is the answer.
  Else: // `h_next < h_current`, Downhill
    If `h_current - h_next <= D`:
      We can reach `i+1` without parachute. Update `rightmost_reachable_hill = i + 2`.
    Else: // Steep downhill
      If `!parachute_used`:
        Use parachute. `parachute_used = true`.
        We can reach `i+1`. Update `rightmost_reachable_hill = i + 2`.
      Else:
        Parachute already used. We cannot reach `i+1`. Break the loop. The current `rightmost_reachable_hill` is the answer.

After the loop finishes (either by breaking or completing all iterations), `rightmost_reachable_hill` will hold the 1-based index of the furthest hill reachable.

Example Walkthrough:
N=5, U=3, D=2
H = [10, 12, 11, 15, 13]

Initial: `rightmost_reachable_hill = 1`, `parachute_used = false`

i = 0: H[0]=10, H[1]=12
  h_next > h_current (12 > 10). Difference = 2.
  2 <= U (3). Yes.
  Can reach hill 1. `rightmost_reachable_hill = 0 + 2 = 2`.

i = 1: H[1]=12, H[2]=11
  h_next < h_current (11 < 12). Difference = 1.
  1 <= D (2). Yes.
  Can reach hill 2. `rightmost_reachable_hill = 1 + 2 = 3`.

i = 2: H[2]=11, H[3]=15
  h_next > h_current (15 > 11). Difference = 4.
  4 <= U (3). No.
  Cannot reach hill 3. Break loop.

Output: `rightmost_reachable_hill = 3`.

Example 2:
N=5, U=3, D=2
H = [10, 8, 6, 10, 8]

Initial: `rightmost_reachable_hill = 1`, `parachute_used = false`

i = 0: H[0]=10, H[1]=8
  h_next < h_current (8 < 10). Difference = 2.
  2 <= D (2). Yes.
  Can reach hill 1. `rightmost_reachable_hill = 0 + 2 = 2`.

i = 1: H[1]=8, H[2]=6
  h_next < h_current (6 < 8). Difference = 2.
  2 <= D (2). Yes.
  Can reach hill 2. `rightmost_reachable_hill = 1 + 2 = 3`.

i = 2: H[2]=6, H[3]=10
  h_next > h_current (10 > 6). Difference = 4.
  4 <= U (3). No.
  Cannot reach hill 3. Break loop.

Output: `rightmost_reachable_hill = 3`.

Example 3:
N=5, U=3, D=2
H = [10, 8, 4, 10, 8]

Initial: `rightmost_reachable_hill = 1`, `parachute_used = false`

i = 0: H[0]=10, H[1]=8
  h_next < h_current (8 < 10). Difference = 2.
  2 <= D (2). Yes.
  Can reach hill 1. `rightmost_reachable_hill = 0 + 2 = 2`.

i = 1: H[1]=8, H[2]=4
  h_next < h_current (4 < 8). Difference = 4.
  4 <= D (2). No.
  Steep downhill. Parachute not used.
  Use parachute. `parachute_used = true`.
  Can reach hill 2. `rightmost_reachable_hill = 1 + 2 = 3`.

i = 2: H[2]=4, H[3]=10
  h_next > h_current (10 > 4). Difference = 6.
  6 <= U (3). No.
  Cannot reach hill 3. Break loop.

Output: `rightmost_reachable_hill = 3`.

Example 4:
N=5, U=3, D=2
H = [10, 8, 4, 2, 10]

Initial: `rightmost_reachable_hill = 1`, `parachute_used = false`

i = 0: H[0]=10, H[1]=8
  h_next < h_current (8 < 10). Difference = 2.
  2 <= D (2). Yes.
  Can reach hill 1. `rightmost_reachable_hill = 0 + 2 = 2`.

i = 1: H[1]=8, H[2]=4
  h_next < h_current (4 < 8). Difference = 4.
  4 <= D (2). No.
  Steep downhill. Parachute not used.
  Use parachute. `parachute_used = true`.
  Can reach hill 2. `rightmost_reachable_hill = 1 + 2 = 3`.

i = 2: H[2]=4, H[3]=2
  h_next < h_current (2 < 4). Difference = 2.
  2 <= D (2). Yes.
  Can reach hill 3. `rightmost_reachable_hill = 2 + 2 = 4`.

i = 3: H[3]=2, H[4]=10
  h_next > h_current (10 > 2). Difference = 8.
  8 <= U (3). No.
  Cannot reach hill 4. Break loop.

Output: `rightmost_reachable_hill = 4`.

Example 5:
N=5, U=3, D=2
H = [10, 8, 4, 1, 10]

Initial: `rightmost_reachable_hill = 1`, `parachute_used = false`

i = 0: H[0]=10, H[1]=8
  h_next < h_current (8 < 10). Difference = 2.
  2 <= D (2). Yes.
  Can reach hill 1. `rightmost_reachable_hill = 0 + 2 = 2`.

i = 1: H[1]=8, H[2]=4
  h_next < h_current (4 < 8). Difference = 4.
  4 <= D (2). No.
  Steep downhill. Parachute not used.
  Use parachute. `parachute_used = true`.
  Can reach hill 2. `rightmost_reachable_hill = 1 + 2 = 3`.

i = 2: H[2]=4, H[3]=1
  h_next < h_current (1 < 4). Difference = 3.
  3 <= D (2). No.
  Steep downhill. Parachute IS used.
  Cannot reach hill 3. Break loop.

Output: `rightmost_reachable_hill = 3`.

The logic seems sound. The code implements this exact logic.

## Complexity Analysis

- **Time Complexity**: $O(N)$
  The code iterates through the array of hills once. Inside the loop, all operations are constant time. Therefore, the time complexity is linear with respect to the number of hills, $N$.

- **Space Complexity**: $O(N)$
  The code uses a `std::vector<int> H` to store the heights of the $N$ hills. This vector takes $O(N)$ space. Other variables use constant space. Thus, the overall space complexity is dominated by the input storage, which is $O(N)$. If we consider the input array as given and not part of the algorithm's auxiliary space, then the auxiliary space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, U, D;
    cin >> N >> U >> D;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // rightmost_reachable_hill stores the 1-based index of the furthest hill reachable.
    // We start at hill 0, so initially we can reach hill 0 (1-based index 1).
    int rightmost_reachable_hill = 1;
    bool parachute_used = false;

    // Iterate through the hills to check reachability to the next hill.
    // We check transitions from hill i to hill i+1.
    for (int i = 0; i < N - 1; ++i) {
        int h_current = H[i];
        int h_next = H[i+1];

        if (h_next == h_current) {
            // Same height, always reachable.
            rightmost_reachable_hill = i + 2; // Can reach hill i+1 (1-based index i+2)
        } else if (h_next > h_current) { // Taller hill (uphill)
            if (h_next - h_current <= U) {
                // Uphill jump within capacity.
                rightmost_reachable_hill = i + 2; // Can reach hill i+1
            } else {
                // Uphill jump exceeds capacity. Cannot proceed further.
                break; 
            }
        } else { // h_next < h_current, Lower hill (downhill)
            if (h_current - h_next <= D) {
                // Downhill jump within normal capacity.
                rightmost_reachable_hill = i + 2; // Can reach hill i+1
            } else { // Steep downhill, requires parachute
                if (!parachute_used) {
                    // Parachute not used yet, use it.
                    parachute_used = true;
                    rightmost_reachable_hill = i + 2; // Can reach hill i+1
                } else {
                    // Parachute already used. Cannot make this steep downhill jump.
                    break; 
                }
            }
        }
    }
    
    cout << rightmost_reachable_hill << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```