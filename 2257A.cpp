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

        // available[c] = whether an initial word starts with c
        bool available[26] = {};

        for (int i = 0; i < n; i++) {
            string w;
            cin >> w;

            available[w[0] - 'a'] = true;
        }

        bool possible = true;

        for (int i = 0; i < m; i++) {
            string a;
            cin >> a;

            for (char c : a) {
                // Abbreviation uses uppercase letters.
                int x = c - 'A';

                if (!available[x]) {
                    possible = false;
                }
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}