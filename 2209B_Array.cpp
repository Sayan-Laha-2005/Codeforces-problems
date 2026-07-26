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

        vector<long long> a(n);

        for (auto &x : a)
            cin >> x;


        for (int i = 0; i < n; i++) {

            int smaller = 0;
            int greater = 0;

            for (int j = i + 1; j < n; j++) {

                if (a[j] < a[i])
                    smaller++;

                else if (a[j] > a[i])
                    greater++;
            }

            cout << max(smaller, greater) << " ";
        }

        cout << "\n";
    }

    return 0;
}