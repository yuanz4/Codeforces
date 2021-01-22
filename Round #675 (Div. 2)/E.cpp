#include <bits/stdc++.h>
using namespace std;

string compress(string& s) {
	string cur;
	if (s.size() <= 10) {
		cur = s;
		reverse(cur.begin(), cur.end());
		return cur;
	} else {
		for (int i = 0; i < 5; i++)
			cur += s[s.size()-1-i];
		cur += "...";
		cur += s[1];
		cur += s[0];
	}
	return cur;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	string suf;
	vector<string> ans;
	vector<int> len;
	char nxt[n+1];
	char dif = 0;
	nxt[n] = dif;
	bool canPop = true;
	for (int i = n-1; i >= 0; i--) {
		if (suf.empty()) {
			suf += s[i];
			canPop = true;
		} else if (s[i] == suf.back()) {
			if (s[i] > dif && canPop) {
				suf.pop_back();
				dif = nxt[i+2];
				canPop = false;
			} else {
				suf += s[i];
				canPop = true;
			}
		} else {
			dif = suf.back();
			suf += s[i];
			canPop = true;
		}
		nxt[i] = dif;
 		ans.push_back(compress(suf));
		len.push_back(suf.size());
	}
	for (int i = n-1; i >= 0; i--)
		cout << len[i] << " " << ans[i] << '\n';
	return 0;
}