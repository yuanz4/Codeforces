#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		vector<int> ans;
		int left = 0, right = n-1;
		bool r = false, flip = false;
		for (int i = n-1; i >= 0; i--) {
			if (left > right)
				break;
			char first, last;
			if (!r) {
				first = a[left];
				last = a[right];
			} else {
				first = a[right];
				last = a[left];
			}
			if (flip) {
				first = first == '0' ? '1' : '0';
				last = last == '0' ? '1' : '0';
			}
			if (last == b[i]) {
				if (r)
					left++;
				else
					right--;
				continue;
			}
			if (first == b[i]) {
				ans.push_back(1);
				if (!r)
					a[left] = a[left] == '0' ? '1' : '0';
				else
					a[right] = a[right] == '0' ? '1' : '0';
			}
			ans.push_back(i+1);
			if (!r)
				left++;
			else
				right--;
			r = !r;
			flip = !flip;
		}
		cout << ans.size();
		for (auto& i: ans)
			cout << " " << i;
		cout << '\n';
	}
	return 0;
}