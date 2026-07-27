#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> ans = {
        "",
        "walk",
        "no",
        "no",
        "no",
        "yes",
        "yes",
        "backwards",
        "seven"
    };

    cout << ans[n] << "\n";
    return 0;
}