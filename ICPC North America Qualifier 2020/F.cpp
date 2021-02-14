#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;
    getline(cin, line);
	int n = stoi(line);
	while (n--) {
		getline(cin, line);
		if (line.size() >= 10) {
			string start = line.substr(0, 10);
			if (start == "Simon says")
				cout << line.substr(11) << '\n';
		}
	}
	return 0;
}