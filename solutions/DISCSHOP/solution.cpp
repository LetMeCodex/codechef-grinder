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
        long long n;
        cin >> n;
        string s = to_string(n);
        long long min_price = -1;

        for (int i = 0; i < s.length(); ++i) {
            string temp = "";
            for (int j = 0; j < s.length(); ++j) {
                if (i == j) continue;
                temp += s[j];
            }

            // Convert the resulting string to a long long
            // The problem statement allows leading zeros in the intermediate
            // representation, but the final output should not have leading zeros.
            // `stoll` handles this correctly by ignoring leading zeros.
            long long current_price = stoll(temp);

            if (min_price == -1 || current_price < min_price) {
                min_price = current_price;
            }
        }
        cout << min_price << "\n";
    }
    return 0;
}