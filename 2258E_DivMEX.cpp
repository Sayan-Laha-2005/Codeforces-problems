#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    const int INF = 1e9;
    vector<int> tree;

    SegTree(int n) : n(n) {
        tree.assign(4 * n + 5, 0);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, val);
        else
            update(node * 2 + 1, mid + 1, r, pos, val);

        tree[node] = min(tree[node * 2],
                         tree[node * 2 + 1]);
    }

    void update(int pos, int val) {
        update(1, 1, n, pos, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return INF;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return min(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        if (l > r)
            return INF;

        return query(1, 1, n, l, r);
    }
};


// Check whether x is a prime power.
bool isPrimePower(int x) {
    int p = 0;

    for (int d = 2; 1LL * d * d <= x; d++) {
        if (x % d == 0) {
            int cnt = 0;

            while (x % d == 0) {
                x /= d;
                cnt++;
            }

            if (p != 0)
                return false;

            p = d;
        }
    }

    // x itself is prime
    if (x > 1) {
        if (p != 0)
            return true;
        return true;
    }

    return p != 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        /*
            Find the smallest prime power > n.
        */
        int limit = n + 1;

        while (!isPrimePower(limit))
            limit++;

        /*
            isPP[x] = whether x is a prime power.

            We only need values up to limit.
        */
        vector<bool> isPP(limit + 1, false);

        for (int x = 2; x <= limit; x++) {
            isPP[x] = isPrimePower(x);
        }

        /*
            Smallest Prime Factor.
        */
        vector<int> spf(n + 1);

        for (int i = 0; i <= n; i++)
            spf[i] = i;

        for (int i = 2; 1LL * i * i <= n; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        /*
            last[x]:
            latest position before/current processing
            where x divides a[position].
        */
        vector<int> last(limit + 1, 0);

        /*
            prev[x]:
            previous obstacle for x,
            i.e. previous position where x | a[i].
        */
        vector<int> prev(limit + 1, 0);

        /*
            Segment tree stores last[x].

            Position = prime power x.
        */
        SegTree seg(limit);

        /*
            1 divides every number.
        */
        last[1] = 0;
        seg.update(1, 0);

        vector<bool> answer(limit + 1, false);

        /*
            Factor every a[i] and obtain its prime-power divisors.
        */
        for (int i = 1; i <= n; i++) {

            vector<int> factors;

            int x = a[i];

            while (x > 1) {
                int p = spf[x];

                int power = 1;

                while (x % p == 0) {
                    x /= p;
                    power *= p;

                    /*
                        power is a prime power divisor
                        of a[i].
                    */
                    factors.push_back(power);
                }
            }

            /*
                Current position i is an obstacle for
                every prime power x dividing a[i].

                IMPORTANT:
                We check BEFORE updating last[],
                because the current position itself cannot
                belong to a valid interval for x.
            */
            for (int x : factors) {

                if (!isPP[x])
                    continue;

                /*
                    We need every prime power q < x
                    to occur after prev[x].

                    min(last[q]) > prev[x]
                */
                int mn = seg.query(1, x - 1);

                if (mn > prev[x]) {
                    answer[x] = true;
                }

                /*
                    Current position becomes the new
                    obstacle for x.
                */
                prev[x] = i;
            }

            /*
                Now current position can be used as an
                occurrence for smaller prime powers.
            */

            last[1] = i;
            seg.update(1, i);

            for (int q : factors) {
                last[q] = i;
                seg.update(q, i);
            }
        }

        /*
            Final interval:
                [prev[x] + 1, n]

            There is no multiple of x after prev[x].
        */
        for (int x = 2; x <= limit; x++) {

            if (!isPP[x])
                continue;

            int mn = seg.query(1, x - 1);

            if (mn > prev[x]) {
                answer[x] = true;
            }
        }

        /*
            Output in increasing order.
        */
        vector<int> ans;

        for (int x = 2; x <= limit; x++) {
            if (answer[x])
                ans.push_back(x);
        }

        cout << ans.size() << '\n';

        for (int x : ans)
            cout << x << ' ';

        cout << '\n';
    }

    return 0;
}