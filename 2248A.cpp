#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        bool removedZero = false;
        bool removedOne = false;

        string ans;

        for (char ch : s) {
            if (ch == '0' && !removedZero) {
                removedZero = true;
            }
            else if (ch == '1' && !removedOne) {
                removedOne = true;
            }
            else {
                ans += ch;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}