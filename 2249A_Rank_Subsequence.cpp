#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> l(n + 1), r(n + 1), u(n + 1), v(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i] >> u[i] >> v[i];
        }

        int ans = 0;

        for (int m = n; m >= 1; m--) {
            int pos = 1;

            for (int i = 1; i <= n && pos <= m; i++) {
                int left = pos;
                int right = m - pos + 1;

                if (left >= l[i] && left <= r[i]) continue;
                if (right >= u[i] && right <= v[i]) continue;

                pos++;
            }

            if (pos == m + 1) {
                ans = m;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}