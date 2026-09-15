#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> freq(m + 1, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        // suffix[x] = number of carrots with length >= x
        vector<int> suffix(m + 2, 0);

        for (int x = m; x >= 1; x--) {
            suffix[x] = suffix[x + 1] + freq[x];
        }

        int ans = 0;

        for (int x = 1; x <= m; x++) {
            int cur = suffix[x];

            if (2 * x <= m) {
                cur += freq[2 * x];
            }

            ans = max(ans, cur);
        }

        cout << ans << '\n';
    }

    return 0;
}