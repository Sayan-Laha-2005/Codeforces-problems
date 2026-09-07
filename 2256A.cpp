#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        // Sort: x <= y <= z
        vector<long long> v = {a, b, c};
        sort(v.begin(), v.end());

        long long x = v[0];
        long long y = v[1];
        long long z = v[2];

        /*
            Option 1:
            Do nothing.

            Range = z - x.

            Option 2:
            Replace the largest number z by x + y.

            New triple = (x, y, x+y)

            Its range is:
                (x+y) - x = y
        */

        cout << min(z - x, y) << '\n';
    }

    return 0;
}