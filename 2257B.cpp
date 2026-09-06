#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n);
        vector<long long> b(m);

        for (auto &x : a)
            cin >> x;

        for (auto &x : b)
            cin >> x;

        int ia = 0; // Bea's current mountain
        int ib = 0; // Ver's current mountain

        /*
            A = number of attacks made by Bea
            B = number of attacks made by Ver
        */
        long long A = 0;
        long long B = 0;

        while (true) {

            /*
                How many attacks does Ver need to make
                before something happens to Bea?

                If Bea is on her last mountain:
                    she loses when it reaches 0.

                Otherwise:
                    she jumps when current = next - 1.
            */
            long long needA;

            if (ia == n - 1) {
                needA = a[ia];
            } else {
                needA = a[ia] - a[ia + 1] + 1;
            }

            /*
                How many attacks does Bea need to make
                before something happens to Ver?
            */
            long long needB;

            if (ib == m - 1) {
                needB = b[ib];
            } else {
                needB = b[ib] - b[ib + 1] + 1;
            }

            /*
                Bea's event happens on Ver's:
                    B + needA
                th attack.

                Global turn:
                    2 * (B + needA)
            */
            long long eventA = 2LL * (B + needA);

            /*
                Ver's event happens on Bea's:
                    A + needB
                th attack.

                Global turn:
                    2 * (A + needB) - 1
            */
            long long eventB = 2LL * (A + needB) - 1;

            if (eventA < eventB) {
                /*
                    Bea's mountain event happens first.

                    Ver makes needA attacks.
                */
                B += needA;

                if (ia == n - 1) {
                    // Bea's last mountain becomes 0.
                    // Bea loses.
                    cout << 2 << '\n';
                    break;
                }

                // Bea jumps to the next mountain.
                ia++;
            } else {
                /*
                    Ver's mountain event happens first.

                    Bea makes needB attacks.
                */
                A += needB;

                if (ib == m - 1) {
                    // Ver's last mountain becomes 0.
                    // Ver loses.
                    cout << 1 << '\n';
                    break;
                }

                // Ver jumps to the next mountain.
                ib++;
            }
        }
    }

    return 0;
}