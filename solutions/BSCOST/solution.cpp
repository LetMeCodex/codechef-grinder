#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;

        long long count0 = 0;
        long long count1 = 0;
        for (char c : s) {
            if (c == '0') {
                count0++;
            } else {
                count1++;
            }
        }

        // If all characters are the same, no 01 or 10 transitions exist.
        if (count0 == 0 || count1 == 0) {
            cout << 0 << "\n";
            continue;
        }

        // To minimize tax, we want to group all 0s together and all 1s together.
        // The possible arrangements that minimize transitions are:
        // 1. All 0s followed by all 1s (e.g., 000111)
        // 2. All 1s followed by all 0s (e.g., 111000)

        // Case 1: All 0s followed by all 1s.
        // This arrangement looks like: 00...011...1
        // There will be exactly one occurrence of '01' at the boundary.
        // The cost is 1 * X.

        // Case 2: All 1s followed by all 0s.
        // This arrangement looks like: 11...100...0
        // There will be exactly one occurrence of '10' at the boundary.
        // The cost is 1 * Y.

        // The minimum tax is the minimum of these two cases.
        // However, the problem states we can rearrange the string in *any* way.
        // The key insight is that any arrangement of a binary string with `count0` zeros and `count1` ones
        // will have a certain number of 01 and 10 transitions.
        // The total number of transitions (01 + 10) is related to how many blocks of consecutive identical characters there are.
        // For example, 11010 has blocks 11, 0, 1, 0. Transitions: 10, 01, 10.
        // The minimum number of transitions is achieved when we have at most two blocks: one block of 0s and one block of 1s.
        // This leads to either 0...01...1 or 1...10...0.
        // In the first case (0...01...1), there is exactly one 01 transition.
        // In the second case (1...10...0), there is exactly one 10 transition.

        // So, the minimum tax is achieved by either forming a string with one 01 transition or one 10 transition.
        // The cost for one 01 transition is X.
        // The cost for one 10 transition is Y.
        // The minimum tax is min(X, Y).

        // Let's re-verify the logic.
        // If we have `count0` zeros and `count1` ones.
        // The string can be rearranged to `count0` zeros followed by `count1` ones: `00...011...1`.
        // This string has exactly one `01` transition. The cost is `X`.
        // The string can be rearranged to `count1` ones followed by `count0` zeros: `11...100...0`.
        // This string has exactly one `10` transition. The cost is `Y`.
        // Any other arrangement will have more transitions. For example, `0101` has two `01` and one `10`.
        // The minimum number of transitions is 1. This can be either a `01` or a `10`.
        // Therefore, the minimum cost is `min(X, Y)`.

        cout << min(x, y) << "\n";
    }
    return 0;
}