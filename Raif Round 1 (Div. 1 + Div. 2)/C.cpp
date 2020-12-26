#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		string s;
		cin >> s;
		stack<char> st;
		for (auto& i: s) {
			st.push(i);
			while (st.size() >= 2 && st.top() == 'B') {
				st.pop();
				st.pop();
			}
		}
		cout << st.size() << '\n';
	}
	return 0;
}