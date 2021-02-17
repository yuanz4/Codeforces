#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w, n;
    cin >> w >> n;
    int a[n+2];
    a[0] = 0;
    a[n+1] = w;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    set<int> ans;
    for (int i = 0; i < n + 1; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            int len = a[j] - a[i];
            ans.insert(len);
        }
    }
    for (auto& i: ans)
        cout << i << ' ';
    cout << '\n';
    return 0;
}