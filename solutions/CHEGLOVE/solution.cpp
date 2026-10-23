#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> fingers(n);
        vector<long long> sheaths(n);
        for (int i = 0; i < n; ++i) {
            cin >> fingers[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> sheaths[i];
        }

        bool can_wear_front = true;
        for (int i = 0; i < n; ++i) {
            if (fingers[i] > sheaths[i]) {
                can_wear_front = false;
                break;
            }
        }

        bool can_wear_back = true;
        for (int i = 0; i < n; ++i) {
            if (fingers[i] > sheaths[n - 1 - i]) {
                can_wear_back = false;
                break;
            }
        }

        if (can_wear_front && can_wear_back) {
            cout << "both\n";
        } else if (can_wear_front) {
            cout << "front\n";
        } else if (can_wear_back) {
            cout << "back\n";
        } else {
            cout << "none\n";
        }
    }
    return 0;
}