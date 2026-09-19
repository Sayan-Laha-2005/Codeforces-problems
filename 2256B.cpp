#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long solveParity(const string &s, int start) {
    long long dp0 = 0, dp1 = 0;

    // Initialize first position
    if (s[start] == '0' || s[start] == '?')
        dp0 = 1;

    if (s[start] == '1' || s[start] == '?')
        dp1 = 1;

    // Process positions with same parity
    for (int i = start + 2; i < (int)s.size(); i += 2) {
        long long ndp0 = 0, ndp1 = 0;

        // Current character = 0
        // Previous must be 1
        if (s[i] == '0' || s[i] == '?')
            ndp0 = dp1;

        // Current character = 1
        // Previous must be 0
        if (s[i] == '1' || s[i] == '?')
            ndp1 = dp0;

        dp0 = ndp0;
        dp1 = ndp1;
    }

    return (dp0 + dp1) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        // Even positions and odd positions are independent
        long long evenWays = solveParity(s, 0);
        long long oddWays = solveParity(s, 1);

        cout << (evenWays * oddWays) % MOD << '\n';
    }

    return 0;
}