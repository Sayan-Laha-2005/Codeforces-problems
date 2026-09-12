#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int ans = 0;

        // Process each farm
        for (int i = 0; i < n; i += k) {
            bool allOne = true;

            // Check the k fields of this farm
            for (int j = i; j < i + k; j++) {
                if (s[j] == '0') {
                    allOne = false;
                    break;
                }
            }

            // If every field belongs to Nhoj
            if (allOne)
                ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}