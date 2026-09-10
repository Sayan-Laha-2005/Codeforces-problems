#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> freq;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            sum += a;
            freq[a]++;
        }

        int mx = 0;
        int x = 0;

        // Find most frequent value
        for (auto it : freq) {
            int value = it.first;
            int count = it.second;

            if (count > mx) {
                mx = count;
                x = value;
            }
        }

        int other = n - mx;

        if (mx <= other + 2) {
            cout << sum << endl;
        }
        else {
            int usable = other + 2;

            long long answer =
                sum - 1LL * (mx - usable) * x;

            cout << answer << endl;
        }
    }

    return 0;
}